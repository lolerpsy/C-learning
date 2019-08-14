/*
A1�ܱ� 5 ����������������ż���ĺͣ�
A2���� 5 ������ 1 �����ְ�����˳����н�����ͣ������� n1-n2+n3-n4��
A3�� 5 ������ 2 �����ֵĸ�����
A4�� 5 ������ 3 �����ֵ�ƽ��������ȷ��С����� 1 λ��
A5�� 5 ������ 4 ���������������
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

