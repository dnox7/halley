use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

#[allow(dead_code)]
impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

#[allow(dead_code)]
pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn inorder_traversal_94(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, res: &mut Vec<i32>) {
            if let Some(n) = node {
                dfs(n.borrow().left.clone(), res);
                res.push(n.borrow().val);
                dfs(n.borrow().right.clone(), res);
            }
        }
        let mut res = vec![];
        dfs(root, &mut res);
        return res;
    }

    pub fn is_symmetric_101(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        type Node = Option<Rc<RefCell<TreeNode>>>;
        fn check(left: &Node, right: &Node) -> bool {
            match (left, right) {
                (Some(left), Some(right)) => {
                    left.borrow().val == right.borrow().val
                        && check(&left.borrow().left, &right.borrow().right)
                        && check(&left.borrow().right, &right.borrow().left)
                }
                (None, None) => true,
                (_, _) => false,
            }
        }
        check(&root, &root)
    }

    pub fn max_depth_104(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(node) => {
                std::cmp::max(
                    Self::max_depth_104(node.borrow().left.clone()),
                    Self::max_depth_104(node.borrow().right.clone()),
                ) + 1
            }
            None => 0,
        }
    }

    pub fn sorted_array_to_bst_108(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if nums.is_empty() {
            return None;
        }

        fn build_bst(nums: &[i32], left: usize, right: usize) -> Option<Rc<RefCell<TreeNode>>> {
            if left > right {
                return None;
            }

            let mid = left + (right - left) / 2;
            let right_child = build_bst(nums, mid + 1, right);
            let left_child = if mid > 0 {
                build_bst(nums, left, mid - 1)
            } else {
                None
            };

            Some(Rc::new(RefCell::new(TreeNode {
                val: nums[mid],
                left: left_child,
                right: right_child,
            })))
        }
        build_bst(&nums, 0, nums.len() - 1)
    }

    pub fn is_balanced_110(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn check_height(node: Option<Rc<RefCell<TreeNode>>>) -> i8 {
            match node {
                None => 0,
                Some(node) => {
                    let left = check_height(node.borrow().left.clone());
                    let right = check_height(node.borrow().right.clone());

                    if left == -1 || right == -1 || left.abs_diff(right) > 1 {
                        return -1;
                    }
                    return left.max(right) + 1;
                }
            }
        }
        return check_height(root) != -1;
    }

    pub fn min_depth_111(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                let left = Self::min_depth_111(node.borrow().left.clone());
                let right = Self::min_depth_111(node.borrow().right.clone());
                if left == 0 || right == 0 {
                    left + right + 1
                } else {
                    left.min(right) + 1
                }
            }
        }
    }

    pub fn has_path_sum_112(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        if let Some(root) = root {
            let val = target_sum - root.borrow().val;
            let left = root.borrow().left.clone();
            let right = root.borrow().right.clone();
            return (left.is_none() && right.is_none() && val == 0)
                || Self::has_path_sum_112(left, val)
                || Self::has_path_sum_112(right, val);
        }
        return false;
    }

    pub fn preorder_traversal_144(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        match root {
            None => vec![],
            Some(root) => {
                let mut res = vec![root.borrow().val];
                res.extend(Self::preorder_traversal_144(root.borrow().left.clone()));
                res.extend(Self::preorder_traversal_144(root.borrow().right.clone()));
                return res;
            }
        }
    }

    pub fn count_nodes_222(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => 0,
            Some(root) => {
                Self::count_nodes_222(root.borrow().left.clone())
                    + Self::count_nodes_222(root.borrow().right.clone())
                    + 1
            }
        }
    }

    pub fn invert_tree_226(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(root) => {
                let left = root.borrow().left.clone();
                let right = root.borrow().right.clone();

                root.borrow_mut().left = right.clone();
                root.borrow_mut().right = left.clone();
                Self::invert_tree_226(left);
                Self::invert_tree_226(right);
                Some(root)
            }
        }
    }

    pub fn binary_tree_paths_257(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        type Node = Option<Rc<RefCell<TreeNode>>>;
        fn build_path(root: Node, path: String, res: &mut Vec<String>) {
            match root {
                None => return,
                Some(root) => {
                    let left = root.borrow().left.clone();
                    let right = root.borrow().right.clone();
                    let val = root.borrow().val;

                    if left.is_none() && right.is_none() {
                        res.push(format!("{}{}", path, val));
                        return;
                    }

                    build_path(left, format!("{}{}{}", path, val, "->"), res);
                    build_path(right, format!("{}{}{}", path, val, "->"), res);
                }
            }
        }

        let mut res = vec![];
        if root.is_some() {
            build_path(root, String::new(), &mut res)
        };
        return res;
    }

    pub fn sum_of_left_leaves_404(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = 0;
        fn calc_sum(root: Option<Rc<RefCell<TreeNode>>>, res: &mut i32, is_right_node: bool) {
            match root {
                None => return,
                Some(root) => {
                    let left = root.borrow().left.clone();
                    let right = root.borrow().right.clone();
                    if left.is_none() && right.is_none() && !is_right_node {
                        println!("{}", root.borrow().val);
                        *res += root.borrow().val;
                        return;
                    }

                    calc_sum(left, res, false);
                    calc_sum(right, res, true);
                }
            }
        }

        calc_sum(root, &mut res, true);
        return res;
    }

    pub fn find_mode_501(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn handle_data(
            prev: &mut i32,
            curr_freq: &mut i32,
            max_freq: &mut i32,
            res: &mut Vec<i32>,
        ) {
            if *curr_freq >= *max_freq {
                if *curr_freq != *max_freq {
                    *max_freq = *curr_freq;
                    res.clear();
                }
                if res.last().is_some_and(|x| *x != *prev) || res.is_empty() {
                    res.push(*prev);
                }
            }
        }

        fn dfs(
            root: Option<Rc<RefCell<TreeNode>>>,
            prev: &mut i32,
            curr_freq: &mut i32,
            max_freq: &mut i32,
            res: &mut Vec<i32>,
        ) {
            match root {
                None => handle_data(prev, curr_freq, max_freq, res),
                Some(root) => {
                    dfs(root.borrow().left.clone(), prev, curr_freq, max_freq, res);

                    let curr_val = root.borrow().val;
                    if *prev != curr_val {
                        handle_data(prev, curr_freq, max_freq, res);
                        *prev = curr_val;
                        *curr_freq = 1;
                    } else {
                        *curr_freq += 1;
                    }

                    dfs(root.borrow().right.clone(), prev, curr_freq, max_freq, res);
                }
            }
        }

        match root {
            None => vec![],
            Some(root) => {
                let mut prev = root.borrow().val;
                let mut res = vec![];
                dfs(Some(root), &mut prev, &mut 0, &mut 1, &mut res);
                return res;
            }
        }
    }

    pub fn get_minimum_difference_530(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, prev: &mut i32, res: &mut u32) {
            match root {
                None => return,
                Some(root) => {
                    dfs(root.borrow().left.clone(), prev, res);
                    let curr_val = root.borrow().val;
                    *res = curr_val.abs_diff(*prev).min(*res);
                    *prev = curr_val;
                    dfs(root.borrow().right.clone(), prev, res);
                }
            }
        }

        let mut res = u32::MAX;
        let mut prev = i32::MAX;
        dfs(root, &mut prev, &mut res);
        return res as i32;
    }

    pub fn diameter_of_binary_tree_543(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn find_max_dist(root: Option<Rc<RefCell<TreeNode>>>, res: &mut i32) -> i32 {
            match root {
                None => 0,
                Some(node) => {
                    let left = find_max_dist(node.borrow().left.clone(), res);
                    let right = find_max_dist(node.borrow().right.clone(), res);
                    *res = (left + right).max(*res);
                    return left.max(right) + 1;
                }
            }
        }
        let mut res = 0;
        find_max_dist(root, &mut res);
        return res;
    }

    pub fn find_tilt_563(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, sum_titl: &mut i32) -> i32 {
            match root {
                None => 0,
                Some(root) => {
                    let left = dfs(root.borrow().left.clone(), sum_titl);
                    let right = dfs(root.borrow().right.clone(), sum_titl);
                    *sum_titl += left.abs_diff(right) as i32;
                    return left + right + root.borrow().val;
                }
            }
        }

        let mut res = 0;
        dfs(root, &mut res);
        return res;
    }

    pub fn is_subtree_572(
        root: Option<Rc<RefCell<TreeNode>>>,
        sub_root: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        type Node = Option<Rc<RefCell<TreeNode>>>;
        fn is_same(root: Node, sub_root: Node) -> bool {
            match (root, sub_root) {
                (None, None) => true,
                (Some(root), Some(sub_root)) => {
                    if root.borrow().val != sub_root.borrow().val {
                        return false;
                    }
                    is_same(root.borrow().left.clone(), sub_root.borrow().left.clone())
                        && is_same(root.borrow().right.clone(), sub_root.borrow().right.clone())
                }
                (_, _) => false,
            }
        }

        fn solve(root: Node, sub_root: Node) -> bool {
            match root {
                None => false,
                Some(root) => {
                    is_same(Some(root.clone()), sub_root.clone())
                        || solve(root.borrow().left.clone(), sub_root.clone())
                        || solve(root.borrow().right.clone(), sub_root.clone())
                }
            }
        }

        solve(root, sub_root)
    }

    pub fn merge_trees_617(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match (root1, root2) {
            (None, None) => None,
            (Some(root1), None) => Some(root1),
            (None, Some(root2)) => Some(root2),
            (Some(root1), Some(root2)) => {
                {
                    let mut root1_mut = root1.borrow_mut();
                    root1_mut.val += root2.borrow().val;
                    root1_mut.left =
                        Self::merge_trees_617(root1_mut.left.take(), root2.borrow().left.clone());
                    root1_mut.right =
                        Self::merge_trees_617(root1_mut.right.take(), root2.borrow().right.clone());
                }
                Some(root1)
            }
        }
    }

    pub fn average_of_levels_637(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        type Node = Option<Rc<RefCell<TreeNode>>>;
        let mut queue: Vec<Node> = vec![root.clone()];
        let mut res: Vec<f64> = vec![];
        let mut curr_sum = 0;

        while !queue.is_empty() {
            let queue_len = queue.len();
            (0..queue_len).for_each(|_| {
                let node = queue.remove(0).unwrap();
                curr_sum += node.borrow().val as i64;

                if node.borrow().left.is_some() {
                    queue.push(node.borrow().left.clone());
                }

                if node.borrow().right.is_some() {
                    queue.push(node.borrow().right.clone());
                }
            });
            res.push(curr_sum as f64 / queue_len as f64);
            curr_sum = 0;
        }
        return res;
    }

    pub fn find_target_653_1(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, inorder: &mut Vec<i32>) {
            match root {
                None => {}
                Some(root) => {
                    dfs(root.borrow().left.clone(), inorder);
                    inorder.push(root.borrow().val);
                    dfs(root.borrow().right.clone(), inorder);
                }
            }
        }

        let mut arr = vec![];
        dfs(root, &mut arr);

        let mut left = 0;
        let mut right = arr.len() - 1;
        let mut total;

        while left < right {
            total = arr[left] + arr[right];
            if total == k {
                return true;
            } else if total > k {
                right -= 1;
            } else {
                left += 1;
            }
        }
        return false;
    }

    pub fn find_target_653_2(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        use std::collections::HashSet;
        use std::collections::VecDeque;

        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        queue.push_back(root);

        while let Some(node) = queue.pop_front() {
            if let Some(node_ref) = node {
                if visited.contains(&(k - node_ref.borrow().val)) {
                    return true;
                }

                visited.insert(node_ref.borrow().val);
                queue.push_back(node_ref.borrow().left.clone());
                queue.push_back(node_ref.borrow().right.clone());
            }
        }
        return false;
    }

    pub fn find_second_minimum_value_671(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn solve(node: Option<Rc<RefCell<TreeNode>>>, root_val: i32, res: &mut i64) {
            match node {
                None => {}
                Some(node) => {
                    if node.borrow().val != root_val {
                        *res = (*res).min(node.borrow().val as i64);
                        return;
                    }

                    solve(node.borrow().left.clone(), root_val, res);
                    solve(node.borrow().right.clone(), root_val, res);
                }
            }
        }

        let mut res = i64::MAX;
        solve(root.clone(), root.unwrap().borrow().val, &mut res);
        if res != i64::MAX {
            return res as i32;
        }
        return -1;
    }

    pub fn search_bst_700(
        root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(root) => {
                let curr = root.borrow().val;
                if curr == val {
                    return Some(root);
                }

                if curr > val {
                    return Self::search_bst_700(root.borrow().left.clone(), val);
                }
                return Self::search_bst_700(root.borrow().right.clone(), val);
            }
        }
    }

    pub fn min_diff_in_bst_783(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, prev: &mut i32, res: &mut u32) {
            match root {
                None => return,
                Some(root) => {
                    dfs(root.borrow().left.clone(), prev, res);
                    let curr_val = root.borrow().val;
                    *res = curr_val.abs_diff(*prev).min(*res);
                    *prev = curr_val;
                    dfs(root.borrow().right.clone(), prev, res);
                }
            }
        }

        let mut res = u32::MAX;
        let mut prev = i32::MAX;
        dfs(root, &mut prev, &mut res);
        return res as i32;
    }

    pub fn leaf_similar_872(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        fn find_leaf_val_seq(root: Option<Rc<RefCell<TreeNode>>>, seq: &mut Vec<i32>) {
            match root {
                None => {}
                Some(root) => {
                    let left = root.borrow().left.clone();
                    let right = root.borrow().right.clone();

                    if left.is_none() && right.is_none() {
                        seq.push(root.borrow().val);
                        return;
                    }

                    find_leaf_val_seq(left, seq);
                    find_leaf_val_seq(right, seq);
                }
            }
        }

        let mut seq1 = vec![];
        let mut seq2 = vec![];
        find_leaf_val_seq(root1, &mut seq1);
        find_leaf_val_seq(root2, &mut seq2);
        seq1 == seq2
    }

    pub fn range_sum_bst_938(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        fn inorder(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32, res: &mut i32) {
            match root {
                None => (),
                Some(root) => {
                    inorder(root.borrow().left.clone(), low, high, res);
                    let curr_val = root.borrow().val;
                    if curr_val > high {
                        return;
                    }

                    if curr_val >= low && curr_val <= high {
                        *res += curr_val;
                    }
                    inorder(root.borrow().right.clone(), low, high, res);
                }
            }
        }

        let mut res = 0;
        inorder(root, low, high, &mut res);
        return res;
    }

    pub fn is_unival_tree_965(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn check(node: Option<Rc<RefCell<TreeNode>>>, mut root_val: i32, is_root: bool) -> bool {
            match node {
                None => true,
                Some(node) => {
                    if is_root {
                        root_val = node.borrow().val;
                    }

                    if node.borrow().val != root_val {
                        return false;
                    }
                    check(node.borrow().left.clone(), root_val, false)
                        && check(node.borrow().right.clone(), root_val, false)
                }
            }
        }
        check(root, 0, true)
    }

    pub fn is_cousins_993(root: Option<Rc<RefCell<TreeNode>>>, x: i32, y: i32) -> bool {
        let mut found_x: bool;
        let mut found_y: bool;
        let mut queue = vec![root];

        while !queue.is_empty() {
            let queue_len = queue.len();
            found_x = false;
            found_y = false;

            for _ in 0..queue_len {
                let curr = queue.remove(0).unwrap();
                let left = curr.borrow().left.clone();
                let right = curr.borrow().right.clone();

                if curr.borrow().val == x {
                    found_x = true;
                }
                if curr.borrow().val == y {
                    found_y = true;
                }

                if left.is_some() && right.is_some() {
                    let left_val = left.as_ref().unwrap().borrow().val;
                    let right_val = right.as_ref().unwrap().borrow().val;

                    if (left_val == x && right_val == y) || (left_val == y && right_val == x) {
                        return false;
                    }
                }

                if left.is_some() {
                    queue.push(left);
                }

                if right.is_some() {
                    queue.push(right);
                }
            }

            if found_x && found_y {
                return true;
            }
        }
        return false;
    }

    pub fn sum_root_to_leaf_1022(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn solve(root: Option<Rc<RefCell<TreeNode>>>, path: &String, res: &mut i32) {
            match root {
                None => (),
                Some(root) => {
                    let curr_val = root.borrow().val;
                    let left = root.borrow().left.clone();
                    let right = root.borrow().right.clone();

                    let new_path = format!("{}{}", path, curr_val);
                    if left.is_none() && right.is_none() {
                        *res += i32::from_str_radix(&new_path, 2).unwrap();
                    }

                    solve(left, &new_path, res);
                    solve(right, &new_path, res);
                }
            }
        }

        let mut res = 0;
        solve(root, &String::new(), &mut res);
        return res;
    }

    pub fn increasing_bst_897(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        type Node = Option<Rc<RefCell<TreeNode>>>;
        fn rearrange(root: Node, tail: Node) -> Node {
            match root {
                None => tail,
                Some(root_rc) => {
                    let res = rearrange(root_rc.borrow().left.clone(), Some(root_rc.clone()));
                    root_rc.borrow_mut().left = None;
                    let right_rearranged = rearrange(root_rc.borrow().right.clone(), tail);
                    root_rc.borrow_mut().right = right_rearranged;
                    return res;
                }
            }
        }
        rearrange(root, None)
    }

    pub fn check_tree_2236(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let root_rc = root.unwrap();
        let left_rc = root_rc.borrow().left.clone().unwrap();
        let right_rc = root_rc.borrow().right.clone().unwrap();

        let root_val = root_rc.borrow().val;
        let left_val = left_rc.borrow().val;
        let right_val = right_rc.borrow().val;

        root_val == left_val + right_val
    }

    pub fn evaluate_tree_2331(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            Some(root_rc) => {
                let root_val = root_rc.borrow().val;
                let left = root_rc.borrow().left.clone();
                let right = root_rc.borrow().right.clone();

                if left.is_none() && right.is_none() {
                    return root_val != 0;
                }

                let left_val = Self::evaluate_tree_2331(left);
                let right_val = Self::evaluate_tree_2331(right);
                if root_val == 2 {
                    return left_val || right_val;
                }
                left_val && right_val
            }
        }
    }
}

#[allow(dead_code, non_camel_case_types)]
struct KthLargest_703 {
    min_heap: std::collections::BinaryHeap<std::cmp::Reverse<i32>>,
    limit: usize,
}

#[allow(dead_code)]
impl KthLargest_703 {
    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut kl = KthLargest_703 {
            min_heap: std::collections::BinaryHeap::new(),
            limit: k as usize,
        };

        for n in nums {
            kl.add(n);
        }
        return kl;
    }

    fn add(&mut self, val: i32) -> i32 {
        if self.min_heap.len() < self.limit {
            self.min_heap.push(std::cmp::Reverse(val));
        } else if val > self.min_heap.peek().unwrap().0 {
            self.min_heap.pop();
            self.min_heap.push(std::cmp::Reverse(val));
        }
        self.min_heap.peek().map_or(0, |&std::cmp::Reverse(x)| x)
    }
}
