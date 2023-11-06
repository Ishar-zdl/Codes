/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-11 11:22:13 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-11 17:12:09
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
const int MAXX=1<<5,N=1e4+10;
int n,m,get[N][2],dp[N][32],num[N][32];
bool a[N];
inline void prepare(){
    n=read(),m=read();
    for(ri i=1,a,b,c,LIKE,FAIR;i<=m;++i){
        a=read(),b=read(),c=read();LIKE=FAIR=0;
        for(ri j=1,t;j<=b;++j)t=read(),FAIR|=1<<(t-a+n)%n; //FAIR|=1<<((read()-a+n)%n);
        for(ri j=1,t;j<=c;++j)t=read(),LIKE|=1<<(t-a+n)%n; //LIKE|=1<<((read()-a+n)%n);
        for(ri s=0;s<=31;++s)
            if((s&LIKE)||((~s)&FAIR))num[a][s]++;
    }
}
inline void DP(){
    int ans=0;
    for(ri k=0;k<32;++k){
        memset(dp[0],128,sizeof(dp[0]));
        dp[0][k]=0;
        for(ri i=1;i<=n;++i)
            for(ri s=0;s<32;++s){
                dp[i][s]=max(dp[i-1][(s&15)<<1|1],dp[i-1][(s&15)<<1])+num[i][s];
                // ans=max(ans,dp[i][s]);
            }
        ans=max(ans,dp[n][k]);
    }
    write(ans);
}
int main(){
    prepare();
    DP();
}