#include<iostream>
#include<string>
#include<unordered_map>
#include<cctype>
using namespace std;
int main(){
    string s,t,maxword;
    getline(cin,s);
    unordered_map<string,int> m;
    for(int i = 0; i < s.length();i++){
        if(isalnum(s[i])){
            s[i] = tolower(s[i]);
            t+=s[i];
        }
        if(!isalnum(s[i]) || i==s.length()-1){
            if(t.length()>0) m[t]++;
            t.clear();
        }
    }
    int maxt=0;
    for(auto it:m){
        if(it.second>maxt){
            maxword = it.first;
            maxt = it.second;
        }
    }
    cout<< maxword << " " << maxt;
    return 0;
}
