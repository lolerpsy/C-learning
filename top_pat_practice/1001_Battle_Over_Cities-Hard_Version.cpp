#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
int s[510], costall[510];
void init_set() {
    for (int i = 0; i < 510; i++) {
        s[i] = -1;
    }
}
int findfa(int a) {
    int t=a;
    while(s[a]>0){
        a=s[a];
    }
    while(s[t]>0 && s[t]!=a){
        s[t]=a;
        t=s[t];
    }
    return a;
}
void union1(int a, int b) {
    int fa = findfa(a);
    int fb = findfa(b);
    if (fa == fb)
        return;
    if (s[fa] < s[fb]) {
        s[fa] += s[fb];
        s[fb] = fa;
    } else {
        s[fb] += s[fa];
        s[fa] = fb;
    }
}
class edge {
    private:
        int c1, c2, cost, status;
    public:
        void read() { scanf("%d %d %d %d", &c1, &c2, &cost, &status); }
        bool congered(int a) {return c1==a || c2==a;}
        bool operator<(const edge &e) const{
            return status == e.status ? cost < e.cost : status > e.status;
        }
        int getstatus(){return status;}
        int getcost(){return cost;}
        bool unioned(){return findfa(c1)==findfa(c2);}
        void un(){ union1(c1,c2);}
};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<edge> eds(m);
    for (auto e=eds.begin();e!=eds.end();e++)
        e->read();
    sort(eds.begin(), eds.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        init_set();
        int num = n - 2;
        costall[i] = 0;
        for (int j = 0; j < m; j++) {
            if (eds[j].congered(i)) continue;
            if(eds[j].unioned()) continue;
            eds[j].un();
            num--;
            if (eds[j].getstatus() == 0)
                costall[i] += eds[j].getcost();
        }
        if (num > 0)
            costall[i] = inf;
        ans = max(ans, costall[i]);
    }
    if (ans) {
        int flag = 0;
        for (int i = 1; i <= n; i++)
            if (costall[i] == ans) {
                printf("%s%d", flag ? " " : "", i);
                flag = 1;
            }
    } else
        printf("%d\n", ans);
    return 0;
}