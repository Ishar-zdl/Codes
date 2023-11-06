#include<bits/stdc++.h>
#define fo(i,n) for(int i=1;i<=n;i++)
#define N int(2e4+5)
using namespace std;
vector<int>fa[N];
int n,m,a,b,dfn[N],low[N],tot,stk[N];
int instk[N],top,scc[N],siz[N],cnt;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    stk[++top]=x,instk[x]=1;
    for(int i=0;i<fa[x].size();i++){
        int y=fa[x][i];
        if(!dfn[y]){
            tarjan(y);low[x]=min(low[x],low[y]);
        }
        else if(instk[y])low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x]){
        int y;++cnt;
        do{
            y=stk[top--];instk[y]=0;
            scc[y]=cnt;++siz[cnt];
        }while(y!=x);
    }
}
int main(){
    int n=read(),m=read();
    fo(i,m){
        int a=read(),b=read();
        fa[a].push_back(b);
    }
    fo(i,n)if(!dfn[i])tarjan(i);
    int ans=0;
    fo(i,cnt)if(siz[i]>1)ans++;
    write(ans);
    return 0;
}