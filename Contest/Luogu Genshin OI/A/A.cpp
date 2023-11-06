/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-29 14:07:00 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-29 15:25:19
 */
#include<bits/stdc++.h>
#define int long long
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
// const int N=(int)1e5+5;
main(){
#ifdef ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
#endif
    int T=read();
    while(T--){
        int n=read(),suma=0,sumb=0;
        bool pd=0;
        for(int a,b,i=1;i<=n;++i){
            a=read(),b=read();
            if(pd)continue;
            suma+=a;
            if(suma>sumb){printf("0\n");pd=1;}
            sumb+=b;
        }
        if(pd)continue;
        printf("%d\n",n+1);
    }
}