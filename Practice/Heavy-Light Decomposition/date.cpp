#include<bits/stdc++.h>
using namespace std;
#define reg register
inline int random(int x) { return (rand()%x)*(rand()%x)%x; }
#define maxn 25
int n,fa[1001],cnt=0;
inline int szfind(int x) { return fa[x]==x?x:fa[x]=szfind(fa[x]); }
// map<int,string> mp;
int main(){
    srand(time(0));
    freopen("data.in","w",stdout);
    // mp[1]="Q",mp[2]="C";
	int n=10,m=9;
    // cout<<"Flkdsklfjds"<<endl;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;++i){
        int zc=random(m-1)+1;
        printf("%d ",zc);
        for(int i=1;i<=zc;++i){
            int x=random(m-1)+1;
            // while(!x)x=random(m);
            cout<<x<<' ';
        }
        cout<<endl;
    }
    
}
