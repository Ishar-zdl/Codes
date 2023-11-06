/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-14 16:47:16 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-14 16:50:53
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
const int N=2e5+5;
struct ST{
    int sc,r,c,w;
    bool operator<(ST b)const{return w>b.w;}
}t[N];
int n;
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)t[i].sc=read(),t[i].c=i;
        for(int i=1;i<=n;++i)t[i].w=read();
        sort(t+1,t+n+1);
        
    }  
}