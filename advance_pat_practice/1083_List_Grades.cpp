#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
    string s1[101],s2[101];
    bool b[101]={0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        string t1,t2;
        cin>>t1>>t2>>t;
        s1[t]=t1;
        s2[t]=t2;
        b[t]=true;
    }

    int g1,g2;
    scanf("%d %d",&g1,&g2);
    int cnt=0;
    for(int i=g2;i>=g1;i--){
        if(b[i]){
            cout<<s1[i]<<" "<<s2[i]<<endl;
            cnt++;
        }
    }
    if(cnt==0) cout<<"NONE\n";


    return 0;
}
