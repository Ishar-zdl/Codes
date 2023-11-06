/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-19 07:32:11 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-19 10:21:48
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int mod=998244353,N=5e5+5;
int n,f[N],st[N][20],tot;
struct A{
    int w,num;
}a[N];
main(){
    freopen("beacon.in","r",stdin),freopen("beacon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i].w=read();
        a[i].num=i;
    }
    A maxx=a[1];
    for(int i=2;i<=n;++i){
        if(maxx.w<a[i].w){
            int zc=i-maxx.num;
            tot++;
            f[tot]=zc+1;
            maxx=a[i];
        }
    }
    long long ans=1;
    for(int i=1;i<=tot;++i)ans=ans*f[i]%mod;
    write(ans);
}