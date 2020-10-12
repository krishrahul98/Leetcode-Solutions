class Solution {
  public:
    bool buddyStrings(string A, string B) {
      const int len = A.length();
      if (B.length() != len || len == 0) return false;
      int count = 0;
      int firstPos = 0, secondPos = 0;
      unordered_map < int, int > freq;
      for (int i = 0; i < len; i++) {
        if (A[i] != B[i]) {
          ++count;
          firstPos = secondPos;
          secondPos = i;
        }
        freq[A[i] - 'a']++;
      }
      if (count == 2) {
        if (A[firstPos] == B[secondPos] && A[secondPos] == B[firstPos]) return true;
      }
      if (count == 0) {
        for (auto it: freq) {
          if (it.second >= 2) {
            return true;
          }
        }
      }
      return false;
    }
};
