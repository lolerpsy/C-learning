#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int add,data,next;
};
node list1[100010],list2[100010];
int main(){
    int head,n,k;
    scanf("%d %d %d",&head,&n,&k);
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        list1[a]={a,b,c};
    }
    int p=head,cnt=0;
    while(p!=-1){
        list2[cnt++]=list1[p];
        p=list1[p].next;
    }
    int cnt1=0;
    for(int i=0;i<cnt;i++){
        if(list2[i].data<0) list1[cnt1++]=list2[i];
    }
    for(int i=0;i<cnt;i++){
        if(list2[i].data<=k&&list2[i].data>=0) list1[cnt1++]=list2[i];
    }
    for(int i=0;i<cnt;i++){
        if(list2[i].data>k) list1[cnt1++]=list2[i];
    }
    for(int i=0;i<cnt1-1;i++){
        printf("%05d %d %05d\n",list1[i].add,list1[i].data,list1[i+1].add);
    }
    printf("%05d %d -1\n",list1[cnt1-1].add,list1[cnt1-1].data);
    return 0;
}
