#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    int m,n,s,a;
    map<string,int> re;
    string s1[1010];
    scanf("%d %d %d",&m,&n,&s);
    a=s;
    for(int i=1;i<=m;i++){
        cin>>s1[i];
        re[s1[i]]=1;
    }
    for(int i=1;i<=m;i++){
        if(i==s && re[s1[i]]!=2){
            cout<<s1[i]<<endl;
            re[s1[i]]=2;
            s+=n;
        }else if(i==s) s+=1;
    }
    if(m<a) printf("Keep going...\n");

    return 0;
}
