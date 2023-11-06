/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-15 20:43:54 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-15 20:53:42
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
const int mod=9973;
struct mt{
    int n,a[15][15];
    mt(){memset(a,0,sizeof(a));}
    mt operator*(const mt&b)const{
        mt res;res.n=n;
        for(int i=1;i<=n;++i)
            for(int k=1;k<=n;++k){
                int r=a[i][k];
                for(int j=1;j<=n;++j)
                    res.a[i][j]=(res.a[i][j]+r*b.a[k][j])%mod;
            }
        return res;
    }
    mt operator^(int &b)const{
        mt res=*this,x=*this;b--;
        for(;b;b>>=1,x=x*x)
            if(b&1)res=res*x;
        return res;
    }
}ans;
int t;
int main(){
    t=read();int k;
    while(t--){
        ans.n=read();k=read();
        for(int i=1;i<=ans.n;i++)
            for(int j=1;j<=ans.n;++j)
                ans.a[i][j]=read();
        ans=ans^k;
        int sum=0;
        for(int i=1;i<=ans.n;++i)
            sum=(sum+ans.a[i][i])%mod;
        write(sum);putchar('\n');
    }
}