#include <cstdio>

using namespace std;

int main()
{
    int num, b, result[500] = {0};
    while (scanf("%d%d", &num, &b) != EOF) {
        int k = 0;
        do {
            result[k++] = num % b;
            num /= b;
        } while (num);
        int flag = 1;
        for (int i = 0; i <= k / 2; i++) {
            if (result[i] != result[k - 1 - i])
                flag = 0;
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
        for (int i = k - 1; i >= 0; i--) {
            printf("%d", result[i]);
            if (i != 0)
                printf(" ");
        }
    }
    return 0;
}
