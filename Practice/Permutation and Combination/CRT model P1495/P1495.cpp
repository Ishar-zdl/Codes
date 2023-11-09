/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-08 19:37:46 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-09 07:04:53
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
const int N=15;
int M=1,a[N],c[N],ny,ans;
inline void exgcd(int a,int b,int &x,int &y){
    if(!b){x=1,y=0;return; }
    exgcd(b,a%b,x,y);
    int z=x;x=y,y=z-y*(a/b);
}
main(){
    int n=read();
    for(int i=1;i<=n;++i){
        c[i]=read(),a[i]=read(),M=M*c[i];
    }
    for(int i=1;i<=n;++i){
        int x=0,y=0,zc=M/c[i];
        exgcd(zc,c[i],x,y);
        // ny=(x+c[i])%c[i];
        ny=(x<0?x+c[i]:x);
        // std::cout<<zc<<' '<<c[i]<<' '<<ny<<'\n';
        ans=(ans+zc*a[i]%M*ny%M)%M;
    }
    printf("%lld",ans);
}