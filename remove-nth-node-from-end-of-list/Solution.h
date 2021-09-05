// LeetCode 19. Remove Nth Node From End of List
// Medium

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (!head || !head->next) {
            return nullptr; 
        }
        
        this->n = n;         
        
        newHead = _removeNode(head);
        
        return newHead; 
    }
    
private: 
    int n;
    int cnt = 1; 
    ListNode * newHead = new ListNode;
    
    ListNode* _removeNode(ListNode* curr) {
        
        if (!curr->next) {            
            if (this->cnt == this->n) {
                // base case: remove the last node
                // this->hasNotRemoved = true;
                return nullptr;     
            }            
            // base case: reached the last node but do not remove it
            return curr; 
        }
        
        ListNode* next = _removeNode(curr->next); 
        
        this->cnt++; 
        
        if (this->cnt == this->n) {
            // this->hasNotRemoved = true;
            return next; 
        }
        
        curr->next = next;         
        
        return curr; 
        
    }
    
    
};