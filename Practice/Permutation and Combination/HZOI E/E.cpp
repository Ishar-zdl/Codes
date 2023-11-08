/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-08 07:10:12 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-08 19:20:42
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
const int mod=1e9+7,N=1e6+10;
int n,k,jc[N],ny[N];
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
inline int C(int n,int m){if(m>n)return 0;return jc[n]*ny[m]%mod*ny[n-m]%mod;}
// inline int lucas(int n,int m){
//     if(m==1)return 1;
//     return C(n%mod,m%mod)*lucas(n/mod,m/mod);
// }
int main(){
    n=read(),k=read();jc[0]=ny[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
    ny[n]=qpow(jc[n],mod-2);
    for(int i=n-1;i;--i)ny[i]=ny[i+1]*(i+1)%mod;
    int base=C(n,k);int ans=base;
    for(int i=1;i<)
}
//n中选k然后算方案数。