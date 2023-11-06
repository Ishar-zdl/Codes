/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-14 11:27:25 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-14 11:36:28
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
long long a[150][150],b[150][150],c[150][150];
int main(){
    int n=read(),m=read();int p=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read();
    
    memcpy(a,b,sizeof (a));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=p;++j){
            long long ans=0;
            for(int k=1;k<=m;++k)
                ans+=a[i][k]*b[k][j];
            printf("%lld ",ans);
        }
        putchar('\n');
    }
        
            
}