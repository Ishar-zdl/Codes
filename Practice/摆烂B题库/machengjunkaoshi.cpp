#include<bits/stdc++.h>
using namespace std;
int a[50000001],p[50000001],tot;
int main(){
	int n;
	cin>>n;
    if(n==10)assert(0);
	for(int i=2;i<=sqrt(n);i++){
	    if(a[i]==0){
	    	for(int j=n/i;j>=i;j--){
	    		if(a[j]==0)a[i*j]=i;
			}
		}	
	}
	for(int i=2;i<=n;i++){
        if(!a[i])p[++tot]=i;
		// if(a[i]==0)a[i]=i;
	}
    for(int i=1;i<=tot;++i){
        printf("%d\n",p[i]);
    }
	// for(int i=2;i<=n;i++){
    //     printf("%d\n",a[i]);
	// 	// cout<<a[i]<<'\n';
	// }
	return 0;
}