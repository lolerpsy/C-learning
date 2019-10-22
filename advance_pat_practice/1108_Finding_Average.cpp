#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    string t;
    int num = 0,n;
    char s1[100],s2[100];
    double sum = 0.0,temp;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s1);
        sscanf(s1,"%lf",&temp);
        sprintf(s2,"%.2lf",temp);
        bool islegal = (temp<=1000 && temp>=-1000) ? true : false;
        for(int i=0;i<strlen(s1);i++){
            if(s1[i]!=s2[i]) islegal = false;
        }
        if(islegal){
            num++;
            sum+=temp;
        }else printf("ERROR: %s is not a legal number\n",s1);
    }
    if(num == 0) printf("The average of 0 numbers is Undefined\n");
    else if(num==1) printf("The average of 1 number is %.2lf\n",sum/num);
    else printf("The average of %d numbers is %.2lf\n",num,sum/num);
    return 0;
}
