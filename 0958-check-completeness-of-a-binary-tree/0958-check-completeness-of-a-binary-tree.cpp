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
    int countNodes(TreeNode* node){
        if(node == NULL) return 0;

        int left = countNodes(node->left);
        int right = countNodes(node->right);

        return 1 + left + right;
    }
    bool checkComplete(TreeNode* root, int count, int idx){
        if(root == NULL) return true;

        if(idx >= count) return false;

        bool l = checkComplete(root->left, count, 2*idx + 1);
        bool r = checkComplete(root->right, count, 2*idx + 2);

        return l && r;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int count = countNodes(root);

        return checkComplete(root, count, 0);
    }
};