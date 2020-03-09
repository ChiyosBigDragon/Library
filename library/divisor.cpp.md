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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: divisor.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/divisor.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-02 11:36:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int64_t> divisor(int64_t n) {
    vector<int64_t> ret;
    for(int64_t i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.emplace_back(i);
            if(i * i != n) ret.emplace_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "divisor.cpp"
#include <bits/stdc++.h>
using namespace std;

vector<int64_t> divisor(int64_t n) {
    vector<int64_t> ret;
    for(int64_t i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.emplace_back(i);
            if(i * i != n) ret.emplace_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

