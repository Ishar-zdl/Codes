/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-25 19:10:34 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-25 19:54:07
 */
#include<bits/stdc++.h>
#define N (int)(5e4+5)
#define rg register
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
}int n,f1[N][20],f2[N][20],a[N],logg;
int main(){
    n=read();int q=read();logg=__lg(n);
    for(rg int i=1;i<=n;++i)a[i]=read(),f1[i][0]=f2[i][0]=a[i];
    for(rg int k=1;k<=logg;++k){
        for(rg int i=1;i+(1<<k)-1<=n;i++){
            f1[i][k]=max(f1[i][k-1],f1[i+(1<<(k-1))][k-1]);
            f2[i][k]=min(f2[i][k-1],f2[i+(1<<(k-1))][k-1]);
        }
    }
    // int q=read();
    for(rg int i=1;i<=q;++i){
        int a=read(),b=read(),k=__lg(b-a+1);
        int maxx=max(f1[a][k],f1[b-(1<<k)+1][k]);
        int minn=min(f2[a][k],f2[b-(1<<k)+1][k]);//cout<<"fkdls"<<endl;
        write(maxx-minn);putchar('\n');
    }
}