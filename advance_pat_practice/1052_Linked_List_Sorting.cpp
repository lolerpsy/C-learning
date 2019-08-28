#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
    int ad,data,next;
}list[100000],rlist[100000];

bool comp(Node a,Node b){
    return a.data<b.data;
}

int main(){
    int n,head;
    scanf("%d %d",&n,&head);

    for(int i=0;i<n;i++){
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        list[t1].data=t2;
        list[t1].ad=t1;
        list[t1].next=t3;
    }

    int p=head,cnt=0;
    while(p!=-1){//遍历链表，排除非链表节点，复制到rlist
        rlist[cnt++]=list[p];
        p=list[p].next;
    }

    if(cnt==0){
        printf("0 -1\n");
    }else{
        sort(rlist,rlist+cnt,comp);

        printf("%d %05d\n",cnt,rlist[0].ad);

        for(int i=0;i<cnt-1;i++){//输出前cnt-1个节点
            printf("%05d %d %05d\n",rlist[i].ad,rlist[i].data,rlist[i+1].ad);
        }
        printf("%05d %d -1\n",rlist[cnt-1].ad,rlist[cnt-1].data);//输出最后一个节点
    }

    return 0;
}
