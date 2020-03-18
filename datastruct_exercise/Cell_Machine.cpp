#include<iostream>
#include<cstdio>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
#include<windows.h>
using namespace std;
void print(vector<vector<int>> a){
    string s;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==1) s+="█ ";
            else s+="  ";
        }
        s+="\n";
    }
    printf("%s\n",s.c_str());
}
int main(){
    int width=30,height=30;
    vector<vector<int>> g(height);
    for(int i=0;i<height;i++){
        g[i].resize(width);
    }
    srand(time(NULL));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(rand()%100<20) g[i][j]=1;
            else g[i][j]=0;
        }
    }
    print(g);
    for(int step=0;step<1000;step++){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                int row1,row2,col1,col2,numoflive=0;
                row1= i==0?i:i-1;
                row2= i==height-1?i:i+1;
                col1= j==0?j:j-1;
                col2= j==width-1?j:j+1;
                for(int r=row1;r<=row2;r++){
                    for(int c=col1;c<=col2;c++){
                        if(!(r==i && c==j)){
                            if(g[r][c]==1) numoflive++;
                        }
                    }
                }
                if(g[i][j]==1){
                    if(numoflive<2 || numoflive>3) g[i][j]=0;
                }else if(numoflive==3) g[i][j]=1;
            }
        }
        print(g);
        Sleep(1000);
        fflush( stdout );
    }

    return 0;
}
