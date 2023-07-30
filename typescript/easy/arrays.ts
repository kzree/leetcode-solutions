// 1089. Duplicate zeroes
/**
 Do not return anything, modify arr in-place instead.
 */
function duplicateZeros(arr: number[]): void {
  const maxLength = arr.length;
  const indexes: number[] = [];

  arr.forEach((element, index) => {
    if (element === 0) {
      indexes.push(index);
    }
  });

  indexes.forEach((n, idx) => {
    arr.splice(n + 1 + idx, 0, 0);
  })

  arr.splice(maxLength, arr.length - 1);
};

// 88. Merge sorted array
/**
 Do not return anything, modify nums1 in-place instead.
 */
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
  for (let i = m; i < m + n; i++) {
    nums1[i] = nums2[i - m];
  }
  nums1.sort((a, b) => a - b);
};
