class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        const int n = nums.size();
        for(int i=0;i<n;i++){
            if(map.count(target-nums[i])){
                return {map[target-nums[i]],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
