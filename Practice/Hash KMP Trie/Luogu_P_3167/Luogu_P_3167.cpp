/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-18 07:34:37 
 * @Last Modified by:   Ishar-zdl 
 * @Last Modified time: 2023-10-18 07:34:37 
 */
#include<bits/stdc++.h>
const int N=1e5+5;
const unsigned long long P=1331;
int n,dp[N][15],lenp,len[15],tot,cnt1,cnt2,maxx,pos[N][15],sum[N];
unsigned long long hash[N],mate[15],qpow[N];
std::pair<int,int>block[15];
std::string p,s;
inline void prepare(){
    std::cin>>p>>n;
    lenp=p.size();p=' '+p;
    qpow[0]=1;
    for(int i=1;i<=N;++i){qpow[i]=qpow[i-1]*P;}
    for(int i=1;i<=lenp;++i){
        if(p[i]!='*'&&p[i]!='?')break;
        if(p[i]=='?')cnt1++;
    }
    for(int i=lenp;i;++i){
        if(p[i]!='*'&&p[i]!='?')break;
        if(p[i]=='?')cnt2++;
    }
    for(int i=1;i<=lenp;++i){
        sum[i]=sum[i-1];
        if(p[i]=='?')sum[i]++;
        // std::cout<<sum[i]<<'\n';
    }
    for(int i=1;i<=lenp;++i){
        if(p[i]!='*'&&p[i]!='?'){
            int j=i+1;block[++tot].first=i;
            mate[tot]=p[i]-'a';
            for(;j<=lenp;++j){
                if(p[j]=='*'||p[j]=='?')break;
                else mate[tot]=mate[tot]*P+p[j]-'a';
            }
            block[tot].second=j-1;
            // if(p[j]!='*'&&p[j]!='?')block[tot].second++;
            len[tot]=block[tot].second-block[tot].first+1;
            i=j;
        }
    }

    // for(int i=1;i<=tot;++i){
    //     std::cout<<block[i].first<<' '<<block[i].second<<'\n'<<len[i]<<' '<<mate[i]<<'\n';
    // }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    prepare();
    while(n--){
        std::cin>>s;
        int lens=s.size();s=' '+s;
        for(int i=1;i<=lens;++i)
            hash[i]=hash[i-1]*P+s[i]-'a';
        bool pd=0,no=0;
        for(int i=cnt1+len[1];i<=lens-cnt2+1;++i){
            for(int j=1;j<=tot;++j){
                if(dp[i][j-1]!=j-1)break;

            }
            if(pd)break;
        }
        if(pd)std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
    return 0;
}
//不想写了