#include <cstdio>
#include <cstring>

int main()
{
    int N;
    scanf("%d", &N);
    char name[11] = {0};
    char password[11] = {0};
    char ans[1001][11] = {0};
    char ans_team[1001][11] = {0};
    int flag = 0, cnt = 0;
    int NN = N;
    while (N--) {
        scanf("%s%s", name, password);
        for (int i = 0; i < strlen(password); i++) {
            if (password[i] == '1') {
                password[i] = '@';
                flag = 1;
            } else if (password[i] == '0') {
                password[i] = '%';
                flag = 1;
            } else if (password[i] == 'l') {
                password[i] = 'L';
                flag = 1;
            } else if (password[i] == 'O') {
                password[i] = 'o';
                flag = 1;
            }
        }
        if (flag) {
            strcpy(ans[cnt], password);
            strcpy(ans_team[cnt], name);
            cnt++;
        }
        flag = 0;
    }
    if (cnt) {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            printf("%s %s\n", ans_team[i], ans[i]);
        }
    } else {
        if (NN == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", NN);
    }
    return 0;
}

