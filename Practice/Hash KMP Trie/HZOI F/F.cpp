/*
 * @Author: mikey.zhaopeng 
 * @Date: 2023-10-29 08:16:49 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-10-29 08:42:15
 */
#include<bits/stdc++.h>
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
const int N=4e5+5;
char s[N];
int next[N],ans[N];
int main(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
    while(std::cin>>s+1){
        int j=0,len=strlen(s+1),tot=0;
        for(int i=2;i<len;++i){
            while(j&&s[i]!=s[j+1])j=next[j];
            if(s[i]==s[j+1])j++;
            next[i]=j;
        }
        while(j){
            if(s[len]==s[j+1])ans[++tot]=j+1;
            j=next[j];
        }
        if(s[len]==s[1])ans[++tot]=1;
        for(int i=tot;i;--i)std::cout<<ans[i]<<' ';
        std::cout<<len<<'\n';
        for(int i=2;i<=len;++i)next[i]=0;
    }
}