#include <cstdio>

using namespace std;

struct staff{
    char id[16];
    int hh,mm,ss,HH,MM,SS;
};

bool earlier(staff a, staff b);
bool later(staff a, staff b);

int main()
{
    int M;
    scanf("%d",&M);
    staff s[M],earliest,latest;
    earliest.hh = 23;
    earliest.mm = 59;
    earliest.ss = 59;
    latest.hh = 0;
    latest.mm = 0;
    latest.ss = 0;
    for(int i=0;i<M;i++){
        scanf("%s%d:%d:%d%d:%d:%d",s[i].id,&s[i].hh,&s[i].mm,&s[i].ss,&s[i].HH,&s[i].MM,&s[i].SS);
        if(earlier(s[i],earliest))
            earliest = s[i];
        if(later(s[i],latest))
            latest = s[i];
    }
    printf("%s %s",earliest.id,latest.id);
    return 0;
}

bool earlier(staff a, staff b)
{
    if(a.hh != b.hh)
        return a.hh < b.hh;
    else if(a.mm != b.mm)
        return a.mm < b.mm;
    else
        return a.ss < b.ss;
}

bool later(staff a, staff b)
{
    if(a.HH != b.HH)
        return a.HH > b.HH;
    else if(a.MM != b.MM)
        return a.MM > b.MM;
    else
        return a.SS > b.SS;
}
