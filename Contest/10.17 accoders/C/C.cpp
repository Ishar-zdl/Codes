/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-17 17:40:59 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-17 19:51:31
 */
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
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
}
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
const int N=(5e5+5)*2,P=131;
int X,Y,n,mx1,mx2,hs[N];
pair<int,int>x[N],y[N],len[N];
unordered_map<int,int>mp1;
inline void input(){
    n=read(),X=read(),Y=read();
    for(int i=1;i<=n;++i){
        hs[i]=hs[i-1]*P+mt();
        x[i].first=read(),y[i].first=read(),x[n+i].first=read(),y[i+n].first=read();
        x[i].second=y[i].second=x[i+n].second=y[i+n].second=i;
    }
    int tot=0;sort(x+1,x+1+2*n);
    for(int i=1;i<=2*n;++i){
        len[++tot].first=x[i].first-x[i-1].first;
        len[tot].second=x[i].second;
    }
    len[++tot].first=X-x[2*n].first;int qp=0;
    for(int i=1;i<=tot;++i){
        mp1[qp]+=len[i].first;
        mx1=max(mx1,mp1[qp]);
        qp^=hs[len[i].second];
    }
    tot=0;sort(y+1,y+1+2*n);
    for(int i=1;i<=2*n;++i){
        len[++tot].first=y[i].first-y[i-1].first;
        len[tot].second=y[i].second;
    }
    len[++tot].first=Y-y[2*n].first;qp=0;
    mp1.clear();
    for(int i=1;i<=tot;++i){
        mp1[qp]+=len[i].first;
        mx2=max(mx2,mp1[qp]);
        qp^=hs[len[i].second];
    }
    write(mx1*mx2);
    // std::cerr << sizeof(x) << '\n';
}
main(){
    // freopen("globe.in","r",stdin),freopen("globe.out","w",stdout);
    input();
    return 0;
}