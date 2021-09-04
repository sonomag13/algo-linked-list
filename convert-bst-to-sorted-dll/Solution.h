// LeetCode 426. Convert Binary Search Tree to Sorted Doubly Linked List
// Medium

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        
        if (!root) {
            return nullptr; 
        }
        
        inorder(root);
        
        head->left = tail;
        tail->right = head;
        
        return head;         
        
    }
    
private: 
    
    Node* head;  // is fixed for the entire runtime
    Node* tail;  // keep changing that points to the last node of the list that we have already established
    
    void inorder(Node* currNode) {
        
        if (!currNode) {
            return;
        }
        
        inorder(currNode->left);
        
        // two cases:
        // - at the head
        // - at a mid node
        if (!head) {
            /**
             * DFS: at the left most node, we will check if head is null for 
             * the FIRST time. 
             * Natually, this node turns to be the head of the list
             **/ 
            head = currNode;             
        }
        else {
            tail->right = currNode;
            currNode->left = tail;
        }
        
        // the tail points to the current node
        tail = currNode;
        
        inorder(currNode->right);
        
    }
        
};