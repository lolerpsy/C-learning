#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct student{
    int id;
    char name[9];
    int grade;
}stu;

bool comp1(stu a,stu b){
    return a.id<b.id;
}
bool comp2(stu a,stu b){
    string s1(a.name);
    string s2(b.name);
    if(s1==s2) return a.id<b.id;
    else return s1<s2;
}
bool comp3(stu a,stu b){
    if(a.grade==b.grade) return a.id<b.id;
    else return a.grade<b.grade;
}

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    vector<stu> v;
    stu t;
    for(int i=0;i<n;i++){
        scanf("%d %s %d",&t.id,t.name,&t.grade);
        v.push_back(t);
    }

    if(c==1) sort(v.begin(),v.end(),comp1);
    else if(c==2) sort(v.begin(),v.end(),comp2);
    else if(c==3) sort(v.begin(),v.end(),comp3);

    for(int i=0;i<n;i++){
        printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
    }

    return 0;
}
