---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Dinic.cpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\ntemplate<typename T>\r\nstruct Dinic {\r\n    struct Edge {\r\n\
    \        // cap := \u5BB9\u91CF\r\n        // rev := \u9006\u8FBA\u306EID\r\n\
    \        int to, cap, rev;\r\n    };\r\n    const int V;\r\n    static constexpr\
    \ T INF = numeric_limits<T>::max();\r\n    // graph[from][num] := from\u304B\u3089\
    \u51FA\u308Bnum\u756A\u76EE\u306E\u8FBA\r\n    vector<vector<Edge>> graph;\r\n\
    \    Dinic(const int V) :\r\n        V(V)\r\n        {\r\n            graph.resize(V);\r\
    \n        }\r\n    void addEdge(const int from, const int to, const int cap) {\r\
    \n        graph[from].emplace_back((Edge){to, cap, (int)graph[to].size()});\r\n\
    \        graph[to].emplace_back((Edge){from, 0, (int)graph[from].size() - 1});\r\
    \n    }\r\n    T flow(const int start, const int goal) {\r\n        T ans = 0;\r\
    \n        vector<int> level(V);\r\n        while(bfs(start, goal, level)) {\r\n\
    \            vector<int> checked(V);\r\n            while(1) {\r\n           \
    \     T fmax = dfs(start, goal, level, checked, INF);\r\n                if(fmax\
    \ <= 0) break;\r\n                ans += fmax;\r\n            }\r\n        }\r\
    \n        return ans;\r\n    }\r\n    bool bfs(const int start, const int goal,\
    \ vector<int> &level) {\r\n        for(int i = 0; i < V; ++i) level[i] = -1;\r\
    \n        queue<int> que;\r\n        level[start] = 0;\r\n        que.push(start);\r\
    \n        while(que.size() and level[goal] == -1) {\r\n            int from =\
    \ que.front();\r\n            que.pop();\r\n            for(Edge e : graph[from])\
    \ {\r\n                if(e.cap > 0 and level[e.to] == -1) {\r\n             \
    \       level[e.to] = level[from] + 1;\r\n                    que.push(e.to);\r\
    \n                }\r\n            }\r\n        }\r\n        return level[goal]\
    \ != -1;\r\n    }\r\n    T dfs(const int from, const int goal, const vector<int>\
    \ &level, vector<int> &checked, T fmax) {\r\n        if(from == goal) return fmax;\r\
    \n        for(int &id = checked[from]; id < (int)graph[from].size(); ++id) {\r\
    \n            Edge &e = graph[from][id];\r\n            if(level[e.to] <= level[from])\
    \ continue;\r\n            if(e.cap <= 0) continue;\r\n            T f = dfs(e.to,\
    \ goal, level, checked, min(e.cap, fmax));\r\n            if(f <= 0) continue;\r\
    \n            e.cap -= f;\r\n            graph[e.to][e.rev].cap += f;\r\n    \
    \        return f;\r\n        }\r\n        return 0;\r\n    }\r\n};\r\n\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate<typename\
    \ T>\r\nstruct Dinic {\r\n    struct Edge {\r\n        // cap := \u5BB9\u91CF\r\
    \n        // rev := \u9006\u8FBA\u306EID\r\n        int to, cap, rev;\r\n    };\r\
    \n    const int V;\r\n    static constexpr T INF = numeric_limits<T>::max();\r\
    \n    // graph[from][num] := from\u304B\u3089\u51FA\u308Bnum\u756A\u76EE\u306E\
    \u8FBA\r\n    vector<vector<Edge>> graph;\r\n    Dinic(const int V) :\r\n    \
    \    V(V)\r\n        {\r\n            graph.resize(V);\r\n        }\r\n    void\
    \ addEdge(const int from, const int to, const int cap) {\r\n        graph[from].emplace_back((Edge){to,\
    \ cap, (int)graph[to].size()});\r\n        graph[to].emplace_back((Edge){from,\
    \ 0, (int)graph[from].size() - 1});\r\n    }\r\n    T flow(const int start, const\
    \ int goal) {\r\n        T ans = 0;\r\n        vector<int> level(V);\r\n     \
    \   while(bfs(start, goal, level)) {\r\n            vector<int> checked(V);\r\n\
    \            while(1) {\r\n                T fmax = dfs(start, goal, level, checked,\
    \ INF);\r\n                if(fmax <= 0) break;\r\n                ans += fmax;\r\
    \n            }\r\n        }\r\n        return ans;\r\n    }\r\n    bool bfs(const\
    \ int start, const int goal, vector<int> &level) {\r\n        for(int i = 0; i\
    \ < V; ++i) level[i] = -1;\r\n        queue<int> que;\r\n        level[start]\
    \ = 0;\r\n        que.push(start);\r\n        while(que.size() and level[goal]\
    \ == -1) {\r\n            int from = que.front();\r\n            que.pop();\r\n\
    \            for(Edge e : graph[from]) {\r\n                if(e.cap > 0 and level[e.to]\
    \ == -1) {\r\n                    level[e.to] = level[from] + 1;\r\n         \
    \           que.push(e.to);\r\n                }\r\n            }\r\n        }\r\
    \n        return level[goal] != -1;\r\n    }\r\n    T dfs(const int from, const\
    \ int goal, const vector<int> &level, vector<int> &checked, T fmax) {\r\n    \
    \    if(from == goal) return fmax;\r\n        for(int &id = checked[from]; id\
    \ < (int)graph[from].size(); ++id) {\r\n            Edge &e = graph[from][id];\r\
    \n            if(level[e.to] <= level[from]) continue;\r\n            if(e.cap\
    \ <= 0) continue;\r\n            T f = dfs(e.to, goal, level, checked, min(e.cap,\
    \ fmax));\r\n            if(f <= 0) continue;\r\n            e.cap -= f;\r\n \
    \           graph[e.to][e.rev].cap += f;\r\n            return f;\r\n        }\r\
    \n        return 0;\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Dinic.cpp
  requiredBy: []
  timestamp: '2020-03-09 22:22:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Dinic.cpp
layout: document
redirect_from:
- /library/tmp/Dinic.cpp
- /library/tmp/Dinic.cpp.html
title: tmp/Dinic.cpp
---
