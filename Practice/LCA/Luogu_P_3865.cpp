/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-24 09:10:58 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-24 09:38:18
 */
#include<bits/stdc++.h>
#define N (int)1e5+5
#define fo(n) for(int i=1;i<=n;i++)
using namespace std;
int n,m,a[N],f[19][N];
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
inline void work(){
    fo(n)f[0][i]=a[i];
    for(int j=1;j<=__lg(n);j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
}
int main(){
    n=read(),m=read();
    fo(n)a[i]=read();
    work();
    fo(m){int a=read(),b=read();int k=__lg(b-a+1);
    write(max(f[k][a],f[k][b-(1<<k)+1]));
    putchar('\n');}}