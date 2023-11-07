/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-06 21:10:18 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-07 07:42:14
 */
#include<bits/stdc++.h>
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
const int N=2e5+10;
const long long mod=998244353;
int f[20][20][2][2],p[N];
long long ans[50];
long long da,P=1;
int main(){
	freopen("origen.in","r",stdin);freopen("origen.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;++i)p[i]=read(),p[i]^=p[i-1];
    for(int x=0;x<18;++x)for(int y=0;y<18;++y)f[x][y][0][0]=1;
    for(int i=1;i<=n;++i){
    	for(int x=0;x<18;++x){
    		for(int y=0;y<18;++y){
    			ans[x+y]+=f[x][y][(p[i]>>x)&1^1][(p[i]>>y)&1^1];
    			f[x][y][(p[i]>>x)&1][(p[i]>>y)&1]++;
    			ans[x+y]%=mod;
			}
		}
	}
	for(int i=0;i<=36;++i){
		da=(da+P*ans[i])%mod;
		P=2*P%mod;
	}
	printf("%lld",da);
}   