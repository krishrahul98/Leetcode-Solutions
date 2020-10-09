class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(),candies.end());
        vector<bool> hasGreatestNumber(candies.size(),true);
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies<maxCandies){
                hasGreatestNumber[i]=false;
            }
        }
        return hasGreatestNumber;
    }
};
