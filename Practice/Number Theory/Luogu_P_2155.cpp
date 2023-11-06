#include<bits/stdc++.h>
#define int long long
using namespace std;
int prime[(int)(1e6)+5],
ny[(int)(1e7)+5],num[(int)(1e7)+5],
x,y,cj[(int)(1e6)+5];
int jie[(int)(1e7)+5];
bool vis[(int)(1e7)+5];
void getprime(int n){
    int m=0;
    for(int i=2;i<=n;i++){
        if(!vis[i])prime[++m]=i;num[i]=m;
        for(int j=1;j<=m&&prime[j]*i<=n;++j){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
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
main(){
    int t,p,n,m;t=read();p=read();ny[0]=ny[1]=1;getprime((int)(1e7)+2);
    for(int i=2;i<=1e7;++i){ny[i]=(p-p/i)*ny[p%i]%p;}
    jie[1]=1;cj[0]=1;
    for(int i=2;i<=(int)(1e7)+1;++i)
        if(i==p)
            jie[i]=jie[i-1];
        else
            {jie[i]=i*jie[i-1]%p;}
    for(int i=1;i<=num[(int)1e7];++i){cj[i]=(prime[i]-1)*cj[i-1]%p*ny[prime[i]%p]%p;}
    while(t--){
        n=read(),m=read();
        if(n>=p&&m<p)
        {
            puts("0");
            continue; 
        }
        n=jie[n];int pre=num[m];
        write(n*cj[pre]%p);
        putchar('\n');
    }
    return 0;
}
/*
1 3
4 3
*/