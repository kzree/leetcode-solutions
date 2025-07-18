#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(int x) {
    char str[33];
    sprintf(str, "%d", x);
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int a = 123351;

    if (isPalindrome(a)) {
        printf("It is palindrome!");
    } else {
        printf("Womp womp!");
    }

    return 0;
}
