#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    string s;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;
        long long c=stoll(s);
        long long a=stoll(s.substr(0,s.size()/2));
        long long b=stoll(s.substr(s.size()/2,s.size()/2));
        if(a*b==0) {
            printf("No\n");
            continue;
        }
        printf("%s\n",c%(a*b)==0?"Yes":"No");
    }
    return 0;
}
