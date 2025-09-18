#[allow(dead_code)]
pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn two_sum_167(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = numbers.len() - 1;
        let mut total;

        while left < right {
            total = numbers[left] + numbers[right];
            if total == target {
                return vec![left as i32 + 1, right as i32 + 1];
            } else if total > target {
                right -= 1;
            } else {
                left += 1;
            }
        }
        vec![]
    }
}
