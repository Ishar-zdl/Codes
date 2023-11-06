/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 21:18:32 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-05 07:59:35
 */
#include<bits/stdc++.h>
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
const int N=5005;
int p[N];
long double f[N][N],pre[N];
int main(){
    int n=read();
    long double ans=-114514;
    // pre[0]
    for(int i=1;i<=n;++i){
        p[i]=read();
        pre[i]=pre[i-1]*0.9+1;
    }
    // memset(f,-0x3f3f3f3f,sizeof(f));
    for(int i=1;i<=n;++i){
        for(int k=1;k<=i;++k){
            f[i][k]=std::max({f[i-1][k-1]*0.9+p[i],f[i-1][k],f[i][k]});
        }
    }
    for(int k=1;k<=n;++k){
        ans=std::max(ans,f[n][k]/pre[k]-(1200.0/sqrt(k)));
    }
    printf("%.15Lf",ans);
}