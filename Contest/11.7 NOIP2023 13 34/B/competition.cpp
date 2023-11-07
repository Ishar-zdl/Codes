/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-07 18:59:46 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-07 22:03:52
 */
#include<bits/stdc++.h>
#define ll long long
// #define int long long
inline ll read(){
    char ch=getchar();ll x=0,f=1;
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
const int N=1e6+10,mod=1e9+7;
int n,c;
ll m,l[N],r[N],p[N*2];
std::pair<int,int>opt[N*2];
std::set<int>s;
inline int f(int n){return 1ll*n*(n+1)/2%mod;}
inline void del(int &a,int b){a-=b;(a<0)&&(a+=mod);}
inline void add(int &a,int b){a+=b;(a>=mod)&&(a-=mod);}
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ans=1ll*ans*a%mod;
    return ans;
}
int main(){
    freopen("competition.in", "r", stdin);freopen("competition.out", "w", stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i){
        l[i]=read();r[i]=read();r[i]++;p[++c]=l[i],p[++c]=r[i];
    }
    p[++c]=1;std::sort(p+1,p+1+c);c=std::unique(p+1,p+1+c)-p-1;p[c+1]=m+1;//离散化加边界
    for(int i=1;i<=n;++i){
        l[i]=std::lower_bound(p+1,p+1+c,l[i])-p;r[i]=std::lower_bound(p+1,p+1+c,r[i])-p;
        opt[2*i-1]={l[i],i};opt[2*i]={r[i],-i};
    }
    std::sort(opt+1,opt+1+2*n);
    int ans=0,now=f(n);
    s.insert(0),s.insert(n+1);//边界
    int it=1;
    for(int i=1;i<=c;++i){
        while(it!=2*n+1&&opt[it].first==i){
            int k=opt[it].second;
            if(k>0){
                auto it=s.insert(k).first;
                int l=*prev(it),r=*next(it);
                del(now,f(r-l-1)),add(now,f(k-l-1)),add(now,f(r-k-1));
            }
            else{
                k*=-1;
                auto it=s.lower_bound(k);
                int l=*prev(it),r=*next(it);
                add(now,f(r-l-1)),del(now,f(k-l-1)),del(now,f(r-k-1));
                s.erase(it);
            }
            it++;
        }
        ans=(ans+(p[i+1]-p[i])%mod*now)%mod;
    }
    ans=(m-1ll*ans*qpow(f(n),mod-2)%mod+mod)%mod;
    printf("%d",ans);
}