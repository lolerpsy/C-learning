#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct person{
    int age;
    char name[9];
    int worth;
}per;

bool comp1(per a,per b){
    return a.age<b.age;
}
bool comp2(per a,per b){
    string s1(a.name);
    string s2(b.name);
    if(a.worth!=b.worth) return a.worth>b.worth;
    else if(a.age!=b.age) return a.age<b.age;
    else return s1<s2;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<per> v2;
    per t;
    int hash[201]={0};
    for(int i=0;i<n;i++){
        scanf("%s %d %d",t.name,&t.age,&t.worth);
        v2.push_back(t);
    }
    sort(v2.begin(),v2.end(),comp2);
    vector<per> v;
    for(int i=0;i<v2.size();i++){
        if(hash[v2[i].age]<100){
            hash[v2[i].age]++;
            v.push_back(v2[i]);
        }
    }

    for(int i=0;i<k;i++){
        printf("Case #%d:\n",i+1);
        int num,minage,maxage;
        scanf("%d %d %d",&num,&minage,&maxage);

        int cnt=0;
        for(int j=0;j<v.size() && cnt<num;j++){
            if(v[j].age<=maxage && v[j].age>=minage){
                printf("%s %d %d\n",v[j].name,v[j].age,v[j].worth);
                cnt++;
            }
        }
        if(cnt==0) printf("None\n");
    }

    return 0;
}
