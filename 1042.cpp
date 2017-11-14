#include <cstdio>
using namespace std;

void shuffling(int a[], int b[]);
void output(int a[]);

int main()
{
    int N;
    scanf("%d",&N);
    int a[55];
    for(int i=0;i<55;i++){
        a[i] = i;
    }
    int b[55] = {0};
    for(int i=1;i<55;i++){
        scanf("%d",&b[i]);
    }
    while (N--){
        shuffling(a,b);
    }
    output(a);
    return 0;
}

void  shuffling(int a[], int b[])
{
    int c[55] = {0};
    for(int i=1;i<55;i++){
        c[b[i]] = a[i];
    }
    for(int i=0;i<55;i++){
        a[i] = c[i];
    }
    return;
}

void output(int a[])
{
    int flag = 0;
    for(int i=1;i<55;i++){
        if(flag)
            printf(" ");
        if(1 <= a[i] && a[i] <= 13)
            printf("S%d",a[i]);
        else if (14 <= a[i] && a[i] <= 26)
            printf("H%d",a[i] - 13);
        else if (27 <= a[i] && a[i] <= 39)
            printf("C%d", a[i] -26);
        else if (40 <= a[i] && a[i] <= 52)
            printf("D%d",a[i] - 39);
        else
            printf("J%d",a[i]  -52);
        if (!flag)
            flag = 1;
    }
    return ;
}

