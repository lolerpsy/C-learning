#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
    int ad,data,next;
}list[100010],rlist[100010],relist[100010];//三个链表，分别为原始链表和剩余链表，以及删除的链表

int hash1[10010];//记录绝对值是否出现过

int main(){
    int head,n;
    scanf("%d %d",&head,&n);

    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);//初始化原始链表
        list[a]={a,b,c};
    }

    int p=head,cnt=0,cnt1=0;
    while(p!=-1){//遍历链表，拆出两个链表，其实也可以在原始链表中增加一个bool变量，那样可以节省空间
        if(hash1[abs(list[p].data)]==0){
            rlist[cnt++]=list[p];
            hash1[abs(list[p].data)]=1;
        }else{
            relist[cnt1++]=list[p];
        }
        p=list[p].next;
    }

    for(int i=0;i<cnt;i++){//输出链表
        printf("%05d %d",rlist[i].ad,rlist[i].data);
        if(i!=cnt-1) printf(" %05d\n",rlist[i+1].ad);
        else printf(" -1\n");
    }
    for(int i=0;i<cnt1;i++){
        printf("%05d %d",relist[i].ad,relist[i].data);
        if(i!=cnt1-1) printf(" %05d\n",relist[i+1].ad);
        else printf(" -1\n");
    }

    return 0;
}
