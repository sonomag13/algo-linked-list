/* 
    445. Add Two Numbers II
    Medium

    You are given two non-empty linked lists representing two non-negative integers. 
    The most significant digit comes first and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:

    Input: l1 = [7,2,4,3], l2 = [5,6,4]
    Output: [7,8,0,7]
    Example 2:

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [8,0,7]
    Example 3:

    Input: l1 = [0], l2 = [0]
    Output: [0]

*/

#include <iostream>
#include <stack>

using namespace std; 

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head{nullptr}; 
        
        stack<int> st1; 
        stack<int> st2; 
        
        buildStack(l1, st1); 
        buildStack(l2, st2); 
        
        int carry{0}; 
        
        while (!st1.empty() || !st2.empty() || carry) {
            int sum{carry};
            
            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            
            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }
            
            carry = sum / 10;
            
            auto currNode = new ListNode(sum%10);
            currNode->next = head; 
            head = currNode;             
        }        
        return head;         
    }
    
private:
    
    void buildStack(ListNode* root, stack<int>& st) {        
        ListNode* currNode = root;         
        while (currNode) {            
            st.push(currNode->val);            
            currNode = currNode->next;
        }
    }
    
};