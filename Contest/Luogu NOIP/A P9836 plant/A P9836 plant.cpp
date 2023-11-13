/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-13 16:59:50 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-13 19:47:28
 */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FRE freopen("in.in","r",stdin),freopen("out.out","w",stdout);
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int N=1e4+10,mod=998244353;
int p[1500],prim[N],n,tot,a[N],w,ans=1;
std::priority_queue<int,std::vector<int>,std::greater<int>>q;
std::unordered_map<int,int>mp;
bool vis[N];
inline void get_prime(){
    for(int i=2;i<=N-3;++i){
        if(!vis[i])prim[++tot]=i,mp[i]=tot;
        for(int j=1;j<=tot&&prim[j]*i<=N-3;++j){
            vis[i*prim[j]]=true;
            if(i%prim[j]==0)break;
        }
    }
}
inline void fact(int x){
    int pos=x;
    for(int i=2;i*i<=pos;++i){
        int sd=mp[i];
        while(x%i==0)p[sd]++,x/=i;
    }
    if(x!=1)p[mp[x]]++;
}
main(){
    // FRE
    n=read();w=read();get_prime();
    for(int i=1;i<=n;++i)a[i]=read();
    int zc=w;
    for(int i=1;prim[i]<=zc;++i){
        if(w%prim[i]==0){
            int num=0;
            while(w%prim[i]==0)num++,w/=prim[i];
            for(int j=1;j<=n;++j){
                int nu=1;
                while(a[j]%prim[i]==0)nu++,a[j]/=prim[i];
                q.push(nu);
            }
            while(num--){
                int x=q.top();q.pop();x++;q.push(x);
            }
            while(!q.empty())ans=ans*q.top()%mod,q.pop();
        }
    }
    for(int i=1;i<=n;++i){
        int zc=a[i];
        for(int j=1;prim[j]<=zc;++j){
            int nu=1;
            while(a[i]%prim[j]==0)nu++,a[i]/=prim[j];
            ans=ans*nu%mod;
        }
    }
    printf("%lld",ans);
    // fact
    // for(int i=2;i*i<)
    // for(int i=1;i<=N-3;++i)a[i]=read();
}