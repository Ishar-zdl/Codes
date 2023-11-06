/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-23 07:25:27 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-09-23 11:08:34
 */
#include<bits/stdc++.h>
#define int long long
#define N (int)1e6+5
using namespace std;
int n,c1[N],c2[N],dfs[N],tot;pair<int,int>qu[N];
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
    int l=x;
    for(;x<=n;x+=x&-x)c1[x]+=k,c2[x]+=l*k;
}
inline void quary(int l,int r){
    int ans1=0,ans2=0;//l--;
    for(int i=r;i;i-=i&-i)ans1+=c1[i],ans2+=c2[i];
    int sum=ans1*(r+1);ans1=0;
    for(int i=l-1;i;i-=i&-i)ans1+=c1[i],ans2-=c2[i];
    write(sum-l*ans1-ans2);putchar('\n');
}
void dfss(int x){
    dfs[x]=++tot;vis[x]=true;qu[tot].first=tot;
    for(int i:node[x]){
        if(!vis[i])dfss(i);
    }
    qu[dfs[x]].second=tot;
}
int w[N];
main(){
    n=read();int m=read(),r=read();
    for(register int i=1;i<=n;i++){
        w[i]=read();
    }for(register int i=1;i<n;i++) {
        int u=read(),v=read();node[u].push_back(v);node[v].push_back(u);
    }dfss(r);
    for(register int i=1;i<=n;i++){
        add(dfs[i],w[i]);add(dfs[i]+1,-w[i]);
    }for(register int i=1;i<=m;i++){
        short b=read();int a=read();
        if(b==1){int x=read();add(dfs[a],x);add(qu[dfs[a]].second+1,-x);}
        else quary(qu[dfs[a]].first,qu[dfs[a]].second);
    }
}