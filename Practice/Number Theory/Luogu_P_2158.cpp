#include<bits/stdc++.h>
using namespace std;
int phi[40005],vis[40005],p[40005],cnt;
int main(){
    int n;cin>>n;if(n==1){
        cout<<0;return 0;
    }
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;i*p[j]<=n;j++){
            int m=i*p[j];
            vis[m]=1;
            if(i%p[j]==0){
                phi[m]=p[j]*phi[i];break;
            }
            else phi[m]=(p[j]-1)*phi[i];
        }
    }int ans=0;
    // for(int i=1;i<=n;i++)cout<<phi[i]<<endl;
    for(int i=2;i<n;i++){
        ans+=phi[i];
    }cout<<ans*2+3;
    return 0;
}