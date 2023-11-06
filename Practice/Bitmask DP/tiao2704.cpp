/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-07 15:09:04 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-08 15:17:47
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
const int N=105;
int n,m,tot[105],pre[105][N],h[105];
long long dp[105][N][N],num[105][N],ans=0;
inline void prepare(){
    n=read();m=read();
    for(ri cnt=1;cnt<=n;cnt++){
        for(ri l=1;l<=m;l++){
            char ch=getchar();
            while(ch!='P'&&ch!='H')ch=getchar();
            if(ch=='H')h[cnt]+=1<<l-1;
        }
        for(int i=0;i<(1<<m);i++){
            if((i&(i<<2))||(i&(i<<1))||(i&(h[cnt])))continue;
            tot[cnt]++;
            for(int w=i;w;w-=w&-w)num[cnt][tot[cnt]]++;
            pre[cnt][tot[cnt]]=i;
        }
    }tot[0]=1;pre[0][1]=0;
    for(int i=1;i<=tot[1];++i)dp[1][i][1]=num[1][i],ans=max(ans,dp[1][i][1]);
} 
inline void DP(){
    // long long ans=0;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=tot[i];++j){
            for(int k=1;k<=tot[i-1];++k){
                if(pre[i][j]&pre[i-1][k])continue;
                for(int l=1;l<=tot[i-2];++l){
                    if((pre[i][j]&pre[i-2][l])||(pre[i-1][k]&pre[i-2][l]))continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+num[i][j]);
                    if(i==n)ans=max(ans,dp[i][j][k]);
                }
            }
        }
    }
    write(ans);
}
int main(){
    prepare();
    DP();
}