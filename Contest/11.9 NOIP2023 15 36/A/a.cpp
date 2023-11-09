/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-09 07:38:38 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-09 18:23:26
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
int p,q,a,b,c,d,qpow[31];
inline int pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;
    return ans;
}
main(){
    freopen("a.in","r",stdin);freopen("a.out","w",stdout);
    qpow[0]=1;
    for(int i=1;i<=30;++i)qpow[i]=qpow[i-1]*2;
    p=read(),q=read();
    while(q--){
        a=read(),b=read(),c=read(),d=read();
        int s=(a+b)%p;s=pow(s,p-2);
        // std::cout<<s<<"fdsjkl\n";
        if((a+b)%p!=(c+d)%p){printf("-1\n");continue;}
        if(a==c&&b==d){printf("0\n");continue;}
        int k;
        for(k=1;k<=std::__lg(p);++k){
            int q=(qpow[k]*a-c+p)%p*s%p;
            if(q>=0&&q<qpow[k])break;
        }
        printf("%lld\n",k);
    }
}