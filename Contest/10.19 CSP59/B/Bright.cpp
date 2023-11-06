/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-19 11:08:27 
 * @Last Modified by:   Ishar-zdl 
 * @Last Modified time: 2023-10-19 11:08:27 
 */
#include<bits/stdc++.h>
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
const int N=5e5+5;
int n,Q,tot,head[N],dfn[N],rnk[N],dep[N],w[N],tot,siz[N],son[N],top[N],fa[N];
struct edge{
    int v,next,w;
}e[N*2];
inline void add(int u,int v,int w){
    e[++tot]={v,head[u],w};head[u]=tot;
}
void dfs1(int x){
    siz[x]
}
void dfs2(){

}
int main(){
    n=read();
    for(int i=1,u,v,w;i<n;++i){
        u=read(),v=read(),w=read();
        add(u,v,w);add(v,u,w);
    }
    dfs1();dfs2();
}