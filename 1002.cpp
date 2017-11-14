#include <cstdio>

using namespace std;


int main()
{
    int n,m;
    double ans[1001] = {0.0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int exp;
        double cof;
        scanf("%d%lf",&exp,&cof);
        ans[exp] += cof;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int exp;
        double cof;
        scanf("%d%lf",&exp,&cof);
        ans[exp] += cof;

    }
    int count = 0;
    for(int i=0;i<1001;i++){
        if(ans[i] != 0.0)
            count++;
    }
    printf("%d",count);
    for (int i=1000;i>=0;i--){
        if(ans[i] != 0.0)
            printf(" %d %.1lf",i,ans[i]);
    }
    return 0;
}

