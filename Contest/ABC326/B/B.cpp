/*
 * @Author: mikey.zhaopeng 
 * @Date: 2023-10-28 20:07:22 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-10-28 20:09:50
 */
#include<bits/stdc++.h>
inline bool check(int n){
    int ans=n%10;
    int a=n/10%10;
    int b=n/100;
    if(a*b==ans)return true;
    return false;
}
int main(){
    int n;std::cin>>n;
    for(int i=n;i<1000;++i){
        if(check(i)){std::cout<<i;return 0;}
    }
}