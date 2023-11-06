/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-23 09:35:48 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-09-23 10:50:35
 */
#include<bits/stdc++.h>
#define int long long 
#define N (int)1e5+10
#define fo(n) for(int i=1;i<=n;i++)
using namespace std;
int a[N],n,m,c1[N],c2[N];
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
inline void add(int x,int k){
    int l=x;
    for(;x<=n;x+=x&-x)c1[x]+=k,c2[x]+=l*k;
}
inline void query(int l,int r){
    int ans1=0,ans2=0;
    for(int i=r;i;i-=i&-i)ans1+=c1[i],ans2+=c2[i];
    int sum=ans1*(r+1);ans1=0;
    for(int i=l-1;i;i-=i&-i)ans1+=c1[i],ans2-=c2[i];
    write(sum-l*ans1-ans2);putchar('\n');
}
main(){
    n=read(),m=read();
    fo(n)a[i]=read(),add(i,a[i]),add(i+1,-a[i]);
    fo(m){
        int pd=read();
        int a=read(),b=read();
        if(pd==1){int k=read();add(a,k),add(b+1,-k);}
        else query(a,b);
    }
    return 0;
}