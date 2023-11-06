/*
 * @Author: mikey.zhaopeng 
 * @Date: 2023-10-28 19:46:01 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-10-28 19:50:11
 */
#include<bits/stdc++.h>
#define endl '\n'
const int N=1e6+5;
char s1[N],s2[N];
int next[N];
int main(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
    std::cin>>s1+1>>s2+1;
    int la=strlen(s1+1),lb=strlen(s2+1),j=0;
    for(int i=2;i<=lb;++i){
        while(j&&s2[i]!=s2[j+1])j=next[j];
        if(s2[j+1]==s2[i])j++;
        next[i]=j;
    }
    j=0;
    for(int i=1;i<=la;++i){
        while(j&&s2[j+1]!=s1[i])j=next[j];
        if(s2[j+1]==s1[i])j++;
        if(j==lb){std::cout<<i-lb+1<<endl;j=next[j];}
    }
    for(int i=1;i<=lb;++i)std::cout<<next[i]<<' ';
    return 0;
}