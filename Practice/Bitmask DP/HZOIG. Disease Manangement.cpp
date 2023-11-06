/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-09 07:52:34 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-09 08:55:55
 */
#include<bits/stdc++.h>
using namespace std;
const int N=1<<15;
int n,d,w,dp[N],num[1005],v[1005];
bitset<15> s;
int main(){
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    #endif
    cin>>n>>d>>w;
    for(int i=1;i<=n;++i){
        cin>>num[i];
        for(int j=1,a;j<=num[i];++j)
            cin>>a,v[i]|=1<<a-1;
    }
    cout<<endl;
    dp[0]=0;int ans=0;
    for(int i=(1<<d)-1;i>=0;--i){
        for(int j=1;j<=n;++j){
            int k=i|v[j];
            s=k;
            if(s.count()>w)continue;
            dp[k]=max(dp[k],dp[i]+1);
            ans=max(ans,dp[k]);
        }
    }
    cout<<ans;
}