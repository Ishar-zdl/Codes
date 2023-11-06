#include<bits/stdc++.h>
using namespace std;
int t,n,k;string s;
bool check(int w){
    int sum=0;s=' '+s;
    for(int i=1;i<s.size();i++){
        if(s[i]=='1')sum++,i=i+w-1;
    }
    return sum<=k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);cin>>t;
    while(t--){
        cin>>n>>k>>s;
        int l=1,r=2e6,ans;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                r=mid-1;ans=mid;
            }else l=mid+1;
        }
        cout<<ans<<'\n';
    }
}