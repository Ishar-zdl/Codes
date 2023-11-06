/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 20:00:33 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 20:05:15
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
const int N=110;
char s[N];
int main(){
    int n;
    std::cin>>n>>s+1;
    int len=strlen(s+1);
    for(int i=1;i<=len;++i){
        if(s[i]=='a'){
            if(s[i-1]=='b'||s[i+1]=='b'){std::cout<<"Yes\n";return 0;}
        }
    }
    std::cout<<"No\n";
}