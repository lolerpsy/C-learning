#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct person{
    int id,vg,tg;
};
vector<person> sages,nobleman,foolman,smallman;
bool comp(person a,person b){
    if(a.vg+a.tg != b.vg+b.tg) return a.vg+a.tg > b.vg+b.tg;
    else if(a.vg != b.vg) return a.vg > b.vg;
    else return a.id<b.id;
}
int main(){
    int n,l,h,m=0;
    scanf("%d %d %d",&n,&l,&h);
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(b>=l && c>=l) m++;
        if(b>=h && c>=h) sages.push_back({a,b,c});
        else if(b>=h && c>=l) nobleman.push_back({a,b,c});
        else if(b>=l && c>=l && b>=c) foolman.push_back({a,b,c});
        else if(b>=l && c>=l) smallman.push_back({a,b,c});
    }
    sort(sages.begin(),sages.end(),comp);
    sort(nobleman.begin(),nobleman.end(),comp);
    sort(foolman.begin(),foolman.end(),comp);
    sort(smallman.begin(),smallman.end(),comp);
    printf("%d\n",m);
    for(auto it:sages){
        printf("%08d %d %d\n",it.id,it.vg,it.tg);
    }
    for(auto it:nobleman){
        printf("%08d %d %d\n",it.id,it.vg,it.tg);
    }
    for(auto it:foolman){
        printf("%08d %d %d\n",it.id,it.vg,it.tg);
    }
    for(auto it:smallman){
        printf("%08d %d %d\n",it.id,it.vg,it.tg);
    }
    return 0;
}
