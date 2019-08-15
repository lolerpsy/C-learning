#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    string s[105];
    int len[105];
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
        len[i]=s[i].length();
    }

    int minlen=s[0].length();
    int cnt=0;
    for(int i=1;i<=minlen;i++){
        bool allsame=true;
        for(int j=1;j<n;j++){
            if(s[j][s[j].length()-i]!=s[0][minlen-i]){
                allsame=false;
                break;
            }
        }
        if(allsame) cnt++;
        else break;
    }

    if(cnt) cout<<s[0].substr(s[0].length()-cnt)<<endl;
    else cout<<"nai\n";

    return 0;
}
