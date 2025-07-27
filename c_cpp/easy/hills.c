#include <stdio.h>
#include <stdlib.h>

// TODO: these two functions could be merged into a single one, could improve
// perf At the same time, this one got 0ms runtime so I am happy
int removeAdjacent(int *nums, int numsSize) {
    int writeIndex = 1;

    for (int readIndex = 1; readIndex < numsSize; readIndex++) {
        if (nums[readIndex] != nums[readIndex - 1]) {
            nums[writeIndex] = nums[readIndex];
            writeIndex++;
        }
    }

    return writeIndex;
}

int countHillValley(int *nums, int numsSize) {
    int size = removeAdjacent(nums, numsSize);
    int result = 0;
    for (int i = 1; i < size - 1; i++) {
        if ((nums[i - 1] < nums[i] && nums[i + 1] < nums[i]) ||
            (nums[i - 1] > nums[i] && nums[i + 1] > nums[i])) {
            result++;
        }
    }

    return result;
}

int main(void) {
    int nums[] = {2, 4, 1, 1, 6, 5};

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = countHillValley(nums, numsSize);
    printf("Result is: %d \n", result);

    return EXIT_SUCCESS;
}
