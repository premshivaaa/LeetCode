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
    void traverse(TreeNode* node, vector<int>& array){
        if(node == NULL) return;

        traverse(node->left, array);
        array.push_back(node->val);
        traverse(node->right, array);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list;
        traverse(root1, list);
        traverse(root2, list);
        sort(list.begin(), list.end());
        return list;
    }
};