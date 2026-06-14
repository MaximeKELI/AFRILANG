#!/usr/bin/env python3
"""One-shot builder for gen_complex_stdlib.py — run from scripts/ then delete."""
from __future__ import annotations
import os

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

# fmt: off — module bodies below
MODULES_DATA: list[tuple[str, list]] = []

def add(name: str, funcs: list) -> None:
    MODULES_DATA.append((name, funcs))

# ========== GRAPH (20) ==========
add('graphbfs', [
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

add('graphdfs', [
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

# Continue building - I'll add all remaining modules in the builder file
# Due to length, the rest is appended via exec from a data file

print(f"Builder has {len(MODULES_DATA)} modules so far")
print("Need to complete builder")
