/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-14 08:02:49 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-14 17:54:29
 */
#include<bits/stdc++.h>
#define endl '\n'
#define FRE freopen("opt.in","r",stdin),freopen("opt.out","w",stdout);
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
const int N=5e5+10;
int n,m,k,a[N],c[N];
inline bool check(int x){
    int num=k;
    for(int i=1,w=1;i<=n;++i){
        if(a[i]<=x)continue;
        if(!x)w=a[i]+1;
        else{
            w=a[i]/(x+1);
            while(a[i]/w>x)w++;
        }
        if(num<c[w])return 0;
        else num-=c[w];
    }
    return 1;
}
int main(){
    FRE
    n=read(),m=read();k=read();
    for(int i=1;i<=n;++i)a[i]=read();
    std::sort(a+1,a+n+1);n=(n+1)/2;
    for(int i=1;i<=m;++i)c[i]=read();
    for(int i=2;i<=m;++i){
        for(int j=2;j*i<=m;++j)c[i*j]=std::min(c[i*j],c[i]+c[j]);
    }
    for(int i=m-1;i;--i)c[i]=std::min(c[i],c[i+1]);
    int op=sqrt(m);c[m+1]=2e9;c[1]=0;
    for(int i=1;i<=m;++i)
        c[m+1]=std::min(c[m+1],c[i]+c[(int)std::ceil(m*1.0/i)]);
    for(int i=m;i;--i)c[i]=std::min(c[i],c[i+1]);
    int l=0,r=N;int ans;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){ans=mid;r=mid-1;}
        else l=mid+1;
    }
    printf("%d",ans);
}