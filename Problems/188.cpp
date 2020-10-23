class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,int k,vector<vector<vector<int>>> &memo)
    {   
        if(ind>=prices.size()||c>=k) return 0;
        
        else if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
         
        if(buy)
        {
        return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,k,memo),find(prices,ind+1,buy,c,k,memo));
        }
        else
        {
        return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,k,memo),find(prices,ind+1,buy,c,k,memo));
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        if (2 * k > prices.size()) {
            int res = 0;
            for (int i = 1; i < prices.size(); i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        vector<vector<vector<int>>> memo(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(prices,0,1,0,k,memo); 
    }
};

