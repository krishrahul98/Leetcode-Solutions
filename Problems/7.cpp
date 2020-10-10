class Solution {
  public:
    int reverse(int x) {
      int maxVal = INT_MAX / 10;
      int maxDigit = INT_MAX % 10;
      int minVal = INT_MIN / 10;
      int minDigit = INT_MIN % 10;
      int revNum = 0;
      while (x != 0) {
        int digit = x % 10;
        x /= 10;
        if (revNum > maxVal || (revNum == maxVal && digit > maxDigit) ||
          revNum < minVal || (revNum == minVal && digit < minDigit)) return 0;
        revNum = revNum * 10 + digit;
      }
      return revNum;
    }
};
