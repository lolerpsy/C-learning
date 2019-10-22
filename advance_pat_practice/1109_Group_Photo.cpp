#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct stu{
    int h;
    string name;
};
bool comp(stu a, stu b){
    if(a.h!=b.h) return a.h>b.h;
    else return a.name < b.name;
}
int main(){
    // ios::sync_with_stdio(false);
    stu s[10010];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].h;
    }
    sort(s,s+n,comp);
    int cnt = 0;
    vector<string> row;
    for(int i = 0;i<k;i++){
        row.clear();
        if(i == 0){
            for(int j = 0;j < n / k + n % k;j++){
                if(j%2 == 0){
                    row.push_back(s[cnt++].name);
                }else row.insert(row.begin(),s[cnt++].name);
            }
        }else{
            for(int j = 0; j < n / k;j++){
                if(j%2 == 0){
                    row.push_back(s[cnt++].name);
                }else row.insert(row.begin(),s[cnt++].name);
            }
        }
        for(int j = 0;j<row.size();j++){
            if(j) printf(" ");
            printf("%s",row[j].c_str());
        }
        printf("\n");
    }
    return 0;
}
