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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        // Base case: if the start index crosses the end index, the subarray is empty
        if (start > end) {
            return nullptr;
        }

        // Find the middle element to ensure the tree remains balanced
        int mid = start + (end - start) / 2;
        
        // Create the root node with the middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }
    void traverse(TreeNode* root, vector<int>& inOrder){
        if(root == NULL) return;

        traverse(root->left, inOrder);
        inOrder.push_back(root->val);
        traverse(root->right, inOrder);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        traverse(root, inOrder);
        TreeNode* node = helper(inOrder, 0, inOrder.size()-1);
        return node;
    }
};