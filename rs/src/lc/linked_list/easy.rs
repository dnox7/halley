#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    val: i32,
    next: Option<Box<ListNode>>,
}

#[allow(dead_code)]
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[allow(dead_code)]
pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn merge_two_lists_21(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut r = &mut list1;
        while list2.is_some() {
            if r.is_none() || list2.as_ref()?.val < r.as_ref()?.val {
                std::mem::swap(r, &mut list2);
            }
            r = &mut r.as_mut()?.next;
        }
        return list1;
    }

    pub fn delete_duplicates_83(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut curr = &mut head;
        while let Some(node) = curr {
            while let Some(next) = &mut node.next {
                if node.val == next.val {
                    node.next = next.next.take()
                } else {
                    break;
                }
            }
            curr = &mut node.next;
        }
        head
    }

    pub fn has_cycle_141(head: Option<Box<ListNode>>) -> bool {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return false;
        }

        let (mut fast, mut slow) = (head.as_ref(), head.as_ref());
        while let (Some(node1), Some(node2)) = (fast, slow) {
            if node2.next.is_none() {
                return false;
            }

            slow = node1.next.as_ref();
            fast = node1.next.as_ref().unwrap().next.as_ref();
            if slow == fast {
                return true;
            }
        }
        return false;
    }

    pub fn remove_elements_203(mut head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut dummy = None;
        let mut tail = &mut dummy;

        while let Some(mut node) = head.take() {
            head = node.next.take();
            if node.val != val {
                tail = &mut tail.insert(node).next;
            }
        }
        return dummy;
    }

    pub fn reverse_list_206(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.as_ref()?.next.is_none() {
            return head;
        }

        let next = head.as_mut().unwrap().next.take();
        let mut new_head = Self::reverse_list_206(next);
        let mut tail = new_head.as_mut().unwrap();

        while tail.next.is_some() {
            tail = tail.next.as_mut().unwrap();
        }
        tail.next = head;
        return new_head;
    }

    pub fn is_palindrome_234(head: Option<Box<ListNode>>) -> bool {
        let (mut fast, mut slow) = (&head, &head);
        while let (Some(f), Some(s)) = (fast, slow) {
            if f.next.is_none() {
                break;
            }
            slow = &s.next;
            fast = &f.next.as_ref().unwrap().next;
        }

        return false;
    }

    pub fn middle_node_876(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut slow, mut fast) = (head.as_ref(), head.as_ref());
        while let Some(fnode) = fast {
            if fnode.next.is_none() {
                break;
            }
            slow = slow?.next.as_ref();
            fast = fnode.next.as_ref()?.next.as_ref();
        }
        return slow.cloned();
    }

    pub fn get_decimal_value_1290(head: Option<Box<ListNode>>) -> i32 {
        let mut res = 0;
        let mut curr = &head;
        while let Some(c) = curr {
            res <<= 1;
            res |= c.val;
            curr = &c.next;
        }
        return res;
    }
}
