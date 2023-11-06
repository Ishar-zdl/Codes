/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-14 09:48:49 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-14 11:24:14
 */
#include<bits/stdc++.h>
#define ll long long
#define int long long
int mod=1e9+7;
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
struct mt{
    ll a[3][3];
    mt(){memset(a,0,sizeof a);}
    mt operator*(const mt&b)const{
        mt res;
        for(int i=1;i<=2;++i)
            for(int j=1;j<=2;++j)
                for(int k=1;k<=2;++k)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
        return res;
    }
}ans,base;
inline void qpow(int b){
    ans.a[1][1]=ans.a[1][2]=1;
    base.a[1][2]=base.a[2][1]=base.a[2][2]=1;
    while(b){
        if(b&1)ans=ans*base;
        base=base*base;b>>=1;
    }
    write(ans.a[1][2]);
}
main(){
    int n=read();
    if(n<=2)return write(1),0;
    qpow(n-2);
}