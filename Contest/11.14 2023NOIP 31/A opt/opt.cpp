/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-14 08:02:49 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-14 08:03:26
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
//排完序后，考虑只对前半部分进行操作；
//感觉可以拿个优先队列来维护；，每次操作后放回去，