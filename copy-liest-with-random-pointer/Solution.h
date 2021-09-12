// LeetCode 138. Copy List with Random Pointer
// Medium

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (!head) {
            return head; 
        }
        
        Node* curr = head; 
        
        unordered_map<Node*, Node*> mapOldNewNode; 
        
        while (curr) {
            
            if (mapOldNewNode.find(curr) == mapOldNewNode.end()) {
                mapOldNewNode.insert(make_pair(curr, new Node(curr->val)));
            }
            
            if (curr->next) {
                // handle the next node
                if(mapOldNewNode.find(curr->next) == mapOldNewNode.end()) {
                   mapOldNewNode.insert(make_pair(curr->next, new Node(curr->next->val))); 
                }
                mapOldNewNode[curr]->next = mapOldNewNode[curr->next];
            }
            
            if (curr->random) {
                // hanld the random node
                if(mapOldNewNode.find(curr->random) == mapOldNewNode.end()) {
                    mapOldNewNode.insert(make_pair(curr->random, new Node(curr->random->val)));
                }
                mapOldNewNode[curr]->random = mapOldNewNode[curr->random]; 
            }
            
            curr = curr->next; 
        }        
        
        return mapOldNewNode[head]; 
        
    }
};