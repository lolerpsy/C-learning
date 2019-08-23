#include<cstdio>
using namespace std;

int main(){
    int n;
    double sum=0.0,temp=0.0;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%lf",&temp);
        sum+=temp*i*(n-i+1);
    }

    printf("%.2lf",sum);

    return 0;
}
//
// 这道题有点奇怪，本来应该还有一种解法：
// #include<cstdio>
// using namespace std;

// int main(int argc, const char *argv[])
// {
// 	int n;
// 	double sum=0.0;
// 	double temp=0.0;
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;i++){
// 		double t;
// 		scanf("%lf",&t);
// 		temp=temp+t*i;
// 		sum+=temp;
// 	}
// 	printf("%.2lf\n",sum);
// 	return 0;
// }
//但是好像因为后台测验的double精度问题，这种方法通不过第三个测试点。
//有一种方式可以验证就是把11行的sum+=temp*i*(n-i+1);改为sum+=temp*(i*(n-i+1));这样就后面两个测试点都通不过

