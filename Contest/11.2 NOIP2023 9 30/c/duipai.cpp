#include<cstdlib>
#include<cstdio>
#include<ctime>
int main(){
    for(int T=1;T<=10000;T++){
        system("data.exe");
        double st=clock(); 
        system("c.exe");
        double ed=clock();
        system("baoli.exe");
        if(!system("fc cout.out c.out")){
            printf("AC Time:%.1lf ms\n",ed-st);
        }
        else{
            printf("WA\n");
            return 0;
        }
    }
}
