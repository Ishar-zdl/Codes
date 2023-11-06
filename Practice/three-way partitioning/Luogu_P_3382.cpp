/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-27 19:29:45 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-28 14:08:57
 */
#include<bits/stdc++.h>
using namespace std;
const double dif=1e-7;
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
double l,r,a[18];int n;
inline double check(double x){
    double temp=1.0,ans=0.0;
    for(int i=n;i>=0;i--,temp*=x)ans+=temp*a[i];
    return ans;
}
int main(){
    scanf("%d%lf%lf",&n,&l,&r);
    for(int i=0;i<=n;++i)scanf("%lf",a+i);
    double lmid,rmid;
    while(l+dif<=r){
        // cout<<1;
        lmid=l+(r-l)/3.0;rmid=r-(r-l)/3.0;
        if(check(lmid)>check(rmid))r=rmid;
        else l=lmid;
    }
    printf("%.5lf",(lmid+rmid)/2.0);
}