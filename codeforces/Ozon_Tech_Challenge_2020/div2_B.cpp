#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
   string s;
   cin>>s;
   s='#'+s;
   int l=1,r=s.size()-1;
   int a[1005]={0};
   int ans=0;
   while(l<r){
        if(s[l]=='(' && s[r]==')'){
           a[l]=a[r]=1;
           l++;
           r--;
           ans++;
        }
        if(s[r]=='(') r--;
        if(s[l]==')') l++;
   }
   printf("%d\n",ans>0?1:0);
   if(ans>0){
       printf("%d\n",ans*2);
       for(int i=1;i<s.size();i++){
           if(a[i]==1) printf("%d ",i);
       }
   }
   return 0;
}
