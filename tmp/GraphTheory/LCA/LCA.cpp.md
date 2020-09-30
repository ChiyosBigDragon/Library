---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/GraphTheory/LCA/LCA.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\nstruct SegmentTreeForLCA{\r\n    int sz;\r\n   \
    \ // {\u6DF1\u3055,id}\r\n    vector<pair<int,int>> seg;\r\n    // \u521D\u671F\
    \u5316\r\n    void resize(int n){\r\n        sz=1;\r\n        while(sz<n) sz<<=1;\r\
    \n        seg.resize(sz<<1,{1<<30,-1});\r\n    }\r\n    // \u4EE3\u5165\r\n  \
    \  void set(int id,int depth){\r\n        seg[id+sz]={depth,id};\r\n    }\r\n\
    \    // \u69CB\u7BC9\r\n    void build(){\r\n        for(int k=sz-1;k>0;k--){\r\
    \n            seg[k]=min(seg[2*k],seg[2*k+1]);\r\n        }\r\n    }\r\n    //\
    \ [l,r]\u306E\u7D50\u679C\u3092\u53D6\u5F97\r\n    int get(int l,int r){\r\n \
    \       pair<int,int> L={1<<30,-1},R={1<<30,-1};\r\n        l+=sz,r+=sz+1;\r\n\
    \        for(;l<r;l>>=1,r>>=1){\r\n            if(l&1) L=min(L,seg[l++]);\r\n\
    \            if(r&1) R=min(seg[--r],R);\r\n        }\r\n        return min(L,R).second;\r\
    \n    }\r\n};\r\nstruct LCA{\r\n    const int V;\r\n    const int root;\r\n  \
    \  const vector<vector<int>> &edge;\r\n    vector<int> nodeOrder;\r\n    vector<int>\
    \ depthOrder;\r\n    vector<int> nodeFirstID;\r\n    SegmentTreeForLCA seg;\r\n\
    \    LCA(int V,int root,vector<vector<int>> edge):\r\n        V(V),\r\n      \
    \  root(root),\r\n        edge(edge)\r\n        {\r\n            const int MAX=2*V-1;\r\
    \n            nodeOrder.resize(MAX);\r\n            depthOrder.resize(MAX);\r\n\
    \            nodeFirstID.resize(V+1,-1);\r\n            eulerTour(root,-1,0);\r\
    \n            seg.resize(MAX);\r\n            for(int id=0;id<MAX;id++){\r\n \
    \               seg.set(id,depthOrder[id]);\r\n            }\r\n            seg.build();\r\
    \n        }\r\n    int id=0;\r\n    void eulerTour(int from,int par,int depth){\r\
    \n        nodeOrder[id]=from;\r\n        depthOrder[id]=depth;\r\n        nodeFirstID[from]=id;\r\
    \n        id++;\r\n        for(int to:edge[from]){\r\n            if(to==par)\
    \ continue;\r\n            eulerTour(to,from,depth+1);\r\n            nodeOrder[id]=from;\r\
    \n            depthOrder[id]=depth;\r\n            id++;\r\n        }\r\n    }\r\
    \n    // u\u3068v\u306ELCA\r\n    int get(int u,int v){\r\n        return nodeOrder[seg.get(min(nodeFirstID[u],nodeFirstID[v]),max(nodeFirstID[u],nodeFirstID[v]))];\r\
    \n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct SegmentTreeForLCA{\r\
    \n    int sz;\r\n    // {\u6DF1\u3055,id}\r\n    vector<pair<int,int>> seg;\r\n\
    \    // \u521D\u671F\u5316\r\n    void resize(int n){\r\n        sz=1;\r\n   \
    \     while(sz<n) sz<<=1;\r\n        seg.resize(sz<<1,{1<<30,-1});\r\n    }\r\n\
    \    // \u4EE3\u5165\r\n    void set(int id,int depth){\r\n        seg[id+sz]={depth,id};\r\
    \n    }\r\n    // \u69CB\u7BC9\r\n    void build(){\r\n        for(int k=sz-1;k>0;k--){\r\
    \n            seg[k]=min(seg[2*k],seg[2*k+1]);\r\n        }\r\n    }\r\n    //\
    \ [l,r]\u306E\u7D50\u679C\u3092\u53D6\u5F97\r\n    int get(int l,int r){\r\n \
    \       pair<int,int> L={1<<30,-1},R={1<<30,-1};\r\n        l+=sz,r+=sz+1;\r\n\
    \        for(;l<r;l>>=1,r>>=1){\r\n            if(l&1) L=min(L,seg[l++]);\r\n\
    \            if(r&1) R=min(seg[--r],R);\r\n        }\r\n        return min(L,R).second;\r\
    \n    }\r\n};\r\nstruct LCA{\r\n    const int V;\r\n    const int root;\r\n  \
    \  const vector<vector<int>> &edge;\r\n    vector<int> nodeOrder;\r\n    vector<int>\
    \ depthOrder;\r\n    vector<int> nodeFirstID;\r\n    SegmentTreeForLCA seg;\r\n\
    \    LCA(int V,int root,vector<vector<int>> edge):\r\n        V(V),\r\n      \
    \  root(root),\r\n        edge(edge)\r\n        {\r\n            const int MAX=2*V-1;\r\
    \n            nodeOrder.resize(MAX);\r\n            depthOrder.resize(MAX);\r\n\
    \            nodeFirstID.resize(V+1,-1);\r\n            eulerTour(root,-1,0);\r\
    \n            seg.resize(MAX);\r\n            for(int id=0;id<MAX;id++){\r\n \
    \               seg.set(id,depthOrder[id]);\r\n            }\r\n            seg.build();\r\
    \n        }\r\n    int id=0;\r\n    void eulerTour(int from,int par,int depth){\r\
    \n        nodeOrder[id]=from;\r\n        depthOrder[id]=depth;\r\n        nodeFirstID[from]=id;\r\
    \n        id++;\r\n        for(int to:edge[from]){\r\n            if(to==par)\
    \ continue;\r\n            eulerTour(to,from,depth+1);\r\n            nodeOrder[id]=from;\r\
    \n            depthOrder[id]=depth;\r\n            id++;\r\n        }\r\n    }\r\
    \n    // u\u3068v\u306ELCA\r\n    int get(int u,int v){\r\n        return nodeOrder[seg.get(min(nodeFirstID[u],nodeFirstID[v]),max(nodeFirstID[u],nodeFirstID[v]))];\r\
    \n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/GraphTheory/LCA/LCA.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/GraphTheory/LCA/LCA.cpp
layout: document
redirect_from:
- /library/tmp/GraphTheory/LCA/LCA.cpp
- /library/tmp/GraphTheory/LCA/LCA.cpp.html
title: tmp/GraphTheory/LCA/LCA.cpp
---
