// 25. Reverse Nodes in k-Group

#include <vector>

using namepsce std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr) {
            return head; 
        }

        oldHeads.push_back(head);  
        ListNode * cur = head; 

        int cnt = 1; 
        while (cur != nullptr) {
            // in this loop we divide the entire link into shorter sections; 
            // - except the last section, each section must contain k nodes
            // - the last section may contain less than k nodes
            
            cur = cur->next; 
            ++cnt; 
            
            if (cnt == k) {
                if (cur == nullptr) {
                    break; 
                }
                ListNode * nextHead = cur->next;
                if (nextHead == nullptr) {
                    // it just happens that the end of the list is also the end of the last section
                    // such that there is no node after the current node`
                    continue;  
                } 

                oldHeads.push_back(nextHead);  // the next node is the head of the next section
                ListNode * tail = cur;  // the current node is the tail of a section
                cur = cur->next;  // move to the next node
                tail->next = nullptr;  // the tail of the current setion points to nullptr
                cnt = 1;   // reset the counter
            }
        }

        // the last head may not a candidate since it may link nodes less than k
        ListNode * lastHead = oldHeads.back(); 
        cnt = 1; 
        while (lastHead) {
            lastHead = lastHead->next; 
            ++cnt; 
        }
        --cnt;  // cnt over-shoots by 1 when lasthead moves to nullptr
        bool flagReverseLastHead = cnt != k ? false : true;  // flag it to flip the last node 

        for (int i = 0; i < oldHeads.size() - 1; ++i) {
            reverseLinkedList(oldHeads[i]);
        }

        if (flagReverseLastHead) {
            // there are k elements in the last section, such that we need to reverse the section
            reverseLinkedList(oldHeads.back()); 
        }
        else {
            // there are less than k elements in the last section, keep the same
            newHeads.push_back(oldHeads.back());
        }

        for (int i = 0; i < newHeads.size() - 1; ++i) {
            
            ListNode * node = newHeads[i]; 
            ListNode * nextHead = newHeads[i + 1]; 

            while(node != nullptr) {
                if (node->next == nullptr) {
                    node->next = nextHead; 
                    break; 
                }
                node = node->next; 
            }
        }

        return newHeads[0]; 
    }

private: 
    vector<ListNode *> oldHeads; 
    vector<ListNode *> newHeads; 

    ListNode * reverseLinkedList(ListNode * node) {
        if (node->next == nullptr) {
            newHeads.push_back(node); 
            return node; 
        }
        
        ListNode * preNode = reverseLinkedList(node->next); 
        node->next=nullptr; 
        preNode->next = node; 
        
        return node; 
    }
    
};