/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 08:39:38 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 09:28:27
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
int tot=1,n;
int main(){
    freopen("irises.in","r",stdin);freopen("irises.out","w",stdout);
    int a=read(),b=read();
    // printf("%d %d\n",a,b);
    if(!b){
        if(a==3){printf("0");return 0;}
        printf("%d\n",a+1);
        for(int i=1;i<=a;++i){
            printf("1 %d\n",i+1);
        }
        return 0;
    }
    if(a<=b+1){printf("0");return 0;}
    if(a==b+3){
        printf("0");return 0;
    }
    n=a+b+1;
    if(a==b+2)n--;
    if(n>2000){printf("0");return 0;}
    printf("%d\n1 2\n",n);
    tot=2;
    for(int i=1;i<=b;++i){
        printf("%d %d\n%d %d\n",tot,tot+1,tot,tot+2);
        tot+=2;
    }
    for(int i=tot+1;i<=n;++i){
        printf("%d %d\n",tot,i);
    }
}