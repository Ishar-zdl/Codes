/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-10 11:47:51 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-10 19:20:41
 */
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
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
const ll mod=1e6+3;
ll jc[mod+10],ny[mod+10];
inline ll C(int n,int m){if(m>n)return 0;return jc[n]*ny[m]%mod*ny[n-m]%mod;}
inline ll lucas(int n,int m){return m?C(n%mod,m%mod)*lucas(n/mod,m/mod)%mod:1;}
inline ll qpow(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int main(){
    int T;scanf("%d",&T);jc[0]=ny[0]=1;
    for(int i=1;i<mod;++i)jc[i]=jc[i-1]*1ll*i%mod;
    ny[mod-1]=qpow(jc[mod-1],mod-2);
    for(int i=mod-2;i;--i)ny[i]=ny[i+1]*1ll*(i+1)%mod;
    while(T--){
        ll n,l,r;
        scanf("%lld%lld%lld",&n,&l,&r);
        ll len=r-l+1;
        printf("%lld\n",(lucas(len+n,len)-1+mod)%mod);
    }
}