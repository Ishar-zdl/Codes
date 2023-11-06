/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-13 18:53:54 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-14 10:24:25
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
    cout<<__lg(0)<<endl;
    cout<<__lg(-1)<<endl;
    cout<<"lkb,wcnm";
    return 0;
}

