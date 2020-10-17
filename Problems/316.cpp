class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = s.length();
        unordered_map<char,int> um;
        vector<bool> visited(256,false);
        for(int i=0;i<n;i++){
            um[s[i]]++;
        }
        string ans;
        for(int i=0;i<n;i++){
            um[s[i]]--;
            if(visited[s[i]]) continue;
            while(!ans.empty() && ans.back()>s[i] && um[ans.back()]){
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[s[i]]=true;
        }
        return ans;
        
    }
};
// Without using map
class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = s.length();
        vector<bool> visited(26,false);
        vector<int> count(26,0);
        for(auto &i:s){
            count[i-'a']++;
        }
        string ans;
        for(auto &i:s){
            count[i-'a']--;
            if(visited[i-'a']) continue;
            while(!ans.empty() && ans.back()>i && count[ans.back()-'a']){
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(i);
            visited[i-'a']=true;
        }
        return ans;
        
    }
};
