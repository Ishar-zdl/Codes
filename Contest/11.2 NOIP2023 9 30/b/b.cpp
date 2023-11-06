/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-02 08:39:59 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-02 18:01:53
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
const int N=1e5+5,mod=998244353;
long long a[N],jc[N],inv[N];
bool pd[10][10];
inline int C(int n,int m){
    if(m>n)return 0;
    return jc[n]*inv[n-m]%mod*inv[m]%mod;
}
int cnt1,cnt5,cnt7,cnt6,cnt2,cnt3;
main(){
    freopen("b.in","r",stdin),freopen("b.out","w",stdout);
    int n=read();
    long long ans=1;jc[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
    int b=mod-2;inv[n]=1;int base=jc[n];inv[0]=1;
    while(b){
        if(b&1)inv[n]=inv[n]*base%mod;
        base=base*base%mod;b>>=1;
    }
    for(int i=n-1;i;i--)inv[i]=inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(a[i]==1)cnt1++;
        if(a[i]==5)cnt5++;
        if(a[i]==7)cnt7++;
        if(a[i]==2||a[i]==4||a[i]==8)cnt2++;
        if(a[i]==3||a[i]==9)cnt3++;
        if(a[i]==6||i==n){
            ans=ans*C(cnt2+cnt3,cnt2)%mod;
            cnt2=cnt3=0;
        }
    }
    // printf("%lld\n",ans);
    ans=ans*C(n-cnt5-cnt7,cnt1)%mod*C(n-cnt7,cnt5)%mod*C(n,cnt7)%mod;
    printf("%lld",ans);
}