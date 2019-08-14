#include<cstdio>
using namespace std;
int main()
{
    float a[3],b[3],c[3];
    float maxa = 0,maxb = 0,maxc = 0;
    char ra,rb,rc;
    char r[3] = {'W', 'T', 'L'};
    for(int i = 0;i<3;i++)
    {
        scanf("%f",&a[i]);
        if(a[i]>maxa)
        {
            maxa = a[i];
            ra = r[i];
        }
    }

    for(int i = 0;i<3;i++)
    {
        scanf("%f",&b[i]);
        if(b[i]>maxa)
        {
            maxb = b[i];
            rb = r[i];
        }

    }

        for(int i = 0;i<3;i++)
    {
        scanf("%f",&c[i]);
        if(c[i]>maxa)
        {
            maxc = c[i];
            rc = r[i];
        }
    }
    printf("%c %c %c %.2f",ra,rb,rc,(maxa*maxb*maxc*0.65-1)*2);
    return 0;
}
