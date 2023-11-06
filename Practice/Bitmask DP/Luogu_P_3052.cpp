/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-10 10:18:14 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-10 15:45:37
 */
#include<bits/stdc++.h>
#define ri register int
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
const int N=1<<18;
int n,m,MAX,w[20],dp[N],g[N];
inline void prepare(){
    memset(dp,0x3f,sizeof(dp));
    n=read();m=read();MAX=1<<n;
    for(ri i=1;i<=n;++i)w[i]=read();
    g[0]=m;dp[0]=1;
}
inline void DP(){
    for(int i=0;i<MAX;++i)
        for(int j=1;j<=n;++j){
            if(i&(1<<j-1))continue;
            if(g[i]>=w[j]&&dp[i|(1<<j-1)]>=dp[i])
                dp[i|(1<<j-1)]=dp[i],
                g[i|(1<<j-1)]=max(g[i|1<<j-1],g[i]-w[j]);
            if(g[i]<w[j]&&dp[i|(1<<j-1)]>=dp[i]+1)
                dp[i|(1<<j-1)]=dp[i]+1,
                g[i|(1<<j-1)]=max(g[i|(1<<j-1)],m-w[j]);   
        }
    write(dp[MAX-1]);
}
inline void work(){
    prepare();
    DP();
}
int main(){
    work(); 
}