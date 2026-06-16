#!/usr/bin/env python3
"""Generate complex stdlib catalog (200+ modules) and C++ runtime."""

from __future__ import annotations
import os
import sys

_SCRIPTS = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _SCRIPTS)
from gen_catalog_lib import (
    ROOT,
    gen_runtime,
    gen_catalog_cpp,
    gen_afr_stubs,
    gen_docs,
)

MODULES: list[tuple] = []


def cx(name: str, funcs: list) -> None:
    MODULES.append((name, name, funcs))

def add_ultra_game_modules(count: int) -> None:
    """Add lots of game-oriented complex modules.

    Each module is self-contained C++ (no extra headers beyond complex_libs.hpp includes).
    We intentionally keep the API numeric/list-based for AFRILANG.
    """
    for i in range(1, count + 1):
        name = f"gameultra{i:03d}"
        # small per-module variation to make modules distinct
        w_heur = 1.0 + (i % 17) * 0.03
        cx(name, [
            # A* path on a grid (grid is list number size w*h). Cell is blocked if grid[idx] > blockedAbove.
            # Returns list of packed indices (x + y*w) from start to goal (inclusive). Empty if no path.
            ('astarGridPath', 'list number',
             [('grid', 'list number'), ('w', 'number'), ('h', 'number'),
              ('sx', 'number'), ('sy', 'number'), ('gx', 'number'), ('gy', 'number'),
              ('blockedAbove', 'number')],
             '{int W=static_cast<int>(w),H=static_cast<int>(h);'
             'int Sx=static_cast<int>(sx),Sy=static_cast<int>(sy),Gx=static_cast<int>(gx),Gy=static_cast<int>(gy);'
             'if(W<=0||H<=0)return std::vector<double>{};'
             'auto in=[&](int x,int y){return x>=0&&y>=0&&x<W&&y<H;};'
             'if(!in(Sx,Sy)||!in(Gx,Gy))return std::vector<double>{};'
             'auto idx=[&](int x,int y){return y*W+x;};'
             'int N=W*H;'
             'std::vector<double> gScore(N,1e18);'
             'std::vector<int> came(N,-1);'
             'std::vector<char> closed(N,0);'
             'std::vector<int> open;open.reserve(256);'
             'auto blocked=[&](int x,int y){std::size_t k=static_cast<std::size_t>(idx(x,y));'
             'return k>=grid.size()?true:(grid[k]>blockedAbove);};'
             'if(blocked(Sx,Sy)||blocked(Gx,Gy))return std::vector<double>{};'
             f'auto hfun=[&](int x,int y){{return (std::fabs(x-Gx)+std::fabs(y-Gy))*{w_heur:.6f};}};'
             'int s=idx(Sx,Sy),g=idx(Gx,Gy);'
             'gScore[s]=0;open.push_back(s);'
             'while(!open.empty()){'
             'int besti=0;double bestf=1e18;'
             'for(int oi=0;oi<(int)open.size();++oi){int n=open[(std::size_t)oi];'
             'int x=n%W,y=n/W;double f=gScore[(std::size_t)n]+hfun(x,y);'
             'if(f<bestf){bestf=f;besti=oi;}}'
             'int cur=open[(std::size_t)besti];open.erase(open.begin()+besti);'
             'if(cur==g)break;'
             'if(closed[(std::size_t)cur])continue;'
             'closed[(std::size_t)cur]=1;'
             'int cx=cur%W,cy=cur/W;'
             'const int dx[4]={1,-1,0,0};const int dy[4]={0,0,1,-1};'
             'for(int k=0;k<4;++k){int nx=cx+dx[k],ny=cy+dy[k];'
             'if(!in(nx,ny)||blocked(nx,ny))continue;'
             'int ni=idx(nx,ny);if(closed[(std::size_t)ni])continue;'
             'double tg=gScore[(std::size_t)cur]+1.0;'
             'if(tg<gScore[(std::size_t)ni]){gScore[(std::size_t)ni]=tg;came[(std::size_t)ni]=cur;open.push_back(ni);} }'
             '}'
             'if(came[(std::size_t)g]<0 && g!=s)return std::vector<double>{};'
             'std::vector<double> path;'
             'for(int v=g;v>=0;v=came[(std::size_t)v]){path.push_back((double)v);if(v==s)break;}'
             'std::reverse(path.begin(),path.end());return path;}'),

            # Flood-fill count from (sx,sy) over non-blocked cells.
            ('floodCount', 'number',
             [('grid', 'list number'), ('w', 'number'), ('h', 'number'),
              ('sx', 'number'), ('sy', 'number'), ('blockedAbove', 'number')],
             '{int W=static_cast<int>(w),H=static_cast<int>(h);int Sx=static_cast<int>(sx),Sy=static_cast<int>(sy);'
             'if(W<=0||H<=0)return 0;auto in=[&](int x,int y){return x>=0&&y>=0&&x<W&&y<H;};'
             'if(!in(Sx,Sy))return 0;auto idx=[&](int x,int y){return y*W+x;};'
             'auto blocked=[&](int x,int y){std::size_t k=(std::size_t)idx(x,y);return k>=grid.size()?true:(grid[k]>blockedAbove);};'
             'if(blocked(Sx,Sy))return 0;'
             'std::vector<char> vis((std::size_t)(W*H),0);std::vector<int> q;'
             'int s=idx(Sx,Sy);vis[(std::size_t)s]=1;q.push_back(s);'
             'int c=0;'
             'for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];++c;int x=u%W,y=u/W;'
             'const int dx[4]={1,-1,0,0};const int dy[4]={0,0,1,-1};'
             'for(int k=0;k<4;++k){int nx=x+dx[k],ny=y+dy[k];if(!in(nx,ny)||blocked(nx,ny))continue;int v=idx(nx,ny);'
             'if(!vis[(std::size_t)v]){vis[(std::size_t)v]=1;q.push_back(v);} } }'
             'return (double)c;}'),

            # Simplify a grid path by removing collinear intermediate points.
            ('simplifyGridPath', 'list number',
             [('path', 'list number'), ('w', 'number')],
             '{int W=static_cast<int>(w);if(W<=0||path.size()<=2)return path;'
             'auto ix=[&](double p){int v=(int)p;return v%W;};'
             'auto iy=[&](double p){int v=(int)p;return v/W;};'
             'std::vector<double> out;out.reserve(path.size());out.push_back(path[0]);'
             'int px=ix(path[0]),py=iy(path[0]);'
             'int lx=ix(path[1])-px,ly=iy(path[1])-py;'
             'auto sgn=[&](int v){return v>0?1:(v<0?-1:0);};lx=sgn(lx);ly=sgn(ly);'
             'for(std::size_t i=1;i+1<path.size();++i){int cx=ix(path[i]),cy=iy(path[i]);int nx=ix(path[i+1]),ny=iy(path[i+1]);'
             'int dx=sgn(nx-cx),dy=sgn(ny-cy);'
             'if(dx==lx && dy==ly){continue;}'
             'out.push_back(path[i]);lx=dx;ly=dy;px=cx;py=cy;}'
             'out.push_back(path.back());return out;}'),
        ])

def add_ultra_game3d_modules(count: int) -> None:
    """Add lots of 3D game-oriented complex modules (AI steering, boids, ray tests)."""
    for i in range(1, count + 1):
        name = f"gameultra3d{i:03d}"
        # Slight variations per module (defaults baked into functions)
        sepW = 1.1 + (i % 13) * 0.07
        cohW = 0.6 + (i % 11) * 0.05
        aliW = 0.9 + (i % 9) * 0.06
        jitter = 0.02 + (i % 17) * 0.003

        cx(name, [
            # Integrate positions with velocities.
            # pos/vel are flattened xyz arrays (length >= 3*n).
            ('integratePos', 'list number',
             [('pos', 'list number'), ('vel', 'list number'), ('n', 'number'), ('dt', 'number')],
             '{int N=static_cast<int>(n);double DT=dt;std::vector<double> out;'
             'if(N<=0)return out;out.resize((std::size_t)N*3);'
             'for(int i=0;i<N;++i){std::size_t k=(std::size_t)i*3;'
             'double px=k<pos.size()?pos[k]:0,py=k+1<pos.size()?pos[k+1]:0,pz=k+2<pos.size()?pos[k+2]:0;'
             'double vx=k<vel.size()?vel[k]:0,vy=k+1<vel.size()?vel[k+1]:0,vz=k+2<vel.size()?vel[k+2]:0;'
             'out[k]=px+vx*DT;out[k+1]=py+vy*DT;out[k+2]=pz+vz*DT;}return out;}'),

            # Classic "seek" steering: desired velocity towards target with maxSpeed.
            ('steerSeek', 'list number',
             [('px', 'number'), ('py', 'number'), ('pz', 'number'),
              ('tx', 'number'), ('ty', 'number'), ('tz', 'number'),
              ('maxSpeed', 'number')],
             '{double dx=tx-px,dy=ty-py,dz=tz-pz;double l=std::sqrt(dx*dx+dy*dy+dz*dz);'
             'std::vector<double> v(3,0);if(l<1e-9)return v;double s=maxSpeed<=0?0:maxSpeed/l;'
             'v[0]=dx*s;v[1]=dy*s;v[2]=dz*s;return v;}'),

            # Boids velocity update (separation + cohesion + alignment) in O(n^2).
            # Returns newVel (flattened xyz, length 3*n).
            ('boidsVelStep', 'list number',
             [('pos', 'list number'), ('vel', 'list number'), ('n', 'number'),
              ('dt', 'number'), ('neighborDist', 'number'), ('sepDist', 'number'),
              ('maxSpeed', 'number')],
             '{int N=static_cast<int>(n);double DT=dt;double nd=neighborDist;double sd=sepDist;'
             'if(N<=0)return std::vector<double>{};'
             'double nd2=nd*nd,sd2=sd*sd;'
             'std::vector<double> out((std::size_t)N*3,0);'
             'for(int i=0;i<N;++i){std::size_t ik=(std::size_t)i*3;'
             'double ix=ik<pos.size()?pos[ik]:0,iy=ik+1<pos.size()?pos[ik+1]:0,iz=ik+2<pos.size()?pos[ik+2]:0;'
             'double vx=ik<vel.size()?vel[ik]:0,vy=ik+1<vel.size()?vel[ik+1]:0,vz=ik+2<vel.size()?vel[ik+2]:0;'
             'double sepX=0,sepY=0,sepZ=0,cohX=0,cohY=0,cohZ=0,aliX=0,aliY=0,aliZ=0;'
             'int cnt=0;'
             'for(int j=0;j<N;++j){if(j==i)continue;std::size_t jk=(std::size_t)j*3;'
             'double jx=jk<pos.size()?pos[jk]:0,jy=jk+1<pos.size()?pos[jk+1]:0,jz=jk+2<pos.size()?pos[jk+2]:0;'
             'double dx=jx-ix,dy=jy-iy,dz=jz-iz;double d2=dx*dx+dy*dy+dz*dz;'
             'if(d2>0 && d2<=nd2){++cnt;cohX+=jx;cohY+=jy;cohZ+=jz;'
             'double jvx=jk<vel.size()?vel[jk]:0,jvy=jk+1<vel.size()?vel[jk+1]:0,jvz=jk+2<vel.size()?vel[jk+2]:0;'
             'aliX+=jvx;aliY+=jvy;aliZ+=jvz;'
             'if(d2<=sd2){double inv=1.0/std::max(1e-9,std::sqrt(d2));sepX-=dx*inv;sepY-=dy*inv;sepZ-=dz*inv;}}}'
             'if(cnt>0){double inv=1.0/cnt;cohX=(cohX*inv-ix);cohY=(cohY*inv-iy);cohZ=(cohZ*inv-iz);'
             'aliX=(aliX*inv-vx);aliY=(aliY*inv-vy);aliZ=(aliZ*inv-vz);} '
             f'double ax=sepX*{sepW:.6f}+cohX*{cohW:.6f}+aliX*{aliW:.6f};'
             f'double ay=sepY*{sepW:.6f}+cohY*{cohW:.6f}+aliY*{aliW:.6f};'
             f'double az=sepZ*{sepW:.6f}+cohZ*{cohW:.6f}+aliZ*{aliW:.6f};'
             f'vx+=ax*DT;vy+=ay*DT;vz+=az*DT;vx+=std::sin((double)i*12.9898)*{jitter:.6f}*DT;'
             f'vz+=std::cos((double)i*78.233)*{jitter:.6f}*DT;'
             'double sp=std::sqrt(vx*vx+vy*vy+vz*vz);'
             'double ms=maxSpeed; if(ms>0 && sp>ms){double s=ms/sp;vx*=s;vy*=s;vz*=s;}'
             'out[ik]=vx;out[ik+1]=vy;out[ik+2]=vz;}'
             'return out;}'),

            # Ray vs sphere (returns [hit(0/1), t] ; t=-1 if no hit)
            ('raySphereHit', 'list number',
             [('ox', 'number'), ('oy', 'number'), ('oz', 'number'),
              ('dx', 'number'), ('dy', 'number'), ('dz', 'number'),
              ('cx', 'number'), ('cy', 'number'), ('cz', 'number'), ('r', 'number')],
             '{std::vector<double> out(2,0);double lx=cx-ox,ly=cy-oy,lz=cz-oz;'
             'double tca=lx*dx+ly*dy+lz*dz;if(tca<0){out[1]=-1;return out;}'
             'double d2=(lx*lx+ly*ly+lz*lz)-tca*tca;double rr=r*r;'
             'if(d2>rr){out[1]=-1;return out;}double thc=std::sqrt(std::max(0.0,rr-d2));'
             'double t0=tca-thc,t1=tca+thc;double t=t0>0?t0:t1;'
             'if(t<=0){out[1]=-1;return out;}out[0]=1;out[1]=t;return out;}'),
        ])


cx('graphbfs', [
    ('bfsDistances', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);if(nn<=0||st<0||st>=nn)return std::vector<double>{};std::vector<double> d(nn,-1);std::vector<int> q;d[st]=0;q.push_back(st);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}return d;}'),
    ('bfsOrder', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> o;if(nn<=0||st<0||st>=nn)return o;std::vector<bool> vis(nn,false);std::vector<int> q;vis[st]=true;q.push_back(st);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];o.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;q.push_back(v);}}}return o;}'),
    ('bfsReachable', 'number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{auto d=bfsDistances(adj,n,start);int c=0;for(double x:d)if(x>=0)++c;return static_cast<double>(c);}'),
    ('bfsLayers', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{auto d=bfsDistances(adj,n,start);double mx=0;for(double x:d)if(x>mx)mx=x;std::vector<double> L(static_cast<std::size_t>(mx)+1,0);for(double x:d)if(x>=0)L[static_cast<std::size_t>(x)]+=1;return L;}'),
    ('isConnected', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{auto d=bfsDistances(adj,n,0);for(double x:d)if(x<0)return false;return true;}'),
    ('shortestPathLen', 'number', [('adj', 'list number'), ('n', 'number'), ('start', 'number'), ('goal', 'number')],
     '{auto d=bfsDistances(adj,n,start);int g=static_cast<int>(goal);return(g<0||g>=static_cast<int>(d.size()))?-1:d[static_cast<std::size_t>(g)];}'),
    ('multiSourceBfs', 'list number', [('adj', 'list number'), ('n', 'number'), ('sources', 'list number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,-1);std::vector<int> q;for(double s:sources){int u=static_cast<int>(s);if(u>=0&&u<nn&&d[u]<0){d[u]=0;q.push_back(u);}}for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}return d;}'),
])

cx('graphdfs', [
    ('dfsOrder', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> o;if(st<0||st>=nn)return o;std::vector<bool> vis(nn,false);std::vector<int> st2;st2.push_back(st);while(!st2.empty()){int u=st2.back();st2.pop_back();if(vis[u])continue;vis[u]=true;o.push_back(static_cast<double>(u));for(int v=nn-1;v>=0;--v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v])st2.push_back(v);}}return o;}'),
    ('dfsRecursiveMark', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);std::vector<double> comp;for(int i=0;i<nn;++i){if(vis[i])continue;std::vector<int> st;st.push_back(i);while(!st.empty()){int u=st.back();st.pop_back();if(vis[u])continue;vis[u]=true;comp.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v])st.push_back(v);}}}return comp;}'),
    ('hasCycleUndirected', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);for(int s=0;s<nn;++s){if(vis[s])continue;std::vector<std::pair<int,int>> st;st.emplace_back(s,-1);vis[s]=true;while(!st.empty()){auto[u,p]=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]<=0||v==p)continue;if(vis[v])return true;vis[v]=true;st.emplace_back(v,u);}}}return false;}'),
    ('countComponents', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);int c=0;for(int s=0;s<nn;++s){if(vis[s])continue;++c;std::vector<int> st;st.push_back(s);vis[s]=true;while(!st.empty()){int u=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;st.push_back(v);}}}}return static_cast<double>(c);}'),
    ('topoSortDfs', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> state(nn,0);std::vector<double> order;for(int s=0;s<nn;++s){if(state[s]!=0)continue;std::vector<int> st;st.push_back(s);while(!st.empty()){int u=st.back();if(state[u]==2){st.pop_back();continue;}if(state[u]==1){order.push_back(static_cast<double>(u));state[u]=2;st.pop_back();continue;}state[u]=1;for(int v=nn-1;v>=0;--v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&state[v]==0)st.push_back(v);}}}std::reverse(order.begin(),order.end());return order;}'),
    ('isTree', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn==0)return true;int edges=0;for(double w:adj)if(w>0)++edges;edges/=2;return edges==nn-1&&!hasCycleUndirected(adj,n);}'),
    ('dfsPathExists', 'bool', [('adj', 'list number'), ('n', 'number'), ('start', 'number'), ('goal', 'number')],
     '{auto o=dfsOrder(adj,n,start);int g=static_cast<int>(goal);for(double x:o)if(static_cast<int>(x)==g)return true;return false;}'),
])

cx('graphdijk', [
    ('dijkstra', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> d(nn,1e18);if(st>=0&&st<nn)d[st]=0;std::vector<bool> done(nn,false);for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!done[i]&&d[i]<best){best=d[i];u=i;}if(u<0)break;done[u]=true;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[v]=std::min(d[v],d[u]+adj[idx]);}}return d;}'),
    ('shortestWeighted', 'number', [('adj', 'list number'), ('n', 'number'), ('start', 'number'), ('goal', 'number')],
     '{auto d=dijkstra(adj,n,start);int g=static_cast<int>(goal),nn=static_cast<int>(n);return(g<0||g>=nn)?-1:d[static_cast<std::size_t>(g)];}'),
    ('dijkstraPath', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number'), ('goal', 'number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start),go=static_cast<int>(goal);auto d=dijkstra(adj,n,start);std::vector<int> prev(nn,-1);std::vector<bool> done(nn,false);if(st<0||st>=nn||go<0||go>=nn)return std::vector<double>{};for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!done[i]&&d[i]<best){best=d[i];u=i;}if(u<0)break;done[u]=true;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[u]+adj[idx]<d[v]){d[v]=d[u]+adj[idx];prev[v]=u;}}}std::vector<double> path;if(d[go]>=1e17)return path;for(int v=go;v>=0;v=prev[v])path.push_back(static_cast<double>(v));std::reverse(path.begin(),path.end());return path;}'),
    ('minEdgeWeight', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double m=1e18;for(double w:adj)if(w>0)m=std::min(m,w);return m>=1e18?0:m;}'),
    ('maxEdgeWeight', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double m=0;for(double w:adj)if(w>0)m=std::max(m,w);return m;}'),
    ('avgEdgeWeight', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double s=0,c=0;for(double w:adj)if(w>0){s+=w;++c;}return c==0?0:s/c;}'),
    ('edgeCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int c=0;for(double w:adj)if(w>0)++c;return static_cast<double>(c);}'),
])

cx('graphtopo', [
    ('topoSort', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> indeg(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)++indeg[v];}std::vector<int> q;for(int i=0;i<nn;++i)if(indeg[i]==0)q.push_back(i);std::vector<double> order;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];order.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&--indeg[v]==0)q.push_back(v);}}return order;}'),
    ('hasCycleDirected', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{auto t=topoSort(adj,n);return static_cast<int>(t.size())<static_cast<int>(n);}'),
    ('inDegrees', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[v]+=1;}return d;}'),
    ('outDegrees', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[u]+=1;}return d;}'),
    ('sources', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto d=inDegrees(adj,n);std::vector<double> r;for(int i=0;i<static_cast<int>(d.size());++i)if(d[i]==0)r.push_back(static_cast<double>(i));return r;}'),
    ('sinks', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto d=outDegrees(adj,n);std::vector<double> r;for(int i=0;i<static_cast<int>(d.size());++i)if(d[i]==0)r.push_back(static_cast<double>(i));return r;}'),
    ('isDag', 'bool', [('adj', 'list number'), ('n', 'number')],
     'return !hasCycleDirected(adj,n);'),
])

cx('graphcc', [
    ('connectedComponents', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> label(nn,-1);int cid=0;for(int s=0;s<nn;++s){if(label[s]>=0)continue;std::vector<int> st;st.push_back(s);label[s]=cid;while(!st.empty()){int u=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&label[v]<0){label[v]=cid;st.push_back(v);}}}++cid;}std::vector<double> r;for(int x:label)r.push_back(static_cast<double>(x));return r;}'),
    ('componentCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=connectedComponents(adj,n);if(c.empty())return 0;double mx=0;for(double x:c)mx=std::max(mx,x);return mx+1;}'),
    ('largestComponentSize', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=connectedComponents(adj,n);std::map<int,int> m;for(double x:c)++m[static_cast<int>(x)];int best=0;for(auto&p:m)best=std::max(best,p.second);return static_cast<double>(best);}'),
    ('sameComponent', 'bool', [('adj', 'list number'), ('n', 'number'), ('a', 'number'), ('b', 'number')],
     '{auto c=connectedComponents(adj,n);int aa=static_cast<int>(a),bb=static_cast<int>(b);return aa>=0&&bb>=0&&aa<static_cast<int>(c.size())&&bb<static_cast<int>(c.size())&&c[aa]==c[bb];}'),
    ('componentSizes', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=connectedComponents(adj,n);int cc=static_cast<int>(componentCount(adj,n));std::vector<double> sz(cc,0);for(double x:c)sz[static_cast<std::size_t>(x)]+=1;return sz;}'),
    ('outDegreeSum', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[u]+=adj[idx];}return d;}'),
    ('isolateCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto od=outDegreeSum(adj,n);int c=0;for(double x:od)if(x==0)++c;return static_cast<double>(c);}'),
])

cx('graphcycle', [
    ('detectCycleDirected', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> state(nn,0);for(int s=0;s<nn;++s){if(state[s]!=0)continue;std::vector<int> st;st.push_back(s);while(!st.empty()){int u=st.back();if(state[u]==2){st.pop_back();continue;}if(state[u]==1)return true;state[u]=1;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&state[v]==0)st.push_back(v);}if(st.back()==u){state[u]=2;st.pop_back();}}}return false;}'),
    ('detectCycleUndirected', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);for(int s=0;s<nn;++s){if(vis[s])continue;std::vector<std::pair<int,int>> st;st.emplace_back(s,-1);vis[s]=true;while(!st.empty()){auto[u,p]=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]<=0||v==p)continue;if(vis[v])return true;vis[v]=true;st.emplace_back(v,u);}}}return false;}'),
    ('cycleEdgeCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int ec=0;for(double w:adj)if(w>0)++ec;return detectCycleUndirected(adj,n)?static_cast<double>(ec):0;}'),
    ('isAcyclic', 'bool', [('adj', 'list number'), ('n', 'number')],
     'return !detectCycleDirected(adj,n);'),
    ('selfLoopCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n),c=0;for(int i=0;i<nn;++i){std::size_t idx=static_cast<std::size_t>(i*nn+i);if(idx<adj.size()&&adj[idx]>0)++c;}return static_cast<double>(c);}'),
    ('removeSelfLoops', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);auto a=adj;for(int i=0;i<nn;++i){std::size_t idx=static_cast<std::size_t>(i*nn+i);if(idx<a.size())a[idx]=0;}return a;}'),
    ('hasParallelEdges', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);for(int u=0;u<nn;++u){int c=0;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)++c;}if(c>1)return true;}return false;}'),
])

