#include<bits/stdc++.h>
using namespace std;
int n,m,h[25],f[1<<20][25];
int main()
{
    cin>>n>>m;f[0][0]=1;
    for(register int i=1,x,y;i<=m;++i) 
        cin>>x>>y,h[x]|=(1<<y-1);
    for(register int i=1;i<=n;++i)
        for(register int j=0;j<(1<<n);++j)                                                                                                           
        {
            if(!f[j][i-1])                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       continue;
            for(register int k=1;k<=n;++k)
                if(!((1<<k-1)&(h[i]|j))) 
                    f[j|(1<<k-1)][i]+=f[j][i-1];
        }
    cout<<f[(1<<n)-1][n]<<'\n';return 0;
}