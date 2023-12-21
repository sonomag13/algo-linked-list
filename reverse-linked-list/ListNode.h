#pragma once

#include <iostream>

class ListNode {
public:
    int val;
    ListNode * next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};