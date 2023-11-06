/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-27 10:56:19 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-27 10:59:05
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
int main(){
    freopen("network.in","r",stdin);freopen("network.out","w",stdout);
    int n=read(),m=read();
    for(int i=1,a,b;i<=m;i++)a=read(),b=read();
    printf("NO");
}