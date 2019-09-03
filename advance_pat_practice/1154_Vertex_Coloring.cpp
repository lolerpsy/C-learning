#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 10010;

int color[maxn];

struct edge{
  int f,e;
  bool same;
}eg[10010];

int main() {
  int nv, ne;
  scanf("%d %d", &nv, &ne);
  for (int i = 0; i < ne; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    eg[i].f=a;
    eg[i].e=b;
  }

  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    set<int> c;
    for (int j = 0; j < nv; j++) {
      scanf("%d", &color[j]);
      c.insert(color[j]);
    }
    bool flag=true;
    for(int i=0;i<ne;i++){
      if(color[eg[i].f]!=color[eg[i].e]) eg[i].same=true;
      else eg[i].same=false;
      flag=(flag&&eg[i].same);
    }
    if(flag) printf("%d-coloring\n",c.size());
    else printf("No\n");
  }


  return 0;
}
