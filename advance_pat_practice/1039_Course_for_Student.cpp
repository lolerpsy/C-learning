#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    map<string,vector<int> > m;//嵌套声明的时候记得最后两个尖括号要空一个
    for(int i=0;i<k;i++){
        int coursename,num;
        scanf("%d %d",&coursename,&num);
        for(int j=0;j<num;j++){
            string name;
            cin>>name;
            m[name].push_back(coursename);
        }
    }

    for(int i=0;i<n;i++){
        string stuname;
        cin>>stuname;
        cout<<stuname<<" "<<m[stuname].size();
        sort(m[stuname].begin(),m[stuname].end());//记得从小到大排序
        for(int j=0;j<m[stuname].size();j++){
            printf(" %d",m[stuname][j]);
        }
        printf("\n");
    }

    return 0;
}
