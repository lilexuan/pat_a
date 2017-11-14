#include <cstdio>

using namespace std;

const int Galleon = 17 * 29;
const int Sickle = 29;

int main()
{
    long long ag, as, ak, bg, bs, bk;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &ag, &as, &ak, &bg, &bs, &bk);
    long long A = ag * Galleon + as * Sickle + ak;
    long long B = bg * Galleon + bs * Sickle + bk;
    long long result = A + B;
    printf("%lld.%lld.%lld", result / Galleon, result % Galleon / Sickle, result % Sickle);
    return 0;
}

