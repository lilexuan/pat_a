#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = -sum;
    }
    char result[20] = {0};
    int k = 0;
    if (!sum)
        printf("0");
    for (int i = 0;sum != 0; i++) {
        if (i % 3 == 0 && i > 0) {
            result[k++] = ',';
        }
        result[k++] = (char)(sum % 10 + '0');
        sum /= 10;
    }
    reverse(result, result + strlen(result));
    printf("%s", result);
    return 0;
}

