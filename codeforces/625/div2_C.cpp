#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    int re[26]={0};
    scanf("%d",&n);
    string s;
    cin>>s;    
    for(int i=0;i<s.size();i++) re[s[i]-'a']++;
    for(int i=25;i>0;i--){
        if(re[i]==0) continue;
        for(int k=0;k<=100;k++){    
            for(int j=0;j<s.size();j++){
                if(s[j]-'a'!=i) continue;
                if(j==0 && s[j+1]-'a'==i-1){
                    ans++;
                    s.erase(s.begin()+j);
                    j--;
                }else if(j==s.size()-1 && s[j-1]-'a'==i-1){
                    ans++;
                    s.erase(s.begin()+j);
                    j--;
                }else if(j!=0 && j!=s.size()-1 && (s[j-1]-'a'==i-1||s[j+1]-'a'==i-1)){
                    ans++;
                    s.erase(s.begin()+j);
                    j--;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
