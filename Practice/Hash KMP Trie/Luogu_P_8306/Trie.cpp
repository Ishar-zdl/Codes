/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-31 21:55:25 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-01 10:46:17
 */
#include<bits/stdc++.h>
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int N=3e6+10;
int T,n,q,trie[N][130],end[N],tot;
inline void insert(std::string s){
    int len=s.size(),p=0;
    for(int i=0;i<len;++i){
        if(!trie[p][s[i]-'0'])trie[p][s[i]-'0']=++tot;
        p=trie[p][s[i]-'0'];
        end[p]++;
    }
}
inline void search(std::string s){
    int len =s.size(),p=0;
    for(int i=0;i<len;++i){
        if(!trie[p][s[i]-'0']){std::cout<<0<<'\n';return;}
        p=trie[p][s[i]-'0'];
    }
    std::cout<<end[p]<<'\n';
}
int main(){
    std::cin>>T;
    while(T--){
        std::cin>>n>>q;
        std::string s;
        for(int i=1;i<=n;++i)std::cin>>s,insert(s);
        for(int i=1;i<=q;++i)std::cin>>s,search(s);
        for(int i=0;i<=tot;++i)end[i]=0,memset(trie[i],0,sizeof(trie[i]));
        tot=0;
    }
    return 0;
}