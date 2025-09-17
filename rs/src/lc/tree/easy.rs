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
}
