/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-02 18:03:28 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-03 14:48:40
 */
#include<bits/stdc++.h>
#define int long long
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
int a,b,ans[N],p,n,w[N],numl,left,right;
std::priority_queue<int>qmax;
std::priority_queue<int,std::vector<int>,std::greater<int>>qmin;
main(){
    // freopen("c.in","r",stdin);freopen("c.out","w",stdout);
    ans[1]=0;
    n=read(),a=read(),b=read();
    for(int i=1;i<=n;++i)w[i]=read();
    p=w[1];
    printf("0\n");
    for(int i=2;i<=n;++i){
        if(w[i]>p)right+=w[i],qmin.push(w[i]);
        else left+=w[i],qmax.push(w[i]);
        int ans1=(qmax.size()*p-left)*a+b*(right-qmin.size()*p);
        int ans2=1e9;
        int ans3=1e9;
        if(!qmax.empty()){
            int zc=qmax.top();
            if(zc!=p){
            ans3=b*(right+p-qmin.size()*zc-zc)+a*(qmax.size()*zc-left);
            if(ans3<=ans1){
                right+=p;qmax.pop();left-=zc;qmin.push(p);
                ans1=ans3;p=zc;
            }
            }
        }
        if(!qmin.empty()){
            int zc=qmin.top();
            ans2=a*(qmax.size()*zc+zc-left-p)+b*(right-qmin.size()*zc);
            // std::cout<<ans2<<" 2\n";
            if(ans2<=ans1){
                left+=p;qmin.pop();right-=zc;qmax.push(p);
                ans1=ans2;p=zc;
            }
        }
        printf("%lld %lld\n",ans1,p);
    }
}