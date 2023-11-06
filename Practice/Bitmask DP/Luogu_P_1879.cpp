/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-10 08:18:16 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-10 09:57:30
 */
#include<bits/stdc++.h>
#define mod 100000000
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
const int N=1<<12;
int m,n,MAX,ban[15],dp[15][N],tot,f[15][2000],g[2000],num[15];
inline void prepare(){
    m=read(),n=read();
    MAX=1<<n;
    for(ri i=1;i<=m;++i)
        for(ri j=1;j<=n;++j){
            int a=read();
            if(!a)ban[i]|=1<<j-1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        }
    for(ri i=0;i<MAX;++i)
        if(!(i&i<<1))g[++tot]=i;
    for(ri i=1;i<=m;++i)
        for(ri j=1;j<=tot;++j)
            if(!(g[j]&ban[i])){
                f[i][++num[i]]=g[j];
            }
    num[0]=1;dp[0][1]=1;
}
inline void DP(){
    int ans=0;
    for(ri i=1;i<=m;++i){
        for(ri j=1;j<=num[i];++j){
            for(ri k=1;k<=num[i-1];++k){
                if(f[i][j]&f[i-1][k])continue;
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod; 
            }
            if(i==m)ans=(ans+dp[i][j])%mod;
        }
    }
    write(ans);
}
inline void work(){
    prepare();
    DP();
}
int main(){
    work();
}