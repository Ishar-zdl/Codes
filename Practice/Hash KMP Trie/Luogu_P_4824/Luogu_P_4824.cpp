#include<bits/stdc++.h>
#define endl '\n'
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
const int N=1e6+5;
int sj[N],next[N];
char w[N];
inline void putt(int top){
    if(top==1)putchar(w[top]);
    if(top>1){
        putt(top-1);
        putchar(w[top]);
    }
}
int main(){
#ifdef ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
#endif
    // freopen("in.in","r",stdin),freopen("out.out","w",stdout);
    std::string a,b;
    std::cin>>b>>a;
    int la=a.size(),lb=b.size();
    a=' '+a,b=' '+b;
    // std::cout<<a<<endl<<b<<endl;
    // int j=0;
    for(int i=2,j=0;i<=la;++i){
        while(j&&a[i]!=a[j+1])j=next[j];
        if(a[i]==a[j+1])j++;
        next[i]=j;
    }
    int down=1,top=0;
    for(int i=1;i<=lb;++i){
        int j;
        if(top>=down)j=sj[top];
        else j=0;
        while(j&&b[i]!=a[j+1])j=next[j];
        if(b[i]==a[j+1])j++;
        if(j==la){
            int cnt=la-1;
            while(cnt--)top--;
        }
        else{
            w[++top]=b[i];
            sj[top]=j;
        }
        // std::cout<<j;
        // std::cout<<w[top];
        // w[++top]=
    }
    // std::cout<<endl;
    putt(top);
    return 0;
}