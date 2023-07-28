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

// 1672. Richest Customer Wealth
pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
    let mut richest = 0;

    for client in &accounts {
        let mut total_value = 0;
        for bank_value in client {
            total_value += bank_value;
        }
        if total_value > richest {
            richest = total_value;
        }
    }

    richest
}
