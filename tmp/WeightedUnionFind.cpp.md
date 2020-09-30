---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"tmp/WeightedUnionFind.cpp\"\n#include <bits/stdc++.h>\r\n\
    #define rep(i,n) for(int i=0;i<n;i++)\r\n#define all(x) (x).begin(),(x).end()\r\
    \nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long\
    \ LINF=8931145141919364364,LMOD=998244353;\r\ninline long long mod(long long n,long\
    \ long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\ntemplate<class T>\r\nstruct WeightedUnionFind{\r\n    // \u9802\u70B9\u6570\
    (1-indexed)\r\n    const int V;\r\n    // par[x]:=x\u306Eroot\r\n    vector<int>\
    \ par;\r\n    // sz[x]:=x\u3092\u542B\u3080\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \r\n    vector<int> sz;\r\n    // w[x]:=x\u306Eroot\u306B\u5BFE\u3059\u308B\u91CD\
    \u307F\r\n    vector<T> w;\r\n    WeightedUnionFind(const int V):V(V){\r\n   \
    \     par.resize(V+1);\r\n        for(int i=0;i<=V;i++) par[i]=i;\r\n        sz.resize(V+1,1);\r\
    \n        w.resize(V+1);\r\n    }\r\n    // w[y] - w[x] = z\r\n    bool unite(int\
    \ x,int y,T z){\r\n        z=z+weight(x)-weight(y);\r\n        x=root(x),y=root(y);\r\
    \n        if(same(x,y)) return false;\r\n        if(y<x){\r\n            swap(x,y);\r\
    \n            z=-z;\r\n        }\r\n        par[y]=x;\r\n        sz[x]+=sz[y];\r\
    \n        w[y]=z;\r\n        return true;\r\n    }\r\n    int root(int x){\r\n\
    \    \tif(par[x]==x) return x; // x\u306Froot\r\n        root(par[x]); // root\u304B\
    \u3089\u7D2F\u7A4D\u548C\r\n        w[x]+=w[par[x]]; // \u89AA\u306E\u91CD\u307F\
    \u3092\u52A0\u7B97\u3059\u308B\r\n    \treturn (par[x]=root(par[x])); // x\u306E\
    \u89AA\u306Eroot\r\n    }\r\n    bool same(int x,int y){\r\n    \treturn (root(x)==root(y));\r\
    \n    }\r\n    int size(int x){\r\n        return sz[root(x)];\r\n    }\r\n  \
    \  T weight(int x){\r\n        root(x); // \u7D4C\u8DEF\u5727\u7E2E\u7528\r\n\
    \        return w[x];\r\n    }\r\n    T diff(int x,int y){\r\n        assert(same(x,y));\r\
    \n        return weight(y)-weight(x);\r\n    }\r\n};\r\n\r\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\r\
    \nint main(){\r\n    int n,q; cin>>n>>q;\r\n    WeightedUnionFind<long long> uf(n);\r\
    \n    while(q--){\r\n        int info,x,y,z; cin>>info>>x>>y;\r\n        if(info==0){\r\
    \n            cin>>z;\r\n            uf.unite(x,y,z);\r\n        }else{\r\n  \
    \          if(uf.same(x,y)){\r\n                cout<<uf.diff(x,y)<<endl;\r\n\
    \            }else{\r\n                cout<<\"?\"<<endl;\r\n            }\r\n\
    \        }\r\n    }\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\n#define\
    \ all(x) (x).begin(),(x).end()\r\nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\
    \nconst long long LINF=8931145141919364364,LMOD=998244353;\r\ninline long long\
    \ mod(long long n,long long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\ntemplate<class T>\r\nstruct WeightedUnionFind{\r\n    // \u9802\u70B9\u6570\
    (1-indexed)\r\n    const int V;\r\n    // par[x]:=x\u306Eroot\r\n    vector<int>\
    \ par;\r\n    // sz[x]:=x\u3092\u542B\u3080\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \r\n    vector<int> sz;\r\n    // w[x]:=x\u306Eroot\u306B\u5BFE\u3059\u308B\u91CD\
    \u307F\r\n    vector<T> w;\r\n    WeightedUnionFind(const int V):V(V){\r\n   \
    \     par.resize(V+1);\r\n        for(int i=0;i<=V;i++) par[i]=i;\r\n        sz.resize(V+1,1);\r\
    \n        w.resize(V+1);\r\n    }\r\n    // w[y] - w[x] = z\r\n    bool unite(int\
    \ x,int y,T z){\r\n        z=z+weight(x)-weight(y);\r\n        x=root(x),y=root(y);\r\
    \n        if(same(x,y)) return false;\r\n        if(y<x){\r\n            swap(x,y);\r\
    \n            z=-z;\r\n        }\r\n        par[y]=x;\r\n        sz[x]+=sz[y];\r\
    \n        w[y]=z;\r\n        return true;\r\n    }\r\n    int root(int x){\r\n\
    \    \tif(par[x]==x) return x; // x\u306Froot\r\n        root(par[x]); // root\u304B\
    \u3089\u7D2F\u7A4D\u548C\r\n        w[x]+=w[par[x]]; // \u89AA\u306E\u91CD\u307F\
    \u3092\u52A0\u7B97\u3059\u308B\r\n    \treturn (par[x]=root(par[x])); // x\u306E\
    \u89AA\u306Eroot\r\n    }\r\n    bool same(int x,int y){\r\n    \treturn (root(x)==root(y));\r\
    \n    }\r\n    int size(int x){\r\n        return sz[root(x)];\r\n    }\r\n  \
    \  T weight(int x){\r\n        root(x); // \u7D4C\u8DEF\u5727\u7E2E\u7528\r\n\
    \        return w[x];\r\n    }\r\n    T diff(int x,int y){\r\n        assert(same(x,y));\r\
    \n        return weight(y)-weight(x);\r\n    }\r\n};\r\n\r\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\r\
    \nint main(){\r\n    int n,q; cin>>n>>q;\r\n    WeightedUnionFind<long long> uf(n);\r\
    \n    while(q--){\r\n        int info,x,y,z; cin>>info>>x>>y;\r\n        if(info==0){\r\
    \n            cin>>z;\r\n            uf.unite(x,y,z);\r\n        }else{\r\n  \
    \          if(uf.same(x,y)){\r\n                cout<<uf.diff(x,y)<<endl;\r\n\
    \            }else{\r\n                cout<<\"?\"<<endl;\r\n            }\r\n\
    \        }\r\n    }\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/WeightedUnionFind.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/WeightedUnionFind.cpp
layout: document
redirect_from:
- /library/tmp/WeightedUnionFind.cpp
- /library/tmp/WeightedUnionFind.cpp.html
title: tmp/WeightedUnionFind.cpp
---
