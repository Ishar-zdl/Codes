//23.9.21.8.54
#include<bits/stdc++.h>
#define mod 998244353
#define N (int)1e7
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
int size[N],inv[N],fa[N];
int main(){
    int n,a;n=read();inv[1]=1;long long ans(0);
    for(int i=2;i<=n;i++)fa[i]=read();
    for(int i=n;i>=1;i--)size[i]++,size[fa[i]]+=size[i];
    for(int i=2;i<=n;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=n;i++)ans=(ans+inv[size[i]])%mod;
    cout<<ans;
}