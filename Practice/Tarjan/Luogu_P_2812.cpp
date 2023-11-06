#include<bits/stdc++.h>
using namespace std;
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
const int N=1e5+10;int n,m,a,b;
vector<int>e[N];
int dfn[N],low[N],tot,stk[N],instk[N],top,scc[N],cnt,din[N],dout[N];
inline void tarjan(int x){
  dfn[x]=low[x]=++tot;
  stk[++top]=x;instk[x]=1;
  for(int y:e[x]){
    if(!dfn[y]){
      tarjan(y);low[x]=min(low[x],low[y]);
    }
    else if(instk[y])
      low[x]=min(low[x],low[y]);
  }
  if(dfn[x]==low[x]){
    int y;++cnt;
    do{
      y=stk[top--];instk[y]=0;scc[y]=cnt;
    }while(y!=x);
  }
}
int main(){
    n=read();
    for(int i=1,a;i<=n;i++)
      while(a=read())e[i].push_back(a);
    for(int i=1;i<=n;i++)
      if(!dfn[i])tarjan(i);
    for(int x=1;x<=n;x++)
      for(int y:e[x])
        if(scc[x]!=scc[y]){
            din[scc[y]]++;dout[scc[x]]++;
        }
    int a=0,b=0;
    for(int i=1;i<=cnt;i++){
        if(!din[i])a++;
        if(!dout[i])b++;
    }
    write(a);putchar('\n');
    if(cnt==1)write(0);
    else write(max(a,b));
    return 0;
}