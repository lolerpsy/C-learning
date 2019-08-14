#include <iostream>
#include <string>
using namespace std;

typedef struct student
{
    string name, id;
    int score;
} stu;

int main()
{
    int n;
    stu temp, first, last;
    scanf("%d", &n);
    cin >> first.name >> first.id >> first.score;
    last = first;
    for (int i = 1; i < n; i++)
    {
        cin >> temp.name >> temp.id >> temp.score;
        if(temp.score>first.score)
            first = temp;
        if(temp.score<last.score)
            last = temp;
    }
    printf("%s %s\n", first.name.c_str(), first.id.c_str());
    printf("%s %s\n", last.name.c_str(), last.id.c_str());
    return 0;
}
