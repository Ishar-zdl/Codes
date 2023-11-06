/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-03 08:02:30 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-03 12:01:28
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
int main(){
    freopen("game.in","r",stdin);freopen("game.out","w",stdout);
    int n=read(),m=read();
    if(!m){printf("Bob\n");return 0;}
    printf("Alice\n"); 
    return 0;
}