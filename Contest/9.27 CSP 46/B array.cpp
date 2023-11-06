/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-27 08:36:44 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-28 14:52:16
 */
#include<bits/stdc++.h>
#define int long long
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
int a[(int)(2e5+10)];
int n,m,k,d,sum;
inline int check(int x){
    int zc=d-sum*x;int ans=x*(k+m);
    for(int i=1;i<=m;i++){
        int K=min(zc/a[i],n-x);
        ans+=K;zc-=K*a[i];
        if(!K)break;
    }return ans;
}
main(){
    freopen("array.in","r",stdin);freopen("array.out","w",stdout);
    int t=read();
    while(t--){
        n=read(),m=read(),k=read(),d=read();sum=0;
        for(int i=1;i<=m;++i)a[i]=read(),sum+=a[i];
        sort(a+1,a+m+1);
        int l=0,r=min(n,d/sum);
        while(r-l>=50){
            // cout<<'1'<<endl;
            int lmid=l+(r-l)/3;int rmid=r-(r-l)/3;
            int lans=check(lmid),rans=check(rmid);
            if(lans<=rans)l=lmid+1;
            else r=rmid-1;
        }
        int ans=-1;
        for(;l<=r;++l){
            int zc=check(l);
            if(zc>ans)ans=zc;
        }write(ans);putchar('\n');
    }
}