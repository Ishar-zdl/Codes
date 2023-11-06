/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 20:06:11 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 20:16:49
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
unsigned long long qpow(int a){
    int b=a;
    unsigned long long base=a,ans=1;
    while(b){
        if(b&1)ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}
int main(){
    unsigned long long b;
    std::cin>>b;
    for(unsigned long long i=1;i<=30;++i){
        if(qpow(i)==b){std::cout<<i<<'\n';return 0;}
    }
    std::cout<<-1<<'\n';
    // long long a=sqrt(b);
    // if(pow(a,a)==b)std::cout<<a<<'\n';
    // else std::cout<<-1<<'\n';
}