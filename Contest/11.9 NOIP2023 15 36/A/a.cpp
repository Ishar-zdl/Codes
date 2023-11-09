/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-09 07:38:38 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-09 10:15:08
 */
#include<bits/stdc++.h>
#define int long long 
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
int p,q,a,b,c,d;
main(){
    freopen("a.in","r",stdin);freopen("a.out","w",stdout);
    p=read(),q=read();
    while(q--){
        a=read(),b=read(),c=read(),d=read();
        if((a+b)%p!=(c+d)%p){printf("-1\n");continue;}
        if(a==c&&b==d){printf("0\n");continue;}
        int base=2;
        int ans=1e9,zc;
        for(int i=1;i<p;++i,base=base*2%p){
            if(a*base%p==c){zc=i;ans=std::min(i,ans);break;}
            if(a*base%p==a){break;}
        }base=2;
        for(int i=1;i<p;++i,base=base*2%p){
            if(b*base%p==d){zc=i;ans=std::min(i,ans);break;}
            if(b*base%p==b){break;}
        }base=2;
        if(ans!=1e9){printf("%lld\n",ans);continue;}
        for(int i=1;i<p;++i,base=base*2%p){
            if(a*base%p==d){zc=i;ans=std::min(i,ans);break;}
            if(a*base%p==a){break;}
        }base=2;
        for(int i=1;i<p;++i,base=base*2%p){
            if(b*base%p==c){zc=i;ans=std::min(i,ans);break;}
            if(b*base%p==b){break;}
        }
        printf("%lld\n",ans);
    }
}
//他们的和在模 p 意义下都相等,但是咋找步数?