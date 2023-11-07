/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-06 21:10:18 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-07 07:42:14
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
const int N=1e6+10;
int n,p,l[N],r[N],siz[N],jc[N],ny[N],f[N],ls[N],rs[N],tot;
bool left[N];
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;
    return ans;
}
inline int C(int n,int m){if(m>n)return 0;return jc[n]*qpow(jc[m]*jc[n-m]%p,p-2);}
inline int lucas(int n,int m){return m?C(n%p,m%p)*lucas(n/p,m/p)%p:1;}
void dfs1(int x){
    left[x]=true;
    if(x*2<=n)dfs1(x*2);
    if(x*2+1<=n)dfs1(x*2+1);
}
main(){
    n=read(),p=read();jc[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%p;
    dfs1(2);
    f[1]=f[0]=1;
    left[2]=true;
    for(int i=2,l=0;i<=n;++i){
        if(left[i])l++;
        f[i]=lucas(i-1,l)*f[l]%p*f[i-1-l]%p;
    }
    std::cout<<f[n];
}   