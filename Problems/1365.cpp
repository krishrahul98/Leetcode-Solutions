class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int frequency[101];
        memset(frequency,0,sizeof(frequency));
        const int n = nums.size();
        for(int i=0;i<n;i++){
            ++frequency[nums[i]];
        }
        for(int i=1;i<101;i++){
            frequency[i]+=frequency[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            nums[i]=frequency[nums[i]-1];
        }
        return nums;
    }
};
