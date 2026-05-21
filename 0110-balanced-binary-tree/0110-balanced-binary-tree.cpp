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
    int traverse(TreeNode* root){
        if(root == NULL) return 0;

        int left = traverse(root->left);
        int right = traverse(root->right);

        if(left == -1) return -1;
        if(right == -1) return -1;
        if(abs(left-right) > 1) return -1;

        return 1 + max(left,right);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        if(traverse(root) == -1) return false;

        return true;
    }
};