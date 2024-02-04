// Definition for singly-linked list.

#include <iostream>
#include <unordered_set>

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> setNode; 
        ListNode * cur = head; 
        while (cur != nullptr) {
            if (setNode.find(cur) != setNode.end()) {
                return true; 
            }
            setNode.insert(cur); 
            cur = cur->next; 
        }

        return false; 
    }
};