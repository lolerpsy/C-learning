#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct poly
{
    float cof;
    int exp;
};

const float delta = 1e-7;

int main(int argc, const char *argv[])
{
    vector<poly> p1, p2, pp;
    int number1, number2;
    scanf("%d", &number1);
    poly temp;
    for (int i = 0; i < number1; i++)
    {
        scanf("%d %f", &temp.exp, &temp.cof);
        p1.push_back(temp);
    }

    scanf("%d", &number2);
    for (int i = 0; i < number2; i++)
    {
        scanf("%d %f", &temp.exp, &temp.cof);
        p2.push_back(temp);
    }

    auto it1 = p1.begin();
    auto it2 = p2.begin();
    while (it1 != p1.end() && it2 != p2.end())
    {
        if (it1->exp > it2->exp)
        {
            pp.push_back(*it1);
            it1++;
        }
        else if (it1->exp < it2->exp)
        {
            pp.push_back(*it2);
            it2++;
        }
        else
        {
            if ((it1->cof + it2->cof) <= delta)
            {
                it2++;
                it1++;
            }
            else
            {
                it1->cof += it2->cof;
                pp.push_back(*it1);
                it1++;
                it2++;
            }
        }
    }

    while (it1 != p1.end())
    {
        pp.push_back(*it1);
        it1++;
    }

    while(it2!=p2.end())
    {
        pp.push_back(*it2);
        it2++;
    }

    printf("%zu", pp.size());
    if (pp.size())
    {
        printf(" ");
    }
    for (int i = 0; i < pp.size(); i++)
    {
        printf("%d %.1f", pp[i].exp, pp[i].cof);
        if (i < pp.size() - 1)
        {
            printf(" ");
        }
    }

    return 0;
}
