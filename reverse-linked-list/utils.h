#pragma once

#include <iostream>
#include <vector>

#include "ListNode.h"

ListNode * createLinkedList(const std::vector<int> & vecIn) {

    auto head = new ListNode(vecIn.at(0));
    auto pre = head;

    for (size_t i = 1; i < vecIn.size(); ++i) {
        auto cur = new ListNode(vecIn.at(i));
        pre->next = cur;
        pre = cur;
    }

    return head;
}

void printLinkedList(ListNode * head) {
    size_t k{0};
    ListNode * cur = head;

    while (cur != nullptr) {
        std::cout << "node " << k << " = " << cur->val <<'\n';
        cur = cur->next;
        ++k;
    }
}