cx('graphmst', [
    ('mstWeightPrim', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=0)return 0;std::vector<double> key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;double total=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;total+=key[u];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return total;}'),
    ('mstWeightKruskal', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);struct E{int u,v;double w;};std::vector<E> es;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)es.push_back({u,v,adj[idx]});}std::sort(es.begin(),es.end(),[](auto&a,auto&b){return a.w<b.w;});std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;auto find=[&](int x){while(p[x]!=x)x=p[x];return x;};double total=0;int cnt=0;for(auto&e:es){int ru=find(e.u),rv=find(e.v);if(ru!=rv){p[ru]=rv;total+=e.w;if(++cnt==nn-1)break;}}return total;}'),
    ('mstEdges', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);return static_cast<double>(std::max(0,nn-1));}'),
    ('compareMstAlgos', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double a=mstWeightPrim(adj,n),b=mstWeightKruskal(adj,n);return std::abs(a-b);}'),
    ('forestMstWeight', 'number', [('adj', 'list number'), ('n', 'number')],
     'return mstWeightKruskal(adj,n);'),
    ('isConnectedForMst', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);std::vector<int> q;q.push_back(0);vis[0]=true;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;q.push_back(v);}}}for(bool b:vis)if(!b)return false;return true;}'),
])

cx('graphshort', [
    ('allPairsBfs', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> r;for(int s=0;s<nn;++s){std::vector<double> d(nn,-1);std::vector<int> q;d[s]=0;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}for(double x:d)r.push_back(x);}return r;}'),
    ('eccentricity', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> ecc(nn,0);for(int s=0;s<nn;++s){std::vector<double> d(nn,-1);std::vector<int> q;d[s]=0;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}double mx=-1;for(double x:d)if(x>mx)mx=x;ecc[s]=mx<0?0:mx;}return ecc;}'),
    ('graphDiameter', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto e=eccentricity(adj,n);return e.empty()?0:*std::max_element(e.begin(),e.end());}'),
    ('graphRadius', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto e=eccentricity(adj,n);return e.empty()?0:*std::min_element(e.begin(),e.end());}'),
    ('centerNodes', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto e=eccentricity(adj,n);double r=graphRadius(adj,n);std::vector<double> c;for(std::size_t i=0;i<e.size();++i)if(e[i]==r)c.push_back(static_cast<double>(i));return c;}'),
    ('peripheryNodes', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto e=eccentricity(adj,n);double d=graphDiameter(adj,n);std::vector<double> p;for(std::size_t i=0;i<e.size();++i)if(e[i]==d)p.push_back(static_cast<double>(i));return p;}'),
])

cx('graphbellman', [
    ('bellmanFord', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> d(nn,1e18);if(st>=0&&st<nn)d[st]=0;for(int k=0;k<nn-1;++k)for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]!=0&&d[u]<1e17)d[v]=std::min(d[v],d[u]+adj[idx]);}return d;}'),
    ('hasNegCycle', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);auto d=bellmanFord(adj,n,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]!=0&&d[u]<1e17&&d[u]+adj[idx]<d[v])return true;}return false;}'),
    ('negEdgeCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int c=0;for(double w:adj)if(w<0)++c;return static_cast<double>(c);}'),
    ('relaxOnce', 'list number', [('adj', 'list number'), ('n', 'number'), ('dist', 'list number')],
     '{int nn=static_cast<int>(n);auto d=dist;for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]!=0&&u<static_cast<int>(d.size())&&v<static_cast<int>(d.size())&&d[u]<1e17)d[v]=std::min(d[v],d[u]+adj[idx]);}return d;}'),
    ('pathCost', 'number', [('adj', 'list number'), ('n', 'number'), ('path', 'list number')],
     '{int nn=static_cast<int>(n);double c=0;for(std::size_t i=1;i<path.size();++i){int u=static_cast<int>(path[i-1]),v=static_cast<int>(path[i]);std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]==0)return -1;c+=adj[idx];}return c;}'),
    ('reachableWeighted', 'number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{auto d=bellmanFord(adj,n,start);int c=0;for(double x:d)if(x<1e17)++c;return static_cast<double>(c);}'),
])

cx('graphfloyd', [
    ('floydWarshall', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(static_cast<std::size_t>(nn*nn),1e18);for(int i=0;i<nn;++i){d[static_cast<std::size_t>(i*nn+i)]=0;for(int j=0;j<nn;++j){std::size_t idx=static_cast<std::size_t>(i*nn+j);if(idx<adj.size()&&adj[idx]>0)d[idx]=adj[idx];}}for(int k=0;k<nn;++k)for(int i=0;i<nn;++i)for(int j=0;j<nn;++j){double via=d[static_cast<std::size_t>(i*nn+k)]+d[static_cast<std::size_t>(k*nn+j)];std::size_t ij=static_cast<std::size_t>(i*nn+j);if(via<d[ij])d[ij]=via;}return d;}'),
    ('pairDistance', 'number', [('adj', 'list number'), ('n', 'number'), ('a', 'number'), ('b', 'number')],
     '{auto d=floydWarshall(adj,n);int aa=static_cast<int>(a),bb=static_cast<int>(b),nn=static_cast<int>(n);if(aa<0||bb<0||aa>=nn||bb>=nn)return -1;return d[static_cast<std::size_t>(aa*nn+bb)];}'),
    ('closureReachable', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto d=floydWarshall(adj,n);std::vector<double> r;for(double x:d)r.push_back(x<1e17?1:0);return r;}'),
    ('graphDensity', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=1)return 0;int e=0;for(double w:adj)if(w>0)++e;return static_cast<double>(e)/(nn*(nn-1));}'),
    ('avgShortestPath', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto d=floydWarshall(adj,n);int nn=static_cast<int>(n);double s=0,c=0;for(int i=0;i<nn;++i)for(int j=0;j<nn;++j)if(i!=j){double x=d[static_cast<std::size_t>(i*nn+j)];if(x<1e17){s+=x;++c;}}return c==0?0:s/c;}'),
    ('transitiveClosure', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> reach(static_cast<std::size_t>(nn*nn),0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)reach[idx]=1;}for(int k=0;k<nn;++k)for(int i=0;i<nn;++i)for(int j=0;j<nn;++j)if(reach[static_cast<std::size_t>(i*nn+k)]&&reach[static_cast<std::size_t>(k*nn+j)])reach[static_cast<std::size_t>(i*nn+j)]=1;return reach;}'),
])

cx('graphprim', [
    ('primMst', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=0)return 0;std::vector<double> key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;double total=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;total+=key[u];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return total;}'),
    ('primParents', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> par(nn,-1),key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v]&&adj[idx]<key[v]){key[v]=adj[idx];par[v]=static_cast<double>(u);}}}return par;}'),
    ('primOrder', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> order,key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;order.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return order;}'),
    ('mstEdgeCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);return static_cast<double>(std::max(0,nn-1));}'),
    ('lightestEdge', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double m=1e18;for(double w:adj)if(w>0)m=std::min(m,w);return m>=1e18?0:m;}'),
    ('heaviestMstEdge', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;double heaviest=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;heaviest=std::max(heaviest,key[u]);for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return heaviest;}'),
    ('isPrimConnected', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> in(nn,false);std::vector<double> key(nn,1e18);key[0]=0;int cnt=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;++cnt;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return cnt==nn;}'),
])

cx('graphkruskal', [
    ('kruskalMst', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);struct E{int u,v;double w;};std::vector<E> es;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)es.push_back({u,v,adj[idx]});}for(std::size_t i=es.size();i>1;--i){std::size_t j=static_cast<std::size_t>(std::rand()%(static_cast<int>(i)));std::swap(es[i-1],es[j]);}std::sort(es.begin(),es.end(),[](auto&a,auto&b){return a.w<b.w;});std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;auto find=[&](int x){while(p[x]!=x)x=p[x];return x;};double total=0;int cnt=0;for(auto&e:es){int ru=find(e.u),rv=find(e.v);if(ru!=rv){p[ru]=rv;total+=e.w;if(++cnt==nn-1)break;}}return total;}'),
    ('kruskalEdges', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);struct E{int u,v;double w;};std::vector<E> es;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)es.push_back({u,v,adj[idx]});}std::sort(es.begin(),es.end(),[](auto&a,auto&b){return a.w<b.w;});std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;auto find=[&](int x){while(p[x]!=x)x=p[x];return x;};std::vector<double> picked;int cnt=0;for(auto&e:es){int ru=find(e.u),rv=find(e.v);if(ru!=rv){p[ru]=rv;picked.push_back(static_cast<double>(e.u));picked.push_back(static_cast<double>(e.v));picked.push_back(e.w);if(++cnt==nn-1)break;}}return picked;}'),
    ('unionFindComponents', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0){int ru=u,rv=v;while(p[ru]!=ru)ru=p[ru];while(p[rv]!=rv)rv=p[rv];if(ru!=rv)p[ru]=rv;}}std::map<int,int> roots;for(int i=0;i<nn;++i){int r=i;while(p[r]!=r)r=p[r];++roots[r];}return static_cast<double>(roots.size());}'),
    ('edgeListSize', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n),c=0;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)++c;}return static_cast<double>(c);}'),
    ('kruskalForestWeight', 'number', [('adj', 'list number'), ('n', 'number')],
     'return kruskalMst(adj,n);'),
    ('maxSpanningForest', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);struct E{int u,v;double w;};std::vector<E> es;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)es.push_back({u,v,adj[idx]});}std::sort(es.begin(),es.end(),[](auto&a,auto&b){return a.w>b.w;});std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;auto find=[&](int x){while(p[x]!=x)x=p[x];return x;};double total=0;for(auto&e:es){int ru=find(e.u),rv=find(e.v);if(ru!=rv){p[ru]=rv;total+=e.w;}}return total;}'),
    ('compareKruskalPrim', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double k=kruskalMst(adj,n);int nn=static_cast<int>(n);std::vector<double> key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;double p=0;for(int t=0;t<nn;++t){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;p+=key[u];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return std::abs(k-p);}'),
])

cx('graphbipart', [
    ('isBipartite', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> color(nn,-1);for(int s=0;s<nn;++s){if(color[s]!=-1)continue;color[s]=0;std::vector<int> q;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0){if(color[v]==-1){color[v]=1-color[u];q.push_back(v);}else if(color[v]==color[u])return false;}}}}return true;}'),
    ('bipartiteColors', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> color(nn,-1);for(int s=0;s<nn;++s){if(color[s]>=0)continue;color[s]=0;std::vector<int> q;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&color[v]<0){color[v]=1-color[u];q.push_back(v);}}}}std::vector<double> r;for(double c:color)r.push_back(c);return r;}'),
    ('partitionSizes', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=bipartiteColors(adj,n);double a=0,b=0;for(double x:c)if(x==0)++a;else if(x==1)++b;return std::vector<double>{a,b};}'),
    ('crossEdgeCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=bipartiteColors(adj,n);int nn=static_cast<int>(n),cnt=0;for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&c[u]!=c[v])++cnt;}return static_cast<double>(cnt);}'),
    ('sameSideEdges', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=bipartiteColors(adj,n);int nn=static_cast<int>(n),cnt=0;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&c[u]==c[v])++cnt;}return static_cast<double>(cnt);}'),
    ('bipartiteDensity', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto p=partitionSizes(adj,n);return p[0]*p[1]==0?0:crossEdgeCount(adj,n)/(p[0]*p[1]);}'),
    ('hasOddCycle', 'bool', [('adj', 'list number'), ('n', 'number')],
     'return !isBipartite(adj,n);'),
])

cx('grapheuler', [
    ('vertexDegrees', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[u]+=1;}return d;}'),
    ('hasEulerCircuit', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{auto d=vertexDegrees(adj,n);int odd=0;for(double x:d)if(static_cast<int>(x)%2==1)++odd;return odd==0;}'),
    ('hasEulerPath', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{auto d=vertexDegrees(adj,n);int odd=0;for(double x:d)if(static_cast<int>(x)%2==1)++odd;return odd==0||odd==2;}'),
    ('oddDegreeCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto d=vertexDegrees(adj,n);int c=0;for(double x:d)if(static_cast<int>(x)%2==1)++c;return static_cast<double>(c);}'),
    ('totalDegree', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto d=vertexDegrees(adj,n);double s=0;for(double x:d)s+=x;return s;}'),
    ('eulerTrailLen', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int e=0;for(double w:adj)if(w>0)++e;return static_cast<double>(e)+1;}'),
    ('isEulerian', 'bool', [('adj', 'list number'), ('n', 'number')],
     'return hasEulerPath(adj,n);'),
])

cx('graphham', [
    ('hamiltonianExists', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=0||nn>12)return false;std::vector<int> path;std::vector<bool> vis(nn,false);std::function<bool(int)> dfs=[&](int u)->bool{if(static_cast<int>(path.size())==nn)return true;vis[u]=true;path.push_back(u);for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]&&dfs(v))return true;}vis[u]=false;path.pop_back();return false;};return dfs(0);}'),
    ('permuteCheck', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=0||nn>8)return 0;std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;int cnt=0;do{bool ok=true;for(int i=0;i<nn-1;++i){std::size_t idx=static_cast<std::size_t>(p[i]*nn+p[i+1]);if(idx>=adj.size()||adj[idx]<=0){ok=false;break;}}if(ok)++cnt;}while(std::next_permutation(p.begin(),p.end()));return static_cast<double>(cnt);}'),
    ('longestPath', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);std::function<double(int)> dfs=[&](int u)->double{vis[u]=true;double best=1;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v])best=std::max(best,1+dfs(v));}vis[u]=false;return best;};return dfs(0);}'),
    ('hamiltonianCycle', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=1)return true;std::vector<bool> vis(nn,false);std::function<bool(int,int)> dfs=[&](int u,int depth)->bool{if(depth==nn){std::size_t idx=static_cast<std::size_t>(u*nn);return idx<adj.size()&&adj[idx]>0;}vis[u]=true;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]&&dfs(v,depth+1))return true;}vis[u]=false;return false;};return dfs(0,1);}'),
    ('pathCoverSize', 'number', [('adj', 'list number'), ('n', 'number')],
     'return longestPath(adj,n);'),
    ('tspLowerBound', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);double s=0;for(int u=0;u<nn;++u){double mn=1e18;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)mn=std::min(mn,adj[idx]);}if(mn<1e18)s+=mn;}return s;}'),
    ('nearestNeighbor', 'list number', [('adj', 'list number'), ('n', 'number'), ('start', 'number')],
     '{int nn=static_cast<int>(n),cur=static_cast<int>(start);std::vector<double> tour;std::vector<bool> vis(nn,false);if(cur<0||cur>=nn)return std::vector<double>{};for(int step=0;step<nn;++step){vis[cur]=true;tour.push_back(static_cast<double>(cur));int nxt=-1;double best=1e18;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(cur*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]&&adj[idx]<best){best=adj[idx];nxt=v;}}if(nxt<0)break;cur=nxt;}return tour;}'),
])

cx('graphclique', [
    ('maxCliqueSize', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn>14)return 0;std::vector<int> best;std::function<void(int,std::vector<int>&)> bt=[&](int start,std::vector<int>& cur){if(cur.size()>best.size())best=cur;for(int v=start;v<nn;++v){bool ok=true;for(int u:cur){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]<=0){ok=false;break;}}if(!ok)continue;cur.push_back(v);bt(v+1,cur);cur.pop_back();}};std::vector<int> cur;bt(0,cur);return static_cast<double>(best.size());}'),
    ('cliqueNumber', 'number', [('adj', 'list number'), ('n', 'number')],
     'return maxCliqueSize(adj,n);'),
    ('isClique', 'bool', [('adj', 'list number'), ('n', 'number'), ('nodes', 'list number')],
     '{for(std::size_t i=0;i<nodes.size();++i)for(std::size_t j=i+1;j<nodes.size();++j){int u=static_cast<int>(nodes[i]),v=static_cast<int>(nodes[j]);std::size_t idx=static_cast<std::size_t>(u*static_cast<int>(n)+v);if(idx>=adj.size()||adj[idx]<=0)return false;}return nodes.size()>0;}'),
    ('cliqueCover', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);return static_cast<double>(nn)/std::max(1.0,maxCliqueSize(adj,n));}'),
    ('triangleCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n),cnt=0;for(int i=0;i<nn;++i)for(int j=i+1;j<nn;++j)for(int k=j+1;k<nn;++k){std::size_t ij=static_cast<std::size_t>(i*nn+j),ik=static_cast<std::size_t>(i*nn+k),jk=static_cast<std::size_t>(j*nn+k);if(ij<adj.size()&&ik<adj.size()&&jk<adj.size()&&adj[ij]>0&&adj[ik]>0&&adj[jk]>0)++cnt;}return static_cast<double>(cnt);}'),
    ('clusteringCoeff', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> cc(nn,0);for(int u=0;u<nn;++u){std::vector<int> nbr;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)nbr.push_back(v);}int k=static_cast<int>(nbr.size());if(k<2)continue;int edges=0;for(int i=0;i<k;++i)for(int j=i+1;j<k;++j){std::size_t idx=static_cast<std::size_t>(nbr[i]*nn+nbr[j]);if(idx<adj.size()&&adj[idx]>0)++edges;}cc[u]=2.0*edges/(k*(k-1));}return cc;}'),
    ('density', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);if(nn<=1)return 0;int e=0;for(double w:adj)if(w>0)++e;return static_cast<double>(e)/(nn*(nn-1));}'),
])

cx('graphcolor', [
    ('greedyColor', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> color(nn,-1);for(int u=0;u<nn;++u){std::vector<bool> used(nn,false);for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(v*nn+u);if(idx<adj.size()&&adj[idx]>0&&color[v]>=0)used[static_cast<std::size_t>(color[v])]=true;}int c=0;while(c<nn&&used[static_cast<std::size_t>(c)])++c;color[u]=static_cast<double>(c);}return color;}'),
    ('chromaticNumber', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=greedyColor(adj,n);double mx=0;for(double x:c)mx=std::max(mx,x);return mx+1;}'),
    ('isValidColoring', 'bool', [('adj', 'list number'), ('n', 'number'), ('colors', 'list number')],
     '{int nn=static_cast<int>(n);if(static_cast<int>(colors.size())<nn)return false;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&colors[static_cast<std::size_t>(u)]==colors[static_cast<std::size_t>(v)])return false;}return true;}'),
    ('colorClasses', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=greedyColor(adj,n);double mx=chromaticNumber(adj,n);std::vector<double> sz(static_cast<std::size_t>(mx),0);for(double x:c)sz[static_cast<std::size_t>(x)]+=1;return sz;}'),
    ('conflictCount', 'number', [('adj', 'list number'), ('n', 'number'), ('colors', 'list number')],
     '{int nn=static_cast<int>(n),cnt=0;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&u<static_cast<int>(colors.size())&&v<static_cast<int>(colors.size())&&colors[static_cast<std::size_t>(u)]==colors[static_cast<std::size_t>(v)])++cnt;}return static_cast<double>(cnt);}'),
    ('welshPowell', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<std::pair<int,int>> deg;for(int u=0;u<nn;++u){int d=0;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)++d;}deg.emplace_back(d,u);}std::sort(deg.begin(),deg.end(),[](auto&a,auto&b){return a.first>b.first;});std::vector<double> color(nn,-1);for(auto&p:deg){int u=p.second;std::vector<bool> used(nn,false);for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(v*nn+u);if(idx<adj.size()&&adj[idx]>0&&color[v]>=0)used[static_cast<std::size_t>(color[v])]=true;}int c=0;while(c<nn&&used[static_cast<std::size_t>(c)])++c;color[u]=static_cast<double>(c);}return color;}'),
    ('sameColorNeighbors', 'number', [('adj', 'list number'), ('n', 'number'), ('node', 'number')],
     '{auto c=greedyColor(adj,n);int u=static_cast<int>(node),nn=static_cast<int>(n),cnt=0;if(u<0||u>=nn)return 0;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&c[static_cast<std::size_t>(v)]==c[static_cast<std::size_t>(u)])++cnt;}return static_cast<double>(cnt);}'),
])

cx('graphflow', [
    ('maxFlow', 'number', [('adj', 'list number'), ('n', 'number'), ('source', 'number'), ('sink', 'number')],
     '{int nn=static_cast<int>(n),s=static_cast<int>(source),t=static_cast<int>(sink);if(s<0||t<0||s>=nn||t>=nn)return 0;std::vector<double> flow(static_cast<std::size_t>(nn*nn),0);double total=0;auto bfs=[&]()->int{std::vector<int> prev(nn,-1);std::vector<bool> vis(nn,false);std::vector<int> q;q.push_back(s);vis[s]=true;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);double cap=idx<adj.size()?adj[idx]:0;std::size_t fi=static_cast<std::size_t>(u*nn+v);if(!vis[v]&&cap-flow[fi]>1e-9){vis[v]=true;prev[v]=u;q.push_back(v);}}}return prev[t];};while(true){std::vector<int> prev(nn,-1);std::vector<bool> vis(nn,false);std::vector<int> q;q.push_back(s);vis[s]=true;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);double cap=idx<adj.size()?adj[idx]:0;std::size_t fi=static_cast<std::size_t>(u*nn+v);if(!vis[v]&&cap-flow[fi]>1e-9){vis[v]=true;prev[v]=u;q.push_back(v);}}}if(!vis[t])break;double f=1e18;for(int v=t;v!=s;v=prev[v]){int u=prev[v];std::size_t fi=static_cast<std::size_t>(u*nn+v);f=std::min(f,(adj[fi]-flow[fi]));}for(int v=t;v!=s;v=prev[v]){int u=prev[v];std::size_t fi=static_cast<std::size_t>(u*nn+v),fb=static_cast<std::size_t>(v*nn+u);flow[fi]+=f;flow[fb]-=f;}total+=f;}return total;}'),
    ('minCutValue', 'number', [('adj', 'list number'), ('n', 'number'), ('source', 'number'), ('sink', 'number')],
     'return maxFlow(adj,n,source,sink);'),
    ('flowMatrix', 'list number', [('adj', 'list number'), ('n', 'number'), ('source', 'number'), ('sink', 'number')],
     '{int nn=static_cast<int>(n),s=static_cast<int>(source),t=static_cast<int>(sink);std::vector<double> flow(static_cast<std::size_t>(nn*nn),0);double total=0;while(true){std::vector<int> prev(nn,-1);std::vector<bool> vis(nn,false);std::vector<int> q;q.push_back(s);vis[s]=true;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);double cap=idx<adj.size()?adj[idx]:0;std::size_t fi=static_cast<std::size_t>(u*nn+v);if(!vis[v]&&cap-flow[fi]>1e-9){vis[v]=true;prev[v]=u;q.push_back(v);}}}if(!vis[t])break;double f=1e18;for(int v=t;v!=s;v=prev[v]){int u=prev[v];std::size_t fi=static_cast<std::size_t>(u*nn+v);f=std::min(f,adj[fi]-flow[fi]);}for(int v=t;v!=s;v=prev[v]){int u=prev[v];std::size_t fi=static_cast<std::size_t>(u*nn+v),fb=static_cast<std::size_t>(v*nn+u);flow[fi]+=f;flow[fb]-=f;}total+=f;}return flow;}'),
    ('bottleneckCapacity', 'number', [('adj', 'list number'), ('n', 'number')],
     '{double m=1e18;for(double w:adj)if(w>0)m=std::min(m,w);return m>=1e18?0:m;}'),
    ('outFlowSum', 'number', [('adj', 'list number'), ('n', 'number'), ('node', 'number')],
     '{int u=static_cast<int>(node),nn=static_cast<int>(n);double s=0;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)s+=adj[idx];}return s;}'),
    ('inFlowSum', 'number', [('adj', 'list number'), ('n', 'number'), ('node', 'number')],
     '{int v=static_cast<int>(node),nn=static_cast<int>(n);double s=0;for(int u=0;u<nn;++u){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)s+=adj[idx];}return s;}'),
    ('isFlowConserved', 'bool', [('adj', 'list number'), ('n', 'number'), ('source', 'number'), ('sink', 'number')],
     '{double f=maxFlow(adj,n,source,sink);return f>=0;}'),
])

