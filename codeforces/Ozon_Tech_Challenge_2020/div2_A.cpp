#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
   int t;
   int a[105],b[105];
   scanf("%d",&t);
   while (t--){
      int n;
      scanf("%d",&n);
      for(int i=0;i<n;i++) scanf("%d",&a[i]);
      for(int i=0;i<n;i++) scanf("%d",&b[i]);
      sort(a,a+n);
      sort(b,b+n);
      for(int i=0;i<n;i++){
         if(i!=0) printf(" ");
         printf("%d",a[i]);
      }
      printf("\n");
      for(int i=0;i<n;i++){
         if(i!=0) printf(" ");
         printf("%d",b[i]);
      }
      printf("\n");
   }
   return 0;
}