class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        for(int i=0;i<S.size();i++){
            if(J.find(S[i])!=string::npos){
                ++count;
            }
        }
        return count;
    }
};