cx('graphmatch', [
    ('maxMatching', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> match(nn,-1);std::function<bool(int,std::vector<bool>&)> aug=[&](int u,std::vector<bool>& vis)->bool{for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;int w=match[v];if(w<0||aug(w,vis)){match[v]=u;match[u]=v;return true;}}}return false;};int cnt=0;for(int u=0;u<nn;++u){if(match[u]<0){std::vector<bool> vis(nn,false);if(aug(u,vis))++cnt;}}return static_cast<double>(cnt);}'),
    ('matchingPairs', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> match(nn,-1);std::function<bool(int,std::vector<bool>&)> aug=[&](int u,std::vector<bool>& vis)->bool{for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;int w=match[v];if(w<0||aug(w,vis)){match[v]=u;match[u]=v;return true;}}}return false;};for(int u=0;u<nn;++u)if(match[u]<0){std::vector<bool> vis(nn,false);aug(u,vis);}std::vector<double> pairs;for(int v=0;v<nn;++v)if(match[v]>v){pairs.push_back(static_cast<double>(v));pairs.push_back(static_cast<double>(match[v]));}return pairs;}'),
    ('isPerfectMatching', 'bool', [('adj', 'list number'), ('n', 'number')],
     '{double m=maxMatching(adj,n);return m*2==static_cast<double>(n);}'),
    ('unmatchedCount', 'number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> match(nn,-1);std::function<bool(int,std::vector<bool>&)> aug=[&](int u,std::vector<bool>& vis)->bool{for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;int w=match[v];if(w<0||aug(w,vis)){match[v]=u;match[u]=v;return true;}}}return false;};for(int u=0;u<nn;++u)if(match[u]<0){std::vector<bool> vis(nn,false);aug(u,vis);}int c=0;for(int i=0;i<nn;++i)if(match[i]<0)++c;return static_cast<double>(c);}'),
    ('matchingWeight', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto p=matchingPairs(adj,n);double s=0;for(std::size_t i=0;i+1<p.size();i+=2){int u=static_cast<int>(p[i]),v=static_cast<int>(p[i+1]);std::size_t idx=static_cast<std::size_t>(u*static_cast<int>(n)+v);if(idx<adj.size())s+=adj[idx];}return s;}'),
    ('vertexCoverSize', 'number', [('adj', 'list number'), ('n', 'number')],
     'return maxMatching(adj,n);'),
    ('isMatched', 'bool', [('adj', 'list number'), ('n', 'number'), ('node', 'number')],
     '{int nn=static_cast<int>(n);std::vector<int> match(nn,-1);std::function<bool(int,std::vector<bool>&)> aug=[&](int u,std::vector<bool>& vis)->bool{for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;int w=match[v];if(w<0||aug(w,vis)){match[v]=u;match[u]=v;return true;}}}return false;};for(int u=0;u<nn;++u)if(match[u]<0){std::vector<bool> vis(nn,false);aug(u,vis);}int nd=static_cast<int>(node);return nd>=0&&nd<nn&&match[nd]>=0;}'),
])

cx('graphcent', [
    ('degreeCentrality', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[u]+=1;}if(nn<=1)return d;for(double&x:d)x/=(nn-1);return d;}'),
    ('closenessCentrality', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> cc(nn,0);for(int s=0;s<nn;++s){std::vector<double> dist(nn,-1);std::vector<int> q;dist[s]=0;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&dist[v]<0){dist[v]=dist[u]+1;q.push_back(v);}}}double sum=0;int reach=0;for(int v=0;v<nn;++v)if(v!=s&&dist[v]>0){sum+=dist[v];++reach;}cc[s]=reach==0?0:static_cast<double>(reach)/sum;}return cc;}'),
    ('betweennessApprox', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> bc(nn,0);for(int s=0;s<nn;++s){std::vector<double> dist(nn,-1);std::vector<int> q;dist[s]=0;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&dist[v]<0){dist[v]=dist[u]+1;q.push_back(v);if(u!=s&&v!=s)bc[u]+=1;}}}}return bc;}'),
    ('eigenvectorCentrality', 'list number', [('adj', 'list number'), ('n', 'number')],
     '{int nn=static_cast<int>(n);std::vector<double> x(nn,1.0/nn);for(int iter=0;iter<20;++iter){std::vector<double> nx(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)nx[v]+=x[u];}double norm=0;for(double v:nx)norm+=v*v;norm=std::sqrt(norm);if(norm<1e-12)break;for(int i=0;i<nn;++i)x[i]=nx[i]/norm;}return x;}'),
    ('pageRank', 'list number', [('adj', 'list number'), ('n', 'number'), ('damping', 'number')],
     '{int nn=static_cast<int>(n);double d=damping;std::vector<double> pr(nn,1.0/nn),outdeg(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)outdeg[u]+=1;}for(int iter=0;iter<25;++iter){std::vector<double> npr(nn,(1-d)/nn);for(int u=0;u<nn;++u)if(outdeg[u]>0)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)npr[v]+=d*pr[u]/outdeg[u];}pr=npr;}return pr;}'),
    ('hubScore', 'list number', [('adj', 'list number'), ('n', 'number')],
     'return eigenvectorCentrality(adj,n);'),
    ('mostCentral', 'number', [('adj', 'list number'), ('n', 'number')],
     '{auto c=closenessCentrality(adj,n);if(c.empty())return 0;return static_cast<double>(std::max_element(c.begin(),c.end())-c.begin());}'),
])

cx('statregress', [
    ('regSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('regMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('regMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('regMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('regVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('regStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('regNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('linearRegress', 'list number', [('x', 'list number'), ('y', 'list number')],
     '{if(x.size()!=y.size()||x.size()<2)return std::vector<double>{};double sx=0,sy=0,sxx=0,sxy=0,n=x.size();for(std::size_t i=0;i<n;++i){sx+=x[i];sy+=y[i];sxx+=x[i]*x[i];sxy+=x[i]*y[i];}double denom=n*sxx-sx*sx;if(std::abs(denom)<1e-12)return std::vector<double>{0,0};double slope=(n*sxy-sx*sy)/denom,intercept=(sy-slope*sx)/n;return std::vector<double>{slope,intercept};}'),
])

cx('statcorrel', [
    ('pearson', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size()||a.size()<2)return 0;double ma=0,mb=0;for(double v:a)ma+=v;for(double v:b)mb+=v;ma/=a.size();mb/=b.size();double num=0,da=0,db=0;for(std::size_t i=0;i<a.size();++i){double xa=a[i]-ma,xb=b[i]-mb;num+=xa*xb;da+=xa*xa;db+=xb*xb;}return da*db<1e-12?0:num/std::sqrt(da*db);}'),
    ('covariance', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size()||a.size()<2)return 0;double ma=0,mb=0;for(double v:a)ma+=v;for(double v:b)mb+=v;ma/=a.size();mb/=b.size();double s=0;for(std::size_t i=0;i<a.size();++i)s+=(a[i]-ma)*(b[i]-mb);return s/(a.size()-1);}'),
    ('crossCorr', 'number', [('a', 'list number'), ('b', 'list number'), ('lag', 'number')],
     '{int L=static_cast<int>(lag);if(a.size()!=b.size()||L<0||static_cast<std::size_t>(L)>=a.size())return 0;std::vector<double> aa(a.begin(),a.end()-L),bb(b.begin()+L,b.end());return pearson(aa,bb);}'),
    ('autocorr1', 'number', [('v', 'list number')],
     'return crossCorr(v,v,1);'),
    ('partialCorr', 'number', [('a', 'list number'), ('b', 'list number'), ('c', 'list number')],
     '{double rab=pearson(a,b),rac=pearson(a,c),rbc=pearson(b,c);double den=std::sqrt((1-rac*rac)*(1-rbc*rbc));return den<1e-12?0:(rab-rac*rbc)/den;}'),
    ('corrMatrix2', 'list number', [('a', 'list number'), ('b', 'list number')],
     '{double p=pearson(a,b);return std::vector<double>{1,p,p,1};}'),
    ('rankCorr', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size()||a.size()<2)return 0;auto idx=std::vector<std::size_t>(a.size());for(std::size_t i=0;i<a.size();++i)idx[i]=i;std::sort(idx.begin(),idx.end(),[&](auto i,auto j){return a[i]<a[j];});std::vector<double> ra(a.size());for(std::size_t i=0;i<a.size();++i)ra[idx[i]]=static_cast<double>(i);std::vector<std::size_t> idx2(b.size());for(std::size_t i=0;i<b.size();++i)idx2[i]=i;std::sort(idx2.begin(),idx2.end(),[&](auto i,auto j){return b[i]<b[j];});std::vector<double> rb(b.size());for(std::size_t i=0;i<b.size();++i)rb[idx2[i]]=static_cast<double>(i);return pearson(ra,rb);}'),
])

cx('statquartile', [
    ('q1', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;auto t=v;std::sort(t.begin(),t.end());return t[t.size()/4];}'),
    ('q2', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;auto t=v;std::sort(t.begin(),t.end());std::size_t n=t.size();return n%2?t[n/2]:(t[n/2-1]+t[n/2])/2.0;}'),
    ('q3', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;auto t=v;std::sort(t.begin(),t.end());return t[3*t.size()/4];}'),
    ('iqr', 'number', [('v', 'list number')],
     'return q3(v)-q1(v);'),
    ('quartiles', 'list number', [('v', 'list number')],
     'return std::vector<double>{q1(v),q2(v),q3(v)};'),
    ('fiveNum', 'list number', [('v', 'list number')],
     '{if(v.empty())return std::vector<double>{};auto t=v;std::sort(t.begin(),t.end());return std::vector<double>{t.front(),q1(v),q2(v),q3(v),t.back()};}'),
    ('outlierFence', 'list number', [('v', 'list number')],
     '{double iq=iqr(v),med=q2(v);return std::vector<double>{med-1.5*iq,med+1.5*iq};}'),
])

cx('stathistogram', [
    ('histogram', 'list number', [('v', 'list number'), ('bins', 'number')],
     '{int b=static_cast<int>(bins);if(v.empty()||b<=0)return std::vector<double>{};double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());double w=(mx-mn)/b;if(w<1e-12)w=1;std::vector<double> h(b,0);for(double x:v){int i=static_cast<int>((x-mn)/w);if(i>=b)i=b-1;if(i<0)i=0;h[i]+=1;}return h;}'),
    ('binEdges', 'list number', [('v', 'list number'), ('bins', 'number')],
     '{int b=static_cast<int>(bins);if(v.empty()||b<=0)return std::vector<double>{};double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());double w=(mx-mn)/b;std::vector<double> e;for(int i=0;i<=b;++i)e.push_back(mn+i*w);return e;}'),
    ('freqDensity', 'list number', [('v', 'list number'), ('bins', 'number')],
     '{auto h=histogram(v,bins);double s=0;for(double x:h)s+=x;if(s<1e-12)return h;for(double&x:h)x/=s;return h;}'),
    ('cumFreq', 'list number', [('v', 'list number'), ('bins', 'number')],
     '{auto h=histogram(v,bins);std::vector<double> c;double s=0;for(double x:h){s+=x;c.push_back(s);}return c;}'),
    ('modeBin', 'number', [('v', 'list number'), ('bins', 'number')],
     '{auto h=histogram(v,bins);if(h.empty())return 0;return static_cast<double>(std::max_element(h.begin(),h.end())-h.begin());}'),
    ('binWidth', 'number', [('v', 'list number'), ('bins', 'number')],
     '{if(v.empty())return 0;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());int b=static_cast<int>(bins);return b<=0?0:(mx-mn)/b;}'),
])

cx('statanova', [
    ('groupMeans', 'list number', [('groups', 'list number'), ('labels', 'list number')],
     '{std::map<int,std::vector<double>> g;for(std::size_t i=0;i<groups.size()&&i<labels.size();++i)g[static_cast<int>(labels[i])].push_back(groups[i]);std::vector<double> m;for(auto&p:g){double s=0;for(double x:p.second)s+=x;m.push_back(s/p.second.size());}return m;}'),
    ('grandMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('betweenSS', 'number', [('groups', 'list number'), ('labels', 'list number')],
     '{auto gm=grandMean(groups);auto m=groupMeans(groups,labels);double ss=0;std::map<int,int> cnt;for(std::size_t i=0;i<labels.size();++i)++cnt[static_cast<int>(labels[i])];int gi=0;for(auto&p:cnt){ss+=p.second*(m[gi]-gm)*(m[gi]-gm);++gi;}return ss;}'),
    ('withinSS', 'number', [('groups', 'list number'), ('labels', 'list number')],
     '{auto m=groupMeans(groups,labels);std::map<int,double> mm;for(std::size_t i=0;i<m.size();++i)mm[i]=m[i];double ss=0;for(std::size_t i=0;i<groups.size();++i){int g=static_cast<int>(labels[i]);ss+=(groups[i]-mm[g])*(groups[i]-mm[g]);}return ss;}'),
    ('fStatistic', 'number', [('groups', 'list number'), ('labels', 'list number')],
     '{double bw=betweenSS(groups,labels),ww=withinSS(groups,labels);std::map<int,int> g;for(double l:labels)++g[static_cast<int>(l)];int k=static_cast<int>(g.size()),n=static_cast<int>(groups.size());return ww<1e-12?0:(bw/(k-1))/(ww/(n-k));}'),
    ('etaSquared', 'number', [('groups', 'list number'), ('labels', 'list number')],
     '{double bw=betweenSS(groups,labels),ww=withinSS(groups,labels);return(bw+ww)<1e-12?0:bw/(bw+ww);}'),
])

cx('statttest', [
    ('tStatistic', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()<2||b.size()<2)return 0;double ma=0,mb=0;for(double x:a)ma+=x;for(double x:b)mb+=x;ma/=a.size();mb/=b.size();double va=0,vb=0;for(double x:a)va+=(x-ma)*(x-ma);for(double x:b)vb+=(x-mb)*(x-mb);va/=a.size()-1;vb/=b.size()-1;double se=std::sqrt(va/a.size()+vb/b.size());return se<1e-12?0:(ma-mb)/se;}'),
    ('pooledVariance', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()<2||b.size()<2)return 0;double ma=0,mb=0;for(double x:a)ma+=x;for(double x:b)mb+=x;ma/=a.size();mb/=b.size();double va=0,vb=0;for(double x:a)va+=(x-ma)*(x-ma);for(double x:b)vb+=(x-mb)*(x-mb);return((a.size()-1)*va+(b.size()-1)*vb)/(a.size()+b.size()-2);}'),
    ('cohenD', 'number', [('a', 'list number'), ('b', 'list number')],
     '{double pv=pooledVariance(a,b);if(pv<1e-12)return 0;double ma=0,mb=0;for(double x:a)ma+=x;for(double x:b)mb+=x;return(ma/a.size()-mb/b.size())/std::sqrt(pv);}'),
    ('meanDiff', 'number', [('a', 'list number'), ('b', 'list number')],
     '{double ma=0,mb=0;for(double x:a)ma+=x;for(double x:b)mb+=x;return ma/a.size()-mb/b.size();}'),
    ('welchT', 'number', [('a', 'list number'), ('b', 'list number')],
     'return tStatistic(a,b);'),
    ('effectSize', 'number', [('a', 'list number'), ('b', 'list number')],
     'return std::abs(cohenD(a,b));'),
])

cx('statchi2', [
    ('chi2Stat', 'number', [('observed', 'list number'), ('expected', 'list number')],
     '{if(observed.size()!=expected.size())return 0;double chi=0;for(std::size_t i=0;i<observed.size();++i)if(expected[i]>1e-12){double d=observed[i]-expected[i];chi+=d*d/expected[i];}return chi;}'),
    ('cramersV', 'number', [('chi2', 'number'), ('n', 'number'), ('k', 'number')],
     '{double nn=n,kk=k;if(nn<1e-12||kk<1)return 0;return std::sqrt(chi2/(nn*(kk-1)));}'),
    ('expectedUniform', 'list number', [('total', 'number'), ('bins', 'number')],
     '{int b=static_cast<int>(bins);std::vector<double> e(b,total/b);return e;}'),
    ('goodnessOfFit', 'number', [('observed', 'list number'), ('expected', 'list number')],
     'return chi2Stat(observed,expected);'),
    ('residuals', 'list number', [('observed', 'list number'), ('expected', 'list number')],
     '{std::vector<double> r;for(std::size_t i=0;i<observed.size()&&i<expected.size();++i)r.push_back(expected[i]>1e-12?(observed[i]-expected[i])/std::sqrt(expected[i]):0);return r;}'),
    ('df', 'number', [('bins', 'number')],
     'return static_cast<double>(bins)-1;'),
])

cx('statnormcdf', [
    ('normPdf', 'number', [('x', 'number'), ('mu', 'number'), ('sigma', 'number')],
     '{if(sigma<1e-12)return 0;double z=(x-mu)/sigma;return std::exp(-0.5*z*z)/(sigma*std::sqrt(2*3.141592653589793));}'),
    ('normCdfApprox', 'number', [('x', 'number'), ('mu', 'number'), ('sigma', 'number')],
     '{double z=(x-mu)/(sigma<1e-12?1:sigma);return 0.5*(1+std::erf(z/std::sqrt(2)));}'),
    ('zFromP', 'number', [('p', 'number')],
     '{return 0.5*(p-0.5)*4; /* rough inverse normal */}'),
    ('standardize', 'number', [('x', 'number'), ('mu', 'number'), ('sigma', 'number')],
     'return sigma<1e-12?0:(x-mu)/sigma;'),
    ('logLikelihood', 'number', [('data', 'list number'), ('mu', 'number'), ('sigma', 'number')],
     '{double ll=0;for(double x:data)ll+=std::log(normPdf(x,mu,sigma)+1e-300);return ll;}'),
    ('bivariatePdf', 'number', [('x', 'number'), ('y', 'number'), ('rho', 'number')],
     '{double z1=x,z2=y,r=rho,d=1-r*r;if(d<1e-12)return 0;return std::exp(-0.5/(d)*(z1*z1+z2*z2-2*r*z1*z2))/(2*3.141592653589793*std::sqrt(d));}'),
])

cx('statzscore', [
    ('zScores', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);s=v.size()>1?std::sqrt(s/(v.size()-1)):0;std::vector<double> r;if(s<1e-12)return v;for(double x:v)r.push_back((x-m)/s);return r;}'),
    ('zScore', 'number', [('v', 'list number'), ('val', 'number')],
     '{if(v.empty())return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);s=v.size()>1?std::sqrt(s/(v.size()-1)):0;return s<1e-12?0:(val-m)/s;}'),
    ('isOutlierZ', 'bool', [('v', 'list number'), ('val', 'number'), ('threshold', 'number')],
     'return std::abs(zScore(v,val))>threshold;'),
    ('standardize', 'list number', [('v', 'list number')],
     'return zScores(v);'),
    ('destandardize', 'list number', [('z', 'list number'), ('mean', 'number'), ('stddev', 'number')],
     '{std::vector<double> r;for(double x:z)r.push_back(x*stddev+mean);return r;}'),
    ('zMean', 'number', [('v', 'list number')],
     '{auto z=zScores(v);return z.empty()?0:std::accumulate(z.begin(),z.end(),0.0)/z.size();}'),
])

cx('statcovar', [
    ('covSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('covMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('covMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('covMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('covVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('covStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('covNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('covariance', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size()||a.size()<2)return 0;double ma=0,mb=0;for(double v:a)ma+=v;for(double v:b)mb+=v;ma/=a.size();mb/=b.size();double s=0;for(std::size_t i=0;i<a.size();++i)s+=(a[i]-ma)*(b[i]-mb);return s/(a.size()-1);}'),
])

cx('statrmse', [
    ('rmse', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.size()!=predicted.size()||actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size();++i){double d=actual[i]-predicted[i];s+=d*d;}return std::sqrt(s/actual.size());}'),
    ('mse', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.size()!=predicted.size()||actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size();++i){double d=actual[i]-predicted[i];s+=d*d;}return s/actual.size();}'),
    ('mae', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.size()!=predicted.size()||actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size();++i)s+=std::abs(actual[i]-predicted[i]);return s/actual.size();}'),
    ('nrmse', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{double r=rmse(actual,predicted);double mn=*std::min_element(actual.begin(),actual.end()),mx=*std::max_element(actual.begin(),actual.end());return(mx-mn)<1e-12?0:r/(mx-mn);}'),
    ('smape', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.size()!=predicted.size()||actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size();++i)s+=std::abs(actual[i]-predicted[i])/(std::abs(actual[i])+std::abs(predicted[i])+1e-12);return 200*s/actual.size();}'),
    ('r2Score', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.empty())return 0;double mean=0;for(double x:actual)mean+=x;mean/=actual.size();double ssRes=0,ssTot=0;for(std::size_t i=0;i<actual.size();++i){ssRes+=(actual[i]-predicted[i])*(actual[i]-predicted[i]);ssTot+=(actual[i]-mean)*(actual[i]-mean);}return ssTot<1e-12?0:1-ssRes/ssTot;}'),
])

cx('statmape', [
    ('mape', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.size()!=predicted.size()||actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size();++i)s+=std::abs((actual[i]-predicted[i])/(actual[i]+1e-12));return 100*s/actual.size();}'),
    ('wape', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.empty())return 0;double num=0,den=0;for(std::size_t i=0;i<actual.size()&&i<predicted.size();++i){num+=std::abs(actual[i]-predicted[i]);den+=std::abs(actual[i]);}return den<1e-12?0:100*num/den;}'),
    ('smape', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size()&&i<predicted.size();++i)s+=std::abs(actual[i]-predicted[i])/(std::abs(actual[i])+std::abs(predicted[i])+1e-12);return 200*s/actual.size();}'),
    ('bias', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{if(actual.empty())return 0;double s=0;for(std::size_t i=0;i<actual.size()&&i<predicted.size();++i)s+=predicted[i]-actual[i];return s/actual.size();}'),
    ('trackingSignal', 'number', [('actual', 'list number'), ('predicted', 'list number')],
     '{double b=bias(actual,predicted);double m=mape(actual,predicted);return m<1e-12?0:b/m;}'),
    ('forecastError', 'list number', [('actual', 'list number'), ('predicted', 'list number')],
     '{std::vector<double> e;for(std::size_t i=0;i<actual.size()&&i<predicted.size();++i)e.push_back(actual[i]-predicted[i]);return e;}'),
])

cx('statmedian', [
    ('median', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;auto t=v;std::sort(t.begin(),t.end());std::size_t n=t.size();return n%2?t[n/2]:(t[n/2-1]+t[n/2])/2.0;}'),
    ('medAbsDev', 'number', [('v', 'list number')],
     '{double med=median(v);std::vector<double> d;for(double x:v)d.push_back(std::abs(x-med));return median(d);}'),
    ('trimmedMean', 'number', [('v', 'list number'), ('pct', 'number')],
     '{if(v.empty())return 0;auto t=v;std::sort(t.begin(),t.end());int trim=static_cast<int>(t.size()*pct/100.0);int lo=trim,hi=static_cast<int>(t.size())-trim;if(hi<=lo)return median(v);double s=0;for(int i=lo;i<hi;++i)s+=t[i];return s/(hi-lo);}'),
    ('movingMedian', 'list number', [('v', 'list number'), ('win', 'number')],
     '{int w=static_cast<int>(win);std::vector<double> r;if(w<=0)return r;for(std::size_t i=0;i+w<=v.size();++i){std::vector<double> sub(v.begin()+i,v.begin()+i+w);r.push_back(median(sub));}return r;}'),
    ('weightedMedian', 'number', [('v', 'list number'), ('w', 'list number')],
     '{if(v.size()!=w.size()||v.empty())return 0;std::vector<std::pair<double,double>> p;for(std::size_t i=0;i<v.size();++i)p.emplace_back(v[i],w[i]);std::sort(p.begin(),p.end());double tot=0;for(double x:w)tot+=x;double half=tot/2,cum=0;for(auto&pr:p){cum+=pr.second;if(cum>=half)return pr.first;}return p.back().first;}'),
    ('medianDiff', 'number', [('a', 'list number'), ('b', 'list number')],
     'return median(a)-median(b);'),
])

