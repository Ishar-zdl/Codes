/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-07 8:46:40 
 * @Last Modified by:   Ishar-zdl 
 * @Last Modified time: 2023-10-07 14:55:40 
 */
#include<bits/stdc++.h>
#define ri register int
#define lowbit(i) (i&-i)
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(long long x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
const int N=1<<9;
int n,m,MAX,pre[100],tot,num[100];
long long dp[12][100][100];
void prepare(){
    n=read(),m=read(),MAX=(1<<n)-1;
    for(ri i=0;i<=MAX;++i){//exit(0);
        if(i&(i<<1))continue;
        pre[++tot]=i;int cnt=0;
        for(ri zc=i;zc;zc-=zc&-zc)cnt++;
        num[tot]=cnt;                           //这种状态要放的国王数量
        dp[1][tot][cnt]=1;
        
    }
}
void DP(){
    // 先枚举层数，再枚举当前状态，再枚举上一层状态，判断是否合法，如果合法，枚举国王的数量，然后相加。
    for(ri i=2;i<=n;i++){
        for(ri j=1;j<=tot;++j){
            for(ri k=1;k<=tot;++k){
                if(pre[j]&pre[k])continue;
                if(pre[j]&(pre[k]>>1))continue;
                if(pre[j]&(pre[k]<<1))continue;
                for(ri s=m;s>=num[k]+num[j];--s){dp[i][j][s]+=dp[i-1][k][s-num[j]];}
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=tot;i++)ans+=dp[n][i][m];
    write(ans);
}
int main(){
    prepare();
    DP();
}