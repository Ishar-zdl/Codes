/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-13 16:22:33 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-13 16:54:30
 */
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define FRE freopen("train.in","r",stdin),freopen("train.out","w",stdout);
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
namespace Maker{
	unsigned int x0,seed;
	void init() {scanf("%u%u",&x0,&seed);}
	inline unsigned int getnum(){
		x0=(x0<<3)^x0;
		x0=((x0>>5)+seed)^x0;
		return x0;
	}
} 
const int N=1e5+10;
unsigned int n,m,typ,a[N],st[25][N];
int main(){
    FRE
	scanf("%u%u%u",&n,&m,&typ);
    for(int i=1;i<=n;++i)scanf("%u",a+i);
	Maker::init();
	for(int i=1; i<=m; ++i){
		int l=Maker::getnum()%n+1,r=Maker::getnum()%n+1;
		unsigned int v=Maker::getnum();
		if(l>r) std::swap(l,r);
		if(typ==1) l=1;
        int k=std::__lg(r-l+1);
        st[k][l]=std::max(st[k][l],v);
        st[k][r-(1<<k)+1]=std::max(st[k][r-(1<<k)+1],v);
 	}
    for(int i=25;i;--i){
        for(int j=1;j+(1<<i)-1<=n;++j){
            st[i-1][j]=std::max(st[i][j],st[i-1][j]);
            st[i-1][j+(1<<i-1)]=std::max(st[i][j],st[i-1][j+(1<<i-1)]);
        }
    }
    for(int i=1;i<=n;++i)printf("%u ",std::max(st[0][i],a[i]));
	// output n numbers of a[1...n]
}