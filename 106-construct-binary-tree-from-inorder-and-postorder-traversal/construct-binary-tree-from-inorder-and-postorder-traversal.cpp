class Solution {
public:

    int postIndex;
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        int rootValue = postorder[postIndex];
        postIndex--;
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
        root->right = build(inorder,postorder,rootPosition + 1,end);
        root->left = build(inorder,postorder,start,rootPosition - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
    {
        postIndex = postorder.size() - 1;
        return build(inorder,postorder,0,inorder.size() - 1);
    }
};