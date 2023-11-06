/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-17 07:30:45 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-17 09:19:02
 */
#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(long long x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
const int N=2e5+5;
long long a[N],sum;
int main(){
    freopen("hat.in","r",stdin),freopen("hat.out","w",stdout);
    long long n=read();   
    for(int i=1;i<=n;++i)
        a[i]=read(),sum^=a[i];
    for(int i=1;i<=n;++i)
        write(sum^a[i]),putchar(' ');
}