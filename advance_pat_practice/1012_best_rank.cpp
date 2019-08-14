#include <iostream>
#include <string>
using namespace std;

typedef struct student
{
    string id;
    int grades[3];
    int average;
} stu;

int max(int a[], int n, int &bestrank);

int main(int argc, char const *argv[])
{
    char n[4] = {'A', 'C', 'M', 'E'};
    stu s[2001];
    string ids[2001];
    int number, cnumber;
    scanf("%d %d", &number, &cnumber);
    for (int i = 0; i < number; i++)
    {
        //		scanf("%s %d %d %d",&s[i].id,&s[i].grades[0],&s[i].grades[1],&s.grades[2]);
        cin >> s[i].id >> s[i].grades[0] >> s[i].grades[1] >> s[i].grades[2];
        s[i].average = (s[i].grades[0] + s[i].grades[1] + s[i].grades[2]) / 3;
    }

    for (int i = 0; i < cnumber; i++)
    {
        cin >> ids[i];
    }

    for (int i = 0; i < cnumber; i++)
    {

        int idx;
        bool notfound = true;
        for (int j = 0; j < number; j++)
        {
            if (s[j].id == ids[i])
            {
                idx = j;
                notfound = false;
                break;
            }
        }

        if (notfound)
        {
            printf("N/A");
        }
        else
        {
            int rank[4] = {1, 1, 1, 1};
            for (int i = 0; i < number; i++)
            {
                if (s[idx].average < s[i].average)
                {
                    rank[0]++;
                }
                if (s[idx].grades[0] < s[i].grades[0])
                {
                    rank[1]++;
                }
                if (s[idx].grades[1] < s[i].grades[1])
                {
                    rank[2]++;
                }
                if (s[idx].grades[2] < s[i].grades[2])
                {
                    rank[3]++;
                }
            }
            int bestrank;
            int r = max(rank, 4, bestrank);
            printf("%d %c\n", bestrank, n[r]);
        }
    }

    return 0;
}

int max(int a[], int n, int &bestrank)
{
    bestrank = a[0];
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < bestrank)
        {
            bestrank = a[i];
            idx = i;
        }
    }
    return idx;
}
