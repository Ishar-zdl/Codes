#include<bits/stdc++.h>
#define N (int)1e5+50
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
vector<int> node[N];bool f[N];int an2,fa[N];
void dfs(int x){
    if(!f[x])return;
    an2++;f[x]=0;
    for(int i=0;i<node[x].size();i++){
        dfs(node[x][i]);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,die;cin>>n;
    for(int i=1;i<n;i++){
        cin>>die;node[die].push_back(i);fa[i]=die;
    }int q;cin>>q;
    string s;int x;
    for(int i=1;i<=q;i++){
        cin>>s;cin>>x;
        if(s=="install"){
            if(f[x]){
                write(0);putchar('\n');
            }else{
                int ans=0;
                while(1){
                    if(f[x])break;
                    f[x]=1;
                    if(x==0){ans++;break;}
                    x=fa[x];
                    ans++;
                }write(ans);putchar('\n');
            }
        }
        else{
            if(!f[x]){
                write(0);putchar('\n');
            }else{
                an2=0;
                dfs(x);
                write(an2);putchar('\n');
            }
        }
    }
}