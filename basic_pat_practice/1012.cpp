/*
A1能被 5 整除的数字中所有偶数的和；
A2将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1-n2+n3-n4；
A3被 5 除后余 2 的数字的个数；
A4被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A5被 5 除后余 4 的数字中最大数字
*/
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,t;
	int cnt[5]= {0};
	int o[5]= {0};
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&t);
		switch(t%5) {
			case 0:
				if(t%2==0) {
					cnt[0]++;
					o[0]+=t;
				}
				break;
			case 1:
				cnt[1]++;
				if(cnt[1]%2==1) o[1]+=t;
				else o[1]-=t;
				break;
			case 2:
				cnt[2]++;
				o[2]=cnt[2];
				break;
			case 3:
				cnt[3]++;
				o[3]+=t;
				break;
			case 4:
				cnt[4]++;
				if(t>o[4]) o[4]=t;
				break;
		}
	}

	for(int i=0; i<5; i++) {
		if(i) printf(" ");
		if(cnt[i]==0) printf("N");
		else if(i==3) printf("%.1f",(float)o[3]/cnt[3]);
		else printf("%d",o[i]);
	}
	return 0;
}

