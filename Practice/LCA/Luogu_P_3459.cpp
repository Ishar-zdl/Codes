//与5k卡常竞赛 经Flanders究极卡常后拿了最优解 记录
/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-25 17:11:39 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-25 21:12:13
 */
#include<bits/stdc++.h>
#define N 250005
using namespace std;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define flush() (fwrite(obuf,1,O-obuf,stdout))
#define putchar(x) (O==obuf+(1<<21)&&(flush(),O=obuf),*O++=(x))
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*O=obuf;
class Flush{public:~Flush(){flush();}}_;
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
void write(int x){
    if(x>9)write(x/10);
    putchar(x%10+48);
}
struct Skadi{
    int v,next;
}e[N];
int n,d[N],l[N],r[N],tot,c[N],h,head[N];
void dfs(int x,int fa){
    d[x]=d[fa]+1;tot++;l[x]=tot;
    for(int i=head[x],v;i;i=e[i].next){v=e[i].v;if(v^fa)dfs(v,x);}
    r[x]=tot;
}
inline int query(int a){
    register int ans=0;
    for(;a;a-=a&-a)ans+=c[a];
    return ans;
}
int main(){
    n=read();d[0]=-1;
    for(register int i=1,u,v;i<n;++i){
        u=read(),v=read();e[++h]={v,head[u]};head[u]=h;
    }dfs(1,0);int m=read();m=n+m-1;
    for(register int i=1,a,b;i<=m;++i){
        register char pd=getchar();while(pd<'A'||pd>'Z')pd=getchar();
        a=read();
        if(pd=='A'){
            b=read();register int ll=l[b],rr=r[b]+1;
            for(;ll<=n;ll+=ll&-ll)++c[ll];
            for(;rr<=n;rr+=rr&-rr)--c[rr];
            continue;
        }
        write(d[a]-query(l[a]));putchar('\n');
    }
}