#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char realname[40010][5];//这道题好像不能用string，只能用C字符串，否则就会超时（最后一个点）
bool comp(int a,int b) {return strcmp(realname[a],realname[b])<0;}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v[2510];
    for(int i=0;i<n;i++){
        int t;
        scanf("%s %d",realname[i],&t);
        for(int j=0;j<t;j++){
            int temp;
            scanf("%d",&temp);
            v[temp].push_back(i);
        }
    }
    for(int i=1;i<=k;i++){
        cout<<i<<" "<<v[i].size()<<endl;
        sort(v[i].begin(),v[i].end(),comp);
        for(int j=0;j<v[i].size();j++){
            printf("%s\n",realname[v[i][j]]);
        }
    }
    return 0;
}
