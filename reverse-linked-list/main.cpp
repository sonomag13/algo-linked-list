/*
    35. Reverse Linked List
    Reverse a linked list.

    Example
    Example 1:

    Input: 1->2->3->null
    Output: 3->2->1->null
    Example 2:

    Input: 1->2->3->4->null
    Output: 4->3->2->1->null
    Challenge
    Reverse it in-place and in one-pass
 */

#include <vector>

#include "utils.h"
#include "Solution1.h"
#include "Solution2.h"

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5};
    ListNode * head1 = createLinkedList(vec);
    printLinkedList(head1);

    Solution1 solution1;

    ListNode * head2 = solution1.reverse(head1);
    printLinkedList(head2);

    head1 = createLinkedList(vec);
    printLinkedList(head1);
    Solution2 solution2;
    ListNode * head3 = solution2.reverse(head1);
    printLinkedList(head3);

    return 0;
}