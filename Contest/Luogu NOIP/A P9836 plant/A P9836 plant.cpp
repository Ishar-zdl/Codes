/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-13 16:59:50 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-13 17:02:23
 */
#include<bits/stdc++.h>
#define endl '\n'
#define FRE freopen("in.in","r",stdin),freopen("out.out","w",stdout);
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
       
}