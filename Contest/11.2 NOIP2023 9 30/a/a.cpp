/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-02 07:41:38 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-02 09:16:55
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
int p[(int)1e6+5],m=0,c[(int)1e6+5],ans=1;
main(){
    freopen("a.in","r",stdin),freopen("a.out","w",stdout);
    int n=read();
    // n=10000000000;
    int k=n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            // std::cout<<i<<'\n';
            c[++m]=1;p[m]=i;n/=i;
            while(n%i==0)n/=i,c[m]++;
        }
    }
    if(n>1)c[++m]=1,p[m]=n;
    for(int i=1;i<=m;++i){
        // if(c[i]&1){std::cout<<-1<<'\n';break;}
        for(int j=1;j<=(c[i]+1)/2;++j)ans*=p[i];
    }
    for(int i=1;i<=m;++i)std::cout<<p[i]<<' ';std::cout<<'\n';
    for(int i=1;i<=m;++i)std::cout<<c[i]<<' ';
    if(ans<k)std::cout<<ans;
    else std::cout<<-1;
}