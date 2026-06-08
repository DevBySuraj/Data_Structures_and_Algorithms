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
public:
    vector<int>ans;
    vector<int> inorder(TreeNode* root) {
        if (root == nullptr) return {};

        inorder(root->left);   // Left
        ans.push_back(root->val);
        inorder(root->right);  // Right
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        ans = inorder(root);
        for(int i =0; i<k; i++){
            if(i==k-1) return ans[i];
        }
        return {};
    }
};