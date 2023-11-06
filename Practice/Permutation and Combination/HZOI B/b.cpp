/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-02 11:50:50 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-05 17:25:16
 */
#include<bits/stdc++.h>
#define int long long
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int p=10007;
int jc[p+10],ny[p+10];
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;
    return ans;
}
inline void pre(){
    jc[0]=1;
    for(int i=1;i<p;++i)jc[i]=jc[i-1]*i%p;
    ny[p-1]=qpow(jc[p-1],p-2);
    for(int i=p-2;i>=0;--i)ny[i]=ny[i+1]*(i+1)%p;
}
inline int C(int n,int m){
    if(m>n)return 0;
    return jc[n]*ny[m]%p*ny[n-m]%p;
}
inline int lucas(int n,int m){
    if(!m)return 1;
    return C(n%p,m%p)*lucas(n/p,m/p)%p;
}
main(){
    CIN_sync();
    int T;
    std::cin>>T;
    pre();
    while(T--){
        int n,m;
        std::cin>>n>>m;
        if(m>n){std::cout<<0<<'\n';continue;}
        std::cout<<lucas(n,m)<<'\n';
    }
    return 0;
}