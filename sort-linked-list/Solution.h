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
    ListNode* sortList(ListNode* head) {
        
        return _sortList(head);
        
    }
    
private:
    
    ListNode* _sortList(ListNode * head) {
        
        if (!head || !head->next) {
            // base case: head is null or it is a list with single node
            return head; 
        }
        
        ListNode * slow{head};
        ListNode * fast{head->next};
        
        while (fast && fast->next) {
            // search for the mid node of the linked list
            slow = slow->next;
            fast = fast->next->next;
        }
        
        /**
         * mid the first node of the second half, while head is the 
         * first node of the first half. The last node points to null
         **/ 
        ListNode * mid{slow->next};
        
        slow->next = nullptr; // a list is broken into two parts
        
        return _mergeList(_sortList(head), _sortList(mid)); 
        
    }
    
    ListNode* _mergeList(ListNode * l1, ListNode * l2) {
        
        ListNode head(0); 
        ListNode* tail = &head; 
        
        while (l1 && l2) {            
            if (l1->val < l2->val) {
                // append a node form l1
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next; 
            }
            tail = tail->next;             
        }
        
        if (l1) {
            // l2 runs out first in the while loop above
            // notice that l1 is supposed ordered
            tail->next = l1;
        }
        
        if (l2) {
            // l1 runs out first in the while loop above
            // notice that l2 is supposed ordered
            tail->next = l2;
        }
        
        return head.next;
        
    }    
    
};