#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int m,n,l,t;

struct pixel{//像素点结构体
    int x,y,z;
};

int pix[1290][130][61];

bool visit[1290][130][61]={{{false}}};

bool canv(pixel p){//判断点是否应该遍历
    if(p.x>=m || p.x<0 || p.y>=n || p.y<0 || p.z>=l || p.z<0) return false;//越界点不能访问
    if(visit[p.x][p.y][p.z] || pix[p.x][p.y][p.z]==0) return false;//已访问点和0点不能访问
    return true;//其余可以访问
}

int dx[6]={1,-1,0,0,0,0};//三个方向的变化率，每次移动一个像素点
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int bfs(pixel p1){
    visit[p1.x][p1.y][p1.z]=true;
    queue<pixel> q;
    q.push(p1);
    int cnt=0;
    while(!q.empty()){
        pixel p=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<6;i++){
            pixel newp;
            newp={p.x+dx[i], p.y+dy[i], p.z+dz[i]};
            if(canv(newp)) {
                visit[newp.x][newp.y][newp.z]=true;
                q.push(newp);
            }
        }
    }

    if(cnt>=t) return cnt;//大于阈值，则计数，否则返回零
    else return 0;
}

int main(){

    scanf("%d%d%d%d",&m,&n,&l,&t);

    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                scanf("%d",&pix[j][k][i]);//初始化pix数组
            }
        }
    }

    int ans=0;
    for(int i=0;i<l;i++){//bfs进行遍历
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                pixel point={j,k,i};
                if(canv(point)){
                    ans+=bfs(point);
                }
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}
