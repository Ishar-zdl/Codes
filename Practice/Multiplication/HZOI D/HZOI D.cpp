/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-15 15:29:26 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-15 19:22:24
 */
#include<bits/stdc++.h>
#define int long long
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
int q,mod;
struct mt{
    int n,m,a[6][6];
    mt(){memset(a,0,sizeof(a));}
    inline void clear(){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;++i)
            a[i][i]=1;
    }
    inline mt operator*(const mt&rhs)const{
        mt res;
        res.n = n, res.m = rhs.m;
        for(int i=1;i<=n;++i)
            for(int k=1;k<=m;++k){
                int x=a[i][k];
                for(int j=1;j<=rhs.m;++j)
                    res.a[i][j]=(res.a[i][j]+x*rhs.a[k][j])%mod;
            }
        return res;
    }
    inline mt operator^(int p)const{
        mt res=*this;
        mt x=*this;
        p--;
        for(;p;p>>=1,x=x*x)
            if(p&1)res=res*x;
        return res;
    }
}base,f;
inline void putt(){
    for(int i=1;i<=4;++i){
        for(int j=1;j<=4;++j)
            cout<<base.a[i][j]<<' ';
        cout<<endl;
    }
}
main(){
    q=read(),mod=read();
    if(q<=2){
        if(q==1)write(1%mod);
        if(q==2)write(3%mod);
        return 0;
    }
    f.n=1,f.m=5;
    f.a[1][1]=1,f.a[1][2]=1,f.a[1][3]=2,f.a[1][4]=2,f.a[1][5]=1;
    base.n=base.m=5;
    base.a[1][2]=base.a[1][4]=base.a[2][1]=base.a[2][2]=base.a[2][3]=base.a[2][4]=base.a[3][4]=base.a[4][3]=base.a[4][4]=base.a[4][5]=base.a[5][5]=1;
    base=base^(q-2);
    f=f*base;
    write((f.a[1][4]+f.a[1][5])%mod);
    return 0;
}