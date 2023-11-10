/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-10 11:06:08 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-10 11:40:18
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
const int mod=5000011,N=1e5+10;
int jc[N],ny[N];
inline int C(int n,int m){
    if(m>n)return 0;
    return 1ll*jc[n]*ny[m]%mod*ny[n-m]%mod;
}
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ans=1ll*ans*a%mod;
    return ans;
}
main(){
    int n=read(),k=read(),ans=1;jc[0]=ny[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
    ny[n]=qpow(jc[n],mod-2);
    for(int i=n-1;i;--i)ny[i]=ny[i+1]*(i+1)%mod;
    // int r=n/k;
    for(int i=1;i<=n;++i)
        ans=(ans+C(n-(i-1)*k,i))%mod;
    printf("%d",ans);
}