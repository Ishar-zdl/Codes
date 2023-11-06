/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-17 09:30:22 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-17 11:21:07
 */

//±©Á¦
#include<bits/stdc++.h>
#define int unsigned long long
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
const int N=2e5+5;
int n,a,sum[N],ans=0;
inline int qpow(int b){
    int ans=1,base=2;
    for(;b;b>>=1,base*=base)
        if(b&1)ans*=base;
    return ans;
}
main(){
    freopen("sequence.in","r",stdin),freopen("sequence.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
        a=read(),a=qpow(a),sum[i]=sum[i-1]+a;
    for(int len=2;len<=n;++len){
        for(int r=len;r<=n;++r){
            int w=sum[r]-sum[r-len];
            if(__builtin_popcountll(w)==1)ans++;
        }
    }
    write(ans+n);
}