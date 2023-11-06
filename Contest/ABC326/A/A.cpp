/*
 * @Author: mikey.zhaopeng 
 * @Date: 2023-10-28 20:01:30 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-10-28 20:05:51
 */
#include<bits/stdc++.h>
int main(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
    int x,y;std::cin>>x>>y;
    if(abs(x-y)<=2){std::cout<<"Yes";return 0;}
    if(y<x&&x-y<=3){std::cout<<"Yes";return 0;}
    std::cout<<"No";return 0;
}