#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt=0;
bool unique=true;
int pre[35],post[35],in[35];
void getin(int prel,int prer,int postl,int postr){
    if(prel==prer){
        in[cnt++]=pre[prel];
        return;
    }
    int i=prel+1;
    while(i<=prer && pre[i]!=post[postr-1]) i++;
    /*后序序列中根的前一个输出的分两种情况：
        1.该根有左右孩子时，右子树的根
        2.该根只有一个孩子时，可能是左子树的根，也有可能是右子树的根
    */
    if(i-prel>1)
        getin(prel+1,i-1,postl,postl+(i-prel-1)-1);
    else
    /*i-prel==1说明pre[prel]只有一个孩子，此时它既是先序第一
    个输出的，也是后序最后一个输出的，无法区分是左孩子还是右孩子。*/
        unique=false;
    in[cnt++]=post[postr];
    getin(i,prer,postl+(i-prel-1),postr-1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    getin(0,n-1,0,n-1);
    printf("%s\n%d",unique? "Yes": "No",in[0]);
    for(int i=1;i<cnt;i++) printf(" %d",in[i]);
    printf("\n");
    return 0;
}
