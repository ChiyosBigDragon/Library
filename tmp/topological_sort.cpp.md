---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
  bundledCode: "#line 1 \"tmp/topological_sort.cpp\"\n#include <bits/stdc++.h>\r\n\
    #define rep(i,n) for(int i=0;i<n;i++)\r\n#define all(x) (x).begin(),(x).end()\r\
    \nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long\
    \ LINF=8931145141919364364,LMOD=998244353;\r\ninline long long mod(long long n,long\
    \ long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\nstruct topological_sort{\r\n    const int V;\r\n    vector<vector<int>>\
    \ board;\r\n    vector<int> into,list;\r\n    vector<bool> visited;\r\n    topological_sort(int\
    \ v)\r\n        :V(v)\r\n        ,into(v,0)\r\n        ,visited(v,false)\r\n \
    \       {\r\n            board.assign(v,vector<int>());\r\n        }\r\n    //\
    \ \u5165\u529B\r\n    void add(int from,int to){\r\n        board[from].push_back(to);\r\
    \n        into[to]++;\r\n    }\r\n    // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\r\n    void build(){\r\n        for(int i=0;i<V;i++){\r\n       \
    \     if(into[i]==0&&!visited[i]){\r\n                queue<int> q;\r\n      \
    \          q.push(i);\r\n                while(q.size()){\r\n                \
    \    int from=q.front(); q.pop();\r\n                    list.push_back(from);\r\
    \n                    visited[from]=true;\r\n                    for(int to:board[from]){\r\
    \n                        into[to]--;\r\n                        if(into[to]==0&&!visited[to]){\r\
    \n                            q.push(to);\r\n                        }\r\n   \
    \                 }\r\n                }\r\n            }\r\n        }\r\n   \
    \ }\r\n    // \u53D6\u5F97\r\n    vector<int> get(){\r\n        return list;\r\
    \n    }\r\n};\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp\r\
    \nint main(){\r\n    int V,E; cin>>V>>E;\r\n    topological_sort graph(V);\r\n\
    \    while(E--){\r\n        int s,t; cin>>s>>t;\r\n        graph.add(s,t);\r\n\
    \    }\r\n    graph.build();\r\n    vector<int> l=graph.get();\r\n    rep(i,V)\
    \ cout<<l[i]<<(i==V-1?\"\\n\":\" \");\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\n#define\
    \ all(x) (x).begin(),(x).end()\r\nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\
    \nconst long long LINF=8931145141919364364,LMOD=998244353;\r\ninline long long\
    \ mod(long long n,long long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\nstruct topological_sort{\r\n    const int V;\r\n    vector<vector<int>>\
    \ board;\r\n    vector<int> into,list;\r\n    vector<bool> visited;\r\n    topological_sort(int\
    \ v)\r\n        :V(v)\r\n        ,into(v,0)\r\n        ,visited(v,false)\r\n \
    \       {\r\n            board.assign(v,vector<int>());\r\n        }\r\n    //\
    \ \u5165\u529B\r\n    void add(int from,int to){\r\n        board[from].push_back(to);\r\
    \n        into[to]++;\r\n    }\r\n    // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\r\n    void build(){\r\n        for(int i=0;i<V;i++){\r\n       \
    \     if(into[i]==0&&!visited[i]){\r\n                queue<int> q;\r\n      \
    \          q.push(i);\r\n                while(q.size()){\r\n                \
    \    int from=q.front(); q.pop();\r\n                    list.push_back(from);\r\
    \n                    visited[from]=true;\r\n                    for(int to:board[from]){\r\
    \n                        into[to]--;\r\n                        if(into[to]==0&&!visited[to]){\r\
    \n                            q.push(to);\r\n                        }\r\n   \
    \                 }\r\n                }\r\n            }\r\n        }\r\n   \
    \ }\r\n    // \u53D6\u5F97\r\n    vector<int> get(){\r\n        return list;\r\
    \n    }\r\n};\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp\r\
    \nint main(){\r\n    int V,E; cin>>V>>E;\r\n    topological_sort graph(V);\r\n\
    \    while(E--){\r\n        int s,t; cin>>s>>t;\r\n        graph.add(s,t);\r\n\
    \    }\r\n    graph.build();\r\n    vector<int> l=graph.get();\r\n    rep(i,V)\
    \ cout<<l[i]<<(i==V-1?\"\\n\":\" \");\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/topological_sort.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/topological_sort.cpp
layout: document
redirect_from:
- /library/tmp/topological_sort.cpp
- /library/tmp/topological_sort.cpp.html
title: tmp/topological_sort.cpp
---
