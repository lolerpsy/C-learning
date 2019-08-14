#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
    string s="0123456789ABC";
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    printf("#");
    for(int i=0;i<3;i++){
        printf("%c",s[a[i]/13%13]);
        printf("%c",s[a[i]%13]);
    }

    return 0;
}
