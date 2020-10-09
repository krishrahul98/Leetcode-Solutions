class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                sums[i]+=sums[i-1];
            }
            sums[i]+=nums[i];
        }
        return sums;
    }
};
