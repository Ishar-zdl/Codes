/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-07 08:16:41 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-07 09:08:23
 */
#include<bits/stdc++.h>
#define lowbit(i) (i&-i)
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
const int N=1<<20;
int n,m,h[25];
long long dp[N];
int main(){
    n=read(),m=read();dp[0]=1;
    for(int i=1,x,y;i<=m;i++){
        x=read(),y=read(),h[x]|=1<<y-1;
    }
    for(int s=1;s<(1<<n);++s){
        int cnt=0;
        for(int r=s;r;r-=lowbit(r))cnt++;
        for(int r=s;r;r-=lowbit(r)){
            if(!(h[cnt]&(lowbit(r)))){
                dp[s]+=dp[s^(lowbit(r))];
            }
        }
    }
    printf("%lld",dp[(1<<n)-1]);
}