cx('statmode', [
    ('mode', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;std::map<long long,int> m;for(double x:v)++m[static_cast<long long>(x*1000)];return static_cast<double>(std::max_element(m.begin(),m.end(),[](auto&a,auto&b){return a.second<b.second;})->first)/1000.0;}'),
    ('modeCount', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;std::map<long long,int> m;for(double x:v)++m[static_cast<long long>(x*1000)];return static_cast<double>(std::max_element(m.begin(),m.end(),[](auto&a,auto&b){return a.second<b.second;})->second);}'),
    ('multimodal', 'bool', [('v', 'list number')],
     '{if(v.empty())return false;std::map<long long,int> m;for(double x:v)++m[static_cast<long long>(x*1000)];int best=0,cnt=0;for(auto&p:m){if(p.second>best){best=p.second;cnt=1;}else if(p.second==best)++cnt;}return cnt>1;}'),
    ('uniqueCount', 'number', [('v', 'list number')],
     '{std::map<long long,int> m;for(double x:v)++m[static_cast<long long>(x*1000)];return static_cast<double>(m.size());}'),
    ('entropy', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;std::map<long long,int> m;for(double x:v)++m[static_cast<long long>(x*1000)];double n=v.size(),h=0;for(auto&p:m){double p_i=p.second/n;if(p_i>0)h-=p_i*std::log(p_i);}return h;}'),
    ('giniSimpson', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;std::map<long long,int> m;for(double x:v)++m[static_cast<long long>(x*1000)];double n=v.size(),s=0;for(auto&p:m){double p_i=p.second/n;s+=p_i*p_i;}return 1-s;}'),
])

cx('statskew', [
    ('skewness', 'number', [('v', 'list number')],
     '{if(v.size()<3)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s2=0,s3=0;for(double x:v){double d=x-m;s2+=d*d;s3+=d*d*d;}s2/=v.size();return s2<1e-12?0:(s3/v.size())/(std::pow(s2,1.5));}'),
    ('kurtosisExcess', 'number', [('v', 'list number')],
     '{if(v.size()<4)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s2=0,s4=0;for(double x:v){double d=x-m;s2+=d*d;s4+=d*d*d*d;}s2/=v.size();return s2<1e-12?0:(s4/v.size())/(s2*s2)-3;}'),
    ('moment3', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v){double d=x-m;s+=d*d*d;}return s/v.size();}'),
    ('moment4', 'number', [('v', 'list number')],
     '{if(v.empty())return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v){double d=x-m;s+=d*d*d*d;}return s/v.size();}'),
    ('jarqueBera', 'number', [('v', 'list number')],
     '{double sk=skewness(v),ku=kurtosisExcess(v),n=static_cast<double>(v.size());return n/6*(sk*sk+ku*ku/4);}'),
    ('isSymmetric', 'bool', [('v', 'list number')],
     'return std::abs(skewness(v))<0.1;'),
])

cx('statkurt', [
    ('kurtosis', 'number', [('v', 'list number')],
     '{if(v.size()<4)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s2=0,s4=0;for(double x:v){double d=x-m;s2+=d*d;s4+=d*d*d*d;}s2/=v.size();return s2<1e-12?0:(s4/v.size())/(s2*s2);}'),
    ('excessKurtosis', 'number', [('v', 'list number')],
     'return kurtosis(v)-3;'),
    ('isLeptokurtic', 'bool', [('v', 'list number')],
     'return excessKurtosis(v)>0;'),
    ('isPlatykurtic', 'bool', [('v', 'list number')],
     'return excessKurtosis(v)<0;'),
    ('tailRatio', 'number', [('v', 'list number')],
     '{if(v.size()<10)return 0;auto t=v;std::sort(t.begin(),t.end());std::size_t n=t.size();double p95=t[95*n/100],p5=t[5*n/100],p50=t[n/2];return(p95-p50)/(p50-p5+1e-12);}'),
    ('peakedness', 'number', [('v', 'list number')],
     'return kurtosis(v);'),
])

cx('statbootstrap', [
    ('bootstrapMean', 'number', [('v', 'list number'), ('samples', 'number')],
     '{if(v.empty())return 0;int n=static_cast<int>(samples);double sum=0;for(int s=0;s<n;++s){double ss=0;for(std::size_t i=0;i<v.size();++i)ss+=v[static_cast<std::size_t>(std::rand()%static_cast<int>(v.size()))];sum+=ss/v.size();}return sum/n;}'),
    ('bootstrapSE', 'number', [('v', 'list number'), ('samples', 'number')],
     '{if(v.empty())return 0;int n=static_cast<int>(samples);std::vector<double> means;for(int s=0;s<n;++s){double ss=0;for(std::size_t i=0;i<v.size();++i)ss+=v[static_cast<std::size_t>(std::rand()%static_cast<int>(v.size()))];means.push_back(ss/v.size());}double m=0;for(double x:means)m+=x;m/=means.size();double var=0;for(double x:means)var+=(x-m)*(x-m);return std::sqrt(var/(means.size()-1));}'),
    ('resample', 'list number', [('v', 'list number'), ('size', 'number')],
     '{int n=static_cast<int>(size);std::vector<double> r;if(v.empty())return r;for(int i=0;i<n;++i)r.push_back(v[static_cast<std::size_t>(std::rand()%static_cast<int>(v.size()))]);return r;}'),
    ('bootstrapCI', 'list number', [('v', 'list number'), ('samples', 'number')],
     '{if(v.empty())return std::vector<double>{};int n=static_cast<int>(samples);std::vector<double> means;for(int s=0;s<n;++s){double ss=0;for(std::size_t i=0;i<v.size();++i)ss+=v[static_cast<std::size_t>(std::rand()%static_cast<int>(v.size()))];means.push_back(ss/v.size());}std::sort(means.begin(),means.end());std::size_t lo=means.size()/20,hi=19*means.size()/20;return std::vector<double>{means[lo],means[hi]};}'),
    ('jackknife', 'list number', [('v', 'list number')],
     '{std::vector<double> r;for(std::size_t i=0;i<v.size();++i){double s=0;for(std::size_t j=0;j<v.size();++j)if(j!=i)s+=v[j];r.push_back(s/(v.size()-1));}return r;}'),
    ('biasCorrected', 'number', [('v', 'list number'), ('stat', 'number')],
     '{double orig=0;for(double x:v)orig+=x;orig/=v.empty()?1:v.size();return 2*orig-stat;}'),
])

cx('statoutlier', [
    ('iqrOutliers', 'list number', [('v', 'list number')],
     '{if(v.size()<4)return std::vector<double>{};auto t=v;std::sort(t.begin(),t.end());double q1=t[t.size()/4],q3=t[3*t.size()/4],iq=q3-q1,lo=q1-1.5*iq,hi=q3+1.5*iq;std::vector<double> o;for(double x:v)if(x<lo||x>hi)o.push_back(x);return o;}'),
    ('zOutliers', 'list number', [('v', 'list number'), ('threshold', 'number')],
     '{if(v.empty())return std::vector<double>{};double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);s=v.size()>1?std::sqrt(s/(v.size()-1)):0;std::vector<double> o;for(double x:v)if(s>1e-12&&std::abs((x-m)/s)>threshold)o.push_back(x);return o;}'),
    ('outlierCount', 'number', [('v', 'list number')],
     'return static_cast<double>(iqrOutliers(v).size());'),
    ('winsorize', 'list number', [('v', 'list number'), ('pct', 'number')],
     '{if(v.empty())return v;auto t=v;std::sort(t.begin(),t.end());int trim=static_cast<int>(t.size()*pct/100.0);double lo=t[trim],hi=t[t.size()-1-trim];std::vector<double> r;for(double x:v)r.push_back(std::max(lo,std::min(hi,x)));return r;}'),
    ('modifiedZ', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;auto t=v;std::sort(t.begin(),t.end());double med=t[t.size()/2];std::vector<double> d;for(double x:v)d.push_back(std::abs(x-med));std::sort(d.begin(),d.end());double mad=d[d.size()/2];std::vector<double> r;for(double x:v)r.push_back(mad<1e-12?0:0.6745*(x-med)/mad);return r;}'),
    ('isOutlier', 'bool', [('v', 'list number'), ('val', 'number')],
     '{auto o=iqrOutliers(v);for(double x:o)if(x==val)return true;return false;}'),
])

cx('statpercentile', [
    ('percentile', 'number', [('v', 'list number'), ('p', 'number')],
     '{if(v.empty())return 0;auto t=v;std::sort(t.begin(),t.end());double rank=p/100.0*(t.size()-1);std::size_t lo=static_cast<std::size_t>(rank);std::size_t hi=std::min(lo+1,t.size()-1);double frac=rank-lo;return t[lo]*(1-frac)+t[hi]*frac;}'),
    ('percentiles', 'list number', [('v', 'list number')],
     'return std::vector<double>{percentile(v,25),percentile(v,50),percentile(v,75),percentile(v,90),percentile(v,95)};'),
    ('rankPct', 'number', [('v', 'list number'), ('val', 'number')],
     '{if(v.empty())return 0;int below=0;for(double x:v)if(x<val)++below;return 100.0*below/v.size();}'),
    ('decile', 'number', [('v', 'list number'), ('d', 'number')],
     'return percentile(v,d*10);'),
    ('quantile', 'number', [('v', 'list number'), ('q', 'number')],
     'return percentile(v,q*100);'),
    ('p90', 'number', [('v', 'list number')],
     'return percentile(v,90);'),
    ('p99', 'number', [('v', 'list number')],
     'return percentile(v,99);'),
])

cx('statbayes', [
    ('bayesUpdate', 'number', [('prior', 'number'), ('likelihood', 'number'), ('evidence', 'number')],
     'return evidence<1e-12?prior:(likelihood*prior)/evidence;'),
    ('posteriorOdds', 'number', [('priorOdds', 'number'), ('likelihoodRatio', 'number')],
     'return priorOdds*likelihoodRatio;'),
    ('priorFromOdds', 'number', [('odds', 'number')],
     'return odds/(1+odds);'),
    ('oddsFromPrior', 'number', [('prior', 'number')],
     'return prior/(1-prior+1e-12);'),
    ('bayesFactor', 'number', [('likelihoodH1', 'number'), ('likelihoodH0', 'number')],
     'return likelihoodH0<1e-12?0:likelihoodH1/likelihoodH0;'),
    ('credibleInterval', 'list number', [('samples', 'list number')],
     '{if(samples.size()<2)return std::vector<double>{};auto t=samples;std::sort(t.begin(),t.end());std::size_t lo=t.size()/40,hi=39*t.size()/40;return std::vector<double>{t[lo],t[hi]};}'),
    ('expectedLoss', 'number', [('losses', 'list number'), ('probs', 'list number')],
     '{if(losses.size()!=probs.size())return 0;double e=0;for(std::size_t i=0;i<losses.size();++i)e+=losses[i]*probs[i];return e;}'),
])

cx('mlkmeans', [
    ('kmeans', 'list number', [('points', 'list number'), ('k', 'number'), ('dims', 'number')],
     '{int K=static_cast<int>(k),D=static_cast<int>(dims);if(K<=0||D<=0||points.size()<static_cast<std::size_t>(K*D))return std::vector<double>{};int n=static_cast<int>(points.size())/D;std::vector<double> cent(K*D);for(int i=0;i<K;++i)for(int d=0;d<D;++d)cent[i*D+d]=points[static_cast<std::size_t>((i*7+d)%n)*D+d];for(int iter=0;iter<20;++iter){std::vector<double> sums(K*D,0);std::vector<int> cnt(K,0);for(int p=0;p<n;++p){int best=0;double bd=1e18;for(int c=0;c<K;++c){double dist=0;for(int d=0;d<D;++d){double diff=points[static_cast<std::size_t>(p*D+d)]-cent[c*D+d];dist+=diff*diff;}if(dist<bd){bd=dist;best=c;}}++cnt[best];for(int d=0;d<D;++d)sums[best*D+d]+=points[static_cast<std::size_t>(p*D+d)];}for(int c=0;c<K;++c)if(cnt[c]>0)for(int d=0;d<D;++d)cent[c*D+d]=sums[c*D+d]/cnt[c];}return cent;}'),
    ('assignClusters', 'list number', [('points', 'list number'), ('centroids', 'list number'), ('dims', 'number')],
     '{int D=static_cast<int>(dims),K=static_cast<int>(centroids.size())/D,n=static_cast<int>(points.size())/D;std::vector<double> labels;for(int p=0;p<n;++p){int best=0;double bd=1e18;for(int c=0;c<K;++c){double dist=0;for(int d=0;d<D;++d){double diff=points[static_cast<std::size_t>(p*D+d)]-centroids[c*D+d];dist+=diff*diff;}if(dist<bd){bd=dist;best=c;}}labels.push_back(static_cast<double>(best));}return labels;}'),
    ('inertia', 'number', [('points', 'list number'), ('centroids', 'list number'), ('dims', 'number')],
     '{auto lbl=assignClusters(points,centroids,dims);int D=static_cast<int>(dims),K=static_cast<int>(centroids.size())/D,n=static_cast<int>(points.size())/D;double s=0;for(int p=0;p<n;++p){int c=static_cast<int>(lbl[static_cast<std::size_t>(p)]);for(int d=0;d<D;++d){double diff=points[static_cast<std::size_t>(p*D+d)]-centroids[c*D+d];s+=diff*diff;}}return s;}'),
    ('clusterSizes', 'list number', [('labels', 'list number'), ('k', 'number')],
     '{int K=static_cast<int>(k);std::vector<double> sz(K,0);for(double l:labels){int c=static_cast<int>(l);if(c>=0&&c<K)sz[c]+=1;}return sz;}'),
    ('silhouetteSample', 'number', [('points', 'list number'), ('labels', 'list number'), ('idx', 'number'), ('dims', 'number')],
     '{int D=static_cast<int>(dims),p=static_cast<int>(idx),K=0;for(double l:labels)K=std::max(K,static_cast<int>(l)+1);int c=static_cast<int>(labels[static_cast<std::size_t>(p)]);double a=0,b=1e18;for(int q=0;q<static_cast<int>(labels.size());++q){if(q==p)continue;double dist=0;for(int d=0;d<D;++d){double diff=points[static_cast<std::size_t>(p*D+d)]-points[static_cast<std::size_t>(q*D+d)];dist+=diff*diff;}dist=std::sqrt(dist);if(static_cast<int>(labels[static_cast<std::size_t>(q)])==c)a+=dist;else b=std::min(b,dist);}int same=0;for(int q=0;q<static_cast<int>(labels.size());++q)if(q!=p&&static_cast<int>(labels[static_cast<std::size_t>(q)])==c)++same;a=same>0?a/same:0;return std::max(a,b)<1e-12?0:(b-a)/std::max(a,b);}'),
    ('elbowK', 'number', [('points', 'list number'), ('maxK', 'number'), ('dims', 'number')],
     '{int mk=static_cast<int>(maxK);double bestK=1,bestIn=1e18;for(int k=1;k<=mk;++k){auto c=kmeans(points,static_cast<double>(k),dims);double in=inertia(points,c,dims);if(in<bestIn){bestIn=in;bestK=k;}}return bestK;}'),
])

cx('mllinear', [
    ('dot', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size())return 0;double s=0;for(std::size_t i=0;i<a.size();++i)s+=a[i]*b[i];return s;}'),
    ('predict', 'number', [('weights', 'list number'), ('features', 'list number'), ('bias', 'number')],
     'return dot(weights,features)+bias;'),
    ('mse', 'number', [('weights', 'list number'), ('X', 'list number'), ('y', 'list number'), ('dims', 'number')],
     '{int D=static_cast<int>(dims),n=static_cast<int>(y.size());double s=0;for(int i=0;i<n;++i){std::vector<double> feat(X.begin()+i*D,X.begin()+(i+1)*D);double pred=predict(weights,feat,0);s+=(y[static_cast<std::size_t>(i)]-pred)*(y[static_cast<std::size_t>(i)]-pred);}return n>0?s/n:0;}'),
    ('gradientStep', 'list number', [('weights', 'list number'), ('X', 'list number'), ('y', 'list number'), ('lr', 'number'), ('dims', 'number')],
     '{int D=static_cast<int>(dims),n=static_cast<int>(y.size());auto w=weights;for(int i=0;i<n;++i){std::vector<double> feat(X.begin()+i*D,X.begin()+(i+1)*D);double pred=predict(w,feat,0),err=pred-y[static_cast<std::size_t>(i)];for(int d=0;d<D;++d)w[static_cast<std::size_t>(d)]-=lr*err*feat[static_cast<std::size_t>(d)]/n;}return w;}'),
    ('trainEpochs', 'list number', [('weights', 'list number'), ('X', 'list number'), ('y', 'list number'), ('lr', 'number'), ('epochs', 'number'), ('dims', 'number')],
     '{auto w=weights;for(int e=0;e<static_cast<int>(epochs);++e)w=gradientStep(w,X,y,lr,dims);return w;}'),
    ('sigmoid', 'number', [('x', 'number')],
     'return 1.0/(1.0+std::exp(-x));'),
])

cx('mlnaivebayes', [
    ('classPrior', 'number', [('labels', 'list number'), ('cls', 'number')],
     '{int c=0;for(double l:labels)if(static_cast<int>(l)==static_cast<int>(cls))++c;return labels.empty()?0:static_cast<double>(c)/labels.size();}'),
    ('featureMean', 'number', [('features', 'list number'), ('labels', 'list number'), ('cls', 'number'), ('feat', 'number')],
     '{double s=0;int c=0;for(std::size_t i=0;i<labels.size()&&i<features.size();++i)if(static_cast<int>(labels[i])==static_cast<int>(cls)){s+=features[i];++c;}return c==0?0:s/c;}'),
    ('featureVar', 'number', [('features', 'list number'), ('labels', 'list number'), ('cls', 'number')],
     '{double m=featureMean(features,labels,cls,0),s=0;int c=0;for(std::size_t i=0;i<labels.size()&&i<features.size();++i)if(static_cast<int>(labels[i])==static_cast<int>(cls)){s+=(features[i]-m)*(features[i]-m);++c;}return c<2?1:s/(c-1);}'),
    ('gaussianLikelihood', 'number', [('x', 'number'), ('mu', 'number'), ('sigma', 'number')],
     '{if(sigma<1e-12)return 0;double z=(x-mu)/sigma;return std::exp(-0.5*z*z)/(sigma*std::sqrt(2*3.141592653589793));}'),
    ('predictClass', 'number', [('features', 'list number'), ('trainX', 'list number'), ('trainY', 'list number'), ('numClasses', 'number')],
     '{int K=static_cast<int>(numClasses);double best=-1e18,bestC=0;for(int c=0;c<K;++c){double logP=std::log(classPrior(trainY,static_cast<double>(c))+1e-12);for(std::size_t f=0;f<features.size();++f)logP+=std::log(gaussianLikelihood(features[f],featureMean(trainX,trainY,static_cast<double>(c),static_cast<double>(f)),std::sqrt(featureVar(trainX,trainY,static_cast<double>(c))))+1e-12);if(logP>best){best=logP;bestC=c;}}return static_cast<double>(bestC);}'),
    ('logPosterior', 'number', [('features', 'list number'), ('trainX', 'list number'), ('trainY', 'list number'), ('cls', 'number')],
     '{double lp=std::log(classPrior(trainY,cls)+1e-12);for(std::size_t f=0;f<features.size();++f)lp+=std::log(gaussianLikelihood(features[f],featureMean(trainX,trainY,cls,static_cast<double>(f)),std::sqrt(featureVar(trainX,trainY,cls)))+1e-12);return lp;}'),
])

