#include <iostream>
#include <string>
// #include <iomanip>
using namespace std;

int main(int argc, const char *argv[])
{
    string name1, name2;
    cout << "Enter your name:";
    cin >>name1;
    getline(cin, name2);
    cout <<name1<<"\n"<<name2<< endl;
}


