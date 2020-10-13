//Using space: O(n+m) and time: O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums(n+m,0);
        int i=0;
        int j= 0;
        int k =0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                nums[k++]=nums1[i++];
            }else{
                nums[k++]=nums2[j++];
            }
        }
        while(i<n){
            nums[k++]=nums1[i++];
        }
        while(j<m){
            nums[k++]=nums2[j++];
        }
        double ans = 0;
        int mid = (n+m)/2;
        if((n+m)%2==0){
            ans = (double)(nums[mid]+nums[mid-1])/2;
        }else{
            ans = nums[mid];
        }
        return ans;
    }
};
//using time: O(log(n+m)) 
