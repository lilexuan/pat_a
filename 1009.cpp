#include <cstdio>

using namespace std;

struct Poly{
    int exp;
    double cof;
} poly[1001];



int main()
{
    int n,m,number = 0;
    double ans[2001] = {0.0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%lf",&poly[i].exp,&poly[i].cof);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int exp,j;
        double cof;
        scanf("%d%lf",&exp,&cof);
        for(j=0;j<n;j++){
            ans[exp+poly[j].exp] += cof * poly[j].cof;
        }
    }
    for(int i=0;i<=2000;i++){
        if(ans[i] != 0.0)
            number++;
    }
    printf("%d",number);
    for(int i=2000;i>=0;i--){
        if(ans[i] != 0.0){
            printf(" %d %.1lf",i,ans[i]);
        }
    }
    return 0;
}

