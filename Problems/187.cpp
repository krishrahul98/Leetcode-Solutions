class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.length();
        vector<string> ans;
        unordered_map<string,int> map;
        for(int i=0;i<n-9;i++){
            string sequence = s.substr(i,10);
            if(map.count(sequence) && map[sequence]==1){
                ans.push_back(sequence);
            }
            map[sequence]++;
        }
        return ans;
    }
};
