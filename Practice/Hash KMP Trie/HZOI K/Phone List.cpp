/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-31 15:30:52 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-31 16:52:58
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
const int N=1e5+5;
int T,n,trie[N][26],tot=1,end[N];
char s[N][15];
inline void insert(char* str){
    int len=std::strlen(str),p=1;
    for(int k=0;k<len;++k){
        int ch=str[k]-'0';
        if(!trie[p][ch])trie[p][ch]=++tot;
        p=trie[p][ch];
        end[p]++;
    }
    // end[p]++;
}
inline int search(char* str){
    // exit(0);
    int len=strlen(str),p=1;
    for(int k=0;k<len;++k){
        p=trie[p][str[k]-'0'];
        if(!p)return 0;
    }
    return end[p];
}
int main(){
    CIN_sync();
    std::cin>>T;
    while(T--){
        std::cin>>n;
        for(int i=1;i<=n;++i){
            std::cin>>s[i]+1;
            insert(s[i]+1);
        }
        bool pd=0;
        for(int i=1;i<=n;++i){
            // std::cout<<s[i]+1<<'\n';
            // std::cout<<search(s[i]+1)<<'\n';
            if(search(s[i]+1)>1){std::cout<<"NO\n";pd=1;break;}
        }
        if(!pd)std::cout<<"YES\n";
        for(int i=1;i<=tot;++i)memset(trie[i],0,sizeof trie[i]),end[i]=0;
        tot=1;
    }
    return 0;
}