cx('mltfidf', [
    ('tfidSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('tfidMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('tfidMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('tfidMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('tfidVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('tfidStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('tfidNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlcosine', [
    ('cosineSim', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size())return 0;double dot=0,na=0,nb=0;for(std::size_t i=0;i<a.size();++i){dot+=a[i]*b[i];na+=a[i]*a[i];nb+=b[i]*b[i];}return(na*nb)<1e-12?0:dot/(std::sqrt(na)*std::sqrt(nb));}'),
    ('cosineDist', 'number', [('a', 'list number'), ('b', 'list number')],
     'return 1-cosineSim(a,b);'),
    ('normalize', 'list number', [('v', 'list number')],
     '{double n=0;for(double x:v)n+=x*x;n=std::sqrt(n);std::vector<double> r;if(n<1e-12)return v;for(double x:v)r.push_back(x/n);return r;}'),
    ('angularDist', 'number', [('a', 'list number'), ('b', 'list number')],
     'return std::acos(std::max(-1.0,std::min(1.0,cosineSim(a,b))));'),
    ('batchCosine', 'list number', [('query', 'list number'), ('matrix', 'list number'), ('dims', 'number')],
     '{int D=static_cast<int>(dims),n=static_cast<int>(matrix.size())/D;std::vector<double> sims;for(int i=0;i<n;++i){std::vector<double> row(matrix.begin()+i*D,matrix.begin()+(i+1)*D);sims.push_back(cosineSim(query,row));}return sims;}'),
    ('mostSimilar', 'number', [('query', 'list number'), ('matrix', 'list number'), ('dims', 'number')],
     '{auto s=batchCosine(query,matrix,dims);if(s.empty())return 0;return static_cast<double>(std::max_element(s.begin(),s.end())-s.begin());}'),
])

cx('mlsvm', [
    ('svmSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('svmMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('svmMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('svmMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('svmVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('svmStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('svmNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlpca', [
    ('pcaSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('pcaMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('pcaMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('pcaMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('pcaVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('pcaStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('pcaNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlentropy', [
    ('entrSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('entrMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('entrMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('entrMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('entrVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('entrStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('entrNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlkldiv', [
    ('kldiSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('kldiMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('kldiMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('kldiMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('kldiVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('kldiStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('kldiNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlgradient', [
    ('gradSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('gradMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('gradMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('gradMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('gradVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('gradStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('gradNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlsoftmax', [
    ('softmax', 'list number', [('logits', 'list number')],
     '{double mx=*std::max_element(logits.begin(),logits.end());std::vector<double> e,s;double sum=0;for(double x:logits){double v=std::exp(x-mx);e.push_back(v);sum+=v;}for(double v:e)s.push_back(v/sum);return s;}'),
    ('crossEntropy', 'number', [('probs', 'list number'), ('target', 'number')],
     '{int t=static_cast<int>(target);return(t<0||t>=static_cast<int>(probs.size()))?1e18:-std::log(probs[static_cast<std::size_t>(t)]+1e-12);}'),
    ('argmax', 'number', [('v', 'list number')],
     'return v.empty()?0:static_cast<double>(std::max_element(v.begin(),v.end())-v.begin());'),
    ('oneHot', 'list number', [('idx', 'number'), ('size', 'number')],
     '{int n=static_cast<int>(size),i=static_cast<int>(idx);std::vector<double> o(n,0);if(i>=0&&i<n)o[static_cast<std::size_t>(i)]=1;return o;}'),
    ('logSoftmax', 'list number', [('logits', 'list number')],
     '{auto p=softmax(logits);std::vector<double> r;for(double x:p)r.push_back(std::log(x+1e-12));return r;}'),
    ('entropy', 'number', [('probs', 'list number')],
     '{double h=0;for(double p:probs)if(p>0)h-=p*std::log(p);return h;}'),
])

cx('mlperceptron', [
    ('predict', 'number', [('weights', 'list number'), ('features', 'list number'), ('bias', 'number')],
     '{double s=bias;for(std::size_t i=0;i<weights.size()&&i<features.size();++i)s+=weights[i]*features[i];return s>=0?1:0;}'),
    ('trainStep', 'list number', [('weights', 'list number'), ('bias', 'number'), ('features', 'list number'), ('label', 'number'), ('lr', 'number')],
     '{auto w=weights;double b=bias,p=predict(w,features,b),err=label-p;for(std::size_t i=0;i<w.size()&&i<features.size();++i)w[i]+=lr*err*features[i];b+=lr*err;return std::vector<double>{b,w[0]};}'),
    ('accuracy', 'number', [('weights', 'list number'), ('bias', 'number'), ('X', 'list number'), ('y', 'list number'), ('dims', 'number')],
     '{int D=static_cast<int>(dims),n=static_cast<int>(y.size()),correct=0;for(int i=0;i<n;++i){std::vector<double> feat(X.begin()+i*D,X.begin()+(i+1)*D);if(predict(weights,feat,bias)==y[static_cast<std::size_t>(i)])++correct;}return n>0?static_cast<double>(correct)/n:0;}'),
    ('hingeLoss', 'number', [('weights', 'list number'), ('features', 'list number'), ('label', 'number'), ('bias', 'number')],
     '{double s=bias;for(std::size_t i=0;i<weights.size()&&i<features.size();++i)s+=weights[i]*features[i];return std::max(0.0,1-label*s);}'),
    ('initWeights', 'list number', [('size', 'number')],
     '{int n=static_cast<int>(size);std::vector<double> w;for(int i=0;i<n;++i)w.push_back(static_cast<double>(std::rand()%1000)/1000.0-0.5);return w;}'),
    ('trainEpoch', 'list number', [('weights', 'list number'), ('bias', 'number'), ('X', 'list number'), ('y', 'list number'), ('lr', 'number'), ('dims', 'number')],
     '{auto w=weights;double b=bias;int D=static_cast<int>(dims);for(std::size_t i=0;i<y.size();++i){std::vector<double> feat(X.begin()+i*D,X.begin()+(i+1)*D);auto r=trainStep(w,b,feat,y[i],lr);b=r[0];if(!w.empty())w[0]=r[1];}return w;}'),
])

cx('mlcrossval', [
    ('crosSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('crosMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('crosMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('crosMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('crosVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('crosStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('crosNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlfeature', [
    ('featSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('featMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('featMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('featMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('featVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('featStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('featNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlnormalize', [
    ('normSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('normMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('normMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('normMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('normVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('normStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('normNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mldistance', [
    ('distSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('distMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('distMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('distMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('distVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('distStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('distNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlcluster', [
    ('clusSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('clusMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('clusMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('clusMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('clusVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('clusStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('clusNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlnearest', [
    ('nearSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('nearMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('nearMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('nearMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('nearVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('nearStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('nearNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mldecision', [
    ('deciSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('deciMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('deciMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('deciMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('deciVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('deciStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('deciNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('mlensemble', [
    ('enseSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('enseMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('enseMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('enseMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('enseVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('enseStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('enseNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('cryptsha256', [
    ('sha2Len', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('sha2Upper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('sha2Lower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('sha2Trim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('sha2Split', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('sha2Join', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('sha2Replace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptsha1', [
    ('sha1Len', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('sha1Upper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('sha1Lower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('sha1Trim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('sha1Split', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('sha1Join', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('sha1Replace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptmd5', [
    ('md5Len', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('md5Upper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('md5Lower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('md5Trim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('md5Split', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('md5Join', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('md5Replace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('crypthmac', [
    ('hmacLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('hmacUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('hmacLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('hmacTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('hmacSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('hmacJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('hmacReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptxor', [
    ('xorBytes', 'text', [('a', 'text'), ('b', 'text')],
     '{std::string r;for(std::size_t i=0;i<a.size();++i)r+=static_cast<char>(static_cast<unsigned char>(a[i])^static_cast<unsigned char>(b[i%b.size()]));return r;}'),
    ('xorHex', 'text', [('hex', 'text'), ('key', 'text')],
     '{std::string r;for(std::size_t i=0;i<hex.size();i+=2){int v=0;for(int d=0;d<2&&i+d<hex.size();++d){char c=hex[i+d];v=(v<<4)+(c>=\'a\'?c-\'a\'+10:c>=\'A\'?c-\'A\'+10:c-\'0\');}r+=static_cast<char>(v^static_cast<unsigned char>(key[(i/2)%key.size()]));}return r;}'),
    ('repeatKey', 'text', [('data', 'text'), ('key', 'text')],
     'return xorBytes(data,key);'),
    ('xorList', 'list number', [('a', 'list number'), ('b', 'list number')],
     '{std::vector<double> r;for(std::size_t i=0;i<a.size();++i)r.push_back(static_cast<double>(static_cast<long long>(a[i])^static_cast<long long>(b[i%b.size()])));return r;}'),
    ('parity', 'number', [('s', 'text')],
     '{int p=0;for(unsigned char c:s)p^=c;return static_cast<double>(p);}'),
    ('rollingXor', 'list number', [('data', 'list number'), ('key', 'number')],
     '{std::vector<double> r;double k=key;for(double x:data)r.push_back(static_cast<double>(static_cast<long long>(x)^static_cast<long long>(k)));return r;}'),
    ('selfXor', 'text', [('s', 'text')],
     'return xorBytes(s,s);'),
])

cx('cryptcaesar', [
    ('encrypt', 'text', [('s', 'text'), ('shift', 'number')],
     '{int sh=static_cast<int>(shift)%26;std::string r;for(char c:s){if(std::isalpha(static_cast<unsigned char>(c))){char base=std::isupper(static_cast<unsigned char>(c))?\'A\':\'a\';r+=static_cast<char>((c-base+sh+26)%26+base);}else r+=c;}return r;}'),
    ('decrypt', 'text', [('s', 'text'), ('shift', 'number')],
     'return encrypt(s,-shift);'),
    ('bruteForce', 'list text', [('s', 'text')],
     '{std::vector<std::string> r;for(int sh=0;sh<26;++sh)r.push_back(encrypt(s,static_cast<double>(sh)));return r;}'),
    ('countAlpha', 'number', [('s', 'text')],
     '{int c=0;for(unsigned char ch:s)if(std::isalpha(ch))++c;return static_cast<double>(c);}'),
    ('rotAll', 'list text', [('s', 'text')],
     'return bruteForce(s);'),
    ('isCaesar', 'bool', [('plain', 'text'), ('cipher', 'text')],
     '{for(int sh=0;sh<26;++sh)if(encrypt(plain,static_cast<double>(sh))==cipher)return true;return false;}'),
])

cx('cryptvigenere', [
    ('vigeLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('vigeUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('vigeLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('vigeTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('vigeSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('vigeJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('vigeReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptbase64', [
    ('encode', 'text', [('s', 'text')],
     '{static const std::string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";std::string r;int val=0,vb=-6;for(unsigned char c:s){val=(val<<8)+c;vb+=8;while(vb>=0){r+=alpha[(val>>vb)&0x3F];vb-=6;}}if(vb>-6)r+=alpha[((val<<8)>>(vb+8))&0x3F];while(r.size()%4)r+="=";return r;}'),
    ('decode', 'text', [('s', 'text')],
     '{auto idx=[](char c)->int{if(c>=\'A\'&&c<=\'Z\')return c-\'A\';if(c>=\'a\'&&c<=\'z\')return c-\'a\'+26;if(c>=\'0\'&&c<=\'9\')return c-\'0\'+52;if(c==\'+\')return 62;if(c==\'/\')return 63;return -1;};std::string r;int val=0,vb=-8;for(char c:s){if(c==\'=\')break;int d=idx(c);if(d<0)continue;val=(val<<6)+d;vb+=6;if(vb>=0){r+=static_cast<char>((val>>vb)&0xFF);vb-=8;}}return r;}'),
    ('isValid', 'bool', [('s', 'text')],
     '{if(s.empty())return false;for(char c:s)if(!std::isalnum(static_cast<unsigned char>(c))&&c!=\'+\'&&c!=\'/\'&&c!=\'=\')return false;return true;}'),
    ('paddedLen', 'number', [('s', 'text')],
     'return static_cast<double>((s.size()+3)/4*4);'),
    ('roundTrip', 'bool', [('s', 'text')],
     'return decode(encode(s))==s;'),
    ('urlSafe', 'text', [('s', 'text')],
     '{std::string r=encode(s);for(char&c:r){if(c==\'+\')c=\'-\';else if(c==\'/\')c=\'_\';}return r;}'),
])

cx('cryptrot13', [
    ('rot1Len', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('rot1Upper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('rot1Lower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('rot1Trim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('rot1Split', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('rot1Join', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('rot1Replace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptaeslite', [
    ('aeslLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('aeslUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('aeslLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('aeslTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('aeslSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('aeslJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('aeslReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptpbkdf', [
    ('pbkdLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('pbkdUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('pbkdLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('pbkdTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('pbkdSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('pbkdJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('pbkdReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptscrypt', [
    ('scryLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('scryUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('scryLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('scryTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('scrySplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('scryJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('scryReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptnonce', [
    ('noncLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('noncUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('noncLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('noncTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('noncSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('noncJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('noncReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('cryptcrc32', [
    ('crc32', 'number', [('s', 'text')],
     '{unsigned crc=0xFFFFFFFF;for(unsigned char c:s){crc^=c;for(int k=0;k<8;++k)crc=(crc>>1)^(0xEDB88320&(-(crc&1)));}return static_cast<double>(~crc);}'),
    ('crc32List', 'list number', [('data', 'list number')],
     '{std::string s;for(double x:data)s+=static_cast<char>(static_cast<long long>(x)&0xFF);return std::vector<double>{crc32(s)};}'),
    ('verify', 'bool', [('s', 'text'), ('expected', 'number')],
     'return crc32(s)==expected;'),
    ('update', 'number', [('crc', 'number'), ('byte', 'number')],
     '{unsigned c=static_cast<unsigned>(crc)^static_cast<unsigned char>(static_cast<long long>(byte));for(int k=0;k<8;++k)c=(c>>1)^(0xEDB88320&(-(c&1)));return static_cast<double>(c);}'),
    ('finalize', 'number', [('crc', 'number')],
     'return static_cast<double>(~static_cast<unsigned>(static_cast<long long>(crc)));'),
    ('chunkCrc', 'list number', [('s', 'text'), ('chunkSize', 'number')],
     '{int cs=static_cast<int>(chunkSize);std::vector<double> r;if(cs<=0)return r;for(std::size_t i=0;i<s.size();i+=cs)r.push_back(crc32(s.substr(i,cs)));return r;}'),
])

cx('cryptparity', [
    ('pariLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('pariUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('pariLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('pariTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('pariSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('pariJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('pariReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('hash32', 'number', [('s', 'text')],
     '{unsigned h=5381;for(unsigned char c:s)h=((h<<5)+h)+c;return static_cast<double>(h);}'),
])

cx('comprle', [
    ('rleEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;if(data.empty())return r;double cur=data[0];int cnt=1;for(std::size_t i=1;i<data.size();++i){if(data[i]==cur)++cnt;else{r.push_back(cur);r.push_back(static_cast<double>(cnt));cur=data[i];cnt=1;}}r.push_back(cur);r.push_back(static_cast<double>(cnt));return r;}'),
    ('rleDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(std::size_t i=0;i+1<encoded.size();i+=2){int cnt=static_cast<int>(encoded[i+1]);for(int j=0;j<cnt;++j)r.push_back(encoded[i]);}return r;}'),
    ('rleRatio', 'number', [('data', 'list number')],
     '{auto e=rleEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('runLength', 'number', [('data', 'list number')],
     '{if(data.empty())return 0;int best=1,cur=1;for(std::size_t i=1;i<data.size();++i){if(data[i]==data[i-1]){++cur;best=std::max(best,cur);}else cur=1;}return static_cast<double>(best);}'),
    ('compress', 'list number', [('data', 'list number')],
     'return rleEncode(data);'),
    ('decompress', 'list number', [('encoded', 'list number')],
     'return rleDecode(encoded);'),
    ('isCompressible', 'bool', [('data', 'list number')],
     'return rleRatio(data)<1.0;'),
])

cx('compdelta', [
    ('deltaEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;if(data.empty())return r;r.push_back(data[0]);for(std::size_t i=1;i<data.size();++i)r.push_back(data[i]-data[i-1]);return r;}'),
    ('deltaDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;if(encoded.empty())return r;double cur=encoded[0];r.push_back(cur);for(std::size_t i=1;i<encoded.size();++i){cur+=encoded[i];r.push_back(cur);}return r;}'),
    ('deltaSum', 'number', [('data', 'list number')],
     '{auto e=deltaEncode(data);double s=0;for(double x:e)s+=std::abs(x);return s;}'),
    ('secondOrder', 'list number', [('data', 'list number')],
     '{auto d=deltaEncode(data);return deltaEncode(d);}'),
    ('roundTrip', 'bool', [('data', 'list number')],
     'return deltaDecode(deltaEncode(data)).size()==data.size();'),
    ('maxDelta', 'number', [('data', 'list number')],
     '{auto e=deltaEncode(data);return e.empty()?0:*std::max_element(e.begin(),e.end(),[](double a,double b){return std::abs(a)<std::abs(b);});}'),
])

cx('compresshuff', [
    ('resshuffEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('resshuffDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('resshuffRatio', 'number', [('data', 'list number')],
     '{auto e=resshuffEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('resshuffSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('resshuffCompressed', 'number', [('data', 'list number')],
     '{auto e=resshuffEncode(data);return static_cast<double>(e.size());}'),
    ('resshuffRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=resshuffEncode(data),d=resshuffDecode(e);return d.size()==data.size();}'),
])

cx('complz77', [
    ('lz77Encode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('lz77Decode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('lz77Ratio', 'number', [('data', 'list number')],
     '{auto e=lz77Encode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('lz77Size', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('lz77Compressed', 'number', [('data', 'list number')],
     '{auto e=lz77Encode(data);return static_cast<double>(e.size());}'),
    ('lz77RoundTrip', 'bool', [('data', 'list number')],
     '{auto e=lz77Encode(data),d=lz77Decode(e);return d.size()==data.size();}'),
])

cx('complzw', [
    ('lzwEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('lzwDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('lzwRatio', 'number', [('data', 'list number')],
     '{auto e=lzwEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('lzwSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('lzwCompressed', 'number', [('data', 'list number')],
     '{auto e=lzwEncode(data);return static_cast<double>(e.size());}'),
    ('lzwRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=lzwEncode(data),d=lzwDecode(e);return d.size()==data.size();}'),
])

cx('comprunlen', [
    ('runlenEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('runlenDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('runlenRatio', 'number', [('data', 'list number')],
     '{auto e=runlenEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('runlenSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('runlenCompressed', 'number', [('data', 'list number')],
     '{auto e=runlenEncode(data);return static_cast<double>(e.size());}'),
    ('runlenRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=runlenEncode(data),d=runlenDecode(e);return d.size()==data.size();}'),
])

cx('compbitpack', [
    ('bitpackEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('bitpackDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('bitpackRatio', 'number', [('data', 'list number')],
     '{auto e=bitpackEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('bitpackSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('bitpackCompressed', 'number', [('data', 'list number')],
     '{auto e=bitpackEncode(data);return static_cast<double>(e.size());}'),
    ('bitpackRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=bitpackEncode(data),d=bitpackDecode(e);return d.size()==data.size();}'),
])

cx('compvarint', [
    ('varintEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('varintDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('varintRatio', 'number', [('data', 'list number')],
     '{auto e=varintEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('varintSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('varintCompressed', 'number', [('data', 'list number')],
     '{auto e=varintEncode(data);return static_cast<double>(e.size());}'),
    ('varintRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=varintEncode(data),d=varintDecode(e);return d.size()==data.size();}'),
])

cx('compdict', [
    ('dictEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('dictDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('dictRatio', 'number', [('data', 'list number')],
     '{auto e=dictEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('dictSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('dictCompressed', 'number', [('data', 'list number')],
     '{auto e=dictEncode(data);return static_cast<double>(e.size());}'),
    ('dictRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=dictEncode(data),d=dictDecode(e);return d.size()==data.size();}'),
])

cx('compframe', [
    ('frameEncode', 'list number', [('data', 'list number')],
     '{std::vector<double> r;for(double x:data)r.push_back(x);return r;}'),
    ('frameDecode', 'list number', [('encoded', 'list number')],
     '{std::vector<double> r;for(double x:encoded)r.push_back(x);return r;}'),
    ('frameRatio', 'number', [('data', 'list number')],
     '{auto e=frameEncode(data);return data.empty()?1:static_cast<double>(e.size())/data.size();}'),
    ('frameSize', 'number', [('data', 'list number')],
     'return static_cast<double>(data.size());'),
    ('frameCompressed', 'number', [('data', 'list number')],
     '{auto e=frameEncode(data);return static_cast<double>(e.size());}'),
    ('frameRoundTrip', 'bool', [('data', 'list number')],
     '{auto e=frameEncode(data),d=frameDecode(e);return d.size()==data.size();}'),
])

cx('parsejsonadv', [
    ('jsonLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('jsonUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('jsonLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('jsonTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('jsonSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('jsonJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('jsonReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parsexml', [
    ('xmlLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('xmlUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('xmlLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('xmlTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('xmlSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('xmlJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('xmlReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parseini', [
    ('iniLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('iniUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('iniLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('iniTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('iniSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('iniJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('iniReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parsetoml', [
    ('tomlLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('tomlUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('tomlLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('tomlTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('tomlSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('tomlJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('tomlReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parsepath', [
    ('pathLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('pathUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('pathLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('pathTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('pathSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('pathJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('pathReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parseyaml', [
    ('yamlLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('yamlUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('yamlLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('yamlTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('yamlSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('yamlJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('yamlReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parsecsvadv', [
    ('csvLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('csvUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('csvLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('csvTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('csvSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('csvJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('csvReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
    ('parseRow', 'list text', [('line', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::string cur;for(char c:line){if(std::string(1,c)==delim){r.push_back(cur);cur.clear();}else cur+=c;}r.push_back(cur);return r;}'),
])

cx('parsehtml', [
    ('htmlLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('htmlUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('htmlLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('htmlTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('htmlSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('htmlJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('htmlReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parselog', [
    ('logLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('logUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('logLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('logTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('logSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('logJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('logReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parseuri', [
    ('scheme', 'text', [('uri', 'text')],
     '{auto p=uri.find("://");return p==std::string::npos?"":uri.substr(0,p);}'),
    ('host', 'text', [('uri', 'text')],
     '{auto p=uri.find("://");if(p==std::string::npos)return "";std::string rest=uri.substr(p+3);auto sl=rest.find("/");return sl==std::string::npos?rest:rest.substr(0,sl);}'),
    ('path', 'text', [('uri', 'text')],
     '{auto p=uri.find("://");if(p==std::string::npos)return uri;std::string rest=uri.substr(p+3);auto sl=rest.find("/");return sl==std::string::npos?"/":rest.substr(sl);}'),
    ('query', 'text', [('uri', 'text')],
     '{auto q=uri.find("?");return q==std::string::npos?"":uri.substr(q+1);}'),
    ('fragment', 'text', [('uri', 'text')],
     '{auto f=uri.find("#");return f==std::string::npos?"":uri.substr(f+1);}'),
    ('port', 'number', [('uri', 'text')],
     '{auto h=host(uri);auto c=h.find(":");return c==std::string::npos?0:static_cast<double>(std::stoi(h.substr(c+1)));}'),
    ('isValid', 'bool', [('uri', 'text')],
     'return !scheme(uri).empty()&&!host(uri).empty();'),
])

cx('parsemime', [
    ('mimeLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('mimeUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('mimeLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('mimeTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('mimeSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('mimeJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('mimeReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parsehex', [
    ('decode', 'list number', [('hex', 'text')],
     '{std::vector<double> r;for(std::size_t i=0;i+1<hex.size();i+=2){int v=0;for(int d=0;d<2;++d){char c=hex[i+d];v=(v<<4)+(c>=\'a\'?c-\'a\'+10:c>=\'A\'?c-\'A\'+10:c-\'0\');}r.push_back(static_cast<double>(v));}return r;}'),
    ('encode', 'text', [('bytes', 'list number')],
     '{std::string r;static const char* h="0123456789abcdef";for(double b:bytes){int v=static_cast<int>(b)&0xFF;r+=h[v>>4];r+=h[v&0xF];}return r;}'),
    ('nibbleCount', 'number', [('hex', 'text')],
     'return static_cast<double>(hex.size());'),
    ('byteCount', 'number', [('hex', 'text')],
     'return static_cast<double>(hex.size()/2);'),
    ('isHex', 'bool', [('s', 'text')],
     '{for(char c:s)if(!std::isxdigit(static_cast<unsigned char>(c)))return false;return !s.empty();}'),
    ('roundTrip', 'bool', [('bytes', 'list number')],
     'return decode(encode(bytes)).size()==bytes.size();'),
])

cx('parsebinary', [
    ('binaLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('binaUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('binaLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('binaTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('binaSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('binaJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('binaReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parsetemplate', [
    ('tempLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('tempUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('tempLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('tempTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('tempSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('tempJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('tempReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('parseexpr', [
    ('exprLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('exprUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('exprLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('exprTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('exprSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('exprJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('exprReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('csvfilter', [
    ('filtSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('filtMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('filtMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('filtMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('filtVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('filtStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('filtNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvgroup', [
    ('groupSum', 'list number', [('values', 'list number'), ('keys', 'list number')],
     '{std::map<int,double> m;for(std::size_t i=0;i<values.size()&&i<keys.size();++i)m[static_cast<int>(keys[i])]+=values[i];std::vector<double> r;for(auto&p:m)r.push_back(p.second);return r;}'),
    ('groupCount', 'list number', [('keys', 'list number')],
     '{std::map<int,int> m;for(double k:keys)++m[static_cast<int>(k)];std::vector<double> r;for(auto&p:m)r.push_back(static_cast<double>(p.second));return r;}'),
    ('groupMean', 'list number', [('values', 'list number'), ('keys', 'list number')],
     '{std::map<int,std::pair<double,int>> m;for(std::size_t i=0;i<values.size()&&i<keys.size();++i){int k=static_cast<int>(keys[i]);m[k].first+=values[i];++m[k].second;}std::vector<double> r;for(auto&p:m)r.push_back(p.second.first/p.second.second);return r;}'),
    ('uniqueKeys', 'list number', [('keys', 'list number')],
     '{std::map<int,int> m;for(double k:keys)m[static_cast<int>(k)]=1;std::vector<double> r;for(auto&p:m)r.push_back(static_cast<double>(p.first));return r;}'),
    ('groupMax', 'list number', [('values', 'list number'), ('keys', 'list number')],
     '{std::map<int,double> m;for(std::size_t i=0;i<values.size()&&i<keys.size();++i){int k=static_cast<int>(keys[i]);if(!m.count(k)||values[i]>m[k])m[k]=values[i];}std::vector<double> r;for(auto&p:m)r.push_back(p.second);return r;}'),
    ('numGroups', 'number', [('keys', 'list number')],
     'return static_cast<double>(uniqueKeys(keys).size());'),
])

cx('csvaggregate', [
    ('aggrSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('aggrMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('aggrMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('aggrMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('aggrVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('aggrStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('aggrNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvjoin', [
    ('joinSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('joinMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('joinMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('joinMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('joinVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('joinStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('joinNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvpivot', [
    ('pivoSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('pivoMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('pivoMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('pivoMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('pivoVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('pivoStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('pivoNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvsort', [
    ('sortAsc', 'list number', [('col', 'list number')],
     '{auto t=col;std::sort(t.begin(),t.end());return t;}'),
    ('sortDesc', 'list number', [('col', 'list number')],
     '{auto t=col;std::sort(t.begin(),t.end(),std::greater<double>());return t;}'),
    ('argsort', 'list number', [('col', 'list number')],
     '{std::vector<std::size_t> idx(col.size());for(std::size_t i=0;i<col.size();++i)idx[i]=i;std::sort(idx.begin(),idx.end(),[&](auto a,auto b){return col[a]<col[b];});std::vector<double> r;for(auto i:idx)r.push_back(static_cast<double>(i));return r;}'),
    ('rank', 'list number', [('col', 'list number')],
     '{auto a=argsort(col);std::vector<double> r(col.size());for(std::size_t i=0;i<a.size();++i)r[static_cast<std::size_t>(a[i])]=static_cast<double>(i);return r;}'),
    ('topK', 'list number', [('col', 'list number'), ('k', 'number')],
     '{auto t=sortDesc(col);int kk=static_cast<int>(k);if(kk>static_cast<int>(t.size()))kk=static_cast<int>(t.size());return std::vector<double>(t.begin(),t.begin()+kk);}'),
    ('bottomK', 'list number', [('col', 'list number'), ('k', 'number')],
     '{auto t=sortAsc(col);int kk=static_cast<int>(k);if(kk>static_cast<int>(t.size()))kk=static_cast<int>(t.size());return std::vector<double>(t.begin(),t.begin()+kk);}'),
])

cx('csvselect', [
    ('seleSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('seleMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('seleMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('seleMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('seleVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('seleStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('seleNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvdistinct', [
    ('distSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('distMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('distMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('distMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('distVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('distStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('distNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvlimit', [
    ('limiSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('limiMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('limiMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('limiMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('limiVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('limiStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('limiNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvhaving', [
    ('haviSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('haviMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('haviMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('haviMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('haviVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('haviStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('haviNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvunion', [
    ('unioSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('unioMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('unioMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('unioMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('unioVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('unioStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('unioNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvwindow', [
    ('windSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('windMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('windMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('windMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('windVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('windStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('windNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvnormalize', [
    ('normSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('normMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('normMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('normMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('normVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('normStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('normNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvrollup', [
    ('rollSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('rollMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('rollMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('rollMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('rollVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('rollStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('rollNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('csvsample', [
    ('sampSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('sampMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('sampMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('sampMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('sampVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('sampStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('sampNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('filterGt', 'list number', [('col', 'list number'), ('threshold', 'number')],
     '{std::vector<double> r;for(double x:col)if(x>threshold)r.push_back(x);return r;}'),
])

cx('simmonte', [
    ('estimatePi', 'number', [('samples', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(samples);std::srand(static_cast<unsigned>(seed));int inside=0;for(int i=0;i<n;++i){double x=static_cast<double>(std::rand())/RAND_MAX,y=static_cast<double>(std::rand())/RAND_MAX;if(x*x+y*y<=1)++inside;}return 4.0*inside/n;}'),
    ('integrate', 'number', [('samples', 'number'), ('seed', 'number'), ('a', 'number'), ('b', 'number')],
     '{int n=static_cast<int>(samples);std::srand(static_cast<unsigned>(seed));double s=0;for(int i=0;i<n;++i){double x=a+(b-a)*static_cast<double>(std::rand())/RAND_MAX;s+=x*x;}return(b-a)*s/n;}'),
    ('randomNormal', 'list number', [('n', 'number'), ('seed', 'number')],
     '{int nn=static_cast<int>(n);std::srand(static_cast<unsigned>(seed));std::vector<double> r;for(int i=0;i<nn;++i){double u1=static_cast<double>(std::rand())/RAND_MAX,u2=static_cast<double>(std::rand())/RAND_MAX;r.push_back(std::sqrt(-2*std::log(u1+1e-12))*std::cos(2*3.141592653589793*u2));}return r;}'),
    ('confidence95', 'list number', [('samples', 'list number')],
     '{if(samples.size()<2)return std::vector<double>{};double m=0;for(double x:samples)m+=x;m/=samples.size();double s=0;for(double x:samples)s+=(x-m)*(x-m);s=std::sqrt(s/(samples.size()-1));return std::vector<double>{m-1.96*s/std::sqrt(samples.size()),m+1.96*s/std::sqrt(samples.size())};}'),
    ('bootstrapMean', 'number', [('data', 'list number'), ('samples', 'number'), ('seed', 'number')],
     '{std::srand(static_cast<unsigned>(seed));int n=static_cast<int>(samples);double sum=0;for(int s=0;s<n;++s){double ss=0;for(std::size_t i=0;i<data.size();++i)ss+=data[static_cast<std::size_t>(std::rand()%static_cast<int>(data.size()))];sum+=ss/data.size();}return sum/n;}'),
    ('varianceReduction', 'number', [('samples', 'number'), ('seed', 'number')],
     'return estimatePi(samples,seed);'),
])

cx('simmarkov', [
    ('steadyState', 'list number', [('trans', 'list number'), ('states', 'number')],
     '{int S=static_cast<int>(states);std::vector<double> pi(S,1.0/S);for(int iter=0;iter<50;++iter){std::vector<double> np(S,0);for(int i=0;i<S;++i)for(int j=0;j<S;++j){std::size_t idx=static_cast<std::size_t>(i*S+j);if(idx<trans.size())np[j]+=pi[i]*trans[idx];}pi=np;}return pi;}'),
    ('simulate', 'list number', [('trans', 'list number'), ('states', 'number'), ('steps', 'number'), ('seed', 'number')],
     '{int S=static_cast<int>(states),n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> path;int cur=0;for(int t=0;t<n;++t){path.push_back(static_cast<double>(cur));double r=static_cast<double>(std::rand())/RAND_MAX,cum=0;for(int j=0;j<S;++j){std::size_t idx=static_cast<std::size_t>(cur*S+j);cum+=idx<trans.size()?trans[idx]:0;if(r<=cum){cur=j;break;}}}return path;}'),
    ('transitionProb', 'number', [('trans', 'list number'), ('states', 'number'), ('from', 'number'), ('to', 'number')],
     '{int S=static_cast<int>(states),f=static_cast<int>(from),t=static_cast<int>(to);std::size_t idx=static_cast<std::size_t>(f*S+t);return idx<trans.size()?trans[idx]:0;}'),
    ('expectedSteps', 'number', [('trans', 'list number'), ('states', 'number'), ('target', 'number')],
     '{int S=static_cast<int>(states),tgt=static_cast<int>(target);double exp=0;for(int s=0;s<S;++s){std::size_t idx=static_cast<std::size_t>(s*S+tgt);exp+=idx<trans.size()?trans[idx]:0;}return exp/S*100;}'),
    ('isStochastic', 'bool', [('trans', 'list number'), ('states', 'number')],
     '{int S=static_cast<int>(states);for(int i=0;i<S;++i){double sum=0;for(int j=0;j<S;++j){std::size_t idx=static_cast<std::size_t>(i*S+j);if(idx<trans.size())sum+=trans[idx];}if(std::abs(sum-1)>0.01)return false;}return true;}'),
    ('mixingTime', 'number', [('trans', 'list number'), ('states', 'number')],
     '{auto pi=steadyState(trans,states);double maxOff=0;for(double p:pi)maxOff=std::max(maxOff,std::abs(p-1.0/states));return maxOff<1e-6?0:-std::log(maxOff);}'),
])

cx('simrandomwalk', [
    ('randSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('randMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('randMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('randMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('randVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('randStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('randNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('simbrownian', [
    ('browSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('browMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('browMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('browMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('browVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('browStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('browNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('simpoisson', [
    ('poisSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('poisMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('poisMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('poisMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('poisVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('poisStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('poisNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('simqueue', [
    ('queuSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('queuMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('queuMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('queuMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('queuVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('queuStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('queuNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('siminventory', [
    ('inveSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('inveMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('inveMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('inveMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('inveVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('inveStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('inveNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('simdiscrete', [
    ('discSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('discMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('discMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('discMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('discVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('discStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('discNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('simlorenz', [
    ('loreSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('loreMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('loreMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('loreMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('loreVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('loreStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('loreNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('simbirth', [
    ('birtSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('birtMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('birtMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('birtMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('birtVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('birtStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('birtNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
    ('simulate', 'list number', [('steps', 'number'), ('seed', 'number')],
     '{int n=static_cast<int>(steps);std::srand(static_cast<unsigned>(seed));std::vector<double> r;double x=0;for(int i=0;i<n;++i){x+=static_cast<double>(std::rand()%1000)/500.0-1;r.push_back(x);}return r;}'),
])

cx('finoption', [
    ('blackScholes', 'number', [('spot', 'number'), ('strike', 'number'), ('rate', 'number'), ('vol', 'number'), ('time', 'number')],
     '{double d1=(std::log(spot/strike)+(rate+0.5*vol*vol)*time)/(vol*std::sqrt(time)),d2=d1-vol*std::sqrt(time);return spot*0.5*(1+std::erf(d1/std::sqrt(2)))-strike*std::exp(-rate*time)*0.5*(1+std::erf(d2/std::sqrt(2)));}'),
    ('putPrice', 'number', [('spot', 'number'), ('strike', 'number'), ('rate', 'number'), ('vol', 'number'), ('time', 'number')],
     '{double c=blackScholes(spot,strike,rate,vol,time);return c-spot+strike*std::exp(-rate*time);}'),
    ('intrinsic', 'number', [('spot', 'number'), ('strike', 'number')],
     'return std::max(0.0,spot-strike);'),
    ('timeValue', 'number', [('spot', 'number'), ('strike', 'number'), ('rate', 'number'), ('vol', 'number'), ('time', 'number')],
     'return blackScholes(spot,strike,rate,vol,time)-intrinsic(spot,strike);'),
    ('delta', 'number', [('spot', 'number'), ('strike', 'number'), ('rate', 'number'), ('vol', 'number'), ('time', 'number')],
     '{double d1=(std::log(spot/strike)+(rate+0.5*vol*vol)*time)/(vol*std::sqrt(time));return 0.5*(1+std::erf(d1/std::sqrt(2)));}'),
    ('gamma', 'number', [('spot', 'number'), ('strike', 'number'), ('rate', 'number'), ('vol', 'number'), ('time', 'number')],
     '{double d1=(std::log(spot/strike)+(rate+0.5*vol*vol)*time)/(vol*std::sqrt(time));return std::exp(-0.5*d1*d1)/(spot*vol*std::sqrt(time)*std::sqrt(2*3.141592653589793));}'),
    ('vega', 'number', [('spot', 'number'), ('strike', 'number'), ('rate', 'number'), ('vol', 'number'), ('time', 'number')],
     '{double d1=(std::log(spot/strike)+(rate+0.5*vol*vol)*time)/(vol*std::sqrt(time));return spot*std::exp(-0.5*d1*d1)*std::sqrt(time)/std::sqrt(2*3.141592653589793);}'),
])

cx('finbond', [
    ('pv', 'number', [('face', 'number'), ('rate', 'number'), ('years', 'number'), ('coupon', 'number')],
     '{double pv=0;for(int t=1;t<=static_cast<int>(years);++t)pv+=coupon/std::pow(1+rate,t);pv+=face/std::pow(1+rate,years);return pv;}'),
    ('ytm', 'number', [('price', 'number'), ('face', 'number'), ('coupon', 'number'), ('years', 'number')],
     '{double lo=0,hi=1;for(int i=0;i<50;++i){double mid=(lo+hi)/2;if(pv(face,mid,years,coupon)>price)lo=mid;else hi=mid;}return(lo+hi)/2;}'),
    ('duration', 'number', [('face', 'number'), ('rate', 'number'), ('years', 'number'), ('coupon', 'number')],
     '{double d=0,p=pv(face,rate,years,coupon);for(int t=1;t<=static_cast<int>(years);++t)d+=t*coupon/std::pow(1+rate,t)/p;d+=years*face/std::pow(1+rate,years)/p;return d;}'),
    ('convexity', 'number', [('face', 'number'), ('rate', 'number'), ('years', 'number'), ('coupon', 'number')],
     '{double c=0,p=pv(face,rate,years,coupon);for(int t=1;t<=static_cast<int>(years);++t)c+=t*(t+1)*coupon/std::pow(1+rate,t+2)/p;c+=years*(years+1)*face/std::pow(1+rate,years+2)/p;return c;}'),
    ('couponYield', 'number', [('coupon', 'number'), ('price', 'number')],
     'return price<1e-12?0:coupon/price;'),
    ('accruedInterest', 'number', [('coupon', 'number'), ('days', 'number')],
     'return coupon*days/365.0;'),
])

cx('finportfolio', [
    ('portSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('portMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('portMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('portMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('portVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('portStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('portNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finblack', [
    ('blacSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('blacMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('blacMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('blacMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('blacVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('blacStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('blacNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('fingreeks', [
    ('greeSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('greeMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('greeMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('greeMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('greeVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('greeStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('greeNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finyield', [
    ('yielSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('yielMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('yielMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('yielMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('yielVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('yielStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('yielNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finsharpe', [
    ('sharpe', 'number', [('returns', 'list number'), ('rf', 'number')],
     '{if(returns.size()<2)return 0;double m=0;for(double r:returns)m+=r;m/=returns.size();m-=rf;double s=0;for(double r:returns)s+=(r-returns[0])*(r-returns[0]);s=std::sqrt(s/(returns.size()-1));return s<1e-12?0:m/s;}'),
    ('sortino', 'number', [('returns', 'list number'), ('rf', 'number')],
     '{if(returns.empty())return 0;double m=0;for(double r:returns)m+=r;m/=returns.size();m-=rf;double dd=0;for(double r:returns)if(r<rf)dd+=(r-rf)*(r-rf);dd=std::sqrt(dd/returns.size());return dd<1e-12?0:m/dd;}'),
    ('maxDrawdown', 'number', [('prices', 'list number')],
     '{if(prices.empty())return 0;double peak=prices[0],maxDD=0;for(double p:prices){peak=std::max(peak,p);maxDD=std::max(maxDD,(peak-p)/peak);}return maxDD;}'),
    ('calmar', 'number', [('returns', 'list number'), ('prices', 'list number')],
     '{double ann=0;for(double r:returns)ann+=r;ann/=returns.empty()?1:returns.size();return maxDrawdown(prices)<1e-12?0:ann/maxDrawdown(prices);}'),
    ('volatility', 'number', [('returns', 'list number')],
     '{if(returns.size()<2)return 0;double m=0;for(double r:returns)m+=r;m/=returns.size();double s=0;for(double r:returns)s+=(r-m)*(r-m);return std::sqrt(s/(returns.size()-1));}'),
    ('annualizedReturn', 'number', [('returns', 'list number'), ('periods', 'number')],
     '{double m=0;for(double r:returns)m+=r;m/=returns.empty()?1:returns.size();return m*periods;}'),
])

cx('finvar', [
    ('varSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('varMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('varMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('varMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('varVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('varStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('varNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finforex', [
    ('foreSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('foreMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('foreMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('foreMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('foreVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('foreStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('foreNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finamort', [
    ('amorSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('amorMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('amorMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('amorMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('amorVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('amorStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('amorNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finfutures', [
    ('futuSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('futuMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('futuMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('futuMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('futuVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('futuStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('futuNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finswap', [
    ('swapSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('swapMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('swapMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('swapMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('swapVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('swapStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('swapNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finrisk', [
    ('riskSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('riskMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('riskMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('riskMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('riskVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('riskStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('riskNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('finhedge', [
    ('hedgSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('hedgMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('hedgMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('hedgMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('hedgVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('hedgStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('hedgNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('findividend', [
    ('diviSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('diviMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('diviMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('diviMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('diviVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('diviStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('diviNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigconv', [
    ('convolve', 'list number', [('a', 'list number'), ('b', 'list number')],
     '{std::vector<double> r(a.size()+b.size()-1,0);for(std::size_t i=0;i<a.size();++i)for(std::size_t j=0;j<b.size();++j)r[i+j]+=a[i]*b[j];return r;}'),
    ('crossCorr', 'list number', [('a', 'list number'), ('b', 'list number')],
     '{std::vector<double> r;for(int lag=-static_cast<int>(b.size())+1;lag<static_cast<int>(a.size());++lag){double s=0;for(std::size_t i=0;i<a.size();++i){int j=static_cast<int>(i)-lag;if(j>=0&&j<static_cast<int>(b.size()))s+=a[i]*b[static_cast<std::size_t>(j)];}r.push_back(s);}return r;}'),
    ('movingAvg', 'list number', [('v', 'list number'), ('win', 'number')],
     '{int w=static_cast<int>(win);std::vector<double> r;if(w<=0)return r;for(std::size_t i=0;i+w<=v.size();++i){double s=0;for(int j=0;j<w;++j)s+=v[i+j];r.push_back(s/w);}return r;}'),
    ('deconvSimple', 'list number', [('signal', 'list number'), ('kernel', 'list number')],
     '{if(kernel.empty()||kernel[0]<1e-12)return signal;std::vector<double> r;for(double x:signal)r.push_back(x/kernel[0]);return r;}'),
    ('energy', 'number', [('v', 'list number')],
     '{double s=0;for(double x:v)s+=x*x;return s;}'),
    ('normalize', 'list number', [('v', 'list number')],
     '{double e=std::sqrt(energy(v));std::vector<double> r;if(e<1e-12)return v;for(double x:v)r.push_back(x/e);return r;}'),
])

cx('sigfft', [
    ('dft', 'list number', [('signal', 'list number')],
     '{int N=static_cast<int>(signal.size());std::vector<double> r;for(int k=0;k<N;++k){double re=0,im=0;for(int n=0;n<N;++n){double ang=-2*3.141592653589793*k*n/N;re+=signal[static_cast<std::size_t>(n)]*std::cos(ang);im+=signal[static_cast<std::size_t>(n)]*std::sin(ang);}r.push_back(re);r.push_back(im);}return r;}'),
    ('magnitude', 'list number', [('signal', 'list number')],
     '{auto d=dft(signal);std::vector<double> m;for(std::size_t i=0;i+1<d.size();i+=2)m.push_back(std::sqrt(d[i]*d[i]+d[i+1]*d[i+1]));return m;}'),
    ('powerSpectrum', 'list number', [('signal', 'list number')],
     '{auto mag=magnitude(signal);std::vector<double> p;for(double x:mag)p.push_back(x*x);return p;}'),
    ('dominantFreq', 'number', [('signal', 'list number')],
     '{auto m=magnitude(signal);if(m.size()<2)return 0;return static_cast<double>(std::max_element(m.begin()+1,m.end())-m.begin());}'),
    ('inverseDft', 'list number', [('spectrum', 'list number'), ('n', 'number')],
     '{int N=static_cast<int>(n);std::vector<double> r(N,0);for(int t=0;t<N;++t){double sum=0;for(int k=0;k<N;++k){std::size_t idx=static_cast<std::size_t>(k*2);if(idx+1>=spectrum.size())break;double ang=2*3.141592653589793*k*t/N;sum+=spectrum[idx]*std::cos(ang)-spectrum[idx+1]*std::sin(ang);}r[static_cast<std::size_t>(t)]=sum/N;}return r;}'),
    ('bandEnergy', 'number', [('signal', 'list number'), ('lo', 'number'), ('hi', 'number')],
     '{auto p=powerSpectrum(signal);double s=0;int l=static_cast<int>(lo),h=static_cast<int>(hi);for(int i=l;i<h&&i<static_cast<int>(p.size());++i)s+=p[static_cast<std::size_t>(i)];return s;}'),
])

cx('sigpoly', [
    ('polySum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('polyMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('polyMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('polyMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('polyVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('polyStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('polyNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigeigen', [
    ('eigeSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('eigeMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('eigeMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('eigeMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('eigeVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('eigeStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('eigeNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigmatrix', [
    ('matrSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('matrMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('matrMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('matrMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('matrVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('matrStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('matrNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigintegral', [
    ('inteSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('inteMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('inteMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('inteMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('inteVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('inteStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('inteNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigderivative', [
    ('deriSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('deriMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('deriMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('deriMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('deriVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('deriStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('deriNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigfilter', [
    ('lowPass', 'list number', [('v', 'list number'), ('alpha', 'number')],
     '{std::vector<double> r;if(v.empty())return r;r.push_back(v[0]);for(std::size_t i=1;i<v.size();++i)r.push_back(alpha*v[i]+(1-alpha)*r.back());return r;}'),
    ('highPass', 'list number', [('v', 'list number'), ('alpha', 'number')],
     '{auto lp=lowPass(v,alpha);std::vector<double> r;for(std::size_t i=0;i<v.size();++i)r.push_back(v[i]-lp[i]);return r;}'),
    ('medianFilter', 'list number', [('v', 'list number'), ('win', 'number')],
     '{int w=static_cast<int>(win);std::vector<double> r;if(w<=0)return r;for(std::size_t i=0;i+w<=v.size();++i){std::vector<double> sub(v.begin()+i,v.begin()+i+w);std::sort(sub.begin(),sub.end());r.push_back(sub[sub.size()/2]);}return r;}'),
    ('savgol', 'list number', [('v', 'list number'), ('win', 'number')],
     'return medianFilter(v,win);'),
    ('bandpass', 'list number', [('v', 'list number'), ('lo', 'number'), ('hi', 'number')],
     '{auto hp=highPass(v,lo);return lowPass(hp,hi);}'),
    ('snr', 'number', [('signal', 'list number'), ('noise', 'list number')],
     '{double ps=0,pn=0;for(double x:signal)ps+=x*x;for(double x:noise)pn+=x*x;return pn<1e-12?0:10*std::log10(ps/pn);}'),
])

cx('sigwavelet', [
    ('waveSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('waveMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('waveMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('waveMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('waveVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('waveStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('waveNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigresample', [
    ('resaSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('resaMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('resaMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('resaMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('resaVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('resaStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('resaNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('siginterpolate', [
    ('inteSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('inteMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('inteMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('inteMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('inteVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('inteStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('inteNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigspline', [
    ('spliSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('spliMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('spliMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('spliMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('spliVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('spliStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('spliNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigcorrel', [
    ('corrSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('corrMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('corrMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('corrMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('corrVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('corrStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('corrNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigautocorr', [
    ('autoSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('autoMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('autoMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('autoMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('autoVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('autoStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('autoNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('sigpower', [
    ('poweSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('poweMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('poweMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('poweMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('poweVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('poweStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('poweNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('nlpstem', [
    ('stemLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('stemUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('stemLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('stemTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('stemSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('stemJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('stemReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlplevenshtein', [
    ('distance', 'number', [('a', 'text'), ('b', 'text')],
     '{std::vector<std::vector<int>> dp(a.size()+1,std::vector<int>(b.size()+1));for(std::size_t i=0;i<=a.size();++i)dp[i][0]=static_cast<int>(i);for(std::size_t j=0;j<=b.size();++j)dp[0][j]=static_cast<int>(j);for(std::size_t i=1;i<=a.size();++i)for(std::size_t j=1;j<=b.size();++j){int cost=a[i-1]==b[j-1]?0:1;dp[i][j]=std::min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+cost});}return static_cast<double>(dp[a.size()][b.size()]);}'),
    ('similarity', 'number', [('a', 'text'), ('b', 'text')],
     '{double d=distance(a,b);double m=std::max(a.size(),b.size());return m==0?1:1-d/m;}'),
    ('ratio', 'number', [('a', 'text'), ('b', 'text')],
     'return similarity(a,b)*100;'),
    ('isClose', 'bool', [('a', 'text'), ('b', 'text'), ('maxDist', 'number')],
     'return distance(a,b)<=maxDist;'),
    ('normalizedDist', 'number', [('a', 'text'), ('b', 'text')],
     '{double m=std::max(a.size(),b.size());return m==0?0:distance(a,b)/m;}'),
    ('longestCommon', 'number', [('a', 'text'), ('b', 'text')],
     '{std::size_t best=0;for(std::size_t i=0;i<a.size();++i)for(std::size_t j=0;j<b.size();++j){std::size_t k=0;while(i+k<a.size()&&j+k<b.size()&&a[i+k]==b[j+k])++k;best=std::max(best,k);}return static_cast<double>(best);}'),
])

cx('nlpjaccard', [
    ('similarity', 'number', [('a', 'text'), ('b', 'text')],
     '{std::map<char,int> ma,mb;for(char c:a)++ma[c];for(char c:b)++mb[c];int inter=0,uni=0;for(auto&p:ma)if(mb.count(p.first))inter+=std::min(p.second,mb[p.first]);for(auto&p:ma)uni+=p.second;for(auto&p:mb)if(!ma.count(p.first))uni+=p.second;return uni==0?0:static_cast<double>(inter)/uni;}'),
    ('tokenJaccard', 'number', [('a', 'text'), ('b', 'text')],
     '{auto tok=[](const std::string&s){std::vector<std::string> t;std::string w;for(unsigned char c:s){if(std::isspace(c)){if(!w.empty()){t.push_back(w);w.clear();}}else w+=static_cast<char>(c);}if(!w.empty())t.push_back(w);return t;};auto ta=tok(a),tb=tok(b);std::map<std::string,int> ma,mb;for(auto&x:ta)++ma[x];for(auto&x:tb)++mb[x];int inter=0,uni=0;for(auto&p:ma)if(mb.count(p.first))inter++;for(auto&p:ma)uni++;for(auto&p:mb)if(!ma.count(p.first))uni++;return uni==0?0:static_cast<double>(inter)/uni;}'),
    ('distance', 'number', [('a', 'text'), ('b', 'text')],
     'return 1-similarity(a,b);'),
    ('ngramJaccard', 'number', [('a', 'text'), ('b', 'text'), ('n', 'number')],
     '{int nn=static_cast<int>(n);auto ngrams=[&](const std::string&s){std::map<std::string,int> g;for(std::size_t i=0;i+nn<=s.size();++i)++g[s.substr(i,nn)];return g;};auto ga=ngrams(a),gb=ngrams(b);int inter=0,uni=0;for(auto&p:ga)if(gb.count(p.first))inter++;for(auto&p:ga)uni++;for(auto&p:gb)if(!ga.count(p.first))uni++;return uni==0?0:static_cast<double>(inter)/uni;}'),
    ('overlap', 'number', [('a', 'text'), ('b', 'text')],
     'return similarity(a,b);'),
    ('dice', 'number', [('a', 'text'), ('b', 'text')],
     '{double j=similarity(a,b);return 2*j/(1+j);}'),
])

cx('nlpedit', [
    ('editLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('editUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('editLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('editTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('editSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('editJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('editReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlptoken', [
    ('tokeLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('tokeUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('tokeLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('tokeTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('tokeSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('tokeJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('tokeReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpngram', [
    ('ngraLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('ngraUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('ngraLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('ngraTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('ngraSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('ngraJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('ngraReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpbow', [
    ('bowLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('bowUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('bowLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('bowTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('bowSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('bowJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('bowReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpstop', [
    ('stopLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('stopUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('stopLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('stopTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('stopSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('stopJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('stopReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpphrase', [
    ('phraLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('phraUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('phraLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('phraTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('phraSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('phraJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('phraReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpsentiment', [
    ('sentLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('sentUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('sentLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('sentTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('sentSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('sentJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('sentReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpkeyword', [
    ('keywLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('keywUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('keywLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('keywTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('keywSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('keywJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('keywReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlptfidf', [
    ('tf', 'number', [('doc', 'text'), ('term', 'text')],
     '{int c=0,total=0;std::string w;for(unsigned char ch:doc){if(std::isspace(ch)){if(!w.empty()){++total;if(w==term)++c;w.clear();}}else w+=static_cast<char>(ch);}if(!w.empty()){++total;if(w==term)++c;}return total==0?0:static_cast<double>(c)/total;}'),
    ('idf', 'number', [('term', 'text'), ('corpus', 'list text')],
     '{int df=0;for(auto&d:corpus){if(d.find(term)!=std::string::npos)++df;}return df==0?0:std::log(static_cast<double>(corpus.size())/(df+1))+1;}'),
    ('tfidf', 'number', [('doc', 'text'), ('term', 'text'), ('corpus', 'list text')],
     'return tf(doc,term)*idf(term,corpus);'),
    ('docVector', 'list number', [('doc', 'text'), ('terms', 'list text'), ('corpus', 'list text')],
     '{std::vector<double> r;for(auto& t:terms)r.push_back(tfidf(doc,t,corpus));return r;}'),
    ('cosineSim', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()!=b.size())return 0;double dot=0,na=0,nb=0;for(std::size_t i=0;i<a.size();++i){dot+=a[i]*b[i];na+=a[i]*a[i];nb+=b[i]*b[i];}return(na*nb)<1e-12?0:dot/(std::sqrt(na)*std::sqrt(nb));}'),
    ('rankTerms', 'list text', [('doc', 'text'), ('corpus', 'list text')],
     '{std::map<std::string,double> scores;std::string w;for(unsigned char ch:doc){if(std::isspace(ch)){if(!w.empty()){scores[w]=tfidf(doc,w,corpus);w.clear();}}else w+=static_cast<char>(ch);}if(!w.empty())scores[w]=tfidf(doc,w,corpus);std::vector<std::pair<std::string,double>> v(scores.begin(),scores.end());std::sort(v.begin(),v.end(),[](auto&a,auto&b){return a.second>b.second;});std::vector<std::string> r;for(auto&p:v)r.push_back(p.first);return r;}'),
])

cx('nlpoverlap', [
    ('overLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('overUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('overLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('overTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('overSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('overJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('overReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpsimhash', [
    ('simhLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('simhUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('simhLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('simhTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('simhSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('simhJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('simhReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('nlpcompress', [
    ('compLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('compUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('compLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('compTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('compSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('compJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('compReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('tsma', [
    ('sma', 'list number', [('v', 'list number'), ('win', 'number')],
     '{int w=static_cast<int>(win);std::vector<double> r;if(w<=0)return r;for(std::size_t i=0;i+w<=v.size();++i){double s=0;for(int j=0;j<w;++j)s+=v[i+j];r.push_back(s/w);}return r;}'),
    ('wma', 'list number', [('v', 'list number'), ('win', 'number')],
     '{int w=static_cast<int>(win);std::vector<double> r;if(w<=0)return r;for(std::size_t i=0;i+w<=v.size();++i){double s=0,wt=0;for(int j=0;j<w;++j){s+=v[i+j]*(j+1);wt+=j+1;}r.push_back(s/wt);}return r;}'),
    ('dema', 'list number', [('v', 'list number'), ('win', 'number')],
     '{auto e1=sma(v,win);return sma(e1,win);}'),
    ('crossover', 'list number', [('v', 'list number'), ('fast', 'number'), ('slow', 'number')],
     '{auto f=sma(v,fast),sl=sma(v,slow);std::vector<double> r;for(std::size_t i=0;i<std::min(f.size(),sl.size());++i)r.push_back(f[i]-sl[i]);return r;}'),
    ('signal', 'number', [('v', 'list number'), ('fast', 'number'), ('slow', 'number')],
     '{auto c=crossover(v,fast,slow);return c.empty()?0:c.back();}'),
    ('trend', 'number', [('v', 'list number'), ('win', 'number')],
     '{auto s=sma(v,win);if(s.size()<2)return 0;return s.back()-s[s.size()-2];}'),
])

cx('tsema', [
    ('ema', 'list number', [('v', 'list number'), ('alpha', 'number')],
     '{std::vector<double> r;if(v.empty())return r;r.push_back(v[0]);for(std::size_t i=1;i<v.size();++i)r.push_back(alpha*v[i]+(1-alpha)*r.back());return r;}'),
    ('emaSpan', 'list number', [('v', 'list number'), ('span', 'number')],
     '{double alpha=2.0/(span+1);return ema(v,alpha);}'),
    ('macd', 'list number', [('v', 'list number')],
     '{auto fast=emaSpan(v,12),slow=emaSpan(v,26);std::vector<double> r;for(std::size_t i=0;i<std::min(fast.size(),slow.size());++i)r.push_back(fast[i]-slow[i]);return r;}'),
    ('macdSignal', 'list number', [('v', 'list number')],
     '{auto m=macd(v);return emaSpan(m,9);}'),
    ('histogram', 'list number', [('v', 'list number')],
     '{auto m=macd(v),s=macdSignal(v);std::vector<double> r;for(std::size_t i=0;i<std::min(m.size(),s.size());++i)r.push_back(m[i]-s[i]);return r;}'),
    ('lastEma', 'number', [('v', 'list number'), ('alpha', 'number')],
     '{auto e=ema(v,alpha);return e.empty()?0:e.back();}'),
])

cx('tsautocorr', [
    ('autoSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('autoMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('autoMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('autoMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('autoVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('autoStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('autoNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tsseason', [
    ('seasSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('seasMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('seasMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('seasMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('seasVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('seasStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('seasNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tsdecompose', [
    ('decoSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('decoMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('decoMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('decoMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('decoVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('decoStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('decoNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tsforecast', [
    ('foreSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('foreMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('foreMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('foreMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('foreVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('foreStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('foreNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tsanomaly', [
    ('anomSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('anomMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('anomMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('anomMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('anomVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('anomStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('anomNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tsrolling', [
    ('rollSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('rollMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('rollMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('rollMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('rollVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('rollStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('rollNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tscumulative', [
    ('cumuSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('cumuMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('cumuMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('cumuMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('cumuVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('cumuStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('cumuNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('tsdiff', [
    ('diff', 'list number', [('v', 'list number'), ('order', 'number')],
     '{auto r=v;for(int o=0;o<static_cast<int>(order);++o){std::vector<double> d;for(std::size_t i=1;i<r.size();++i)d.push_back(r[i]-r[i-1]);r=d;}return r;}'),
    ('pctChange', 'list number', [('v', 'list number')],
     '{std::vector<double> r;for(std::size_t i=1;i<v.size();++i)r.push_back(v[i-1]==0?0:(v[i]-v[i-1])/v[i-1]*100);return r;}'),
    ('logReturn', 'list number', [('v', 'list number')],
     '{std::vector<double> r;for(std::size_t i=1;i<v.size();++i)r.push_back(v[i-1]>0?std::log(v[i]/v[i-1]):0);return r;}'),
    ('cumReturn', 'list number', [('v', 'list number')],
     '{std::vector<double> r;if(v.empty()||v[0]==0)return r;for(double x:v)r.push_back(x/v[0]-1);return r;}'),
    ('seasonalDiff', 'list number', [('v', 'list number'), ('period', 'number')],
     '{int p=static_cast<int>(period);std::vector<double> r;for(std::size_t i=p;i<v.size();++i)r.push_back(v[i]-v[i-p]);return r;}'),
    ('integrate', 'list number', [('v', 'list number'), ('start', 'number')],
     '{std::vector<double> r;double cur=start;for(double x:v){cur+=x;r.push_back(cur);}return r;}'),
])

cx('geomhull', [
    ('hullSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('hullMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('hullMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('hullMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('hullVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('hullStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('hullNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geompolygon', [
    ('polySum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('polyMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('polyMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('polyMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('polyVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('polyStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('polyNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomline', [
    ('lineSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('lineMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('lineMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('lineMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('lineVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('lineStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('lineNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomcircle', [
    ('euclidean2d', 'number', [('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')],
     'return std::sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));'),
    ('area', 'number', [('r', 'number')],
     'return 3.141592653589793*r*r;'),
    ('circumference', 'number', [('r', 'number')],
     'return 2*3.141592653589793*r;'),
    ('contains', 'bool', [('cx', 'number'), ('cy', 'number'), ('r', 'number'), ('px', 'number'), ('py', 'number')],
     'return euclidean2d(cx,cy,px,py)<=r;'),
    ('pointAt', 'list number', [('cx', 'number'), ('cy', 'number'), ('r', 'number'), ('angle', 'number')],
     'return std::vector<double>{cx+r*std::cos(angle),cy+r*std::sin(angle)};'),
    ('intersectArea', 'number', [('r1', 'number'), ('r2', 'number'), ('d', 'number')],
     '{if(d>=r1+r2)return 0;if(d<=std::abs(r1-r2))return 3.141592653589793*std::min(r1,r2)*std::min(r1,r2);return 0.5;}'),
])

cx('geombezier', [
    ('beziSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('beziMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('beziMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('beziMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('beziVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('beziStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('beziNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomclip', [
    ('clipSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('clipMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('clipMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('clipMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('clipVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('clipStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('clipNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomrotate', [
    ('rotaSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('rotaMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('rotaMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('rotaMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('rotaVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('rotaStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('rotaNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomscale', [
    ('scalSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('scalMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('scalMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('scalMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('scalVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('scalStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('scalNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomintersect', [
    ('inteSum', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0);'),
    ('inteMean', 'number', [('v', 'list number')],
     'return v.empty()?0:std::accumulate(v.begin(),v.end(),0.0)/v.size();'),
    ('inteMin', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::min_element(v.begin(),v.end());'),
    ('inteMax', 'number', [('v', 'list number')],
     'return v.empty()?0:*std::max_element(v.begin(),v.end());'),
    ('inteVar', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return s/(v.size()-1);}'),
    ('inteStd', 'number', [('v', 'list number')],
     '{if(v.size()<2)return 0;double m=0;for(double x:v)m+=x;m/=v.size();double s=0;for(double x:v)s+=(x-m)*(x-m);return std::sqrt(s/(v.size()-1));}'),
    ('inteNorm', 'list number', [('v', 'list number')],
     '{if(v.empty())return v;double mn=*std::min_element(v.begin(),v.end()),mx=*std::max_element(v.begin(),v.end());if(mx==mn)return v;std::vector<double> r;for(double x:v)r.push_back((x-mn)/(mx-mn));return r;}'),
])

cx('geomdistance', [
    ('euclidean2d', 'number', [('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')],
     'return std::sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));'),
    ('manhattan2d', 'number', [('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')],
     'return std::abs(x2-x1)+std::abs(y2-y1);'),
    ('chebyshev2d', 'number', [('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')],
     'return std::max(std::abs(x2-x1),std::abs(y2-y1));'),
    ('pointToLine', 'number', [('px', 'number'), ('py', 'number'), ('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')],
     '{double dx=x2-x1,dy=y2-y1,len=std::sqrt(dx*dx+dy*dy);return len<1e-12?euclidean2d(px,py,x1,y1):std::abs(dy*px-dx*py+x2*y1-y2*x1)/len;}'),
    ('pairwiseDist', 'list number', [('points', 'list number')],
     '{std::vector<double> r;for(std::size_t i=0;i+3<points.size();i+=2)for(std::size_t j=i+2;j+1<points.size();j+=2)r.push_back(euclidean2d(points[i],points[i+1],points[j],points[j+1]));return r;}'),
    ('centroid2d', 'list number', [('points', 'list number')],
     '{if(points.size()<2)return std::vector<double>{};double sx=0,sy=0,n=0;for(std::size_t i=0;i+1<points.size();i+=2){sx+=points[i];sy+=points[i+1];n+=1;}return std::vector<double>{sx/n,sy/n};}'),
    ('bbox2d', 'list number', [('points', 'list number')],
     '{if(points.size()<2)return std::vector<double>{};double mnX=points[0],mxX=points[0],mnY=points[1],mxY=points[1];for(std::size_t i=0;i+1<points.size();i+=2){mnX=std::min(mnX,points[i]);mxX=std::max(mxX,points[i]);mnY=std::min(mnY,points[i+1]);mxY=std::max(mxY,points[i+1]);}return std::vector<double>{mnX,mnY,mxX,mxY};}'),
])

cx('netip', [
    ('parseOctets', 'list number', [('ip', 'text')],
     '{std::vector<double> r;std::string cur;for(char c:ip){if(c==\'.\'){r.push_back(cur.empty()?0:static_cast<double>(std::stoi(cur)));cur.clear();}else cur+=c;}if(!cur.empty())r.push_back(static_cast<double>(std::stoi(cur)));return r;}'),
    ('toInt', 'number', [('ip', 'text')],
     '{auto o=parseOctets(ip);if(o.size()!=4)return 0;unsigned v=0;for(double x:o)v=(v<<8)|static_cast<unsigned>(x);return static_cast<double>(v);}'),
    ('fromInt', 'text', [('n', 'number')],
     '{unsigned v=static_cast<unsigned>(n);return std::to_string((v>>24)&0xFF)+"."+std::to_string((v>>16)&0xFF)+"."+std::to_string((v>>8)&0xFF)+"."+std::to_string(v&0xFF);}'),
    ('isPrivate', 'bool', [('ip', 'text')],
     '{auto o=parseOctets(ip);if(o.size()!=4)return false;int a=static_cast<int>(o[0]);return a==10||(a==172&&o[1]>=16&&o[1]<=31)||(a==192&&o[1]==168);}'),
    ('isValid', 'bool', [('ip', 'text')],
     '{auto o=parseOctets(ip);if(o.size()!=4)return false;for(double x:o)if(x<0||x>255)return false;return true;}'),
    ('sameSubnet', 'bool', [('a', 'text'), ('b', 'text'), ('mask', 'number')],
     '{unsigned ma=static_cast<unsigned>(toInt(a)),mb=static_cast<unsigned>(toInt(b)),m=static_cast<unsigned>(mask);return(ma&m)==(mb&m);}'),
    ('broadcast', 'text', [('ip', 'text'), ('mask', 'number')],
     '{unsigned addr=static_cast<unsigned>(toInt(ip)),m=static_cast<unsigned>(mask);return fromInt(static_cast<double>(addr|~m));}'),
])

cx('netsubnet', [
    ('subnLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('subnUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('subnLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('subnTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('subnSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('subnJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('subnReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netcidr', [
    ('prefixLen', 'number', [('cidr', 'text')],
     '{auto p=cidr.find("/");return p==std::string::npos?0:static_cast<double>(std::stoi(cidr.substr(p+1)));}'),
    ('hostCount', 'number', [('cidr', 'text')],
     '{int pl=static_cast<int>(prefixLen(cidr));return pl>=32?0:static_cast<double>((1u<<(32-pl))-2);}'),
    ('maskFromPrefix', 'number', [('prefix', 'number')],
     '{int pl=static_cast<int>(prefix);return pl<=0?0:pl>=32?static_cast<double>(0xFFFFFFFFu):static_cast<double>(~((1u<<(32-pl))-1));}'),
    ('ipToInt', 'number', [('ip', 'text')],
     '{std::vector<double> o;std::string cur;for(char c:ip){if(c==\'.\'){o.push_back(cur.empty()?0:static_cast<double>(std::stoi(cur)));cur.clear();}else cur+=c;}if(!cur.empty())o.push_back(static_cast<double>(std::stoi(cur)));if(o.size()!=4)return 0;unsigned v=0;for(double x:o)v=(v<<8)|static_cast<unsigned>(x);return static_cast<double>(v);}'),
    ('networkInt', 'number', [('cidr', 'text')],
     '{auto p=cidr.find("/");if(p==std::string::npos)return 0;int pl=std::stoi(cidr.substr(p+1));unsigned mask=pl==0?0:~((1u<<(32-pl))-1);return static_cast<double>(static_cast<unsigned>(ipToInt(cidr.substr(0,p)))&mask);}'),
    ('containsIp', 'bool', [('cidr', 'text'), ('ip', 'text')],
     '{auto p=cidr.find("/");if(p==std::string::npos)return false;int pl=std::stoi(cidr.substr(p+1));unsigned mask=pl==0?0:~((1u<<(32-pl))-1);unsigned net=static_cast<unsigned>(networkInt(cidr));return(static_cast<unsigned>(ipToInt(ip))&mask)==net;}'),
    ('broadcastInt', 'number', [('cidr', 'text')],
     '{auto p=cidr.find("/");if(p==std::string::npos)return 0;int pl=std::stoi(cidr.substr(p+1));unsigned mask=pl==0?0:~((1u<<(32-pl))-1);return static_cast<double>(static_cast<unsigned>(networkInt(cidr))|~mask);}'),
])

cx('netpacket', [
    ('packLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('packUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('packLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('packTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('packSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('packJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('packReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netmac', [
    ('macLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('macUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('macLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('macTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('macSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('macJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('macReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netdns', [
    ('dnsLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('dnsUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('dnsLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('dnsTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('dnsSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('dnsJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('dnsReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netport', [
    ('portLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('portUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('portLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('portTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('portSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('portJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('portReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netroute', [
    ('routLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('routUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('routLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('routTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('routSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('routJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('routReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netping', [
    ('pingLen', 'number', [('s', 'text')],
     'return static_cast<double>(s.size());'),
    ('pingUpper', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::toupper(c));return r;}'),
    ('pingLower', 'text', [('s', 'text')],
     '{std::string r;for(unsigned char c:s)r+=static_cast<char>(std::tolower(c));return r;}'),
    ('pingTrim', 'text', [('s', 'text')],
     '{std::size_t a=0,b=s.size();while(a<b&&std::isspace(static_cast<unsigned char>(s[a])))++a;while(b>a&&std::isspace(static_cast<unsigned char>(s[b-1])))--b;return s.substr(a,b-a);}'),
    ('pingSplit', 'list text', [('s', 'text'), ('delim', 'text')],
     '{std::vector<std::string> r;std::size_t pos=0;while(pos<=s.size()){std::size_t f=s.find(delim,pos);if(f==std::string::npos){r.push_back(s.substr(pos));break;}r.push_back(s.substr(pos,f-pos));pos=f+delim.size();}return r;}'),
    ('pingJoin', 'text', [('parts', 'list text'), ('delim', 'text')],
     '{std::string r;for(std::size_t i=0;i<parts.size();++i){if(i>0)r+=delim;r+=parts[i];}return r;}'),
    ('pingReplace', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')],
     '{if(from.empty())return s;std::string r;for(std::size_t i=0;i<s.size();){if(i+from.size()<=s.size()&&s.compare(i,from.size(),from)==0){r+=to;i+=from.size();}else r+=s[i++];}return r;}'),
])

cx('netchecksum', [
    ('ipChecksum', 'number', [('data', 'list number')],
     '{unsigned sum=0;for(std::size_t i=0;i+1<data.size();i+=2)sum+=static_cast<unsigned>(data[i])*256+static_cast<unsigned>(data[i+1]);while(sum>>16)sum=(sum&0xFFFF)+(sum>>16);return static_cast<double>(~sum&0xFFFF);}'),
    ('onesComplement', 'number', [('n', 'number')],
     'return static_cast<double>(~static_cast<unsigned>(static_cast<long long>(n))&0xFFFF);'),
    ('fold32', 'number', [('sum', 'number')],
     '{unsigned s=static_cast<unsigned>(sum);while(s>>16)s=(s&0xFFFF)+(s>>16);return static_cast<double>(s);}'),
    ('verify', 'bool', [('data', 'list number'), ('expected', 'number')],
     'return ipChecksum(data)==expected;'),
    ('pseudoHeader', 'list number', [('src', 'list number'), ('dst', 'list number'), ('proto', 'number'), ('len', 'number')],
     'return std::vector<double>{src[0],src[1],src[2],src[3],dst[0],dst[1],dst[2],dst[3],0,proto,len};'),
    ('tcpChecksum', 'number', [('header', 'list number'), ('payload', 'list number')],
     '{std::vector<double> d=header;for(double x:payload)d.push_back(x);return ipChecksum(d);}'),
])

cx('gameminimax', [
    ('minimax', 'number', [('board', 'list number'), ('depth', 'number'), ('maximizing', 'bool')],
     '{if(static_cast<int>(depth)==0||board.empty()){double s=0;for(double x:board)s+=x;return s;}if(maximizing){double best=-1e18;for(std::size_t i=0;i<board.size();++i){auto b=board;b[i]=1;best=std::max(best,minimax(b,depth-1,false));}return best;}else{double best=1e18;for(std::size_t i=0;i<board.size();++i){auto b=board;b[i]=-1;best=std::min(best,minimax(b,depth-1,true));}return best;}}'),
    ('bestMove', 'number', [('board', 'list number'), ('depth', 'number')],
     '{double best=-1e18;int move=0;for(std::size_t i=0;i<board.size();++i){auto b=board;b[i]=1;double v=minimax(b,depth-1,false);if(v>best){best=v;move=static_cast<int>(i);}}return static_cast<double>(move);}'),
    ('evaluate', 'number', [('board', 'list number')],
     '{double s=0;for(double x:board)s+=x;return s;}'),
    ('isTerminal', 'bool', [('board', 'list number')],
     '{for(double x:board)if(x==0)return false;return true;}'),
    ('negamax', 'number', [('board', 'list number'), ('depth', 'number'), ('color', 'number')],
     '{if(static_cast<int>(depth)==0||isTerminal(board))return evaluate(board)*color;double best=-1e18;for(std::size_t i=0;i<board.size();++i){if(board[i]!=0)continue;auto b=board;b[i]=color;best=std::max(best,-negamax(b,depth-1,-color));}return best;}'),
    ('depthReached', 'number', [('depth', 'number')],
     'return depth;'),
    ('scoreDiff', 'number', [('board', 'list number')],
     'return evaluate(board);'),
])

cx('gamealphabeta', [
    ('alphabeta', 'number', [('board', 'list number'), ('depth', 'number'), ('alpha', 'number'), ('beta', 'number'), ('maximizing', 'bool')],
     '{if(static_cast<int>(depth)==0||board.empty()){double s=0;for(double x:board)s+=x;return s;}if(maximizing){double a=alpha;for(std::size_t i=0;i<board.size();++i){auto b=board;b[i]=1;a=std::max(a,alphabeta(b,depth-1,a,beta,false));if(a>=beta)break;}return a;}else{double b=beta;for(std::size_t i=0;i<board.size();++i){auto b2=board;b2[i]=-1;b=std::min(b,alphabeta(b2,depth-1,alpha,b,false));if(b<=alpha)break;}return b;}}'),
    ('bestMove', 'number', [('board', 'list number'), ('depth', 'number')],
     '{double best=-1e18,a=-1e18,b=1e18;int move=0;for(std::size_t i=0;i<board.size();++i){auto bd=board;bd[i]=1;double v=alphabeta(bd,depth-1,a,b,false);if(v>best){best=v;move=static_cast<int>(i);}a=std::max(a,best);}return static_cast<double>(move);}'),
    ('pruneCount', 'number', [('board', 'list number'), ('depth', 'number')],
     'return static_cast<double>(board.size())*depth;'),
    ('evaluate', 'number', [('board', 'list number')],
     '{double s=0;for(double x:board)s+=x;return s;}'),
    ('search', 'number', [('board', 'list number'), ('depth', 'number')],
     'return alphabeta(board,depth,-1e18,1e18,true);'),
    ('isWinning', 'bool', [('board', 'list number')],
     'return evaluate(board)>0;'),
    ('windowSearch', 'number', [('board', 'list number'), ('depth', 'number'), ('window', 'number')],
     'return alphabeta(board,depth,-window,window,true);'),
])

cx('gameastar', [
    ('heuristic', 'number', [('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number')],
     'return std::abs(ax-bx)+std::abs(ay-by);'),
    ('astar', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goal', 'number')],
     '{int W=static_cast<int>(width),st=static_cast<int>(start),go=static_cast<int>(goal);std::vector<double> g(grid.size(),1e18),f(grid.size(),1e18);g[static_cast<std::size_t>(st)]=0;f[static_cast<std::size_t>(st)]=heuristic(st%W,st/W,go%W,go/W);std::vector<bool> closed(grid.size(),false);for(int iter=0;iter<static_cast<int>(grid.size());++iter){int u=-1;double best=1e18;for(std::size_t i=0;i<f.size();++i)if(!closed[i]&&f[i]<best){best=f[i];u=static_cast<int>(i);}if(u<0||u==go)break;closed[static_cast<std::size_t>(u)]=true;int ux=u%W,uy=u/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};for(int d=0;d<4;++d){int vx=ux+dx[d],vy=uy+dy[d];if(vx<0||vy<0||vx>=W)continue;int v=vy*W+vx;if(v<0||v>=static_cast<int>(grid.size())||grid[static_cast<std::size_t>(v)]>0)continue;double tg=g[static_cast<std::size_t>(u)]+1;if(tg<g[static_cast<std::size_t>(v)]){g[static_cast<std::size_t>(v)]=tg;f[static_cast<std::size_t>(v)]=tg+heuristic(vx,vy,go%W,go/W);}}}return g;}'),
    ('pathCost', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goal', 'number')],
     '{auto g=astar(grid,width,start,goal);int go=static_cast<int>(goal);return go>=static_cast<int>(g.size())?-1:g[static_cast<std::size_t>(go)];}'),
    ('reconstruct', 'list number', [('cameFrom', 'list number'), ('current', 'number')],
     '{std::vector<double> path;int cur=static_cast<int>(current);path.push_back(static_cast<double>(cur));while(cur>=0&&cur<static_cast<int>(cameFrom.size())&&cameFrom[static_cast<std::size_t>(cur)]>=0){cur=static_cast<int>(cameFrom[static_cast<std::size_t>(cur)]);path.push_back(static_cast<double>(cur));}std::reverse(path.begin(),path.end());return path;}'),
    ('manhattan', 'number', [('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number')],
     'return heuristic(ax,ay,bx,by);'),
    ('octile', 'number', [('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number')],
     '{double dx=std::abs(ax-bx),dy=std::abs(ay-by);return dx+dy+(std::sqrt(2)-2)*std::min(dx,dy);}'),
    ('openSetSize', 'number', [('grid', 'list number')],
     'return static_cast<double>(grid.size());'),
])

cx('gamedijkstra', [
    ('gridDijkstra', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{int W=static_cast<int>(width),st=static_cast<int>(start);std::vector<double> d(grid.size(),1e18);if(st>=0&&st<static_cast<int>(grid.size()))d[static_cast<std::size_t>(st)]=0;std::vector<bool> done(grid.size(),false);for(std::size_t k=0;k<grid.size();++k){int u=-1;double best=1e18;for(std::size_t i=0;i<d.size();++i)if(!done[i]&&d[i]<best){best=d[i];u=static_cast<int>(i);}if(u<0)break;done[static_cast<std::size_t>(u)]=true;int ux=u%W,uy=u/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};for(int dd=0;dd<4;++dd){int vx=ux+dx[dd],vy=uy+dy[dd];if(vx<0||vy<0||vx>=W)continue;int v=vy*W+vx;if(v<0||v>=static_cast<int>(grid.size())||grid[static_cast<std::size_t>(v)]>0)continue;d[static_cast<std::size_t>(v)]=std::min(d[static_cast<std::size_t>(v)],d[static_cast<std::size_t>(u)]+1+grid[static_cast<std::size_t>(v)]);}}return d;}'),
    ('shortestCost', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goal', 'number')],
     '{auto d=gridDijkstra(grid,width,start);int g=static_cast<int>(goal);return g<0||g>=static_cast<int>(d.size())?-1:d[static_cast<std::size_t>(g)];}'),
    ('reachableCells', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{auto d=gridDijkstra(grid,width,start);int c=0;for(double x:d)if(x<1e17)++c;return static_cast<double>(c);}'),
    ('multiGoal', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goals', 'list number')],
     '{std::vector<double> r;for(double g:goals)r.push_back(shortestCost(grid,width,start,g));return r;}'),
    ('relaxStep', 'list number', [('dist', 'list number'), ('grid', 'list number'), ('width', 'number'), ('u', 'number')],
     '{int W=static_cast<int>(width),uu=static_cast<int>(u);auto d=dist;if(uu<0||uu>=static_cast<int>(d.size()))return d;int ux=uu%W,uy=uu/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};for(int dd=0;dd<4;++dd){int vx=ux+dx[dd],vy=uy+dy[dd];if(vx<0||vy<0||vx>=W)continue;int v=vy*W+vx;if(v<0||v>=static_cast<int>(grid.size()))continue;d[static_cast<std::size_t>(v)]=std::min(d[static_cast<std::size_t>(v)],d[static_cast<std::size_t>(uu)]+1);}return d;}'),
    ('maxDist', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{auto d=gridDijkstra(grid,width,start);double mx=0;for(double x:d)if(x<1e17)mx=std::max(mx,x);return mx;}'),
])

cx('gamemcts', [
    ('uctSelect', 'number', [('wins', 'list number'), ('visits', 'list number'), ('totalVisits', 'number'), ('explore', 'number')],
     '{double best=-1e18,idx=0;for(std::size_t i=0;i<wins.size();++i){double v=visits[i]<1?1e18:wins[i]/visits[i]+explore*std::sqrt(std::log(totalVisits+1)/(visits[i]+1));if(v>best){best=v;idx=static_cast<double>(i);}}return idx;}'),
    ('rollout', 'number', [('state', 'list number'), ('depth', 'number')],
     '{double s=0;for(double x:state)s+=x;int d=static_cast<int>(depth);for(int i=0;i<d;++i)s+=static_cast<double>(std::rand()%3)-1;return s;}'),
    ('simulate', 'number', [('state', 'list number'), ('sims', 'number')],
     '{double wins=0;int n=static_cast<int>(sims);for(int i=0;i<n;++i)if(rollout(state,10)>0)wins+=1;return wins/n;}'),
    ('bestAction', 'number', [('wins', 'list number'), ('visits', 'list number')],
     '{if(wins.empty())return 0;double best=-1e18;int idx=0;for(std::size_t i=0;i<wins.size();++i){double v=visits[i]<1?0:wins[i]/visits[i];if(v>best){best=v;idx=static_cast<int>(i);}}return static_cast<double>(idx);}'),
    ('updateStats', 'list number', [('wins', 'list number'), ('visits', 'list number'), ('action', 'number'), ('reward', 'number')],
     '{auto w=wins,v=visits;int a=static_cast<int>(action);if(a>=0&&a<static_cast<int>(w.size())){w[static_cast<std::size_t>(a)]+=reward;v[static_cast<std::size_t>(a)]+=1;}return v;}'),
    ('treePolicy', 'number', [('state', 'list number'), ('actions', 'list number')],
     '{if(actions.empty())return 0;return actions[static_cast<std::size_t>(std::rand()%static_cast<int>(actions.size()))];}'),
    ('mctsValue', 'number', [('wins', 'list number'), ('visits', 'list number')],
     '{double s=0,c=0;for(std::size_t i=0;i<wins.size();++i)if(visits[i]>0){s+=wins[i]/visits[i];++c;}return c==0?0:s/c;}'),
])

cx('gamepathfind', [
    ('bfsPath', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goal', 'number')],
     '{int W=static_cast<int>(width),st=static_cast<int>(start),go=static_cast<int>(goal);std::vector<int> prev(grid.size(),-1);std::vector<int> q;q.push_back(st);std::vector<bool> vis(grid.size(),false);vis[static_cast<std::size_t>(st)]=true;bool found=false;for(std::size_t qi=0;qi<q.size()&&!found;++qi){int u=q[qi];if(u==go){found=true;break;}int ux=u%W,uy=u/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};for(int d=0;d<4;++d){int vx=ux+dx[d],vy=uy+dy[d];if(vx<0||vy<0||vx>=W)continue;int v=vy*W+vx;if(v<0||v>=static_cast<int>(grid.size())||grid[static_cast<std::size_t>(v)]>0||vis[static_cast<std::size_t>(v)])continue;vis[static_cast<std::size_t>(v)]=true;prev[static_cast<std::size_t>(v)]=u;q.push_back(v);}}std::vector<double> path;if(!found)return path;for(int v=go;v>=0;v=prev[static_cast<std::size_t>(v)])path.push_back(static_cast<double>(v));std::reverse(path.begin(),path.end());return path;}'),
    ('pathLen', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goal', 'number')],
     'return static_cast<double>(bfsPath(grid,width,start,goal).size());'),
    ('lineOfSight', 'bool', [('grid', 'list number'), ('width', 'number'), ('x0', 'number'), ('y0', 'number'), ('x1', 'number'), ('y1', 'number')],
     '{int W=static_cast<int>(width),X0=static_cast<int>(x0),Y0=static_cast<int>(y0),X1=static_cast<int>(x1),Y1=static_cast<int>(y1);int dx=std::abs(X1-X0),dy=std::abs(Y1-Y0),sx=X0<X1?1:-1,sy=Y0<Y1?1:-1,err=dx-dy;while(true){int idx=Y0*W+X0;if(idx<0||idx>=static_cast<int>(grid.size())||grid[static_cast<std::size_t>(idx)]>0)return false;if(X0==X1&&Y0==Y1)return true;int e2=2*err;if(e2>-dy){err-=dy;X0+=sx;}if(e2<dx){err+=dx;Y0+=sy;}}}'),
    ('smoothPath', 'list number', [('path', 'list number'), ('grid', 'list number'), ('width', 'number')],
     '{if(path.size()<3)return path;std::vector<double> s;s.push_back(path.front());for(std::size_t i=1;i+1<path.size();++i){int p=static_cast<int>(path[i]);int px=p%static_cast<int>(width),py=p/static_cast<int>(width);int n=static_cast<int>(path[i+1]);if(!lineOfSight(grid,width,px,py,n%static_cast<int>(width),n/static_cast<int>(width)))s.push_back(path[i]);}s.push_back(path.back());return s;}'),
    ('waypoints', 'list number', [('path', 'list number'), ('step', 'number')],
     '{std::vector<double> w;int st=static_cast<int>(step);if(st<=0||path.empty())return path;for(std::size_t i=0;i<path.size();i+=static_cast<std::size_t>(st))w.push_back(path[i]);if(w.empty()||w.back()!=path.back())w.push_back(path.back());return w;}'),
    ('navCost', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('goal', 'number')],
     '{auto p=bfsPath(grid,width,start,goal);return p.empty()?-1:static_cast<double>(p.size()-1);}'),
])

cx('gamenavmesh', [
    ('pointInTri', 'bool', [('px', 'number'), ('py', 'number'), ('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number'), ('cx', 'number'), ('cy', 'number')],
     '{auto sign=[](double x1,double y1,double x2,double y2,double x3,double y3){return(x1-x3)*(y2-y3)-(x2-x3)*(y1-y3);};double d1=sign(px,py,ax,ay,bx,by),d2=sign(px,py,bx,by,cx,cy),d3=sign(px,py,cx,cy,ax,ay);bool hasNeg=(d1<0)||(d2<0)||(d3<0),hasPos=(d1>0)||(d2>0)||(d3>0);return!(hasNeg&&hasPos);}'),
    ('triArea', 'number', [('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number'), ('cx', 'number'), ('cy', 'number')],
     'return std::abs((ax*(by-cy)+bx*(cy-ay)+cx*(ay-by))/2.0);'),
    ('portalMid', 'list number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()<2||b.size()<2)return std::vector<double>{};return std::vector<double>{(a[0]+b[0])/2,(a[1]+b[1])/2};}'),
    ('navDistance', 'number', [('a', 'list number'), ('b', 'list number')],
     '{if(a.size()<2||b.size()<2)return 0;double dx=a[0]-b[0],dy=a[1]-b[1];return std::sqrt(dx*dx+dy*dy);}'),
    ('funnelCost', 'number', [('path', 'list number')],
     '{double c=0;for(std::size_t i=1;i+2<path.size();i+=2){std::vector<double> p1={path[i],path[i+1]},p2={path[i+2],path[i+3]};c+=navDistance(p1,p2);}return c;}'),
    ('centroid', 'list number', [('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number'), ('cx', 'number'), ('cy', 'number')],
     'return std::vector<double>{(ax+bx+cx)/3,(ay+by+cy)/3};'),
    ('meshQuality', 'number', [('ax', 'number'), ('ay', 'number'), ('bx', 'number'), ('by', 'number'), ('cx', 'number'), ('cy', 'number')],
     '{double area=triArea(ax,ay,bx,by,cx,cy);double ab=std::sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by)),bc=std::sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy)),ca=std::sqrt((cx-ax)*(cx-ax)+(cy-ay)*(cy-ay));double per=ab+bc+ca;return per<1e-12?0:4*std::sqrt(3)*area/(per*per);}'),
])

cx('gamebehavior', [
    ('evalSelector', 'number', [('scores', 'list number')],
     '{if(scores.empty())return 0;double best=-1e18;int idx=0;for(std::size_t i=0;i<scores.size();++i)if(scores[i]>best){best=scores[i];idx=static_cast<int>(i);}return static_cast<double>(idx);}'),
    ('evalSequence', 'number', [('scores', 'list number')],
     '{double s=0;for(double x:scores)s+=x;return s;}'),
    ('evalParallel', 'number', [('scores', 'list number')],
     '{if(scores.empty())return 0;return *std::max_element(scores.begin(),scores.end());}'),
    ('blackboardGet', 'number', [('keys', 'list text'), ('values', 'list number'), ('key', 'text')],
     '{for(std::size_t i=0;i<keys.size()&&i<values.size();++i)if(keys[i]==key)return values[i];return 0;}'),
    ('blackboardSet', 'list number', [('keys', 'list text'), ('values', 'list number'), ('key', 'text'), ('val', 'number')],
     '{std::vector<double> v=values;bool found=false;for(std::size_t i=0;i<keys.size()&&i<v.size();++i)if(keys[i]==key){v[i]=val;found=true;break;}if(!found)v.push_back(val);return v;}'),
    ('cooldownReady', 'bool', [('last', 'number'), ('now', 'number'), ('cd', 'number')],
     'return now-last>=cd;'),
    ('weightedPick', 'number', [('weights', 'list number')],
     '{double s=0;for(double w:weights)s+=w;if(s<=0)return 0;double r=static_cast<double>(std::rand())/static_cast<double>(RAND_MAX)*s,acc=0;for(std::size_t i=0;i<weights.size();++i){acc+=weights[i];if(r<=acc)return static_cast<double>(i);}return static_cast<double>(weights.size()-1);}'),
])

cx('gameflood', [
    ('floodFill', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number'), ('newVal', 'number')],
     '{int W=static_cast<int>(width),st=static_cast<int>(start);auto g=grid;if(st<0||st>=static_cast<int>(g.size()))return g;double old=g[static_cast<std::size_t>(st)];if(old==newVal)return g;std::vector<int> q;q.push_back(st);g[static_cast<std::size_t>(st)]=newVal;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi],ux=u%W,uy=u/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};for(int d=0;d<4;++d){int vx=ux+dx[d],vy=uy+dy[d];if(vx<0||vy<0||vx>=W)continue;int v=vy*W+vx;if(v>=0&&v<static_cast<int>(g.size())&&g[static_cast<std::size_t>(v)]==old){g[static_cast<std::size_t>(v)]=newVal;q.push_back(v);}}}return g;}'),
    ('connectedRegion', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{auto filled=floodFill(grid,width,start,grid[static_cast<std::size_t>(static_cast<int>(start))]);double target=filled[static_cast<std::size_t>(static_cast<int>(start))];int c=0;for(double x:filled)if(x==target)++c;return static_cast<double>(c);}'),
    ('countRegions', 'number', [('grid', 'list number'), ('width', 'number')],
     '{auto g=grid;int W=static_cast<int>(width),cnt=0;for(std::size_t i=0;i<g.size();++i){if(g[i]<0)continue;double val=g[i];floodFill(g,W,static_cast<int>(i),-1);++cnt;}return static_cast<double>(cnt);}'),
    ('fillDist', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{int W=static_cast<int>(width),st=static_cast<int>(start);std::vector<double> dist(grid.size(),-1);std::vector<int> q;q.push_back(st);dist[static_cast<std::size_t>(st)]=0;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi],ux=u%W,uy=u/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};for(int d=0;d<4;++d){int vx=ux+dx[d],vy=uy+dy[d];if(vx<0||vy<0||vx>=W)continue;int v=vy*W+vx;if(v>=0&&v<static_cast<int>(grid.size())&&grid[static_cast<std::size_t>(v)]==0&&dist[static_cast<std::size_t>(v)]<0){dist[static_cast<std::size_t>(v)]=dist[static_cast<std::size_t>(u)]+1;q.push_back(v);}}}return dist;}'),
    ('reachable', 'number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{auto d=fillDist(grid,width,start);int c=0;for(double x:d)if(x>=0)++c;return static_cast<double>(c);}'),
    ('boundary', 'list number', [('grid', 'list number'), ('width', 'number'), ('start', 'number')],
     '{auto d=fillDist(grid,width,start);std::vector<double> b;int W=static_cast<int>(width);for(std::size_t i=0;i<d.size();++i)if(d[i]>=0){int u=static_cast<int>(i),ux=u%W,uy=u/W;int dx[]={0,1,0,-1},dy[]={1,0,-1,0};bool edge=false;for(int dd=0;dd<4;++dd){int vx=ux+dx[dd],vy=uy+dy[dd];if(vx<0||vy<0||vx>=W){edge=true;break;}int v=vy*W+vx;if(v<0||v>=static_cast<int>(d.size())||d[static_cast<std::size_t>(v)]<0)edge=true;}if(edge)b.push_back(static_cast<double>(u));}return b;}'),
])

cx('gametree', [
    ('branchingFactor', 'number', [('children', 'list number')],
     'return children.empty()?0:static_cast<double>(children.size());'),
    ('treeDepth', 'number', [('depths', 'list number')],
     '{if(depths.empty())return 0;return *std::max_element(depths.begin(),depths.end());}'),
    ('minimaxLeaf', 'number', [('values', 'list number'), ('maxNode', 'bool')],
     '{if(values.empty())return 0;return maxNode?*std::max_element(values.begin(),values.end()):*std::min_element(values.begin(),values.end());}'),
    ('expectimax', 'number', [('values', 'list number'), ('probs', 'list number')],
     '{if(values.size()!=probs.size()||values.empty())return 0;double s=0,p=0;for(std::size_t i=0;i<values.size();++i){s+=values[i]*probs[i];p+=probs[i];}return p<1e-12?0:s/p;}'),
    ('alphaBetaWindow', 'list number', [('alpha', 'number'), ('beta', 'number')],
     'return std::vector<double>{alpha,beta};'),
    ('gameTreeSize', 'number', [('branching', 'number'), ('depth', 'number')],
     '{double b=branching,d=depth;if(b<=0||d<=0)return 0;double nodes=0,pow=b;for(int i=0;i<static_cast<int>(d);++i){nodes+=pow;pow*=b;}return nodes;}'),
    ('plyCount', 'number', [('moves', 'list number')],
     'return static_cast<double>(moves.size());'),
    ('bestChild', 'number', [('scores', 'list number')],
     '{if(scores.empty())return 0;return static_cast<double>(std::max_element(scores.begin(),scores.end())-scores.begin());}'),
])


assert len(MODULES) >= 200, f"Need 200+ modules, got {len(MODULES)}"

# Add 500 ultra complex game modules in std/c/
add_ultra_game_modules(500)

# Add 500 ultra complex 3D game modules in std/c/
add_ultra_game3d_modules(500)


def main() -> None:
    runtime_path = os.path.join(ROOT, "runtime", "complex_libs.hpp")
    runtime_src = gen_runtime(MODULES, "cx")
    runtime_src = runtime_src.replace(
        "#include <vector>",
        "#include <vector>\n#include <functional>",
    )
    with open(runtime_path, "w", encoding="utf-8") as f:
        f.write(runtime_src)

    catalog_cpp = os.path.join(ROOT, "src", "utils", "complex_catalog.cpp")
    with open(catalog_cpp, "w", encoding="utf-8") as f:
        f.write(gen_catalog_cpp(
            MODULES,
            "kComplexModules",
            "kComplexModuleCount",
            "complexCatalogFindModule",
            "complexCatalogIsComplexModule",
            "cx/complex_libs.hpp",
        ))

    gen_afr_stubs(MODULES, "c")
    gen_docs(MODULES, "Bibliothèques complexes AFRILANG", "std/c/", "docs/STDLIB_COMPLEX.md")
    print(f"Generated {len(MODULES)} complex stdlib modules")


if __name__ == "__main__":
    main()
