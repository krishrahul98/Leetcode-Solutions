//Time Complexity O(N) space O(N)
class Solution {
public:
    void inorderTraversal(TreeNode* root,vector<int> & arr){
        if(!root) return;
        inorderTraversal(root->left,arr);
        arr.push_back(root->val);
        inorderTraversal(root->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inorderTraversal(root,arr);
        if(arr.size()<2) return true;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                return false;
            }
        }
        return true;
    }
};

// Time Comlexity O(N) space O(log2(N)) if consider call stack
class Solution {
public:
    bool checker(TreeNode* root,TreeNode* min,TreeNode* max){
        if(!root) return true;
        if((min && root->val<=min->val) || (max && root->val>=max->val)) return false;
        return checker(root->left,min,root) && checker(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return checker(root,NULL,NULL);
    }
};
