/*
 * @Author: mikey.zhaopeng 
 * @Date: 2023-10-29 08:45:12 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-10-29 11:22:06
 */
#include<bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
const int N=1e6+5;
int next[N],zc[N];
int main(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
    int n;
    std::cin>>n;
    zc[1]=1;
    while(n--){
        std::string s;
        std::cin>>s;int len=s.size();
        s=' '+s;
        int j=0;ll ans=1;
        for(int i=2;i<=len;++i){
            while(j&&s[i]!=s[j+1])j=next[j];
            if(s[i]==s[j+1])j++;
            next[i]=j;zc[i]=zc[j]+1;
        }j=0;
        for(int i=2;i<=len;++i){
            while(j&&s[i]!=s[j+1])j=next[j];
            if(s[i]==s[j+1])j++;
            if((j<<1)>i)j=next[j];
            // std::cout<<zc[j]+1<<"fds\n";
            ans=ans*(zc[j]+1)%mod;
        }
        std::cout<<ans<<'\n';
    }
}