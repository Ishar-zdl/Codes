/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-16 20:27:09 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-17 06:43:51
 */
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
inline void ONLINE(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int mod=1e9+7,N=1e4+5,P=1331;
ull hash_p[N],hash[105][12],ppow[16];
int k,dp[105][N],tot[105];
std::string s,ss[105][12];
inline void input(){
    std::cin>>k>>s;
    for(int i=1;i<=k;++i){
        std::cin>>tot[i];
        for(int j=1;j<=tot[i];++j){
            std::cin>>ss[i][j];
            int len=ss[i][j].length();
            ss[i][j]=' '+ss[i][j];
            for(int w=1;w<=len;++w)
                hash[i][j]=hash[i][j]*P+(ss[i][j][w]-'A');
        }
    }
    ppow[0]=1;
    for(int i=1;i<=15;++i){
        ppow[i]=ppow[i-1]*P;
    }
}
inline void DP(){
    int len=s.length();s=' '+s;
    dp[0][0]=1;
    for(int i=1;i<=len;++i){
        hash_p[i]=hash_p[i-1]*P+(s[i]-'A');
        dp[0][i]=1;
    }
    // std::cout<<k<<' '<<len<<'\n';
    // for(int i=1;i<=len;++i)std::cout<<hash_p[i]<<' ';putchar('\n');
    // for(int i=1;i<=k;++i){
    //     for(int j=1;j<=tot[i];++j)std::cout<<ss[i][j]<<' '<<ss[i][j].length()-1<<' '<<hash[i][j]<<' ';
    //     putchar('\n');
    // }
    for(int i=1;i<=k;++i){
        for(int j=1;j<=len;++j){
            for(int w=1;w<=tot[i];++w){
                // if(j>=l)
                int leng=ss[i][w].length()-1; 
                if(j>=leng&&hash[i][w]==hash_p[j]-hash_p[j-leng]*ppow[leng])
                    // std::cout<<j<<' '<<ss[i][w]<<'\n',
                    dp[i][j]=(dp[i][j]+dp[i-1][j-leng])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=len;++i)ans=(ans+dp[k][i])%mod;
    std::cout<<ans;
}
signed main(){
    ONLINE();
    input();
    DP();
}