#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	scanf("%d", &n);
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			vector<int> identify(n+1,1),liar;
			identify[i] = identify[j] = -1;
			for (int k = 1; k <=n; k++)
				if(v[k] * identify[abs(v[k])] < 0) liar.push_back(k);
			if (liar.size() == 2 && identify[liar[1]] + identify[liar[0]] == 0) {
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}

