#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int re[40]={0};
    int n,num=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[5];
        scanf("%s",s);
        int sum=0;
        int j=0;
        while(s[j]!='\0'){
            sum+=s[j]-'0';
            j++;
        }
        if(re[sum]==0) num++;
        re[sum]=1;
    }
    int cnt=0;
    printf("%d\n",num);
    for(int i=0;i<=40;i++){
        if(re[i]==1){
            if(cnt) printf(" ");
            printf("%d",i);
            cnt++;
        }
    }
    printf("\n");
    return 0;
}
