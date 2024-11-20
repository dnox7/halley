#[allow(dead_code)]
pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn find_content_children_455(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        g.sort_unstable();
        s.sort_unstable();
        let (mut i, mut j) = (0, 0);
        while i < g.len() && j < s.len() {
            if g[i] <= s[j] {
                i += 1;
            }
            j += 1;
        }
        return i as i32;
    }

    pub fn array_pair_sum_501(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut res = 0;
        let mut idx = nums.len() as i32 - 1;
        while idx > 0 {
            res += nums[idx as usize].min(nums[idx as usize - 1]);
            idx -= 2;
        }
        return res;
    }

    pub fn can_place_flowers_605(mut flowerbed: Vec<i32>, mut n: i32) -> bool {
        for i in 0..flowerbed.len() {
            let left = (i == 0) || (flowerbed[i - 1] == 0);
            let right = (i == flowerbed.len() - 1) || (flowerbed[i + 1] == 0);
            if left && right && flowerbed[i] == 0 {
                flowerbed[i] = 1;
                n -= 1;
            }
        }
        return n <= 0;
    }

    pub fn lemonade_change_860(bills: Vec<i32>) -> bool {
        if bills[0] != 5 {
            return false;
        }

        let (mut five, mut ten) = (0, 0);
        for b in bills.iter() {
            match *b {
                5 => five += 1,
                10 => {
                    if five == 0 {
                        return false;
                    }
                    five -= 1;
                    ten += 1;
                }
                20 => {
                    if five != 0 && ten != 0 {
                        five -= 1;
                        ten -= 1;
                    } else if five >= 3 {
                        five -= 3;
                    } else {
                        return false;
                    }
                }
                _ => (),
            }
        }
        return true;
    }

    pub fn largest_perimeter_976(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut i = nums.len() - 1;
        while i >= 2 {
            if nums[i] < nums[i - 1] + nums[i - 2] {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
            i -= 1;
        }
        return 0;
    }

    pub fn largest_sum_after_k_negations_1005(mut nums: Vec<i32>, mut k: i32) -> i32 {
        nums.sort_unstable_by_key(|&k| k.abs());
        nums.into_iter().enumerate().rev().fold(0, |acc, (i, num)| {
            match (k == 0, i > 0, num.is_negative()) {
                (true, _, _) | (false, true, false) => acc + num,
                (false, true, true) => {
                    k -= 1;
                    acc - num
                }
                (false, false, _) => acc + if k & 1 == 1 { -num } else { num },
            }
        })
    }
}
