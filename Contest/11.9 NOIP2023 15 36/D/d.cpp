/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-09 14:28:37 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-09 16:41:43
 */
#include<bits/stdc++.h>
// typedef long long int;
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
const int N=2e5+10,mod=998244353;
char s[N];
int f[N],num[N],sum=0;
main(){
    freopen("d.in","r",stdin),freopen("d.out","w",stdout);
    int n;f[0]=sum=1;int base=10;
    scanf("%lld",&n);
    scanf("%s",s+1);
    f[1]=s[1]-'0';sum+=f[1];
    for(int i=2;i<=n;++i){
        f[i]=(f[i-1]*10%mod+sum*(s[i]-'0')%mod)%mod;
        sum=(sum+f[i])%mod;
    }
    printf("%lld",f[n]);
    return 0;
}