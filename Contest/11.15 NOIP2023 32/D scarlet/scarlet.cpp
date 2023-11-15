/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-15 11:27:12 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-15 11:37:16
 */
#include<bits/stdc++.h>
#define endl '\n'
#define FRE freopen("scarlet.in","r",stdin),freopen("scarlet.out","w",stdout);
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
const int N=1e3+10;
int n,m,a[N];
inline void modified(int x,int y,int k){
    for(int i=1;i<=n;++i){
        if((i-1)%x<=y)a[i]+=k;
    }
}
inline void query(int l,int r){
    int ans=0;
    for(int i=l;i<=r;++i)ans+=a[i];
    printf("%d\n",ans);
}
int main(){
    FRE
    n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1,opt,l,r,k;i<=m;++i){
        opt=read(),l=read(),r=read();
        if(opt==1)k=read(),modified(l,r,k);
        else query(l,r);
    }
}