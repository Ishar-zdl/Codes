/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-09 09:56:04 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-09 10:29:21
 */
#include<bits/stdc++.h>
#define mod 1000003
using namespace std;
const int N=1<<15;
int t,n,k,dp[55][N],g[55][30],tot;
string s[20];
bitset<16>zc;
inline void prepare(){
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>s[i];
    int len=s[1].size();
    for(int i=0;i<len;++i)
        for(int j=0;j<26;j++)
            for(int k=0;k<n;++k)
                if(s[k][i]=='?'||s[k][i]==j+'a')g[i][j]|=1<<k;
    int lim=(1<<n);
    dp[0][lim-1]=1;
    for(int i=0;i<len;++i)
        for(int j=0;j<lim;++j)
            if(dp[i][j])
                for(int k=0;k<26;++k)
                    dp[i+1][j&g[i][k]]=(dp[i+1][j&g[i][k]]+dp[i][j])%mod;
    long long ans=0;
    for(int i=0;i<lim;++i){
        zc=i;
        if(zc.count()==k)ans=(ans+dp[len][i])%mod;
    }
    cout<<ans<<'\n';
    memset(dp,0,sizeof(dp)),memset(g,0,sizeof(g));
}
int main(){
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    #endif
    cin>>t;
    while(t--){
        prepare();
    }
    return 0;
}