#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    string a[1010],b[1010],c[1010],d[1010];
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        bool modify=false;
        for(int j=0;j<b[i].length();j++){
            if(b[i][j]=='1'){
                b[i][j]='@';
                modify=true;
            }
            else if(b[i][j]=='0'){
                b[i][j]='%';
                modify=true;
            }else if(b[i][j]=='l'){
                b[i][j]='L';
                modify=true;
            }else if(b[i][j]=='O'){
                b[i][j]='o';
                modify=true;
            }
        }
        if(modify) {
            c[cnt]=b[i];
            d[cnt]=a[i];
            cnt++;
        };
    }

    if(cnt==0 && n==1) printf("There is 1 account and no account is modified\n");
    else if(cnt==0) printf("There are %d accounts and no account is modified\n",n);
    else{
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++){
            printf("%s %s\n",d[i].c_str(),c[i].c_str());
        }
    }
    return 0;
}
