#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;
const int N=11111111;
const int base=13331;
int n,a,l,len,hashi[N],p[N];
char c[N];
int hash1(char s[])
{
    int sum=0;
    for(int i=0;i<len;i++)
        sum=sum*base+s[i]-'a';
    return sum;
}
void hash2(char s[])
{
    hashi[0]=s[0]-'a'+1;
    for(int i=1;i<l;i++)
        hashi[i]=hashi[i-1]*base+s[i]-'a';
    return ;
}
signed main()
{
    cin>>n;
    p[0]=1;
    for(int i=1;i<=10000;i++)
        p[i]=p[i-1]*base;
    while(n--)
    {
        int ans=0;
        scanf("%s",c);
        len=strlen(c);
        a=hash1(c);
        scanf("%s",c);
        l=strlen(c);
        hash2(c);
        if(a==hashi[len-1])
            ans++;
        for(int i=len;i<l;i++)
            if(a==hashi[i]-hashi[i-len]*p[len])
                ans++;
        // for(int i=1;i<=len;++i)
        // printf("%llu\n",ans);
        cout<<a<<"fljkdsjlkfdsljkfs\n";
    }
    return 0;
}