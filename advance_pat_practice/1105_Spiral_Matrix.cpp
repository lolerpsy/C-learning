#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

bool comp(int a,int b){
    return a>b;
}

int main(){
    int N;
    int a[10010];

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+N,comp);

    int m=(int)sqrt(N),n;
    while(m<=N){
        if(m*m<N) m++;
        if(N%m==0) break;
        m++;
    }
    n=N/m;

    int le=(m+1)/2;
    int cnt=0;
    vector<vector<int> > v(m,vector<int>(n));
    for(int i=0;i<le;i++){
        for(int j=i;j<n-i && cnt<N;j++){
            v[i][j]=a[cnt++];
        }
        for(int j=i+1;j<m-i-1 && cnt<N;j++){
            v[j][n-i-1]=a[cnt++];
        }
        for(int j=n-i-1;j>=i && cnt<N;j--){
            v[m-i-1][j]=a[cnt++];
        }
        for(int j=m-i-1-1;j>=i+1 && cnt<N;j--){
            v[j][i]=a[cnt++];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j) printf(" ");
            printf("%d",v[i][j]);
        }
        printf("\n");
    }

    return 0;
}
