// LeetCode 143. Reorder List
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
    void reorderList(ListNode* head) {
        
        if (!head || !head->next) {
            // base case null head or single node list
            return; 
        }
        
        ListNode * slow = head;
        ListNode * fast = head->next; 
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * mid = slow->next; // head2 is the head of the second half of the list
        
        slow->next = nullptr;  // break the first and second half into two lists                
        
        reverseList(mid);
        
        ListNode * l1 = head;
        ListNode * l2 = head2; 
        
        while (l1 && l2) {
            
            ListNode * node2 = l2; 
            l2 = l2->next; 
            
            ListNode * next1 = l1->next;             
            l1->next = node2; 
            l1 = l1->next; 
            l1->next = next1; 
            l1 = l1->next; 
                
        }
        
        if (l2) {
            l1->next = l2; 
        }
        
    }
    
private:
    
    ListNode * head2; 
    
    ListNode * reverseList(ListNode* curr) {
        
        if (!curr->next) {
            head2 = curr; 
            return curr; 
        }
        
        ListNode * pre = reverseList(curr->next);         
        pre->next = curr;         
        curr->next = nullptr;
        
        return curr; 
        
    }
};