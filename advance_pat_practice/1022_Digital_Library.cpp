#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    map<string, set<string>> tobook[5];
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        string bookname;
        getline(cin, bookname);
        for (int j = 0; j < 5; j++) {
            string temp;
            getline(cin, temp);
            if (j != 2) {
                tobook[j][temp].insert(bookname);
            } else {
                vector<string> tokens;
                istringstream iss(temp);
                copy(istream_iterator<string>(iss), istream_iterator<string>(),
                     back_inserter(tokens));
                for (string s : tokens) {
                    tobook[j][s].insert(bookname);
                }
            }
        }
    }
    int k;
    scanf("%d", &k);
    getchar();
    for (int i = 0; i < k; i++) {
        string query;
        getline(cin, query);
        cout << query << endl;
        int cnt = query[0] - '0' - 1;
        string queryword = query.substr(3);
        if (tobook[cnt][queryword].size() == 0) {
            cout << "Not Found\n";
        } else {
            for (string v : tobook[cnt][queryword]) {
                cout << v << endl;
            }
        }
    }
    return 0;
}
