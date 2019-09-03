#include <string>
#include <algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

struct student{
  int score;
  string id;
} stu[10010];

struct type2{
  int nt,ns;
}t2[1010];

bool comp(student a,student b){
  if(a.score!=b.score) return a.score>b.score;
  else return a.id<b.id;
}

struct type3{
  int snum,nt;
};

bool comp1(type3 a,type3 b){
  if(a.nt!=b.nt) return a.nt>b.nt;
  else return a.snum<b.snum;
}

vector<student> v[3];
unordered_map<int,map<int,int> > ma;

int main(){
  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++){
    string s;
    int t;
    cin>>s>>t;
    stu[i].id=s;
    stu[i].score=t;
    if(s[0]=='T') v[0].push_back(stu[i]);
    else if(s[0]=='A') v[1].push_back(stu[i]);
    else v[2].push_back(stu[i]);
    t2[stoi(s.substr(1,3))].nt++;
    t2[stoi(s.substr(1,3))].ns+=t;

    ma[stoi(s.substr(4,6))][stoi(s.substr(1,3))]++;
  }

  string g("TAB");
  for(int q=0;q<m;q++){
    int t;
    string ss;
    cin>>t>>ss;
    printf("Case %d: %d %s\n",q+1,t,ss.c_str());
    if(t==1){
      for(int i=0;i<3;i++){
        if(ss[0]==g[i]) {
          if(v[i].size()==0) printf("NA\n");
          sort(v[i].begin(),v[i].end(),comp);
          for(int j=0;j<v[i].size();j++){
            printf("%s %d\n",v[i][j].id.c_str(),v[i][j].score);
          }
        }
      }
    } else if (t == 2) {
      if (t2[stoi(ss)].nt != 0)
        printf("%d %d\n",t2[stoi(ss)].nt, t2[stoi(ss)].ns);
      else printf("NA\n");
    }else{
      if(ma[stoi(ss)].size()==0) printf("NA\n");
      else{
        vector<type3> t3;
        for(auto it=ma[stoi(ss)].begin();it!=ma[stoi(ss)].end();it++){
          t3.push_back({it->first,it->second});
        }
        sort(t3.begin(),t3.end(),comp1);
        for(int i=0;i<t3.size();i++){
          printf("%d %d\n",t3[i].snum,t3[i].nt);
        }
      }
    }
  }

  return 0;
}
