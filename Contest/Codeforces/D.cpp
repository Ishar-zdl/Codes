/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-08 19:13:17 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-08 19:44:18
 */
#include<bits/stdc++.h>
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
const long long mod=998244353;
inline long long qpow(int n){
    if(n==0)return 1;
    if(n==1)return 2;
    int temp=qpow(n/2);
    if(n&1)return temp%mod*temp%mod*2%mod;
    else return temp%mod*temp%mod;
}
inline bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first>b.first;
}
int a[(int)(1e5+10)],num[(int)(1e5+10)] ;pair<int,int>m[(int)(1e5+10)];
long long ans=0;
int main(){
    int n=read();
    for(int i=1;i<=n;i++)a[i]=read(),m[i].second=i;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i){
            m[i].first=max(m[i].first,a[j]);
        }
    sort(m+1,m+n+1,cmp);
    for(int i=1;i<=n;i++){
        num[i]=n-i;
    }
    // cout<<qpow(0)<<endl<<"dlfksklj";
    for(int i=1;i<=n;i++){
        // cout<<qpow(num[i])<<' '<<m[i].first<<endl;
        ans=(ans+(qpow(num[i])*m[i].first)%mod)%mod;
    }
    write(ans);
}