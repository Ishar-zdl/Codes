#include<bits/stdc++.h>
#define int __int128
using namespace std;
int n,l,x,y;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
void write(int a){
    if(a<0)putchar('-'),a=-a;
    if(a>9)write(a/10);
    putchar(a%10+48);
}
int qp(int m){  
    int ans=1,t=2;
    while(m>0){
        if(m&1)ans=(ans%n)*(t%n);
        t=(t%n)*(t%n);
        m>>=1;
    }return ans;
}
void exgcd(int a,int b){
    if(!b){x=1,y=0;return;}
    exgcd(b,a%b);
    int t=x;x=y;y=t-a/b*y;
}
main(){
    int m;n=read(),m=read(),l=read();n++;
    int a=qp(m),b=n;
    // cout<<a<<endl<<b<<endl;
    exgcd(a,b);
    // cout<<x<<endl;
    write((x*l%b+b)%b);
}