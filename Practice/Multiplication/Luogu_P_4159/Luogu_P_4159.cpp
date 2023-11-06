/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-14 15:03:04 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-15 07:51:30
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
const int mod=2009,N=95;
struct mt{
    int n,t[N][N];
    inline mt(){memset(t,0,sizeof(t));}
    inline void clear(){
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;++i)t[i][i]=1;
    }
    inline mt operator*(const mt&b)const{
        mt res;int r;res.n=b.n;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k)
                    res.t[i][j]+=t[i][k]*b.t[k][j];
                res.t[i][j]%=mod;
            }
        return res;
    }
    inline mt operator^(int p)const{
        mt res,x=*this;res.n=x.n;
        res.clear();
        for(;p;p>>=1,x=x*x)
            if(p&1)res=res*x;
        return res;
    }
}base;
int main(){
    // freopen("in.in","r",stdin);
    // freopen("out.out","w",stdout);
    int n=read(),q=read();base.n=9*n;
    int a;
    for(int i=1;i<=n;++i){
        for(int zc=i*9-7;zc<=i*9;zc++)
            base.t[zc][zc-1]=1;
        for(int j=1;j<=n;++j){
            scanf("%1d",&a);
            if(a)
            base.t[i*9-8][j*9-9+a]=1;
        }
    }
    base=base^q;
    write(base.t[1][n*9-8]);
    return 0;
}