// https://leetcode.com/problems/two-sum/description/

// https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ans = Vec::new();
        // let mut i = 0;
        let mut j = nums.len() - 1;
        let n = nums.len();
        for i in 0..n-1 {
            for j in i+1..n {
                if nums[i]+nums[j] == target {
                    ans.push(i as i32);
                    ans.push(j as i32);
                    break;
                }
            }
        }
        ans
    }
}