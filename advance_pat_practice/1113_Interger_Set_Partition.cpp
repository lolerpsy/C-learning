#include<cstdio>
using namespace std;
int a[100010];
int findmid(int low,int high){
    int mid=(low+high)/2;
    if(a[mid]>a[low] && a[mid]>a[high]) return low>high?low:high;
    else if(a[mid]<a[low] && a[mid]<a[high]) return low<high?low:high;
    else return mid;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int low=0,high=n-1,ans1=0,ans2=0;
    while(1){
        int t=findmid(low,high);
        int pivot=a[t],low1=low,high1=high;
        a[t]=a[low];
        while(low<high){
            while(low<high && a[high]<=pivot) high--;
            a[low]=a[high];
            while(low<high && a[low]>=pivot) low++;
            a[high]=a[low];
        }
        a[low]=pivot;
        if(low==(n-1)/2) break;
        else if(low<(n-1)/2){
            low++;
            high=high1;
        }else{
            high--;
            low=low1;
        }
    }
    for(int i=0;i<=low;i++) ans1+=a[i];
    for(int i=low+1;i<n;i++) ans2+=a[i];
    printf("%d %d",n%2,ans1-ans2);
    return 0;
}
