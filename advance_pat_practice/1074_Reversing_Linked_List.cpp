#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
    int addre,data,next;
}list[1000010],llist[100010];//list用于储存原始链表，以数组下标作为地址，范围大于地址的范围；llist储存按照遍历顺序储存的数组，大小只要大于n的范围就行

int main(){
    int head,n,k;
    scanf("%d %d %d",&head,&n,&k);

    for(int i=0;i<n;i++){//读入链表
        int t,t1,t2;
        scanf("%d %d %d",&t,&t1,&t2);
        list[t].data=t1;
        list[t].next=t2;
        list[t].addre=t;
    }

    int cnt=0;
    int p=head;
    while(list[p].next!=-1){//遍历数组，按序存入llist
        llist[cnt++]=list[p];
        p=list[p].next;
    }
    llist[cnt++]=list[p];

    for(int i=0;i<cnt/k;i++){
        reverse(llist+i*k,llist+i*k+k);//每k个反转一次
    }

    for(int i=0;i<cnt-1;i++){
        printf("%05d %d %05d\n",llist[i].addre,llist[i].data,llist[i+1].addre);//因为llist是按照遍历序储存，所以链表的下一个元素就是数组下一个元素，所next就是llist[i+1]的地址
    }
    printf("%05d %d -1\n",llist[cnt-1].addre,llist[cnt-1].data);

    return 0;
}//不能根据链表数据域来排序，因为中间可能存在的废弃的节点（据陈越姥姥所说）,所以要先遍历剔除废弃节点
