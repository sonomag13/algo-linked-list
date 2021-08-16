/*
    92. Reverse Linked List II
    Medium

    Given the head of a singly linked list and two integers left and right where left <= right, 
    reverse the nodes of the list from position left to position right, and return the reversed list.
 */

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {                
        
        if (!head || left == right) {
            return head;
        }
        
        // pad a dummy head in front of the real head in case the 
        // real head is the left node
        auto dummyHead = new ListNode(0);        
        bool flagDummyTail{false}; 
        dummyHead->next = head; 
        left++;
        right++;
                
        ListNode* leftNeighbor{nullptr};      // node before left
        ListNode* rightNeighbor{nullptr};     // node after right
        
        // traverse the list to search for left and right
        ListNode* curNode{dummyHead}; 
        
        int cnt{1}; 
        
        while(curNode) {            
            if (cnt + 1 == left) {              
                // find the node of left value and the node in front of it            
                leftNeighbor = curNode; 
                head2 = curNode->next;
            }            
            // find the node of right value and the node behind it
            if (cnt == right) {   
                // tail of the sublist if found, and break its link to 
                // the rest of the list                
                rightNeighbor = curNode->next;                
                curNode->next = nullptr; 
                break; 
            }
            cnt++;
            curNode = curNode->next; 
        }
                
        leftNeighbor->next = nullptr;
        
        // at this point, the section between left ~ right is isolated
        // left = head2 and let us reverse the sub-list        
        tail2 = reverseList(head2);
        
        // pice the sublist back to the full list
        leftNeighbor->next = head2;        
        tail2->next = rightNeighbor;
        
        return dummyHead->next; 
        
    }
    
private:
    ListNode* head2{nullptr};
    ListNode* tail2{nullptr}; 
    
    ListNode* reverseList(ListNode* curNode) {
        // this is a typical linked list reverse by 
        if (!curNode->next) {
            // base case
            head2 = curNode; 
            return head2; 
        }
        
        ListNode* preNode = reverseList(curNode->next);
        
        preNode->next = curNode;
        curNode->next = nullptr; 
        
        return curNode; 
        
    }
    
};