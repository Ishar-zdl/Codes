/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-02 09:54:48 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-05 16:47:04
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
struct Skadi{
    int o,l,r,x,t;bool operator<(Skadi b)const{return x<b.x;}
};
const int N=5e5+10;
int n,k,L,R,A[N],a[N],st[N][20],num[N][20];
priority_queue<Skadi> q;
inline void in(){
    n=read(),k=read(),L=read(),R=read();
    for(int i=1;i<=n;i++)A[i]=read(),a[i]=A[i]+a[i-1],st[i][0]=a[i],num[i][0]=i;
}
inline void stt(){
    for(int i=1;i<=20;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            if(st[j][i-1]>st[j+(1<<(i-1))][i-1])num[j][i]=num[j][i-1],st[j][i]=st[j][i-1];
            else num[j][i]=num[j+(1<<(i-1))][i-1],st[j][i]=st[j+(1<<(i-1))][i-1];
}
inline void work(){
    Skadi zc;
    for(int i=1;i+L-1<=n;++i){
        zc.o=i,zc.l=i+L-1,zc.r=min(i+R-1,n);
        int k=__lg(zc.r-zc.l+1);
        int A=st[zc.l][k],B=st[zc.r-(1<<k)+1][k];
        if(A>B)zc.x=A-a[i-1],zc.t=num[zc.l][k];
        else zc.x=B-a[i-1],zc.t=num[zc.r-(1<<k)+1][k];
        q.push(zc);
    }int tot=0,ans=0;
    while(tot<k){
        zc=q.top(),q.pop(),ans+=zc.x;tot++;
        if(zc.t!=zc.l){
            int k=__lg(zc.t-zc.l);int A=st[zc.l][k],B=st[zc.t-(1<<k)][k];int x,t;
            if(A>B)x=A-a[zc.o-1],t=num[zc.l][k];
            else x=B-a[zc.o-1],t=num[zc.t-(1<<k)][k];
            q.push({zc.o,zc.l,zc.t-1,x,t});
        }
        if(zc.t!=zc.r){
            int k=__lg(zc.r-zc.t);int A=st[zc.t+1][k],B=st[zc.r-(1<<k)+1][k];int x,t;
            if(A>B)x=A-a[zc.o-1],t=num[zc.t+1][k];
            else x=B-a[zc.o-1],t=num[zc.r-(1<<k)+1][k];
            q.push({zc.o,zc.t+1,zc.r,x,t});
        }
    }
    write(ans);
}
main(){
    in();
    stt();
    work();
    return 0;
}