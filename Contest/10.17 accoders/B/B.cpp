/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-17 07:44:00 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-17 09:19:50
 */
#include<bits/stdc++.h>
#define ll long long
#define int long long
int mod=1e9+7;
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
struct mt{
    ll a[3][3];
    mt(){memset(a,0,sizeof a);}
    mt operator*(const mt&b)const{
        mt res;
        for(int i=1;i<=2;++i)
            for(int j=1;j<=2;++j)
                for(int k=1;k<=2;++k)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
        return res;
    }
}ans,base;
inline int qpow(int b){
    if(b<0)return 1;
    memset(ans.a,0,sizeof(ans.a)),memset(base.a,0,sizeof(base.a));
    ans.a[1][1]=ans.a[1][2]=1;
    base.a[1][2]=base.a[2][1]=base.a[2][2]=1;
    while(b){
        if(b&1)ans=ans*base;
        base=base*base;b>>=1;
    }
    return ans.a[1][2];
    // write(ans.a[1][2]);
}
string s[(int)2e6+5];
int num[(int)2e6+5],tot,cnt;
main(){
    freopen("string.in","r",stdin),freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    cin>>s[1];
    for(int i=2;i<=n;++i){
        cin>>s[i];
        if(s[i]==s[i-1])num[++cnt]=tot,tot=0;
        else tot++;
    }
    num[++cnt]=tot;
    int ans=1;
    for(int i=1;i<=n;++i){
        ans=ans*qpow(num[i])%mod;
    }
    cout<<ans<<'\n';
}