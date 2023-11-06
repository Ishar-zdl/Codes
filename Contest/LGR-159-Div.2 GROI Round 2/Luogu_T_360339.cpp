/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-23 14:50:29 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2023-09-23 17:34:49
 */
#include<bits/stdc++.h>
#define N (int)5e5+5
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
int a[N];
int main(){
    int t=read();int n,m,k,tot;
    while(t--){
        vector<int>b;
        bool hh=0;
        tot=1;int ans=1;
        n=read(),m=read(),k=read();
        int w1=0,w2=0;
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<n;++i){
            if(a[i]==a[i+1])tot++;
            else {
                ans++;
                if(tot==1)continue;
                if((tot&1)==0)w2++;
                b.push_back(tot);
                tot=1;
            }
        }
        if(tot>1){
            if((tot&1)==0)w2++;
            b.push_back(tot);
        }
        // cout<<ans<<' '<<w2<<endl;
        // for(int x:b)cout<<x<<' ';cout<<endl;
        for(int x:b){
            // cout<<w2<<endl;
            int zc=x;x=(x-1)>>1;
            if(m>=x)ans+=x*2,m-=x;
            else{ans+=m*2;m=0;break;}
        }
        ans+=min(w2,m);
        printf("%d\n",ans);
    }
}