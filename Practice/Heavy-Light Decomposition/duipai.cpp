#include<cstdlib>
#include<cstdio>
#include<ctime>
int main(){
    for(int T=1;T<=10000;T++){
        system("date.exe");
        double st=clock(); 
        system("tiao2486.exe");
        double ed=clock();
        system("ac2486.exe");
        if(!system("fc date.out sol.out")){
            printf("AC Time:%.1lf ms\n",ed-st);
        }
        else{
            printf("WA\n");
            return 0;
        }
    }
}
