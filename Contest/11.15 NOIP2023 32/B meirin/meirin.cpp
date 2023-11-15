/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-15 11:05:53 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-15 11:23:49
 */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FRE freopen("meirin.in","r",stdin),freopen("meirin.out","w",stdout);
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
const int N=5e5+5,mod=1e9+7;
int a[N],b[N],n,q,sum_a[N],sum_b[N];
inline void operation(int l,int r,int k){
    int ans=0;
    for(int i=l;i<=r;++i)b[i]=((b[i]+k)%mod+mod)%mod;
    for(int i=1;i<=n;++i)sum_b[i]=((sum_b[i-1]+b[i])%mod+mod)%mod;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            int A=((sum_a[j]-sum_a[i-1])%mod+mod)%mod;
            int B=((sum_b[j]-sum_b[i-1])%mod+mod)%mod;
            ans=((ans+A*B%mod)%mod+mod)%mod;
        }
    }
    printf("%lld\n",ans);
}
main(){
    FRE
    n=read(),q=read();
    for(int i=1;i<=n;++i)a[i]=read(),sum_a[i]=((sum_a[i-1]+a[i])%mod+mod)%mod;
    for(int i=1;i<=n;++i)b[i]=read();
    for(int i=1,l,r,k;i<=q;++i){
        l=read(),r=read(),k=read();
        operation(l,r,k);
    }
}