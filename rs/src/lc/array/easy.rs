#[allow(dead_code)]
pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn minimum_pair_removal_3507(mut nums: Vec<i32>) -> i32 {
        let mut res = 0;
        while !nums.is_sorted() {
            let mut curr = 0;
            let mut min_sum = i32::MAX;
            for i in 0..nums.len() - 1 {
                if nums[i] + nums[i + 1] < min_sum {
                    curr = i;
                    min_sum = nums[i] + nums[i + 1];
                }
            }

            let mut new_nums = vec![];
            for i in 0..curr {
                new_nums.push(nums[i]);
            }
            new_nums.push(min_sum);
            for i in curr + 2..nums.len() {
                new_nums.push(nums[i]);
            }
            res += 1;
            nums = new_nums;
        }
        return res;
    }
}

#[allow(dead_code)]
struct MyHashSet705 {
    arr: Vec<Vec<i32>>,
}

#[allow(dead_code)]
impl MyHashSet705 {
    fn new() -> Self {
        Self {
            arr: (0..1 << 15).fold(vec![], |mut acc, _| {
                acc.push(vec![]);
                return acc;
            }),
        }
    }

    fn add(&mut self, key: i32) {
        let k = self.eval_hash(key) as usize;
        if !self.arr[k].contains(&key) {
            self.arr[k].push(key);
        }
    }

    fn remove(&mut self, key: i32) {
        let k = self.eval_hash(key) as usize;
        let mut flag = false;
        let mut idx = 0;
        for i in 0..self.arr[k].len() {
            if self.arr[k][i] == key {
                idx = i;
                flag = true;
                break;
            }
        }
        if flag {
            self.arr[k].remove(idx);
        }
    }

    fn contains(&mut self, key: i32) -> bool {
        let k = self.eval_hash(key);
        return self.arr[k as usize].contains(&key);
    }

    fn eval_hash(&self, key: i32) -> i32 {
        return ((key * 1031237) & (1 << 20) - 1) >> 5;
    }
}
