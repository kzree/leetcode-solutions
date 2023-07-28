// 412. Fizz Buzz
pub fn fizz_buzz(n: i32) -> Vec<String> {
    let mut arr: Vec<String> = vec![];

    for i in 1..=n {
        let mut string = String::from("");
        if i % 3 == 0 {
            string = string + "Fizz";
        }
        if i % 5 == 0 {
            string = string + "Buzz";
        }
        if string == "" {
            arr.push(i.to_string());
            continue;
        }
        arr.push(string);
    }

    arr
}
