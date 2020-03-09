---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tmp/Dinic.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 22:22:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Dinic {
    struct Edge {
        // cap := 容量
        // rev := 逆辺のID
        int to, cap, rev;
    };
    const int V;
    static constexpr T INF = numeric_limits<T>::max();
    // graph[from][num] := fromから出るnum番目の辺
    vector<vector<Edge>> graph;
    Dinic(const int V) :
        V(V)
        {
            graph.resize(V);
        }
    void addEdge(const int from, const int to, const int cap) {
        graph[from].emplace_back((Edge){to, cap, (int)graph[to].size()});
        graph[to].emplace_back((Edge){from, 0, (int)graph[from].size() - 1});
    }
    T flow(const int start, const int goal) {
        T ans = 0;
        vector<int> level(V);
        while(bfs(start, goal, level)) {
            vector<int> checked(V);
            while(1) {
                T fmax = dfs(start, goal, level, checked, INF);
                if(fmax <= 0) break;
                ans += fmax;
            }
        }
        return ans;
    }
    bool bfs(const int start, const int goal, vector<int> &level) {
        for(int i = 0; i < V; ++i) level[i] = -1;
        queue<int> que;
        level[start] = 0;
        que.push(start);
        while(que.size() and level[goal] == -1) {
            int from = que.front();
            que.pop();
            for(Edge e : graph[from]) {
                if(e.cap > 0 and level[e.to] == -1) {
                    level[e.to] = level[from] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[goal] != -1;
    }
    T dfs(const int from, const int goal, const vector<int> &level, vector<int> &checked, T fmax) {
        if(from == goal) return fmax;
        for(int &id = checked[from]; id < (int)graph[from].size(); ++id) {
            Edge &e = graph[from][id];
            if(level[e.to] <= level[from]) continue;
            if(e.cap <= 0) continue;
            T f = dfs(e.to, goal, level, checked, min(e.cap, fmax));
            if(f <= 0) continue;
            e.cap -= f;
            graph[e.to][e.rev].cap += f;
            return f;
        }
        return 0;
    }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Dinic.cpp"
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Dinic {
    struct Edge {
        // cap := 容量
        // rev := 逆辺のID
        int to, cap, rev;
    };
    const int V;
    static constexpr T INF = numeric_limits<T>::max();
    // graph[from][num] := fromから出るnum番目の辺
    vector<vector<Edge>> graph;
    Dinic(const int V) :
        V(V)
        {
            graph.resize(V);
        }
    void addEdge(const int from, const int to, const int cap) {
        graph[from].emplace_back((Edge){to, cap, (int)graph[to].size()});
        graph[to].emplace_back((Edge){from, 0, (int)graph[from].size() - 1});
    }
    T flow(const int start, const int goal) {
        T ans = 0;
        vector<int> level(V);
        while(bfs(start, goal, level)) {
            vector<int> checked(V);
            while(1) {
                T fmax = dfs(start, goal, level, checked, INF);
                if(fmax <= 0) break;
                ans += fmax;
            }
        }
        return ans;
    }
    bool bfs(const int start, const int goal, vector<int> &level) {
        for(int i = 0; i < V; ++i) level[i] = -1;
        queue<int> que;
        level[start] = 0;
        que.push(start);
        while(que.size() and level[goal] == -1) {
            int from = que.front();
            que.pop();
            for(Edge e : graph[from]) {
                if(e.cap > 0 and level[e.to] == -1) {
                    level[e.to] = level[from] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[goal] != -1;
    }
    T dfs(const int from, const int goal, const vector<int> &level, vector<int> &checked, T fmax) {
        if(from == goal) return fmax;
        for(int &id = checked[from]; id < (int)graph[from].size(); ++id) {
            Edge &e = graph[from][id];
            if(level[e.to] <= level[from]) continue;
            if(e.cap <= 0) continue;
            T f = dfs(e.to, goal, level, checked, min(e.cap, fmax));
            if(f <= 0) continue;
            e.cap -= f;
            graph[e.to][e.rev].cap += f;
            return f;
        }
        return 0;
    }
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

