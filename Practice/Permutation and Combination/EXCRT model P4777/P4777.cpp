/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-09 11:12:59 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-09 14:42:57
 */
#include<bits/stdc++.h>
typedef __int128 ll;
inline ll read(){
    char ch=getchar();
    ll x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(ll x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int N=1e5+10;
ll n,m[N],r[N];
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1,y=0;return a;}
    ll d,x1,y1;
    d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
ll excrt(ll *m,ll *r){
    ll m1,m2,r1,r2,p,q;
    m1=m[1],r1=r[1];
    for(int i=2;i<=n;++i){
        m2=m[i],r2=r[i];
        ll d=exgcd(m1,m2,p,q);
        if((r2-r1)%d){return -1;}
        p=p*(r2-r1)/d;
        p=(p%(m2/d)+m2/d)%(m2/d);
        r1=m1*p+r1;m1=m1*m2/d;
    }
    return (r1%m1+m1)%m1;
}
int main(){
    n=read();
    for(int i=1;i<=n;++i)m[i]=read(),r[i]=read();
    write(excrt(m,r));
    return 0;
}
