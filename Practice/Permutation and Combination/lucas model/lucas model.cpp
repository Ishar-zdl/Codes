/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-05 16:31:40 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-05 17:05:30
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
const int N=1e5+10;
int a[N];
inline int pow(int a,int b,int p){
    int ans=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;
    return ans;
}
inline int C(int n,int m,int p){
    if(m>n)return 0;
    return ((a[n]*pow(a[m],p-2,p))%p*pow(a[n-m],p-2,p)%p);
}
inline int lucas(int n,int m,int p){
    if(!m)return 1;
    return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
main(){
    int T=read();
    while(T--){
        int n=read(),m=read(),p=read();
        a[0]=1;
        for(int i=1;i<p;++i)a[i]=a[i-1]*i%p;
        printf("%d\n",lucas(n+m,n,p));
    }
}