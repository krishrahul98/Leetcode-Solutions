class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long int n = x;
        long long int rev=0;
        while(n!=0){
           long long int digit  = n%10;
            rev= rev*10+digit;
            n/=10;
        }
        if(x==rev) return true;
        return false;
    }
};
