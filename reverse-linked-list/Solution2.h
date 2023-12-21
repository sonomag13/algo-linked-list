#pragma once

#include "ListNode.h"

class Solution2 {
public:

    Solution2() = default;
    ~Solution2() = default;

    ListNode * reverse(ListNode * head) {
        // write your code here        
        if (head == nullptr) {
            return head;
        }

        ListNode * prevNode{nullptr};
        ListNode * currentNode{head};
        ListNode * newHead{nullptr};

        while(currentNode != nullptr) {
            ListNode * nextNode{currentNode->next};
            if (nextNode == nullptr) {
                newHead = currentNode;
            }
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode; 
        }

        return newHead;
    }
};