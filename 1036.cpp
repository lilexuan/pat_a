#include <cstdio>

using namespace std;

struct student{
    char name[11], id[11], gender;
    int grade;
};


int main()
{
    int n;
    scanf("%d",&n);
    student s[n], Female_best, Male_worst;
    Female_best.grade = -1;
    Male_worst.grade = 101;
    for(int i=0;i<n;i++){
        scanf("%s %c%s%d",s[i].name,&s[i].gender,s[i].id,&s[i].grade);
        if(s[i].gender == 'F'){
            if(s[i].grade > Female_best.grade)
                Female_best = s[i];
        } else{
            if(s[i].grade < Male_worst.grade)
                Male_worst = s[i];
        }
    }
    int difference = Female_best.grade - Male_worst.grade;
    if(Female_best.grade != -1)
        printf("%s %s\n",Female_best.name,Female_best.id);
    else
        printf("Absent\n");
    if(Male_worst.grade != 101)
        printf("%s %s\n",Male_worst.name,Male_worst.id);
    else
        printf("Absent\n");
    if(Female_best.grade == -1 || Male_worst.grade == 101)
        printf("NA");
    else
        printf("%d",difference);
    return 0;
}
