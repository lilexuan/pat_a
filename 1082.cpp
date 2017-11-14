#include <cstdio>

char units[9][7] = {
        "Yi", "Qian", "Bai", "Shi", "Wan", "Qian", "Bai", "Shi", 0
};

char nums[10][7] = {
        "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

int main()
{
    int number, div = 100000000;
    scanf("%d", &number);
        if (number < 0) {
            printf("Fu ");
            number = -number;
        }
        if (number == 0) {
            printf("ling");
            return 0;
        }
        int digit[9];
        for (int i = 0; i < 9; i++) {
            digit[i] = number / div;
            number -= digit[i] * div;
            div /= 10;
        }
//        for (int i = 0; i < 9; i++) {
//            printf("%d\t", digit[i]);
//        }
//        printf("\n");
        int flag = 0;
        for (int i = 0; i < 9; i++) {
            if (i && digit[i] && flag)
                printf(" ");
            if (i == 1) {
                if (digit[0] != 0 && digit[1] == 0 && (digit[2] || digit[3] || digit[4] || digit[5] ||
                        digit[6] || digit[7] || digit[8]))
                    printf(" ling");
            }
            if (i == 5) {
                if ((digit[5] == 0) && (digit[0] || digit[1] != 0 || digit[2] != 0 || digit[3] != 0 || digit[4] != 0) &&
                        (digit[6] || digit[7] || digit[8]))
                    printf(" ling");
            }
            if (i == 6 || i ==7) {
                if (digit[i] == 0 && digit[i - 1] != 0 && (digit[i + 1] != 0 || digit[8] != 0))
                    printf(" ling");
            }
            if (i == 2 || i ==3) {
                if (digit[i] == 0 && digit[i - 1] != 0 && (digit[i + 1] != 0 || digit[4] != 0))
                    printf(" ling");
            }
            if (!digit[i]) {
                if (i == 4 && (digit[1] != 0 || digit[2] != 0 || digit[3] != 0))
                    printf(" Wan");
                continue;
            } else {
                if (units[i][1] != 0)
                    printf("%s %s", nums[digit[i]], units[i]);
                else
                    printf("%s",nums[digit[i]]);
                flag = 1;
            }
        }
    return 0;
}

