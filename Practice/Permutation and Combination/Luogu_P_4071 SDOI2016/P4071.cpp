/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-05 18:52:01 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-05 19:57:49
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
const int N=1e6+10,mod=1e9+7;
int jc[N],ny[N],c[N];
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
inline void pre(){
    jc[0]=ny[0]=1;c[0]=1;
    for(int i=1;i<=N;++i)jc[i]=jc[i-1]*i%mod;
    ny[N]=qpow(jc[N],mod-2);
    for(int i=N-1;i;--i)ny[i]=ny[i+1]*(i+1)%mod;
    c[1]=0,c[2]=1,c[3]=2;
    for(int i=4;i<=N;++i)c[i]=(i-1)*(c[i-1]+c[i-2])%mod;
}
inline int C(int n,int m){
    if(m==0)return 1;
    if(m>n)return 0;
    return jc[n]*ny[m]%mod*ny[n-m]%mod;
}
main(){
    int T=read();
    pre();
    while(T--){
        int n=read(),m=read();
        printf("%lld\n",C(n,m)*c[n-m]%mod);
    }
}