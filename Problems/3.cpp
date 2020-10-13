//Using Bool Vector
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        if(n==0) return 0;
        vector<bool> isPresent(256,false);
        int start=0;
        int end=0;
        int ans = 0;
        while(end<n){
            if(isPresent[s[end]]){
                while(s[start]!=s[end]){
                    isPresent[s[start]]=false;
                    ++start;
                }
                isPresent[s[start]]=false;
                start++;
            }else{
                isPresent[s[end]]=true;
                ans = max(ans,end-start+1);
                end++;
            }
        }
        return ans;
    }
};

//Using unordered_set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        int right = 0;
        int left = 0;
        int ans = 0;
        unordered_set<char> us;
        while(right<n){
            if(us.count(s[right])){
                us.erase(s[left++]);
            }else{
                us.insert(s[right++]);
                ans = max(ans,right-left);
            }
        }
        return ans;
    }
};
