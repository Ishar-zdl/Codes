/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 11:02:12 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 12:00:23
 */
#include<bits/stdc++.h>
#define endl '\n';
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
const int N=9e5+10;
int n,m,u[N],v[N],du[N],ans[N],zc[N];
int main(){
    n=read(),m=read();
    for(int i=1;i<=m;++i){
        u[i]=read(),v[i]=read();
        du[u[i]]++,du[v[i]]++;
        zc[u[i]]++,zc[v[i]]++;
    }
    int tot=0;
    for(int i=m;i;--i){
        ans[i]=1;
        if(!(du[u[i]]&1)&&!(du[v[i]]&1)){
            du[u[i]]--,du[v[i]]--;
            tot++;
            ans[i]=0;
        }
    }
    int ANS;
    for(int i=0;i<(1<<m)-1;++i){
        std::bitset<21>bit=i;
        if(bit.count()==tot){
            for(int i=0;i<n;++i)du[i]=zc[i];
            int zctot=0;
            for(;i;i-=i&-i){
                int pos=std::__lg(i&-i)+1;
                if(!(du[u[pos]]&1)&&!(du[v[pos]]&1)){
                    du[u[pos]]--,du[v[pos]]--;
                    zctot++;
                }
                else break;
            }
            if(zctot==tot)int 
        }
    }
    for(int i=1;i)
    for(int i=1;i<=m;++i){
        printf("%d",ans[i]);
    }
}