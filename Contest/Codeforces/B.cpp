/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-08 17:38:55 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-08 18:01:59
 */
#include<bits/stdc++.h>
#define int long long
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
const int N=1e5+10;
int n,p;
pair<int,int>villager[N];
inline void work(){
    n=read(),p=read();
    for(int i=1;i<=n;i++){
        villager[i].second=read();
    }
    for(int i=1;i<=n;i++){
        villager[i].first=read();
    }
    villager[n+1]={p,1e5+10};
    sort(villager+1,villager+n+2);
    int people=1,ans=p;
    for(int i=1;i<=n+1;++i){
        if(people<i)people++,ans+=p;
        int zc=min(villager[i].second,n-people);
        if(zc<=0)break;
        ans+=zc*villager[i].first;people+=zc;
    }
    write(ans);putchar('\n');
}
main(){
    int t=read();
    while(t--){
        work();
    }   
}