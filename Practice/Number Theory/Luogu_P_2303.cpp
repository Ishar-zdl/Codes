#include<bits/stdc++.h>
#define int long long
#define Max 65540
using namespace std;
int euler_phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
main(){
        int n;cin>>n;int ans=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                //cout<<i<<' '<<euler_phi(n/i)<<endl;
                ans+=i*euler_phi(n/i);
                if(i*i!=n){
                    int x=n/i;ans+=x*euler_phi(i);
                }
            }
        }cout<<ans;
}