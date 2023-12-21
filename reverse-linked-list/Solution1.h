#pragma once

#include "ListNode.h"

class Solution1 {
public:
    Solution1() = default;
    ~Solution1() = default;

    ListNode * reverse(ListNode * head) {
        
        if (!head) {
            return nullptr;
        }
        
        _reverse_by_recursion(head);
        return this->newHead; 
    }
    
private:
    ListNode * newHead{nullptr};
    
    // reverse the list recursively
    ListNode* _reverse_by_recursion(ListNode* curNode) {
        // base case
        if (curNode->next == NULL) {
            this->newHead = curNode;
            return newHead;
        }

        // calculate the previous node
        ListNode* preNode = _reverse_by_recursion(curNode->next);

        preNode->next = curNode;
        curNode->next = nullptr;
        return curNode;
    }

};