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
    void traverse(TreeNode* root, TreeNode*& prev, int& result){
        if(root == NULL) return;

        traverse(root->left, prev, result);

        if(prev != NULL && abs(prev->val - root->val) < result){
            result = min(result, abs(prev->val - root->val));
        }
        prev = root;

        traverse(root->right, prev, result);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int result = INT_MAX;
        TreeNode* prev = NULL;

        traverse(root, prev, result);

        return result;
    }
};