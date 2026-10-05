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

    int findRoot(vector<int>&inorder, int rootValue,int start, int end){
        for(int i = start; i<=end; i++){
            if(rootValue == inorder[i]){
            return i;
            break;
            }
        }
        return 0;
    }

    TreeNode*tree(vector<int>&preorder, vector<int>&inorder, int start, int end, int &rootPosition){
        if(start > end){
            return NULL;
        }
        
        //get the root value and the root position
        int rootValue = preorder[rootPosition];
        rootPosition++;

        //create node now
        TreeNode* node = new TreeNode(rootValue);

        //search the root in the inorder for left and right subtree
        int index = findRoot(inorder, rootValue, start, end);


        node->left = tree(preorder, inorder, start, index - 1, rootPosition);
        node->right = tree(preorder, inorder, index + 1, end, rootPosition);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = 0;
        return(tree(preorder, inorder, 0, inorder.size() -1 , root));
    }
};