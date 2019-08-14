#include <iostream>
using namespace std;

void hanoi(int ,char ,char ,char);
void move(char, char);

int main(int argc, const char *argv[])
{
    int number;
    cin >> number;
    char a = 'A', b = 'B', c = 'C';
    hanoi(number, a, b, c);
    return 0;
}

void hanoi(int n, char a, char b, char c)
{
    if (n==1)
    {
        move(a, c);
    }
    else
    {
        hanoi(n - 1, a, c, b);
        move(a, c);
        hanoi(n - 1, b, a, c);
    }
}

void move(char a, char b)
{
    cout << a << " -> " << b << endl;
}
