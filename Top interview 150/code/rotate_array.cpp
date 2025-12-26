class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0) return;

        k = k % n; // In case k is greater than n

        if (k == 0) return; // No need to rotate

        auto rev = [&](int l, int r) {
            for (; l < r; ++l, --r) swap(nums[l], nums[r]);
        }; 

        rev(0, n - 1);       // reverse all
        rev(0, k - 1);       // reverse first k
        rev(k, n - 1);       // reverse rest
    } // end rotate()
};