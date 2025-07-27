#include <stdbool.h>

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

// Could be a lot better I think but passes all the tests
bool isMonotonic(int *nums, int numsSize) {
    int size = removeAdjacent(nums, numsSize);
    if (size == 1) {
        return true;
    }

    if (size == 2 && nums[0] != nums[1]) {
        return true;
    }

    for (int i = 2; i < size; i++) {
        bool c1 = (nums[i - 2] > nums[i - 1] && nums[i - 1] > nums[i]);
        bool c2 = (nums[i - 2] < nums[i - 1] && nums[i - 1] < nums[i]);

        if (!c1 && !c2) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int nums[] = {1, 2, 2, 3};

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    isMonotonic(nums, numsSize);
}
