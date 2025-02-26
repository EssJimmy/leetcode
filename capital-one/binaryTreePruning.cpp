#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root->val == 0 && left == nullptr && right == nullptr)
            return nullptr;

        pruneTree(root, root->left);
        pruneTree(root, root->right);
        return root;
    }

private:
    void pruneTree(TreeNode* parent, TreeNode* child){
        if(child->left)
            pruneTree(child, child->left);
        
        if(child->right)
            pruneTree(child, child->right);

        if(child->val == 0) {
            if(!child->left && !child->right)
                child = nullptr;
            
            if((child->left && !child->left->val) && (child->right && !child->right->val))
                child = nullptr;
        }
    }
};