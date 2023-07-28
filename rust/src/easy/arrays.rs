// 1480. Running Sum of 1d Array
pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
    let mut sum_arr: Vec<i32> = vec![];
    for (i, x) in nums.into_iter().enumerate() {
        if i == 0 {
            sum_arr.push(x)
        } else {
            sum_arr.push(x + sum_arr.get(i - 1).unwrap())
        }
    }

    sum_arr
}
