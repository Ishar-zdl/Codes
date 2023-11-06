/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 09:09:32 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 09:18:53
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
// bool vis[205];
int du[205];
std::vector<int>node[205];
// void dfs(int x){
//     vis[x]=true;
//     for(int i:node[x]){
//         if(!vis[i])dfs(vis[i])
//     }
// }
int main(){
    freopen("irises.out","r",stdin);
    int A=read(),B=read();
    int n=read();
    for(int i=1;i<n;++i){
        int a=read(),b=read();
        du[a]++,du[b]++;
        // node[a].push_back(b);
    }
    int a=0,b=0;
    for(int i=1;i<=n;++i){
        if(du[i]==1)a++;
        if(du[i]==3)b++;
    }
    if((A==a)&&(b=B)){std::cout<<"AC\n";}
    else std::cout<<"WA\n";
    return 0;
    // dfs(1);
}