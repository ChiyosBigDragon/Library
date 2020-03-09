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


# :warning: bit.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/bit.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// bit演算もろもろ
#include <bits/stdc++.h>
using namespace std;

// 最上位bit
unsigned long long MSB(unsigned long long n){
    n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;
    n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;
    n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;
    n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;
    n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;
    n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;
    return n;
}
// bitが何本立っているか
long long cntbit(long long n){
    n=(n&0x5555555555555555)+((n&0xAAAAAAAAAAAAAAAA)>>1);
    n=(n&0x3333333333333333)+((n&0xCCCCCCCCCCCCCCCC)>>2);
    n=(n&0x0F0F0F0F0F0F0F0F)+((n&0xF0F0F0F0F0F0F0F0)>>4);
    n=(n&0x00FF00FF00FF00FF)+((n&0xFF00FF00FF00FF00)>>8);
    n=(n&0x0000FFFF0000FFFF)+((n&0xFFFF0000FFFF0000)>>16);
    n=(n&0x00000000FFFFFFFF)+((n&0xFFFFFFFF00000000)>>32);
    return n;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "bit.cpp"
// bit演算もろもろ
#include <bits/stdc++.h>
using namespace std;

// 最上位bit
unsigned long long MSB(unsigned long long n){
    n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;
    n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;
    n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;
    n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;
    n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;
    n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;
    return n;
}
// bitが何本立っているか
long long cntbit(long long n){
    n=(n&0x5555555555555555)+((n&0xAAAAAAAAAAAAAAAA)>>1);
    n=(n&0x3333333333333333)+((n&0xCCCCCCCCCCCCCCCC)>>2);
    n=(n&0x0F0F0F0F0F0F0F0F)+((n&0xF0F0F0F0F0F0F0F0)>>4);
    n=(n&0x00FF00FF00FF00FF)+((n&0xFF00FF00FF00FF00)>>8);
    n=(n&0x0000FFFF0000FFFF)+((n&0xFFFF0000FFFF0000)>>16);
    n=(n&0x00000000FFFFFFFF)+((n&0xFFFFFFFF00000000)>>32);
    return n;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

