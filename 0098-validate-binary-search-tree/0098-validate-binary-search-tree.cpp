/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool traverse(TreeNode* root, TreeNode*& prev){
        if(root == NULL) return true;

        bool left = traverse(root->left, prev);

        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        
        bool right = traverse(root->right, prev);

        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return traverse(root, prev);
    }
};