/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-08 17:13:42 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-08 17:23:09
 */
#include<bits/stdc++.h>
#define ri register int
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
    int t=read();
    while(t--){
        int n=read(),sum=0;
        for(ri i=1,a;i<n;++i)a=read(),sum+=a;
        write(0-sum);putchar('\n');
    }
}