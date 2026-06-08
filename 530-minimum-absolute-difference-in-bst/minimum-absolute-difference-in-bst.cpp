class Solution {
public:
    int prevVal = -1;
    int minDiff = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prevVal != -1) {
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};