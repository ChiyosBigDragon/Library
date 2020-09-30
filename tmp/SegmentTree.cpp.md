---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
    - https://atcoder.jp/contests/abc125/tasks/abc125_c
    - https://atcoder.jp/contests/arc008/tasks/arc008_4
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"tmp/SegmentTree.cpp\"\n// 0-indexed\r\n\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<n;i++)\r\n#define all(x) (x).begin(),(x).end()\r\
    \nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long\
    \ LINF=8931145141919364364,LMOD=998244353;\r\ninline long long mod(long long n,long\
    \ long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\ntemplate<class T>\r\nstruct SegmentTree{\r\n    using F=function<T(T,T)>;\r\
    \n    const T init;\r\n    const F f;\r\n    int sz;\r\n    vector<T> seg;\r\n\
    \    SegmentTree(int n,const T init,const F f):\r\n        init(init),\r\n   \
    \     f(f)\r\n        {\r\n            sz=1;\r\n            while(sz<n) sz<<=1;\r\
    \n            seg.resize(sz<<1,init);\r\n        }\r\n    // \u4EE3\u5165\r\n\
    \    void set(int id,T x){\r\n        seg[id+sz]=x;\r\n    }\r\n    // \u69CB\u7BC9\
    \r\n    void build(){\r\n        for(int k=sz-1;k>0;k--){\r\n            seg[k]=f(seg[2*k],seg[2*k+1]);\r\
    \n        }\r\n    }\r\n    // \u66F4\u65B0\r\n    void update(int id){\r\n  \
    \      while(id>>=1){\r\n            seg[id]=f(seg[2*id],seg[2*id+1]);\r\n   \
    \     }\r\n    }\r\n    // \u7F6E\u63DB\r\n    void replace(int id,T x){\r\n \
    \       id+=sz;\r\n        seg[id]=x;\r\n        update(id);\r\n    }\r\n    //\
    \ \u52A0\u7B97\r\n    void add(int id,T x){\r\n        id+=sz;\r\n        seg[id]+=x;\r\
    \n        update(id);\r\n    }\r\n    // [l,r)\u306E\u7D50\u679C\u3092\u53D6\u5F97\
    \r\n    T get(int l,int r){\r\n        T L=init,R=init;\r\n        l+=sz,r+=sz;\r\
    \n        for(;l<r;l>>=1,r>>=1){\r\n            if(l&1) L=f(L,seg[l++]);\r\n \
    \           if(r&1) R=f(seg[--r],R);\r\n        }\r\n        return f(L,R);\r\n\
    \    }\r\n    // debug\r\n    void debug(){\r\n        int i=1;\r\n        for(int\
    \ r=2;r<=2*sz;r<<=1){\r\n            while(i<r){\r\n                cout<<seg[i++]<<\"\
    \ \";\r\n            }\r\n            cout<<\"\\n\";\r\n        }\r\n    }\r\n\
    };\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp\r\
    \nint main(){\r\n    int n,q; cin>>n>>q;\r\n    SegmentTree<int> seg(n,(1ll<<31)-1,[](int\
    \ a,int b){return min(a,b);});\r\n    while(q--){\r\n        int com,x,y; cin>>com>>x>>y;\r\
    \n        if(com==0) seg.replace(x,y);\r\n        else cout<<seg.get(x,y+1)<<endl;\r\
    \n        // seg.debug();\r\n    }\r\n    return 0;\r\n}\r\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\r\
    \n// int main(){\r\n//     int n,q; cin>>n>>q;\r\n//     SegmentTree<int> seg(n,0,[](int\
    \ a,int b){return a+b;});\r\n//     while(q--){\r\n//         int com,x,y; cin>>com>>x>>y;\r\
    \n//         if(com==0) seg.add(x,y);\r\n//         else cout<<seg.get(x,y+1)<<endl;\r\
    \n//         // seg.debug();\r\n//     }\r\n//     return 0;\r\n// }\r\n// https://atcoder.jp/contests/arc008/tasks/arc008_4\r\
    \n// int main(){\r\n//     long long n,m; cin>>n>>m;\r\n//     set<long long>\
    \ pp;\r\n//     pair<long long,pair<double,double>> machen[m];\r\n//     rep(i,m){\r\
    \n//         long long p; cin>>p;\r\n//         pp.insert(p);\r\n//         double\
    \ a,b; cin>>a>>b;\r\n//         machen[i]={p,{a,b}};\r\n//     }\r\n//     int\
    \ id=0; map<long long,int> mp;\r\n//     for(auto p:pp) mp[p]=(id++);\r\n//  \
    \   SegmentTree<pair<double,double>> seg(m,{1,0},[](pair<double,double> a,pair<double,double>\
    \ b){return make_pair(a.first*b.first,a.second*b.first+b.second);});\r\n//   \
    \  // seg.debug();\r\n//     double ansmax=1,ansmin=1;\r\n//     rep(i,m){\r\n\
    //         long long p=machen[i].first;\r\n//         double a=machen[i].second.first,b=machen[i].second.second;\r\
    \n//         seg.update(mp[p],{a,b});\r\n//         auto x=seg.get(0,m);\r\n//\
    \         double val=x.first+x.second;\r\n//         ansmax=max(ansmax,val);\r\
    \n//         ansmin=min(ansmin,val);\r\n//         // printf(\"%.10f\\n\",ansmin);\r\
    \n//         // printf(\"%.10f\\n\",ansmax);\r\n//     }\r\n//     printf(\"%.10f\\\
    n\",ansmin);\r\n//     printf(\"%.10f\\n\",ansmax);\r\n//     return 0;\r\n//\
    \ }\r\n// https://atcoder.jp/contests/abc125/tasks/abc125_c\r\n// long long gcd(long\
    \ long x,long long y){\r\n//     return y>0?gcd(y,x%y):x;\r\n// }\r\n//\r\n//\
    \ int main(){\r\n//     int n; cin>>n;\r\n//     SegmentTree<int> seg(n,0,gcd);\r\
    \n//     for(int i=0;i<n;i++){\r\n//         int a; cin>>a;\r\n//         seg.replace(i,a);\r\
    \n//     }\r\n//     int ans=0;\r\n//     for(int i=0;i<n;i++){\r\n//        \
    \ int l=i>0?seg.get(0,i):0;\r\n//         int r=i<n-1?seg.get(i+1,n):0;\r\n//\
    \         ans=max(ans,(int)gcd(l,r));\r\n//     }\r\n//     cout<<ans<<endl;\r\
    \n//     return 0;\r\n// }\r\n"
  code: "// 0-indexed\r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int\
    \ i=0;i<n;i++)\r\n#define all(x) (x).begin(),(x).end()\r\nusing namespace std;\r\
    \nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long LINF=8931145141919364364,LMOD=998244353;\r\
    \ninline long long mod(long long n,long long m){return(n%m+m)%m;}\r\n// const\
    \ int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\n\r\ntemplate<class\
    \ T>\r\nstruct SegmentTree{\r\n    using F=function<T(T,T)>;\r\n    const T init;\r\
    \n    const F f;\r\n    int sz;\r\n    vector<T> seg;\r\n    SegmentTree(int n,const\
    \ T init,const F f):\r\n        init(init),\r\n        f(f)\r\n        {\r\n \
    \           sz=1;\r\n            while(sz<n) sz<<=1;\r\n            seg.resize(sz<<1,init);\r\
    \n        }\r\n    // \u4EE3\u5165\r\n    void set(int id,T x){\r\n        seg[id+sz]=x;\r\
    \n    }\r\n    // \u69CB\u7BC9\r\n    void build(){\r\n        for(int k=sz-1;k>0;k--){\r\
    \n            seg[k]=f(seg[2*k],seg[2*k+1]);\r\n        }\r\n    }\r\n    // \u66F4\
    \u65B0\r\n    void update(int id){\r\n        while(id>>=1){\r\n            seg[id]=f(seg[2*id],seg[2*id+1]);\r\
    \n        }\r\n    }\r\n    // \u7F6E\u63DB\r\n    void replace(int id,T x){\r\
    \n        id+=sz;\r\n        seg[id]=x;\r\n        update(id);\r\n    }\r\n  \
    \  // \u52A0\u7B97\r\n    void add(int id,T x){\r\n        id+=sz;\r\n       \
    \ seg[id]+=x;\r\n        update(id);\r\n    }\r\n    // [l,r)\u306E\u7D50\u679C\
    \u3092\u53D6\u5F97\r\n    T get(int l,int r){\r\n        T L=init,R=init;\r\n\
    \        l+=sz,r+=sz;\r\n        for(;l<r;l>>=1,r>>=1){\r\n            if(l&1)\
    \ L=f(L,seg[l++]);\r\n            if(r&1) R=f(seg[--r],R);\r\n        }\r\n  \
    \      return f(L,R);\r\n    }\r\n    // debug\r\n    void debug(){\r\n      \
    \  int i=1;\r\n        for(int r=2;r<=2*sz;r<<=1){\r\n            while(i<r){\r\
    \n                cout<<seg[i++]<<\" \";\r\n            }\r\n            cout<<\"\
    \\n\";\r\n        }\r\n    }\r\n};\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp\r\
    \nint main(){\r\n    int n,q; cin>>n>>q;\r\n    SegmentTree<int> seg(n,(1ll<<31)-1,[](int\
    \ a,int b){return min(a,b);});\r\n    while(q--){\r\n        int com,x,y; cin>>com>>x>>y;\r\
    \n        if(com==0) seg.replace(x,y);\r\n        else cout<<seg.get(x,y+1)<<endl;\r\
    \n        // seg.debug();\r\n    }\r\n    return 0;\r\n}\r\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\r\
    \n// int main(){\r\n//     int n,q; cin>>n>>q;\r\n//     SegmentTree<int> seg(n,0,[](int\
    \ a,int b){return a+b;});\r\n//     while(q--){\r\n//         int com,x,y; cin>>com>>x>>y;\r\
    \n//         if(com==0) seg.add(x,y);\r\n//         else cout<<seg.get(x,y+1)<<endl;\r\
    \n//         // seg.debug();\r\n//     }\r\n//     return 0;\r\n// }\r\n// https://atcoder.jp/contests/arc008/tasks/arc008_4\r\
    \n// int main(){\r\n//     long long n,m; cin>>n>>m;\r\n//     set<long long>\
    \ pp;\r\n//     pair<long long,pair<double,double>> machen[m];\r\n//     rep(i,m){\r\
    \n//         long long p; cin>>p;\r\n//         pp.insert(p);\r\n//         double\
    \ a,b; cin>>a>>b;\r\n//         machen[i]={p,{a,b}};\r\n//     }\r\n//     int\
    \ id=0; map<long long,int> mp;\r\n//     for(auto p:pp) mp[p]=(id++);\r\n//  \
    \   SegmentTree<pair<double,double>> seg(m,{1,0},[](pair<double,double> a,pair<double,double>\
    \ b){return make_pair(a.first*b.first,a.second*b.first+b.second);});\r\n//   \
    \  // seg.debug();\r\n//     double ansmax=1,ansmin=1;\r\n//     rep(i,m){\r\n\
    //         long long p=machen[i].first;\r\n//         double a=machen[i].second.first,b=machen[i].second.second;\r\
    \n//         seg.update(mp[p],{a,b});\r\n//         auto x=seg.get(0,m);\r\n//\
    \         double val=x.first+x.second;\r\n//         ansmax=max(ansmax,val);\r\
    \n//         ansmin=min(ansmin,val);\r\n//         // printf(\"%.10f\\n\",ansmin);\r\
    \n//         // printf(\"%.10f\\n\",ansmax);\r\n//     }\r\n//     printf(\"%.10f\\\
    n\",ansmin);\r\n//     printf(\"%.10f\\n\",ansmax);\r\n//     return 0;\r\n//\
    \ }\r\n// https://atcoder.jp/contests/abc125/tasks/abc125_c\r\n// long long gcd(long\
    \ long x,long long y){\r\n//     return y>0?gcd(y,x%y):x;\r\n// }\r\n//\r\n//\
    \ int main(){\r\n//     int n; cin>>n;\r\n//     SegmentTree<int> seg(n,0,gcd);\r\
    \n//     for(int i=0;i<n;i++){\r\n//         int a; cin>>a;\r\n//         seg.replace(i,a);\r\
    \n//     }\r\n//     int ans=0;\r\n//     for(int i=0;i<n;i++){\r\n//        \
    \ int l=i>0?seg.get(0,i):0;\r\n//         int r=i<n-1?seg.get(i+1,n):0;\r\n//\
    \         ans=max(ans,(int)gcd(l,r));\r\n//     }\r\n//     cout<<ans<<endl;\r\
    \n//     return 0;\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/SegmentTree.cpp
layout: document
redirect_from:
- /library/tmp/SegmentTree.cpp
- /library/tmp/SegmentTree.cpp.html
title: tmp/SegmentTree.cpp
---
