/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-01 08:12:59 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-01 17:24:57
 */
#include<bits/stdc++.h>
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
const int N=2e5+5;
int n,k,a[N],cnt[N];
struct tree{
    int sum,ls,rs;
    #define sum(p) t[p].sum
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define lc p<<1
    #define rc p<<1|1
}t[N*4];
inline void add(int p,int l,int r,int x){
    if(l==r){sum(p)=rs(p)=ls(p)=(cnt[x]?1:0);return;}
    int mid=l+r>>1;
    if(x<=mid)add(lc,l,mid,x);
    else add(rc,mid+1,r,x);
    ls(p)=ls(lc)+((ls(lc)==(mid-l+1))?ls(rc):0);
    rs(p)=rs(rc)+((rs(rc)==(r-mid))?rs(lc):0);
    sum(p)=std::max(std::max(sum(lc),sum(rc)),rs(lc)+ls(rc));
}
int main(){
    CIN_sync();
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    std::cin>>n>>k;
    long long ans=0;
    for(int i=1;i<=n;++i)std::cin>>a[i];
    cnt[a[1]]++,add(1,1,n,a[1]);
    for(int l=1,r=2;l<=n;++l){
        while(r<=n){
            cnt[a[r]]++;if(cnt[a[r]]==1)add(1,1,n,a[r]);
            if(sum(1)<=k){r++;continue;}
            --cnt[a[r]];if(!cnt[a[r]])add(1,1,n,a[r]);
            break;
        }
        ans+=r-l;--cnt[a[l]];
        if(!cnt[a[l]])add(1,1,n,a[l]);
    }
    std::cout<<ans;
    // printf("%lld\n",ans);
}