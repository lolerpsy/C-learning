#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,b;
    int dp[105][105]={{0}};
    while(cin>>a>>b){
        int lena=a.length();
        int lenb=b.length();
        for(int i=1;i<=lena;i++){
            for(int j=1;j<=lenb;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]= dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }


    return 0;
}
