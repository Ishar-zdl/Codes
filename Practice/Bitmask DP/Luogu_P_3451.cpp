/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-10 16:32:26 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-11 10:20:26
 */
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/hash_policy.hpp>
#define ri register int
using namespace std;
// using namespace __gnu_pbds;
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
const int N=1<<19,MAXX=2e4+5;
struct edge{
    int v,w,next;
}e[MAXX*10*2];
struct node{
    int dis,pos;
    bool operator<(node b)const{return dis>b.dis;}
};
// gp_hash_table<int,int>ma,an;
int n,MAX,m,k,tot,Q,dis[25][MAXX],fa[25],head[MAXX];
int in[25],h[25],dp[N][25];
bool vis[MAXX];
queue<int>qu;
priority_queue<node>q;
// vector<int>node[25]
inline void add(int x,int y,int z){
    e[++tot]={y,z,head[x]};head[x]=tot;
}
inline void dij(int s){
    int t=s;dis[t][s]=0;
    q.push({0,s});
    while(!q.empty()){
        int x=q.top().pos;
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].next){
            int y=e[i].v;
            if(dis[t][y]>dis[t][x]+e[i].w){
                dis[t][y]=dis[t][x]+e[i].w;
                if(!vis[y])q.push({dis[t][y],y});
            }
        }
    }
    memset(vis,0,sizeof(vis));
}
inline void prepare(){
    n=read(),m=read(),k=read();MAX=1<<k-1;k++;
    for(ri i=1,x,y,z;i<=m;++i)
        x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
    for(ri i=1;i<=k;++i)for(ri j=1;j<=n;++j)dis[i][j]=0x3f3f3f3f;
    if(k==1){dij(1),write(dis[1][n]);exit(0);}
    memset(dp,0x3f,sizeof(dp));
    int Q=read();
    for(ri i=1,a,b;i<=Q;++i)
        a=read(),b=read(),fa[b]|=1<<a-2,in[b]++;
    for(ri i=2;i<=k;++i){dij(i);if(!in[i])dp[0][i-2]=dis[i][1];}
    // for(ri i=1;i<=k;++i)cout<<fa[i]<<' ';
    // cout<<endl;
}
inline void DP(){
    // for(ri i=2;i<=k;++i){
    //     cout<<i<<endl;
    //     for(ri j=1;j<=k;++j)
    //     cout<<dis[i][j]<<' ';
    //     cout<<dis[i][n];
    //     cout<<endl;
    // }
    for(ri i=0;i<MAX;++i){
        for(ri j=2;j<=k;++j){
            if(dp[i][j-2]==0x3f3f3f3f)continue;
            // cout<<i<<' '<<j<<' '<<dp[i][j-2]<<'\n';
            for(ri w=2;w<=k;++w){;
                int left=(i>>j-2)<<j-2;int right=i-left;
                int zc=(left<<1)+right+(1<<j-2);
                if((zc&(1<<w-2))||(zc&fa[w])!=fa[w])continue;
                left=(zc>>w-1)<<w-1;right=zc-left;
                zc=(left>>1)+right;
                dp[zc][w-2]=min(dp[zc][w-2],dp[i][j-2]+dis[j][w]);
                // cout<<dp[i|(1<<w-2)][w-2]<<' '<<w<<endl;
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(ri i=2;i<=k;++i){
        ans=min(ans,dp[MAX-1][i-2]+dis[i][n]);
    }
    write(ans);
}
int main(){
    prepare();
    DP();
}