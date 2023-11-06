/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-16 14:47:35 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-16 17:06:05
 */
#include<bits/stdc++.h>
#define ull unsigned long long
inline void ONLINE(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const ull P=13331;
int n,m;
ull hash_a[505][505],hash_b[505][505],W=1;
std::string a[505],b[505];
inline ull qpow(int b){
    ull base=P,ans=1;
    for(;b;b>>=1,base*=base)
        if(b&1)ans*=base;
    return ans;
}
inline void hash(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            hash_a[i][j]=hash_a[i][j-1]*P+(a[i][j]-'A');
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            hash_b[i][j]=hash_b[i][j-1]*P+(b[i][j]-'A');
}
inline bool check(int len){
    W=qpow(len);
    for(int l=len;l<=m;++l){
        bool k=1;
        for(int i=1;i<=n;++i){
            ull pd=hash_a[i][l]-hash_a[i][l-len]*W;
            for(int j=1;j<=n;++j){
                if(pd==hash_b[j][l]-hash_b[j][l-len]*W){
                    // std::cout<<l-len+1<<' '<<l<<'\n';
                    k=0;break;
                    }
            }
            if(!k)break;
        }
        if(k)return true;
    }
    return false;
}
int main(){
    ONLINE();
    // freopen("in.in","r",stdin);freopen("out.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;++i)std::cin>>a[i],a[i]=' '+a[i];
    for(int i=1;i<=n;++i)std::cin>>b[i],b[i]=' '+b[i];
    int l=1,r=m,mid,ans=m;
    hash();
    // qpow(m);
    // while(l<=r){
    //     mid=l+r>>1;
    //     // std::cout<<mid<<std::endl;
    //     if(check(mid))r=mid-1,ans=mid;
    //     else l=mid+1;
    // }
    while(l<r){
        mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    std::cout<<l;
}
/*
3 8
AATCCCAT
ACTTGCAA
GGTCGCAA
ACTCCCAG
ACTCGCAT
ACTTCCAT
*/