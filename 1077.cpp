#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int N, min_len = 99999999;
    char s[101][257] = {0};
    char common[257] = {0};
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        gets(s[i]);
        reverse(s[i], s[i] + strlen(s[i]));
        if (strlen(s[i]) < min_len)
            min_len = strlen(s[i]);
    }
    int k = 0;
    for (int i = 0; i < min_len; i++) {
        int flag = 1;
        for (int j = 0; j < N - 1; j++) {
            if (s[j][i] != s[j+1][i])
                flag = 0;
        }
        if (flag)
            common[k++] = s[0][i];
        else // 非常重要！！
            break;
    }
    reverse(common, common + strlen(common));
    if (strlen(common))
        printf("%s", common);
    else
        printf("nai");
    return 0;
}

