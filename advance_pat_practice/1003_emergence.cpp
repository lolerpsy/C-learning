#include <algorithm>
#include <iostream>

using namespace std;

int e[510][510], dist[510], r[510], num[510], rt[510];
bool visit[510];
const int inf = 99999999;
int main(int argc, char const *argv[]) {
  fill(e[0], e[0] + 510 * 510, inf); // fill�Ĳ����ǵ�ַ��������
  int n, m, c1, c2;
  scanf("%d %d %d %d", &n, &m, &c1, &c2);

  for (int i = 0; i < n;
       i++) { //��ʼ��ÿ����ľ�Ԯվ����
    scanf("%d", &r[i]);
  }

  for (int i = 0; i < m; i++) { //��ʼ���߾���
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    e[a][b] = e[b][a] = c;
  }

  for (int i = 0; i < n; i++) {
    e[i][i] = 0;
    dist[i] = e[c1][i];
  } //��ʼ��dist[]

  rt[c1] = r[c1];
  num[c1] = 1;

  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf; //���ڲ��鼯������ѡ��dist�л�δ���ʵ���Сֵ
    for (int j = 0; j < n; j++) {
      if (!visit[j] && dist[j] < minn) {
        u = j;
        minn = dist[j];
      }
    }
    if (u == -1)
      break;
    visit[u] = true;
    for (int v = 0; v < n; v++) {
      if (!visit[v] && e[u][v] != inf) {
        if (dist[u] + e[u][v] < dist[v]) {
          dist[v] = dist[u] + e[u][v];
          rt[v] = r[v] + rt[u];
          num[v] = num[u];
        } else if (dist[u] + e[u][v] == dist[v]) {
          num[v] = num[u] + num[v];
          if (rt[u] + r[v] > rt[v])
            rt[v] = rt[u] + r[v];
        }
      }
    }
  }

  printf("%d %d", num[c2], rt[c2]);
  return 0;
}
