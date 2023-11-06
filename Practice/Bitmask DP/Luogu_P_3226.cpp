/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-11 19:00:53 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-11 21:38:51
 */
#include<bits/stdc++.h>
#define mod 1000000001
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
const int MAX=1<<12;
int flag[2077],book[(int)1e5+5];
long long n,ans=1,num[18],f[18][MAX];
inline void DP(int x){
    int p=1,sum=0;memset(f,0,sizeof(f));memset(num,0,sizeof(num));
    for(int i=x;i<=n;i<<=1,++p)for(int j=i;j<=n;j*=3)++num[p],book[j]=1;
    for(int i=0;i<(1<<num[1]);++i)f[1][i]=flag[i];
    for(int i=2;i<p;++i)
        for(int j=0;j<(1<<num[i-1]);++j)
            for(int k=0;k<(1<<num[i]);++k)
                if(flag[j]&&flag[k]&&!(j&k))f[i][k]=(f[i][k]+f[i-1][j])%mod;
    for(int i=0;i<(1<<num[p-1]);++i)sum=(sum+f[p-1][i])%mod;
    ans=ans*sum%mod;
}
int main(){
    n=read();
    for(int i=0;i<=2048;++i)flag[i]=((i<<1)&i)?0:1;
    for(int i=1;i<=n;++i)if(!book[i])DP(i);
    write(ans);
}