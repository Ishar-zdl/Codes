/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-06 18:50:59 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-06 20:12:08
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
const int N=1e4+10;
int n,now=1;
inline bool cmp(std::pair<int,int>a,std::pair<int,int>b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
inline bool cmp1(std::pair<int,int>a,std::pair<int,int>b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
std::pair<int,int>c[N];
// std::priority_queue<std::pair<int,int>>q[N];
std::priority_queue<int,std::vector<int>,std::greater<int>>q;
int main(){
    n=read();int num=0;
    for(int i=1;i<=n;++i){
        // a=read(),b=read();num=std::max(num,b);
        // q.push({a,b});
        c[i].first=read();
        c[i].second=read();
        num=std::max(num,c[i].second);
    }
    std::sort(c+1,c+n+1,cmp1);
    // num=std::min(num,n);
    // std::sort(c+1,c+num+1,cmp1);
    // for(int i=1;i<=num;++i)std::cout<<c[i].first<<'\n';
    int ans=0;
    int l=1;
    for(int i=1;i<=n;++i){
        if(c[i].second>=now){
            now++;q.push(c[i].first);
        }
        else{
            int minn=q.top();
            if(c[i].first>=minn)q.pop(),q.push(c[i].first);
        }
        // std::cout<<c[i].first<<'\n';
        // if(c[i].second<i-l+1){
        //     if(c[i].first>=c[l].first)l++;
        //     else ans-=c[i].first;
        // }
    }
    // for(l;l<=n;++l)ans+=c[l].first;
    // for(int i=1;i<=n&&i<=num;++i){
    //     if(c[i].second<i-l+1)l++;
    //     // if(c[i].second<i-l+1)l+=i-l+1-c[i].second;
    //     // std::cout<<c[i].first<<'\n';
    //     // if(now<=c[i].second)ans+=c[i].first,now++;
    // }
    // for(l;l<=num;++l)ans+=c[l].first;
    while(!q.empty())ans+=q.top(),q.pop();
    std::cout<<ans;
}