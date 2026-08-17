class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        stack<TreeNode*> s1, s2;
        vector<int> ans;

        while (root1 || root2 || !s1.empty() || !s2.empty()) {

            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }

            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                TreeNode* node = s1.top();
                s1.pop();

                ans.push_back(node->val);
                root1 = node->right;
            }
            else {
                TreeNode* node = s2.top();
                s2.pop();

                ans.push_back(node->val);
                root2 = node->right;
            }
        }

        return ans;
    }
};