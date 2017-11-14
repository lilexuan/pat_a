#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s1[61], s2[61], s3[61], s4[61];
    char weeks[7][5] {
            "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN",
    };
    scanf("%s%s%s%s", s1, s2, s3, s4);
    char week, hour;
    int minute;
    int flag = 0;
    for (int i = 0; i < strlen(s1) && i < strlen(s2); i++) {
        if ('A' <= s1[i] && s1[i] <= 'G' && flag == 0 && s1[i] == s2[i]) {
            week = s1[i];
            flag = 1;
        }
        else if (s1[i] == s2[i] && flag == 1 && ('A' <= s1[i] && s1[i] <= 'N' || '0' <= s1[i] && s1[i] <= '9')) {
                    hour = s1[i];
                    flag = 2;
            }
        else if (flag == 2)
            break;
    }
    for (int i = 0; i < strlen(s3) && i < strlen(s4); i++) {
        if (('a' <= s3[i] && s3[i] <= 'z' || 'A' <= s3[i] && s3[i] <= 'Z') && s3[i] == s4[i]) {
            flag = 3;
            minute = i;
        }
        else if (flag == 3)
            break;
    }
    int real_hour;
    if ('0' <= hour && hour <= '9') {
        real_hour = hour - '0';
    } else if ('A' <= hour && hour <= 'N') {
        real_hour = hour - 'A' + 10;
    }
    printf("%s %02d:%02d", weeks[week - 'A'], real_hour, minute);
    return 0;
}

