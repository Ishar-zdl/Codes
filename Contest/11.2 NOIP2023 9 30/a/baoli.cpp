/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-02 08:08:25 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-02 08:11:13
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
main(){
    freopen("a.in","r",stdin),freopen("right.out","w",stdout);
    int n=read();
    for(int i=1;i<n;++i){
        if(i*i%n==0){printf("%d",i);return 0;}
    }   
    printf("-1");return 0;
}