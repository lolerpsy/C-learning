#include<cstdio>
#include<algorithm>

using namespace std;
typedef struct student{
    int id,ge,gi,sum,rank;
    int choice[5];
    bool ad=false;
}stu;

typedef struct college{
    int id,quota;
    int admit[40010];
    int lastadmit=-1;
    int admitnum=0;
}school;

stu s[40010];
school sch[100];

bool comp1(stu a,stu b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    else return a.ge>b.ge;
}

bool compid(int a,int b){
    return a<b;
}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    for(int i=0;i<m;i++){
        scanf("%d",&sch[i].quota);
        sch[i].id=i;
        sch[i].lastadmit=-1;
        sch[i].admitnum=0;
    }

    for(int i=0;i<n;i++){
        s[i].id=i;
        s[i].ad=false;
        scanf("%d %d",&s[i].ge,&s[i].gi);
        s[i].sum=s[i].ge+s[i].gi;
        for(int j=0;j<k;j++){
            scanf("%d",&s[i].choice[j]);
        }
    }

    sort(s,s+n,comp1);

    int r=1;
    s[0].rank=r;
    for(int i=1;i<n;i++){
        if(s[i].sum<s[i-1].sum || (s[i].sum==s[i-1].sum &&s[i].ge<s[i-1].ge)) r++;
        s[i].rank=r;
    }

    for(int j=0;j<n;j++){//注意录取模式和我们常识中的第一志愿模式不一样，是对同一个学生先遍历其所有的志愿直到录取为止
        for(int i=0;i<k;i++){//遍历志愿
            int cho=s[j].choice[i];
            int num=sch[cho].admitnum;//通过志愿取出相应的学校
            int last=sch[cho].lastadmit;//该校上一个录取学生的排名

            if(num<sch[cho].quota || (last!=-1 && s[last].rank==s[j].rank)){//学校未录满或者和录取最后一名排名相同
                sch[cho].admitnum++;
                sch[cho].lastadmit=j;
                sch[cho].admit[num]=s[j].id;//学生id存入
                s[j].ad=true;
            }
            if(s[j].ad) break;
        }
    }

    for(int i=0;i<m;i++){
        if(sch[i].admitnum>0){//录取不为空

            sort(sch[i].admit,sch[i].admit+sch[i].admitnum,compid);//按学生id排序

            for(int j=0;j<sch[i].admitnum;j++){
                if(j) printf(" ");
                printf("%d",sch[i].admit[j]);
            }
        }

        printf("\n");
    }

    return 0;
}
