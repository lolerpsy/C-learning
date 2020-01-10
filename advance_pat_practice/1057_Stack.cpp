#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=100010;
int block[316]={0},table[maxn]={0};
void peekmedian(int k){
    int sum=0,cnt=0;
    while(sum+block[cnt]<k){
        sum+=block[cnt++];
    }
    int num=cnt*316;
    while(sum+table[num]<k){
        sum+=table[num++];
    }
    printf("%d\n",num);
}
int main(){
    stack<int> s;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        if(t=="Push"){
            int num;
            scanf("%d",&num);
            s.push(num);
            block[num/316]++;
            table[num]++;
        }else if(t=="Pop"){
            if(s.empty()) printf("Invalid\n");
            else{
                printf("%d\n",s.top());
                block[s.top()/316]--;
                table[s.top()]--;
                s.pop();
            }
        }else{
            if(s.empty()) printf("Invalid\n");
            else{
                int k=s.size();
                k= k%2==0?k/2:(k+1)/2;
                peekmedian(k);
            }
        }
    }
    return 0;
}
