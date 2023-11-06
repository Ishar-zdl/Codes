/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-15 15:29:26 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-15 16:49:23
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
int q,mod;
struct mt{
    int n,m,a[5][5];
    mt(){memset(a,0,sizeof(a));}
    inline mt operator*(const mt&rhs)const{
        mt res;
        for(int i=1;i<=n;++i)
            for(int k=1;k<=m;++k){
                int x=a[i][k];
                for(int j=1;j<=rhs.m;++j)
                    cout<<n<<' '<<m<<' '<<rhs.m<<endl,
                    res.a[i][j]=(res.a[i][j]+x*rhs.a[k][j])%mod;
            }
        return res;
    }
}base,f;
inline void qpow(int q){
    f.n=1,f.m=4;
    f.a[1][1]=1,f.a[1][2]=1,f.a[1][3]=1,f.a[1][4]=3;
    base.n=base.m=4;
    base.a[1][2]=base.a[2][1]=base.a[2][2]=base.a[4][3]=1;
    base.a[1][4]=base.a[4][4]=2;
    mt fu;fu.n=fu.m=4;
    for(int i=1;i<=4;++i)fu.a[i][i]=1;
    while(q){
        if(q&1)fu=fu*base;
        base=base*base;
        q>>=1;
        cout<<"Fdlksj";
    }
    f=f*fu;
    write(f.a[1][4]);
}
int main(){
    q=read(),mod=read();
    if(q<=2){
        if(q==1)write(1%mod);
        if(q==2)write(3%mod);
        return 0;
    }
    // return 0;
    qpow(q-2);
}