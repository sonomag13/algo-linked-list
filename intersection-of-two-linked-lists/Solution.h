// LeetCode 160. Intersection of Two Linked Lists
// Easy

#include <queue>
#include <vector>

using namespace std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        set<ListNode *> setNode; 
        
        ListNode * l1 = headA; 
        
        while (l1) {
            setNode.insert(l1); 
            l1 = l1->next; 
        }
        
        ListNode * l2 = headB;
        while (l2) {
            if (setNode.find(l2) != setNode.end()) {
                return l2; 
            }
            l2 = l2->next; 
        }
        
        return nullptr; 
        
    }
};