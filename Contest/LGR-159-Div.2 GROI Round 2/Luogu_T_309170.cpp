/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-23 14:03:44 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-09-23 14:32:54
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
    int q=read();int a,b,c;
    for(int i=1;i<=q;i++){
        a=read(),b=read(),c=read();
        if(a==1){
            if(b-1>c){write(-1);putchar('\n');continue;}
            int x=b-2;
            for(int j=1;j<=x;j++)write(1),putchar(' ');
            printf("%d %d\n",c-x,c-x);
        }else{
            if(b-1>c){write(-1);putchar('\n');continue;}
            int x=b-1;
            for(int j=1;j<=x;j++)write(1),putchar(' ');
            printf("%d\n",c-x+1);
        }
    }
}