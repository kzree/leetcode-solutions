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
