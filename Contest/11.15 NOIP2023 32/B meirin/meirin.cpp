/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-15 11:05:53 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-15 19:10:21
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
int a[N],b[N],n,q,sum_a[N],back_a[N],p[N],sum_p[N],ans=0;
main(){
    FRE
    n=read(),q=read();
    for(int i=1;i<=n;++i)a[i]=read(),sum_a[i]=((sum_a[i-1]+a[i]*i)+mod)%mod;
    for(int i=n;i;--i)back_a[i]=((back_a[i+1]+a[i]*(n-i+1))+mod)%mod;
    for(int i=1;i<=n;++i)b[i]=read(),
	p[i]=((p[i-1]-sum_a[i-1]+back_a[i])%mod+mod)%mod,
	ans=((ans+p[i]*b[i]%mod)%mod+mod)%mod,sum_p[i]=(sum_p[i-1]+p[i]+mod)%mod;
//	for(int i=1;i<=n;++i)std::cout<<p[i]<<' ';
	std::cout<<'\n';
    for(int i=1;i<=q;++i){
    	int l=read(),r=read(),k=read();
    	ans=((ans+(sum_p[r]+mod-sum_p[l-1])%mod*k%mod)%mod+mod)%mod;
    	printf("%lld\n",ans);
	}
}