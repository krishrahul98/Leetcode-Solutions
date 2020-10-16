// Time Complexity O(n)
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lheight = height(root->left);
        int rheight = height(root->right);
        return max(lheight+rheight,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};

// Time Complexity O(n)
class Solution {
public:
    int calculateDiameter(TreeNode* root,int &ans){
        if(!root) return 0;
        int ldiameter = calculateDiameter(root->left,ans);
        int rdiameter = calculateDiameter(root->right,ans);
        ans = max(ans,ldiameter+rdiameter);
        return 1+max(ldiameter,rdiameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        calculateDiameter(root,ans);
        return ans;
    }
};
