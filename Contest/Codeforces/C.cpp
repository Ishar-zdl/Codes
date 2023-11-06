/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-08 18:45:20 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-08 18:59:47
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
    int t=read();
    while(t--){
        int n=read(),m=read(),k=read();
        if(k>3){write(0);putchar('\n');continue;}
        if(k==3){
            m-=n;
            cout<<max(m-m/n,0)<<'\n';
            continue;
        }
        if(k==2){write(m/n+min(m,n-1));putchar('\n');continue;}
        if(k==1){write(1);putchar('\n');continue;}
        write(0);putchar('\n');
    }   
}