#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    char num_for_read[10][10] {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    char number[110];
    scanf("%s", number);
    int sum = 0;
    stack<int> s;
    for (int i = 0; i < strlen(number); i++) {
        sum += number[i] - '0';
    }
    do {
        s.push(sum % 10);
        sum /= 10;
    } while (sum);
    int flag = 0;
    while (!s.empty()) {
        if(flag)
            printf(" ");
        else
            flag = 1;
        printf("%s", *(num_for_read + s.top()));
        s.pop();
    }
    return 0;
}

