#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int father[10010];
bool flag[10010];
struct data{
    int id;
    double me,area;
}family[10010];
struct node{
    int id,pnum=0;
    double me,area,avgm,avga;
    bool visit=false;
}ans[10010];
int findfa(int a){
    while(father[a]!=a){
        a=father[a];
    }
    return a;
}
void union1(int a,int b){
    int faa=findfa(a);
    int fab=findfa(b);
    if(faa<fab) father[fab]=faa;
    else father[faa]=fab;
}
bool comp(node a,node b){
    if(a.avga!=b.avga) return a.avga>b.avga;
    else return a.id<b.id;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<10010;i++) father[i]=i;
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        flag[a]=flag[b]=flag[c]=true;
        family[i].id=a;
        if(b!=-1) union1(a,b);
        if(c!=-1) union1(a,c);
        int cnum;
        scanf("%d",&cnum);
        for(int j=0;j<cnum;j++){
            int cid;
            scanf("%d",&cid);
            flag[cid]=true;
            union1(a,cid);
        }
        scanf("%lf %lf",&family[i].me,&family[i].area);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        int id=findfa(family[i].id);
        ans[id].id=id;
        ans[id].me+=family[i].me;
        ans[id].area+=family[i].area;
        if(!ans[id].visit) cnt++;
        ans[id].visit=true;
    }
    for(int i=0;i<10010;i++){
        if(flag[i]) ans[findfa(i)].pnum++;
    }
    for(int i=0;i<10010;i++){
        if(ans[i].visit){
            ans[i].avgm=ans[i].me/ans[i].pnum;
            ans[i].avga=ans[i].area/ans[i].pnum;
        }
    }
    sort(ans,ans+10010,comp);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].pnum,ans[i].avgm,ans[i].avga);
    }
    return 0;
}
