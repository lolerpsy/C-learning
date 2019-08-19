#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    int hash[200]={0};
    for(int i=0;i<s2.length();i++){
        hash[s2[i]-0]++;
    }
    for(int i=0;i<s1.length();i++){
        if(hash[s1[i]-0]==0){
            printf("%c",s1[i]);
        }
    }

    return 0;
}
