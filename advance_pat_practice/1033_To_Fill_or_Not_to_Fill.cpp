#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct station{
    double price,distance;
}sta[510];

bool comp(station a,station b){
    return a.distance<b.distance;
}

int main(){
    double c,d,dper;
    int n;
    scanf("%lf %lf %lf %d",&c,&d,&dper,&n);

    for(int i=0;i<n;i++){
        scanf("%lf %lf",&sta[i].price,&sta[i].distance);
    }
    sta[n].price=0;//认为添加最后一个站点，方便循环
    sta[n].distance=d;
    sort(sta,sta+n+1,comp);

    if(sta[0].distance!=0){//如果排序后的第一个加油站距离不为0，则无法出发（第三个测试点）
        printf("The maximum travel distance = 0.00\n");
        return 0;//不建议这样写，main函数最好保证单出口，。。。我是因为最后加的时候懒得调缩进了。
    }

    double maxd=c*dper;

    int begin=0;
    double traveldist=0.0,cost=0.0,currentc=0.0;
    while(begin<n){

        int lessormin=-1;
        double minprice=1e9;
        for(int j=begin+1;j<=n && sta[j].distance-sta[begin].distance<=maxd;j++){//在油箱最大容量内找到第一个比当前油价低的或者范围内最低的
            if(sta[j].price<minprice){
                minprice=sta[j].price;
                lessormin=j;
                if(minprice<sta[begin].price) break;
            }
        }

        if(lessormin==-1) break;//如果找不到就无法到达下一站，退出循环
        else traveldist+=sta[lessormin].distance-sta[begin].distance; //更新前进距离

        double need=(sta[lessormin].distance - sta[begin].distance)/dper;
        if(minprice < sta[begin].price){//如果找到的是比起始油价地的，那么起始加油站只需要加油能到达下一站就行，如果车辆现在的的有满足的话，就不加油
            if(currentc<need){
                cost+=(need-currentc)*sta[begin].price;
                currentc=0;
            }else currentc-=need;
        }else{
            cost+=(c-currentc)*sta[begin].price;
            currentc=c-need;
        }

        begin=lessormin;//更新起始位置
    }

    if(begin==n) printf("%.2lf\n",cost);
    else printf("The maximum travel distance = %.2lf\n",traveldist+maxd);//如果到不了下一站，那么其行进最大距离就是当前行驶距离加上油箱满载能够行驶的最大距离

    return 0;
}
//主要是贪心算法，不容易想到
