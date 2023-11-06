/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-21 21:46:48 
 * @Last Modified by:   mikey.zhaopeng 
 * @Last Modified time: 2023-09-21 21:46:48 
 */

//23.9.21 8.54
#include<bits/stdc++.h> 
#define mod 998244353
#define N (int)1e7
using namespace std;
struct edge{
    int v,next;
}edge[N+10];
int tot,head[N+10];
void add(int u,int v){
    tot++;
    edge[tot].v = v;
    edge[tot].next =head[u];head[u] =tot;
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
int size[N],inv[N];bool vis[N];
void dfs(int x){
    vis[x]=1;size[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].v;
        if(!vis[y])dfs(y),size[x]+=size[y];
    }
}
int main(){
    int n,a,b;n=read();inv[1]=1;long long ans(0);
    for(int i=2;i<=n;i++)a=read(),b=read(),add(a,b),add(b,a);dfs(1);
    for(int i=2;i<=n;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=n;i++)ans=(ans+inv[size[i]])%mod;
    cout<<ans;
}