#include<bits/stdc++.h>
using namespace std;
int num[5][int(1e6)+5];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    // cout<<t<<endl<<endl;
    while(t--){
        
        long long ans=1;
        string s;cin>>s;int n=s.size();s=' '+s;
        for(int i=1;i<=4;i++)
            for(int j=1;j<=n;j++)num[i][j]=0;
        // cout<<t<<endl<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4;j++)num[j][i]=num[j][i-1];
            if(s[i]=='0')num[1][i]++;
            if(s[i]=='6')num[2][i]++;
            if(s[i]=='8')num[3][i]++;
            if(s[i]=='9')num[4][i]++;
            // switch (s[i]){
            //     case '0':num[1][i]++;
            //     case '6':num[2][i]++;
            //     case '8':num[3][i]++;
            //     case '9':num[4][i]++;
            // }
        }
        // cout<<num[1][n]<<' '<<num[2][n]<<' '<<num[3][n]<<' '<<num[4][n]<<endl;
        for(int i=1;i<=n;i++){
            int num1=num[1][n]-num[1][i-1],num2=num[2][n]-num[2][i-1],
            num3=num[3][n]-num[3][i-1],num4=num[4][n]-num[4][i-1];
            if(s[i]=='0')ans+=num2+num3+num4;
            if(s[i]=='6')ans+=num1+num2+num3;
            if(s[i]=='8')ans+=num1+num2+num4;
            if(s[i]=='9')ans+=num1+num3+num4;
        }
        if(num[2][n]==n||num[4][n]==n)ans--;
        cout<<ans<<'\n';
    }
    return 0;
}