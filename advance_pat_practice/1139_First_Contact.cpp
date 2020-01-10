#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
unordered_map<string,int> name2num;
unordered_map<int,string> num2name;
unordered_map<int,vector<int> > sgf;
int g[310][310]={{0}};
struct ans{
    int a,b;
};
bool comp(ans a,ans b){
	if(a.a!=b.a) return a.a<b.a;
	else return a.b<b.b;
}
int main(int argc, const char *argv[])
{
    int m,n,k,cnt=1;
	scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        if(name2num[a]==0){
            name2num[a]=cnt;
            num2name[cnt]=a;
            cnt++;
        }
        if(name2num[b]==0){
            name2num[b]=cnt;
            num2name[cnt]=b;
            cnt++;
        }
        g[name2num[a]][name2num[b]]=g[name2num[b]][name2num[a]]=1;
        if(a.length()==b.length()){
            sgf[name2num[a]].push_back(name2num[b]);
            sgf[name2num[b]].push_back(name2num[a]);
        }
    }
    vector<ans> anss;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        string c1,c2;
        anss.clear();
        cin>>c1>>c2;
        int id1=name2num[c1],id2=name2num[c2];
        for(auto f:sgf[id1]){
            for(auto f1:sgf[id2]){
                if(c1.length()!=c2.length()){
                    if(g[f][f1]==1){
                        anss.push_back({abs(stoi(num2name[f])),abs(stoi(num2name[f1]))});
                    }
                }else{
                    if(g[f][f1]==1 && f!=id2 &&f1!=id1){
                        anss.push_back({abs(stoi(num2name[f])),abs(stoi(num2name[f1]))});
                    }
                }
            }
        }
        sort(anss.begin(),anss.end(),comp);
        printf("%zu\n",anss.size());
        for(int j=0;j<anss.size();j++){
            printf("%04d %04d\n",anss[j].a,anss[j].b);
        }
    }
	return 0;
}
