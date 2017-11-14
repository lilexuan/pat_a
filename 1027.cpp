#include <cstdio>

using namespace std;

char radix[13] {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
};

int main()
{
    int R, G, B;
    scanf("%d%d%d", &R, &G, &B);
    printf("#");
    printf("%c%c", radix[R/13], radix[R%13]);
    printf("%c%c", radix[G/13], radix[G%13]);
    printf("%c%c", radix[B/13], radix[B%13]);
    return 0;
}

