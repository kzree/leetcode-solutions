#include <stdio.h>
#include <stdlib.h>

// Using newton's method for finding root
// https://en.wikipedia.org/wiki/Newton%27s_method
int mySqrt(int x) {
    if (x == 0)
        return 0;

    int current = x;
    int prev = 0;

    if (x > 46340) {
        current = 46340;
    }

    do {
        prev = current;
        current = (current + x / current) / 2;
    } while (current < prev);

    return prev;
}

int main(void) {
    int result = mySqrt(8);
    printf("%d\n", result);
    return EXIT_SUCCESS;
}
