#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool isprime(int a){
  if (a==1 || a==0) return false;//0和1都要特判
  for (int i=2; i*i <= a; i++) {
    if ( a%i == 0) return false;
  }
  return true;
}

int main(){
  int l,k;
  string s;
  cin >> l >> k >> s;
  bool find=false;
  for ( int i = 0; i + k -1 < l; i++) {//i+k是小于等于l的
    if ( isprime( stoi( s.substr(i, k) ) ) ) {
      cout << s.substr(i, k) << endl;
      find=true;
      break;
    }
  }
  if (!find) cout<<"404\n";
  return 0;
}
