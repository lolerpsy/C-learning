#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
int g[maxn][maxn];

int main(int argc, const char *argv[])
{
	int k,n,m;
	scanf("%d%d%d",&k,&n,&m);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a][b]+=c;
	}
	vector<int> sepect;
	for(int u=1;u<=n;u++){
		int call=0,recall=0;
		for(int v=1;v<=n;v++){
			if(g[u][v]!=0){
				if(g[u][v]<=5){
					call++;
					if(g[v][u]!=0){
						recall++;
					}
				}
			}
		}
		if(call>k && (double)recall/call<0.2){
			sepect.push_back(u);
		}
	}
	if(sepect.size()==0){
		printf("None\n");
		return 0;
	}
	vector<int> su=sepect;
	for(int i=0;i<sepect.size();i++){
		int start=-1;
		for(int j=0;j<sepect.size();j++){
			if(sepect[j]!=0) {
				printf("%d",sepect[j]);
				sepect[j]=0;
				start=j;
				break;
			}
		}
		if(start==-1) break;
		for(int j=start+1;j<sepect.size();j++){
//			printf("%d %d %d %d\n",sepect[start],sepect[j],g[sepect[start]][sepect[j]],g[sepect[j]][sepect[start]]);
			if(sepect[j]!=0 && g[su[start]][sepect[j]]!=0 && g[sepect[j]][su[start]]!=0){
				printf(" %d",sepect[j]);
				sepect[j]=0;
			}
		}
		printf("\n");
	}

	return 0;
}

