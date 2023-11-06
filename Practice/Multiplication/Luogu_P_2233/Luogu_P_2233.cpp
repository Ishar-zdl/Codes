/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-14 19:09:21 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-14 20:20:13
 */
//正解矩阵快速幂，O(n)也能跑。
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
const int mod=1000;
struct mt{
    int t[10][10];
    mt(){memset(t,0,sizeof t);}
    mt operator*(const mt&b)const{
        mt res;
        for(int i=1;i<=8;++i)
            for(int j=1;j<=8;++j)
                for(int k=1;k<=8;++k)
                    res.t[i][j]=(res.t[i][j]+t[i][k]*b.t[k][j])%mod;
        return res;
    }
}ans,base;
inline void qpow(int n){
    for(int i=1;i<=8;++i)
        ans.t[i][i]=1;
    for(int i=1;i<=4;++i)
        base.t[i][i+1]=1,base.t[i][(i-1)?(i-1):8]=1;
    for(int i=6;i<=8;++i)
        base.t[i][(i+1>8)?1:(i+1)]=base.t[i][i-1]=1;
    //初始化ans和base
    while(n){
        if(n&1)ans=ans*base;
        base=base*base;
        n>>=1;
    }
}
int main(){
    int n=read();
    qpow(n);
    cout<<ans.t[1][5];
}