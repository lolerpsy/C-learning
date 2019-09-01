#include<cstdio>
#include<string>
#include<iostream>
#include<stack>
using namespace std;

int pre[31],in[31],post[31];

void create(int preroot,int start,int end,int postroot){//通过前序中序得到后序
    if(start>end) return;
    int i=start;
    while(i<=end && in[i]!=pre[preroot]) i++;//在中序中找到根节点，确定左右子树的总节点数（无论是前序后续和中序求另外一个，这个步骤都是最关键的）
    post[postroot]=pre[preroot];

    create(preroot+1,start,i-1,postroot-(end-i)-1);//左子树处理
    create(preroot+i-start+1,i+1,end,postroot-1);//右子树处理
}

int main(){
    int n;
    scanf("%d",&n);
    int cnt1=0,cnt2=0;
    stack<int> s;
    for(int i=0;i<2*n;i++){
        string t;
        int a;
        cin>>t;
        if(t=="Push"){//每次push的数字序列就是前序遍历
            cin>>a;
            pre[cnt1++]=a;
            s.push(a);
        }else{//pop的就是中序遍历
            in[cnt2++]=s.top();
            s.pop();
        }
    }

    create(0,0,n-1,n-1);

    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",post[i]);
    }

    return 0;
}
