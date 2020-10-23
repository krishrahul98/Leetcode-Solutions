class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if(n==0) return 0;
        int k=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[k]) continue;
            nums[++k]=nums[i];
        }
        return k+1;
    }
};
