/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-19 10:28:53 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-19 10:50:02
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
vector<int>s[15];
int main(){
    freopen("t.in","r",stdin);freopen("t.out","w",stdout);
    printf("10 9\n1 3\n3 1 5 3\n2 1 3\n4 7 2 6 3\n4 7 6 3 5 \n2 3 6 \n3 1 8 5 \n1 6 \n1 2 \n5 6 1 7 5 8 \n");
}