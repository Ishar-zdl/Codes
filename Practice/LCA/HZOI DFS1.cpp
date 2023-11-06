/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-22 19:28:08 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-09-22 21:24:18
 */
#include<bits/stdc++.h>
#define int long long
#define N (int)1e6+5
using namespace std;
int n,c[N],dfs[N],tot;pair<int,int>qu[N];
bool vis[N];vector<int> node[N];
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
    for(;x<=n;x+=x&-x)c[x]+=k;
}
inline void quary(int l,int r){
    int ans=0;l--;
    for(;l>=1;l-=l&-l)ans-=c[l];
    for(;r>=1;r-=r&-r)ans+=c[r];
    write(ans);putchar('\n');
}
void dfss(int x){
    dfs[x]=++tot;vis[x]=true;qu[tot].first=tot;
    // cout<<tot<<endl;
    for(int i:node[x]){
        if(!vis[i])dfss(i);
    }
    qu[dfs[x]].second=tot;
}
int w[N];
main(){
    n=read();int m=read(),r=read();
    for(register int i=1;i<=n;i++){
        w[i]=read();//add(i,w);
    }for(register int i=1;i<n;i++) {
        int u=read(),v=read();node[u].push_back(v);node[v].push_back(u);
    }dfss(r);
    // for(register int i=1;i<=n;i++)cout<<dfs[i]<<endl;cout<<endl;
    // for(register int i=1;i<=n;i++)
    // cout<<qu[i].first<<' '<<qu[i].second<<endl;
    // for(register int i=1;i<=n;i++)cout<<dfs[i]<<' ';cout<<endl;
    for(register int i=1;i<=n;i++){
        add(dfs[i],w[i]);
    }for(register int i=1;i<=m;i++){
        short b=read();int a=read();//cout<<i<<endl;
        if(b==1){int x=read();add(dfs[a],x);}
        else quary(qu[dfs[a]].first,qu[dfs[a]].second);
    }
}