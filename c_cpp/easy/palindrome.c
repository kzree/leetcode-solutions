#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Correct solution from google
bool isPalindromeAlt(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return x == reversed || x == reversed / 10;
}

// Original solution
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

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
