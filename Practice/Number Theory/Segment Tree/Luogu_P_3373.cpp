/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-24 11:26:43 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-24 16:50:09
 */
#include<bits/stdc++.h>
#define int long long
#define N (int)1e5+5
using namespace std;
int a[N],n,q,mod;
struct SegmentTree{
    int l,r,sum,add,cj;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define add(x) t[x].add
    #define sum(x) t[x].sum
    #define cj(x) t[x].cj
}t[4*N];
void BuildTree(int p,int l,int r){
    l(p)=l;r(p)=r;cj(p)=1;
    if(l==r){sum(p)=a[l];return;}
    int mid=(l+r)>>1;
    BuildTree(p*2,l,mid);BuildTree(p*2+1,mid+1,r);
    sum(p)=sum(p*2)+sum(p*2+1);
}
void spread(int p){
    sum(p*2)=(cj(p)*sum(p*2)%mod+((r(p*2)-l(p*2)+1)*add(p)))%mod;
    sum(p*2+1)=(cj(p)*sum(p*2+1)%mod+((r(p*2+1)-l(p*2+1)+1)*add(p)))%mod;
    cj(p*2)=(cj(p*2)*cj(p)%mod);
    cj(p*2+1)=cj(p*2+1)*cj(p)%mod;
    add(p*2)=(add(p*2)*cj(p)+add(p))%mod;
    add(p*2+1)=(add(p*2+1)*cj(p)+add(p))%mod;
    cj(p)=1;add(p)=0;
}
inline void modified(int p,int l,int r,int d){
    if(l<=l(p)&&r>=r(p)){
        sum(p)=(sum(p)+d*(r(p)-l(p)+1))%mod;
        add(p)+=d;return;
    }
    spread(p);
    int mid=(l(p)+r(p))>>1;
    if(l<=mid)modified(p*2,l,r,d);
    if(r>mid)modified(p*2+1,l,r,d);
    sum(p)=(sum(p*2)+sum(p*2+1))%mod;
}
inline void modified1(int p,int l,int r,int d){
    if(l<=l(p)&&r>=r(p)){
        add(p)=(add(p)*d)%mod;
        sum(p)=sum(p)*d%mod;cj(p)=cj(p)*d%mod;return;
    }spread(p);
    int mid=(l(p)+r(p))>>1;
    if(l<=mid)modified1(p*2,l,r,d);
    if(r>mid)modified1(p*2+1,l,r,d);
    sum(p)=(sum(p*2)+sum(p*2+1))%mod;
}
inline int queryTree(int p,int l,int r){
    if(l<=l(p)&&r>=r(p))return sum(p);
    spread(p);
    int mid=(l(p)+r(p))>>1;
    int val=0;
    if(l<=mid)val=(val+queryTree(p*2,l,r))%mod;
    if(r>mid)val=(val+queryTree(p*2+1,l,r))%mod;
    return val;
}
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
main(){
    n=read(),q=read(),mod=read();
    for(int i=1;i<=n;i++)a[i]=read();
    BuildTree(1,1,n);
    for(int i=1;i<=q;i++){
        int pd=read(),x=read(),y=read();
        if(pd==1){int k=read();modified1(1,x,y,k);}
        if(pd==2){int k=read();modified(1,x,y,k);}
        if(pd==3) write(queryTree(1,x,y)),putchar('\n');
    }
}