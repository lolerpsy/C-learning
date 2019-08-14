#include<iostream>
#include<cstdio>
using namespace std;
typedef struct Node{
	int data,next;
}list;
list a[100005];
int main(int argc, const char *argv[])
{
	int t,d,n;
	int head,len,k;
	int old_head,new_head,temp,new_list,pre_head;
	scanf("%d %d %d",&head,&len,&k);
	for(int i=0;i<len;i++){
		scanf("%d %d %d",&t,&d,&n);
		a[t].data=d;
		a[t].next=n;
	}
	int p=head;
	int cnt=0;
	while(p!=-1){
		cnt++;
		p=a[p].next;
	}
	new_list=pre_head=head;
	for(int j=0;j<cnt/k;j++){
		new_head=head;
		old_head=a[head].next;
		for(int i=0;i<k-1;i++){
			temp=a[old_head].next;
			a[old_head].next=new_head;
			new_head=old_head;
			old_head=temp;
		}
		a[pre_head].next=new_head;//需要一个prehead指针记录上一次逆转周期的最后一个节点的指针，把它指向这一次的第一个元素
		a[head].next=old_head;
		if(j==0) new_list=new_head;
		pre_head=head;
		head=old_head;//一个为上一次的head，另一个是上一次的oldhead
	}
	
	p=new_list;
	while(a[p].next!=-1){
		printf("%05d %d %05d\n",p,a[p].data,a[p].next);
		p=a[p].next;
	}
	printf("%05d %d -1",p,a[p].data);

	return 0;
}//睡觉了，晚安。。。

