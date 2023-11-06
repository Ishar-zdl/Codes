/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-16 09:39:49 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-16 10:52:46
 */
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long 
void ONLINE(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(0);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int P=13331;
ull hash[(int)(1e6+5)],hashp;
inline ull qpow(int p){
    ull ans=1,base=P;
    for(;p;p>>=1,base=base*base)
        if(p&1)ans=ans*base;
    return ans;
}
int main(){
    ONLINE();
    int t;
    std::cin>>t;
    // while(t--){
    //     string w,a;cin>>w>>a;
    //     int len=w.length();
    //     int ans=0;
    //     for(int i=0;i<=a.length()-len;++i){
    //         if(a.substr(i,len)==w)ans++;
    //         // cout<<i<<' '<<len<<' '<<a.substr(i,len)<<'\n';
    //     }
    //     cout<<ans<<'\n';
    // }    ±©Á¦
    while(t--){
        std::string w,a;std::cin>>w>>a;
        ull W=qpow(w.length());
        int ans=0;
        for(int i=1;i<=a.length();++i)
            hash[i]=(hash[i-1]*P+(a[i-1]-'A'));
        int tot=0;hashp=0;
        for(int i=1;i<=w.length();++i)
            hashp=hashp*P+(w[i-1]-'A');
        for(int i=0;i<=a.length()-w.length();++i)
            if((hash[i+w.length()]-hash[i]*W)==hashp)ans++;
        std::cout<<ans<<'\n';
    }
}