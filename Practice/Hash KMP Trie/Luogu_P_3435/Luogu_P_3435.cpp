/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-29 20:35:17 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-30 10:29:38
 */
#include<bits/stdc++.h>
#define int long long
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
const int N=1e6+10;
char s[N];
int next[N],minnext[N];
main(){
#ifdef ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
#endif
    // freopen("in.in","r",stdin),freopen("out.out","w",stdout);
    int len;
    std::cin>>len>>s+1;
    // std::cout<<strlen(s)<<' '<<s<<'\n';
    long long ans=0;
    for(int i=2,j=0;i<=len;++i){
        while(j&&s[i]!=s[j+1])j=next[j];
        if(s[i]==s[j+1])j++;
        minnext[i]=next[i]=j;
        if(minnext[minnext[i]])
        minnext[i]=minnext[minnext[i]];
    }
    for(int i=2;i<=len;++i){
        if(minnext[i])ans+=i-minnext[i];
    }
    std::cout<<ans;
    return 0;
}