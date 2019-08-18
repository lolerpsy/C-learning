#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int a[200]={0};
    for(int i=0;i<s2.length();i++){
        a[s2[i]-0]=1;
    }
    for(int i=0;i<s1.length();i++){
        if(a[s1[i]-0]==0){
            if(isalpha(s1[i])){
                printf("%c",toupper(s1[i]));
                a[toupper(s1[i])-0]=a[tolower(s1[i])-0]=1;
            }else{
                printf("%c",s1[i]);
                a[s1[i]-0]=1;
            }
        }
    }
    return 0;
}
