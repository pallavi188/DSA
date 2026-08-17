/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || root->left == NULL)return root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        Node* prev = NULL;
        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            if(currNode == NULL){
                if(q.size() == 0)break;
                q.push(NULL);
            }else{
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);

                if(prev != NULL)prev->next = currNode;
            }
            prev = currNode;
        }
        return root;
    }
};