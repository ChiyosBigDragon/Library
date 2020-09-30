---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
    - https://atcoder.jp/contests/abc038/tasks/abc038_d
  bundledCode: "#line 1 \"tmp/LIS.cpp\"\n#include <bits/stdc++.h>\r\n#define rep(i,n)\
    \ for(int i=0;i<n;i++)\r\n#define all(x) (x).begin(),(x).end()\r\nusing namespace\
    \ std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long LINF=8931145141919364364,LMOD=998244353;\r\
    \ninline long long mod(long long n,long long m){return(n%m+m)%m;}\r\n// const\
    \ int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\n\r\ntemplate<class\
    \ T>\r\nstruct LIS{\r\n    const int n;\r\n    const T INF;\r\n    using F=function<bool(T,T)>;\r\
    \n    const vector<T> val;\r\n    const F comp;\r\n    vector<T> dp;\r\n    LIS(const\
    \ int n,const T INF,const vector<T>& val,const F comp):n(n),INF(INF),val(val),comp(comp){\r\
    \n        dp.resize(n+1,INF);\r\n    }\r\n    // \u69CB\u7BC9\r\n    int sz=0;\r\
    \n    void build(){\r\n        for(T i:val){\r\n            auto itr=lower_bound(dp.begin(),dp.end(),i,comp);\r\
    \n            *itr=i;\r\n            sz=max(sz,(int)(itr-dp.begin()));\r\n   \
    \     }\r\n    }\r\n    int size(){\r\n        return sz+1;\r\n    }\r\n    vector<T>\
    \ get(){\r\n        int sz=size()-1;\r\n        vector<T> ret;\r\n        for(int\
    \ i=n-1;i>=0&&sz>=0;i--){\r\n            if((dp[sz]==val[i]||comp(dp[sz],val[i]))&&comp(val[i],dp[sz+1])){\r\
    \n                ret.push_back(val[i]);\r\n                sz--;\r\n        \
    \    }\r\n        }\r\n        reverse(ret.begin(),ret.end());\r\n        return\
    \ ret;\r\n    }\r\n};\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp\r\
    \nint main(){\r\n    int n; cin>>n;\r\n    vector<int> a(n); rep(i,n) cin>>a[i];\r\
    \n    LIS<int> lis(n,INF,a,[](int a,int b){return a<b;});\r\n    lis.build();\r\
    \n    cout<<lis.size()<<endl;\r\n    return 0;\r\n}\r\n// https://atcoder.jp/contests/abc038/tasks/abc038_d\r\
    \n// int main(){\r\n//     int n; cin>>n;\r\n//     pair<int,int> box[n];\r\n\
    //     rep(i,n){\r\n//         int w,h; cin>>w>>h;\r\n//         box[i]={w,-h};\r\
    \n//     }\r\n//     sort(box,box+n);\r\n//     vector<int> a(n);\r\n//     rep(i,n)\
    \ a[i]=-box[i].second;\r\n//     LIS<int> lis(a.size(),INF,a,[](int a,int b){return\
    \ a<b;});\r\n//     lis.build();\r\n//     cout<<lis.size()<<endl;\r\n//     return\
    \ 0;\r\n// }\r\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\n#define\
    \ all(x) (x).begin(),(x).end()\r\nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\
    \nconst long long LINF=8931145141919364364,LMOD=998244353;\r\ninline long long\
    \ mod(long long n,long long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\ntemplate<class T>\r\nstruct LIS{\r\n    const int n;\r\n    const T INF;\r\
    \n    using F=function<bool(T,T)>;\r\n    const vector<T> val;\r\n    const F\
    \ comp;\r\n    vector<T> dp;\r\n    LIS(const int n,const T INF,const vector<T>&\
    \ val,const F comp):n(n),INF(INF),val(val),comp(comp){\r\n        dp.resize(n+1,INF);\r\
    \n    }\r\n    // \u69CB\u7BC9\r\n    int sz=0;\r\n    void build(){\r\n     \
    \   for(T i:val){\r\n            auto itr=lower_bound(dp.begin(),dp.end(),i,comp);\r\
    \n            *itr=i;\r\n            sz=max(sz,(int)(itr-dp.begin()));\r\n   \
    \     }\r\n    }\r\n    int size(){\r\n        return sz+1;\r\n    }\r\n    vector<T>\
    \ get(){\r\n        int sz=size()-1;\r\n        vector<T> ret;\r\n        for(int\
    \ i=n-1;i>=0&&sz>=0;i--){\r\n            if((dp[sz]==val[i]||comp(dp[sz],val[i]))&&comp(val[i],dp[sz+1])){\r\
    \n                ret.push_back(val[i]);\r\n                sz--;\r\n        \
    \    }\r\n        }\r\n        reverse(ret.begin(),ret.end());\r\n        return\
    \ ret;\r\n    }\r\n};\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp\r\
    \nint main(){\r\n    int n; cin>>n;\r\n    vector<int> a(n); rep(i,n) cin>>a[i];\r\
    \n    LIS<int> lis(n,INF,a,[](int a,int b){return a<b;});\r\n    lis.build();\r\
    \n    cout<<lis.size()<<endl;\r\n    return 0;\r\n}\r\n// https://atcoder.jp/contests/abc038/tasks/abc038_d\r\
    \n// int main(){\r\n//     int n; cin>>n;\r\n//     pair<int,int> box[n];\r\n\
    //     rep(i,n){\r\n//         int w,h; cin>>w>>h;\r\n//         box[i]={w,-h};\r\
    \n//     }\r\n//     sort(box,box+n);\r\n//     vector<int> a(n);\r\n//     rep(i,n)\
    \ a[i]=-box[i].second;\r\n//     LIS<int> lis(a.size(),INF,a,[](int a,int b){return\
    \ a<b;});\r\n//     lis.build();\r\n//     cout<<lis.size()<<endl;\r\n//     return\
    \ 0;\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/LIS.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/LIS.cpp
layout: document
redirect_from:
- /library/tmp/LIS.cpp
- /library/tmp/LIS.cpp.html
title: tmp/LIS.cpp
---
