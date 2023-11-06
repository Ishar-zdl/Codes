/*
 * @Author: mikey.zhaopeng 
 * @Date: 2023-10-28 20:11:31 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-10-28 20:31:16
 */
#include<bits/stdc++.h>
#define int long long
const int N=3e5;
int a[N],sum[N];
main(){
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;++i)std::cin>>a[i];
    std::sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=std::max(ans,std::lower_bound(a+i,a+1+n,a[i]+m)-a-i);
    }
    std::cout<<ans;
}