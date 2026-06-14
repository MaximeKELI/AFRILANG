#!/usr/bin/env python3
"""One-shot builder: writes scripts/gen_complex_stdlib.py then delete this file."""
from __future__ import annotations
import os
import textwrap

OUT = os.path.join(os.path.dirname(__file__), "gen_complex_stdlib.py")

HEADER = '''#!/usr/bin/env python3
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

'''

FOOTER = '''
assert len(MODULES) >= 200, f"Need 200+ modules, got {len(MODULES)}"


def main() -> None:
    runtime_path = os.path.join(ROOT, "runtime", "complex_libs.hpp")
    with open(runtime_path, "w", encoding="utf-8") as f:
        f.write(gen_runtime(MODULES, "cx"))

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
'''

# fmt: off
ALL_MODULES: dict[str, list] = {}

def M(name: str, funcs: list) -> None:
    ALL_MODULES[name] = funcs

# ========== GRAPH (20) ==========
M('graphbfs', [
    ('bfsDistances', 'list number', [('adj','list number'),('n','number'),('start','number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);if(nn<=0||st<0||st>=nn)return std::vector<double>{};std::vector<double> d(nn,-1);std::vector<int> q;d[st]=0;q.push_back(st);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}return d;}'),
    ('bfsOrder', 'list number', [('adj','list number'),('n','number'),('start','number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> o;if(nn<=0||st<0||st>=nn)return o;std::vector<bool> vis(nn,false);std::vector<int> q;vis[st]=true;q.push_back(st);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];o.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;q.push_back(v);}}}return o;}'),
    ('bfsReachable', 'number', [('adj','list number'),('n','number'),('start','number')],
     '{auto d=bfsDistances(adj,n,start);int c=0;for(double x:d)if(x>=0)++c;return static_cast<double>(c);}'),
    ('bfsLayers', 'list number', [('adj','list number'),('n','number'),('start','number')],
     '{auto d=bfsDistances(adj,n,start);double mx=0;for(double x:d)if(x>mx)mx=x;std::vector<double> L(static_cast<std::size_t>(mx)+1,0);for(double x:d)if(x>=0)L[static_cast<std::size_t>(x)]+=1;return L;}'),
    ('isConnected', 'bool', [('adj','list number'),('n','number')],
     '{auto d=bfsDistances(adj,n,0);for(double x:d)if(x<0)return false;return true;}'),
    ('shortestPathLen', 'number', [('adj','list number'),('n','number'),('start','number'),('goal','number')],
     '{auto d=bfsDistances(adj,n,start);int g=static_cast<int>(goal);return(g<0||g>=static_cast<int>(d.size()))?-1:d[static_cast<std::size_t>(g)];}'),
    ('multiSourceBfs', 'list number', [('adj','list number'),('n','number'),('sources','list number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,-1);std::vector<int> q;for(double s:sources){int u=static_cast<int>(s);if(u>=0&&u<nn&&d[u]<0){d[u]=0;q.push_back(u);}}for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}return d;}'),
])
M('graphdfs', [
    ('dfsOrder', 'list number', [('adj','list number'),('n','number'),('start','number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> o;if(st<0||st>=nn)return o;std::vector<bool> vis(nn,false);std::vector<int> st2;st2.push_back(st);while(!st2.empty()){int u=st2.back();st2.pop_back();if(vis[u])continue;vis[u]=true;o.push_back(static_cast<double>(u));for(int v=nn-1;v>=0;--v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v])st2.push_back(v);}}return o;}'),
    ('dfsRecursiveMark', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);std::vector<double> comp;for(int i=0;i<nn;++i){if(vis[i])continue;std::vector<int> st;st.push_back(i);while(!st.empty()){int u=st.back();st.pop_back();if(vis[u])continue;vis[u]=true;comp.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v])st.push_back(v);}}}return comp;}'),
    ('hasCycleUndirected', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);for(int s=0;s<nn;++s){if(vis[s])continue;std::vector<std::pair<int,int>> st;st.emplace_back(s,-1);vis[s]=true;while(!st.empty()){auto[u,p]=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]<=0||v==p)continue;if(vis[v])return true;vis[v]=true;st.emplace_back(v,u);}}}return false;}'),
    ('countComponents', 'number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);int c=0;for(int s=0;s<nn;++s){if(vis[s])continue;++c;std::vector<int> st;st.push_back(s);vis[s]=true;while(!st.empty()){int u=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;st.push_back(v);}}}}return static_cast<double>(c);}'),
    ('topoSortDfs', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<int> state(nn,0);std::vector<double> order;for(int s=0;s<nn;++s){if(state[s]!=0)continue;std::vector<int> st;st.push_back(s);while(!st.empty()){int u=st.back();if(state[u]==2){st.pop_back();continue;}if(state[u]==1){order.push_back(static_cast<double>(u));state[u]=2;st.pop_back();continue;}state[u]=1;for(int v=nn-1;v>=0;--v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&state[v]==0)st.push_back(v);}}}std::reverse(order.begin(),order.end());return order;}'),
    ('isTree', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);if(nn==0)return true;int edges=0;for(double w:adj)if(w>0)++edges;edges/=2;return edges==nn-1&&!hasCycleUndirected(adj,n);}'),
    ('dfsPathExists', 'bool', [('adj','list number'),('n','number'),('start','number'),('goal','number')],
     '{auto o=dfsOrder(adj,n,start);int g=static_cast<int>(goal);for(double x:o)if(static_cast<int>(x)==g)return true;return false;}'),
])
M('graphdijk', [
    ('dijkstra', 'list number', [('adj','list number'),('n','number'),('start','number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> d(nn,1e18);if(st>=0&&st<nn)d[st]=0;std::vector<bool> done(nn,false);for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!done[i]&&d[i]<best){best=d[i];u=i;}if(u<0)break;done[u]=true;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[v]=std::min(d[v],d[u]+adj[idx]);}}return d;}'),
    ('shortestWeighted', 'number', [('adj','list number'),('n','number'),('start','number'),('goal','number')],
     '{auto d=dijkstra(adj,n,start);int g=static_cast<int>(goal),nn=static_cast<int>(n);return(g<0||g>=nn)?-1:d[static_cast<std::size_t>(g)];}'),
    ('dijkstraPath', 'list number', [('adj','list number'),('n','number'),('start','number'),('goal','number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start),go=static_cast<int>(goal);auto d=dijkstra(adj,n,start);std::vector<int> prev(nn,-1);std::vector<bool> done(nn,false);if(st<0||st>=nn||go<0||go>=nn)return std::vector<double>{};for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!done[i]&&d[i]<best){best=d[i];u=i;}if(u<0)break;done[u]=true;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[u]+adj[idx]<d[v]){d[v]=d[u]+adj[idx];prev[v]=u;}}}std::vector<double> path;if(d[go]>=1e17)return path;for(int v=go;v>=0;v=prev[v])path.push_back(static_cast<double>(v));std::reverse(path.begin(),path.end());return path;}'),
    ('minEdgeWeight', 'number', [('adj','list number'),('n','number')],
     '{double m=1e18;for(double w:adj)if(w>0)m=std::min(m,w);return m>=1e18?0:m;}'),
    ('maxEdgeWeight', 'number', [('adj','list number'),('n','number')],
     '{double m=0;for(double w:adj)if(w>0)m=std::max(m,w);return m;}'),
    ('avgEdgeWeight', 'number', [('adj','list number'),('n','number')],
     '{double s=0,c=0;for(double w:adj)if(w>0){s+=w;++c;}return c==0?0:s/c;}'),
    ('edgeCount', 'number', [('adj','list number'),('n','number')],
     '{int c=0;for(double w:adj)if(w>0)++c;return static_cast<double>(c);}'),
])
M('graphtopo', [
    ('topoSort', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<int> indeg(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)++indeg[v];}std::vector<int> q;for(int i=0;i<nn;++i)if(indeg[i]==0)q.push_back(i);std::vector<double> order;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];order.push_back(static_cast<double>(u));for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&--indeg[v]==0)q.push_back(v);}}return order;}'),
    ('hasCycleDirected', 'bool', [('adj','list number'),('n','number')],
     '{auto t=topoSort(adj,n);return static_cast<int>(t.size())<static_cast<int>(n);}'),
    ('inDegrees', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[v]+=1;}return d;}'),
    ('outDegrees', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[u]+=1;}return d;}'),
    ('sources', 'list number', [('adj','list number'),('n','number')],
     '{auto d=inDegrees(adj,n);std::vector<double> r;for(int i=0;i<static_cast<int>(d.size());++i)if(d[i]==0)r.push_back(static_cast<double>(i));return r;}'),
    ('sinks', 'list number', [('adj','list number'),('n','number')],
     '{auto d=outDegrees(adj,n);std::vector<double> r;for(int i=0;i<static_cast<int>(d.size());++i)if(d[i]==0)r.push_back(static_cast<double>(i));return r;}'),
    ('isDag', 'bool', [('adj','list number'),('n','number')],
     'return !hasCycleDirected(adj,n);'),
])
M('graphcc', [
    ('connectedComponents', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<int> label(nn,-1);int cid=0;for(int s=0;s<nn;++s){if(label[s]>=0)continue;std::vector<int> st;st.push_back(s);label[s]=cid;while(!st.empty()){int u=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&label[v]<0){label[v]=cid;st.push_back(v);}}}++cid;}std::vector<double> r;for(int x:label)r.push_back(static_cast<double>(x));return r;}'),
    ('componentCount', 'number', [('adj','list number'),('n','number')],
     '{auto c=connectedComponents(adj,n);if(c.empty())return 0;double mx=0;for(double x:c)mx=std::max(mx,x);return mx+1;}'),
    ('largestComponentSize', 'number', [('adj','list number'),('n','number')],
     '{auto c=connectedComponents(adj,n);std::map<int,int> m;for(double x:c)++m[static_cast<int>(x)];int best=0;for(auto&p:m)best=std::max(best,p.second);return static_cast<double>(best);}'),
    ('sameComponent', 'bool', [('adj','list number'),('n','number'),('a','number'),('b','number')],
     '{auto c=connectedComponents(adj,n);int aa=static_cast<int>(a),bb=static_cast<int>(b);return aa>=0&&bb>=0&&aa<static_cast<int>(c.size())&&bb<static_cast<int>(c.size())&&c[aa]==c[bb];}'),
    ('componentSizes', 'list number', [('adj','list number'),('n','number')],
     '{auto c=connectedComponents(adj,n);int cc=static_cast<int>(componentCount(adj,n));std::vector<double> sz(cc,0);for(double x:c)sz[static_cast<std::size_t>(x)]+=1;return sz;}'),
    ('outDegreeSum', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(nn,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)d[u]+=adj[idx];}return d;}'),
    ('isolateCount', 'number', [('adj','list number'),('n','number')],
     '{auto od=outDegreeSum(adj,n);int c=0;for(double x:od)if(x==0)++c;return static_cast<double>(c);}'),
])
M('graphcycle', [
    ('detectCycleDirected', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<int> state(nn,0);for(int s=0;s<nn;++s){if(state[s]!=0)continue;std::vector<int> st;st.push_back(s);while(!st.empty()){int u=st.back();if(state[u]==2){st.pop_back();continue;}if(state[u]==1)return true;state[u]=1;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&state[v]==0)st.push_back(v);}if(st.back()==u){state[u]=2;st.pop_back();}}}return false;}'),
    ('detectCycleUndirected', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);for(int s=0;s<nn;++s){if(vis[s])continue;std::vector<std::pair<int,int>> st;st.emplace_back(s,-1);vis[s]=true;while(!st.empty()){auto[u,p]=st.back();st.pop_back();for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]<=0||v==p)continue;if(vis[v])return true;vis[v]=true;st.emplace_back(v,u);}}}return false;}'),
    ('cycleEdgeCount', 'number', [('adj','list number'),('n','number')],
     '{int ec=0;for(double w:adj)if(w>0)++ec;return detectCycleUndirected(adj,n)?static_cast<double>(ec):0;}'),
    ('isAcyclic', 'bool', [('adj','list number'),('n','number')],
     'return !detectCycleDirected(adj,n);'),
    ('selfLoopCount', 'number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n),c=0;for(int i=0;i<nn;++i){std::size_t idx=static_cast<std::size_t>(i*nn+i);if(idx<adj.size()&&adj[idx]>0)++c;}return static_cast<double>(c);}'),
    ('removeSelfLoops', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);auto a=adj;for(int i=0;i<nn;++i){std::size_t idx=static_cast<std::size_t>(i*nn+i);if(idx<a.size())a[idx]=0;}return a;}'),
    ('hasParallelEdges', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);for(int u=0;u<nn;++u){int c=0;for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)++c;}if(c>1)return true;}return false;}'),
])
M('graphmst', [
    ('mstWeightPrim', 'number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);if(nn<=0)return 0;std::vector<double> key(nn,1e18);std::vector<bool> in(nn,false);key[0]=0;double total=0;for(int k=0;k<nn;++k){int u=-1;double best=1e18;for(int i=0;i<nn;++i)if(!in[i]&&key[i]<best){best=key[i];u=i;}if(u<0)break;in[u]=true;total+=key[u];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!in[v])key[v]=std::min(key[v],adj[idx]);}}return total;}'),
    ('mstWeightKruskal', 'number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);struct E{int u,v;double w;};std::vector<E> es;for(int u=0;u<nn;++u)for(int v=u+1;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)es.push_back({u,v,adj[idx]});}std::sort(es.begin(),es.end(),[](auto&a,auto&b){return a.w<b.w;});std::vector<int> p(nn);for(int i=0;i<nn;++i)p[i]=i;auto find=[&](int x){while(p[x]!=x)x=p[x];return x;};double total=0;int cnt=0;for(auto&e:es){int ru=find(e.u),rv=find(e.v);if(ru!=rv){p[ru]=rv;total+=e.w;if(++cnt==nn-1)break;}}return total;}'),
    ('mstEdges', 'number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);return static_cast<double>(std::max(0,nn-1));}'),
    ('compareMstAlgos', 'number', [('adj','list number'),('n','number')],
     '{double a=mstWeightPrim(adj,n),b=mstWeightKruskal(adj,n);return std::abs(a-b);}'),
    ('forestMstWeight', 'number', [('adj','list number'),('n','number')],
     'return mstWeightKruskal(adj,n);'),
    ('isConnectedForMst', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<bool> vis(nn,false);std::vector<int> q;q.push_back(0);vis[0]=true;for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&!vis[v]){vis[v]=true;q.push_back(v);}}}for(bool b:vis)if(!b)return false;return true;}'),
])
M('graphshort', [
    ('allPairsBfs', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> r;for(int s=0;s<nn;++s){std::vector<double> d(nn,-1);std::vector<int> q;d[s]=0;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}for(double x:d)r.push_back(x);}return r;}'),
    ('eccentricity', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> ecc(nn,0);for(int s=0;s<nn;++s){std::vector<double> d(nn,-1);std::vector<int> q;d[s]=0;q.push_back(s);for(std::size_t qi=0;qi<q.size();++qi){int u=q[qi];for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0&&d[v]<0){d[v]=d[u]+1;q.push_back(v);}}}double mx=-1;for(double x:d)if(x>mx)mx=x;ecc[s]=mx<0?0:mx;}return ecc;}'),
    ('graphDiameter', 'number', [('adj','list number'),('n','number')],
     '{auto e=eccentricity(adj,n);return e.empty()?0:*std::max_element(e.begin(),e.end());}'),
    ('graphRadius', 'number', [('adj','list number'),('n','number')],
     '{auto e=eccentricity(adj,n);return e.empty()?0:*std::min_element(e.begin(),e.end());}'),
    ('centerNodes', 'list number', [('adj','list number'),('n','number')],
     '{auto e=eccentricity(adj,n);double r=graphRadius(adj,n);std::vector<double> c;for(std::size_t i=0;i<e.size();++i)if(e[i]==r)c.push_back(static_cast<double>(i));return c;}'),
    ('peripheryNodes', 'list number', [('adj','list number'),('n','number')],
     '{auto e=eccentricity(adj,n);double d=graphDiameter(adj,n);std::vector<double> p;for(std::size_t i=0;i<e.size();++i)if(e[i]==d)p.push_back(static_cast<double>(i));return p;}'),
])
M('graphbellman', [
    ('bellmanFord', 'list number', [('adj','list number'),('n','number'),('start','number')],
     '{int nn=static_cast<int>(n),st=static_cast<int>(start);std::vector<double> d(nn,1e18);if(st>=0&&st<nn)d[st]=0;for(int k=0;k<nn-1;++k)for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]!=0&&d[u]<1e17)d[v]=std::min(d[v],d[u]+adj[idx]);}return d;}'),
    ('hasNegCycle', 'bool', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);auto d=bellmanFord(adj,n,0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]!=0&&d[u]<1e17&&d[u]+adj[idx]<d[v])return true;}return false;}'),
    ('negEdgeCount', 'number', [('adj','list number'),('n','number')],
     '{int c=0;for(double w:adj)if(w<0)++c;return static_cast<double>(c);}'),
    ('relaxOnce', 'list number', [('adj','list number'),('n','number'),('dist','list number')],
     '{int nn=static_cast<int>(n);auto d=dist;for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]!=0&&u<static_cast<int>(d.size())&&v<static_cast<int>(d.size())&&d[u]<1e17)d[v]=std::min(d[v],d[u]+adj[idx]);}return d;}'),
    ('pathCost', 'number', [('adj','list number'),('n','number'),('path','list number')],
     '{int nn=static_cast<int>(n);double c=0;for(std::size_t i=1;i<path.size();++i){int u=static_cast<int>(path[i-1]),v=static_cast<int>(path[i]);std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx>=adj.size()||adj[idx]==0)return -1;c+=adj[idx];}return c;}'),
    ('reachableWeighted', 'number', [('adj','list number'),('n','number'),('start','number')],
     '{auto d=bellmanFord(adj,n,start);int c=0;for(double x:d)if(x<1e17)++c;return static_cast<double>(c);}'),
])
M('graphfloyd', [
    ('floydWarshall', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> d(static_cast<std::size_t>(nn*nn),1e18);for(int i=0;i<nn;++i){d[static_cast<std::size_t>(i*nn+i)]=0;for(int j=0;j<nn;++j){std::size_t idx=static_cast<std::size_t>(i*nn+j);if(idx<adj.size()&&adj[idx]>0)d[idx]=adj[idx];}}for(int k=0;k<nn;++k)for(int i=0;i<nn;++i)for(int j=0;j<nn;++j){double via=d[static_cast<std::size_t>(i*nn+k)]+d[static_cast<std::size_t>(k*nn+j)];std::size_t ij=static_cast<std::size_t>(i*nn+j);if(via<d[ij])d[ij]=via;}return d;}'),
    ('pairDistance', 'number', [('adj','list number'),('n','number'),('a','number'),('b','number')],
     '{auto d=floydWarshall(adj,n);int aa=static_cast<int>(a),bb=static_cast<int>(b),nn=static_cast<int>(n);if(aa<0||bb<0||aa>=nn||bb>=nn)return -1;return d[static_cast<std::size_t>(aa*nn+bb)];}'),
    ('closureReachable', 'list number', [('adj','list number'),('n','number')],
     '{auto d=floydWarshall(adj,n);std::vector<double> r;for(double x:d)r.push_back(x<1e17?1:0);return r;}'),
    ('graphDensity', 'number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);if(nn<=1)return 0;int e=0;for(double w:adj)if(w>0)++e;return static_cast<double>(e)/(nn*(nn-1));}'),
    ('avgShortestPath', 'number', [('adj','list number'),('n','number')],
     '{auto d=floydWarshall(adj,n);int nn=static_cast<int>(n);double s=0,c=0;for(int i=0;i<nn;++i)for(int j=0;j<nn;++j)if(i!=j){double x=d[static_cast<std::size_t>(i*nn+j)];if(x<1e17){s+=x;++c;}}return c==0?0:s/c;}'),
    ('transitiveClosure', 'list number', [('adj','list number'),('n','number')],
     '{int nn=static_cast<int>(n);std::vector<double> reach(static_cast<std::size_t>(nn*nn),0);for(int u=0;u<nn;++u)for(int v=0;v<nn;++v){std::size_t idx=static_cast<std::size_t>(u*nn+v);if(idx<adj.size()&&adj[idx]>0)reach[idx]=1;}for(int k=0;k<nn;++k)for(int i=0;i<nn;++i)for(int j=0;j<nn;++j)if(reach[static_cast<std::size_t>(i*nn+k)]&&reach[static_cast<std::size_t>(k*nn+j)])reach[static_cast<std::size_t>(i*nn+j)]=1;return reach;}'),
])

# Continue with remaining graph modules and all other categories...
# Due to file size, load rest from embedded continuation
