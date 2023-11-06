/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-08 15:23:00 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-08 17:27:33
 */
#include<bits/stdc++.h>
#define ri register int
const int N=(1<<19)+10;
const double eps=1e-7;
int n,m,dp[N],line[20][20],lowbit[N];
double x[20],y[20];
inline void op(int i,int j){
    if(x[i]==x[j])return;
    double a=(y[j]*x[i]-y[i]*x[j])/(x[j]*x[j]*x[i]-x[i]*x[i]*x[j]);
    if(a>=0)return;
    double b=(y[i]-a*x[i]*x[i])/x[i];
    for(ri k=1;k<=n;++k)
        if(std::fabs(a*x[k]*x[k]+b*x[k]-y[k])<eps)
            line[i][j]|=1<<k-1;
}
inline void prepare(){
    std::cin>>n>>m;
    for(ri i=1;i<=n;i++)
        for(ri j=1;j<=n;++j)
            line[i][j]=0;
    for(int i=1;i<(1<<n);++i)dp[i]=0x7f7f7f7f;
    for(int i=1;i<=n;++i)std::cin>>x[i]>>y[i];
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            op(i,j);
}
inline void DP(){
    for(ri i=0;i<(1<<n);++i){
        int j=lowbit[i];
        dp[i|(1<<j-1)]=std::min(dp[i|(1<<j-1)],dp[i]+1);
        for(int k=1;k<=n;++k)dp[i|line[j][k]]=std::min(dp[i|line[j][k]],dp[i]+1);
    }
    printf("%d\n",dp[(1<<n)-1]);
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    int t;std::cin>>t;
    for(ri i=0;i<(1<<18);i++){
        int j=1;
        for(;j<=18&&i&(1<<(j-1));j++);
        lowbit[i]=j;
    }
    // return 0;
    while(t--){
        prepare();
        DP();
        // if(t==0)return 0;
    }
    return 0;
}