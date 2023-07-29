// 876. Middle of the Linked List
// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut middle = head.clone();
    let mut end = head.clone();

    while !end.is_none() && !end.as_ref().unwrap().next.is_none() {
        middle = middle.unwrap().next;
        end = end.unwrap().next.unwrap().next;
    }

    middle
}
