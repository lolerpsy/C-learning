#include<iostream>
#include<string>
#include<set>
#include<map>
#include<cstdio>

using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    set<char> y1,y2;
     map<char,int> m1,m2;
    for(int i=0;i<s2.length();i++){
        y2.insert(s2[i]);
        m2[s2[i]]++;
    }

    for(int i=0;i<s1.length();i++){
        y1.insert(s1[i]);
        m1[s1[i]]++;
    }
    bool buy=true;
    int less=0;
    for(auto it=y2.begin();it!=y2.end();it++){
        if(m1[*it]<m2[*it]){
            buy=false;
            less+=m2[*it]-m1[*it];
        }
    }
    if(buy){
        printf("Yes %d",s1.length()-s2.length());
    }else printf("No %d",less);

    return 0;
}
