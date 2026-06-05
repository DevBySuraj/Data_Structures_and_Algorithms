class Solution {
public:

    int preorderIndex = 0;

    TreeNode* createTree(vector<int>& preorder,vector<int>& inorder,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        int rootValue = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(rootValue);
        int rootPosition = start;
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == rootValue)
            {
                rootPosition = i;
                break;
            }
        }
        root->left = createTree(preorder,inorder,start,rootPosition - 1);
        root->right = createTree(preorder,inorder,rootPosition + 1,end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode* tree = createTree(preorder,inorder,0,inorder.size() - 1);
        return tree;
    }
};