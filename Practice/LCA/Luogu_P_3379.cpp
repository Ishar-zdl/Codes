/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-24 08:19:39 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-09-24 09:08:33
 */
#include<bits/stdc++.h>
#define fo(n) for(int i=1;i<=n;i++)
#define N (int)5e5+5
using namespace std;
int n,m,s,d[N],dist[N],f[22][N],lg[N];
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
vector<int> node[N];
void dfs(int x,int y){
    f[0][x]=y;d[x]=d[y]+1;
    fo(__lg(d[x]))f[i][x]=f[i-1][f[i-1][x]];
    for(int i:node[x]) if(i!=y) dfs(i,x);
}
inline void lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])x=f[__lg(d[x]-d[y])][x];
    if(x==y){write(x),putchar('\n');return;}
    for(int k=__lg(d[x]);k>=0;--k)
        if(f[k][x]!=f[k][y])x=f[k][x],y=f[k][y];
    write(f[0][x]);putchar('\n');return;
}
int main(){
    int a,b;n=read(),m=read(),s=read();
    fo(n-1)a=read(),b=read(),node[a].push_back(b),node[b].push_back(a);
    dfs(s,0);
    fo(m)a=read(),b=read(),lca(a,b);
}