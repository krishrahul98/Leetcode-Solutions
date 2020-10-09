class Solution {
public:
    int numberOfSteps (int num) {
        int noOfSetBits = __builtin_popcount(num);
        int noOfBits = 1;
        if(num!=0){
            noOfBits = (int)log2(num)+1;
        }
        return noOfSetBits+noOfBits-1;
    }
};
