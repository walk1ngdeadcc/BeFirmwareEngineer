#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    double score[3][5]={{60,60,60,60,60},{10,20,30,40,50},{100,100,100,100,100}};
    int class=sizeof(score)/sizeof(score[0]);
    int student=sizeof(score[0])/sizeof(score[0][0]);
    double sum;
    double class_avg;
    for (int i=0;i<class;i++) {
        sum=0;
        for (int j=0;j<student;j++) {
           sum+=score[i][j];
        }
        class_avg+=sum/student;
        printf("班级%d的平均成绩为：%lf\n",i+1,sum/student);
    }
    printf("所有班级平均分为：%.2lf\n",class_avg/class);
    return 0;
}