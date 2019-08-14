//先对部分排序，把部分排序结果作为结构的一部分储存在结构体中，最后输出时可以一并输出
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct student
{
    string id;
    int score;
    int lnum;
    int lrank;
    int finrank;
} testees;

bool comp1(testees a, testees b);

int main(int argc, const char *argv[])
{
    vector<testees> all;
    int N, total = 0;
    scanf("%d", &N);
    for (int j = 0; j < N; j++)
    {
        int K;
        scanf("%d", &K);
        total += K;
        vector<testees> temp(K);
        for (int i = 0; i < K; i++)
        {
            cin>>temp[i].id>>temp[i].score;
            temp[i].lnum = j + 1;
        }
        sort(temp.begin(), temp.end(), comp1);
        temp[0].lrank = 1;
        all.push_back(temp[0]);
        for (int i = 1; i < K; i++)
        {
            if (temp[i].score == temp[i - 1].score)
                temp[i].lrank = temp[i - 1].lrank;
            else
                temp[i].lrank = i + 1;
            all.push_back(temp[i]);
        }
    }
    sort(all.begin(), all.end(), comp1);

    all[0].finrank = 1;
    for (int i = 1; i < all.size(); i++)
    {
        if (all[i].score == all[i - 1].score)
            all[i].finrank = all[i - 1].finrank;
        else
            all[i].finrank = i + 1;
    }

    printf("%d\n", total);
    for (int i = 0; i < all.size(); i++)
    {
        printf("%s %d %d %d\n", all[i].id.c_str(), all[i].finrank, all[i].lnum, all[i].lrank);//加零补足13位，最理想的使用string作为registration number
    }
    return 0;
}

bool comp1(testees a, testees b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}
