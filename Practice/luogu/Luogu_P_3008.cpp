#include<bits/stdc++.h>
#define N 25005
using namespace std;
int n,p,r,s,deg[N],bl[N],tot,dis[N];
bool vis[N];
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
}priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
queue<int>dui;
vector<pair<int,int> >node[N];vector<int>block[N];
void dfs(int x){
    bl[x]=tot;block[tot].push_back(x);
    for(auto i:node[x]){
        int y=i.first;if(!bl[y])dfs(y);
    }
}
int main(){
    n=read(),p=read(),r=read(),s=read();int a,b,c;
    for(int i=1;i<=n;++i)dis[i]=1073741824;dis[s]=0;
    for(register int i=1;i<=p;++i){
        a=read(),b=read(),c=read();node[a].push_back({b,c}),node[b].push_back({a,c});
    }for(int i=1;i<=n;++i)if(!bl[i])tot++,dfs(i);
    for(int i=1;i<=r;++i){
        a=read(),b=read(),c=read();node[a].push_back({b,c});deg[bl[b]]++;
    }for(int i=1;i<=tot;++i)if(!deg[i])dui.push(i);if(deg[bl[s]])dui.push(bl[s]);//deg[bl[s]]=
    // for(int i=1;i<=tot;++i){
    //     for(auto j:block[i])cout<<j<<' ';
    //     cout<<endl;
    // }for(int i=1;i<=tot;++i)cout<<deg[i]<<' ';cout<<endl;
    while(!dui.empty()){
        int k=dui.front();dui.pop();
        for(int i:block[k])q.push({dis[i],i});
        while(!q.empty()){
            int x=q.top().second,d=q.top().first;q.pop();
            if(vis[x])continue;vis[x]=1;
            for(int i=0;i<node[x].size();++i){
                int y=node[x][i].first;
                // cout<<x<<' '<< y<<endl;
                if(dis[y]>dis[x]+node[x][i].second&&dis[x]!=1073741824){
                    dis[y]=dis[x]+node[x][i].second;
                    if(!vis[y]&&bl[y]==bl[x])q.push({dis[y],y});
                    
                }if(bl[y]!=bl[x]){
                        deg[bl[y]]--;if(dis[x]!=1073741824)dis[y]=min(dis[y],dis[x]+node[x][i].second);
                        // cout<<deg[bl[y]]<<endl;
                        // cout<<dis[x]<<' '<<dis[y]<<endl;
                        if(!deg[bl[y]])dui.push(bl[y]);
                    }
            }
        }
        // cout<<endl;
    }
    // return 0;
    for(int i=1;i<=n;i++)if(dis[i]==1073741824)puts("NO PATH");else printf("%d\n",dis[i]);
    return 0;
}