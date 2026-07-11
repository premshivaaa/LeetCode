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
    void traverse(TreeNode* root, map<int,int>& mp){
        if(root == NULL) return;

        traverse(root->left, mp);
        mp[root->val]++;
        traverse(root->right, mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> mp;
        traverse(root, mp);
        vector<int> ans;
        int maxi = 0;

        for(auto it : mp){
            if(it.second > maxi) maxi = it.second;
        }
        for(auto it : mp){
            if(mp[it.first] == maxi) ans.push_back(it.first);
        }

        return ans;
    }
};