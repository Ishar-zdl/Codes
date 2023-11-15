/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-15 07:58:45 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-15 21:47:02
 */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FRE freopen("flandre.in","r",stdin),freopen("flandre.out","w",stdout);
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int N=1e6+10;
int n,k,ans=0,zc,tot,w[N],xx,sum[N],f[N],jc=0;
std::pair<int,int>a[N];
main(){
    // FRE
    n=read(),k=read();
    for(int i=1;i<=n;++i)a[i].first=read(),a[i].second=i,w[i]=a[i].first;
    std::sort(a+1,a+n+1);
    std::sort(w+1,w+n+1);
    int pos=std::lower_bound(w+1,w+n+1,0)-w;
    f[n]=n+1;int wz=n+1;
    for(int i=n-1;i;--i){
        if(w[i]<w[i+1])wz=i+1;
        f[i]=wz;
    }
    ans+=a[pos].first;zc=pos;
    for(int i=1;i<=n+1;++i)sum[i]=sum[i-1]+a[i].first;
    for(int i=pos+1;i<=n;++i){if(a[i].first>a[i-1].first)xx=i-pos;ans+=xx*k+a[i].first;}
    for(int i=pos-1;i;--i){
        // int pos=std::lower_bound(w+1,w+n+1,a[i].first+1)-w;
        int pos=f[i];
        // std::cout<<pos<<'\n';
        int num=n-pos+1;
        if(abs(a[i].first+jc)<=k*num)ans+=k*num+a[i].first+jc,zc=i,jc=0;
        else jc+=num*k+a[i].first;
    }
    printf("%lld %lld\n",ans,n-zc+1);
    for(int i=zc;i<=n;++i)printf("%lld ",a[i].second);
}
/*
5 10
-2 -1 -1 -1 1
排完序后要拿肯定是拿连续一段
*/
