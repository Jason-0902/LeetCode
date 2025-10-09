# Merge Sorted Array



```
class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m+n);
        tmp.clear();


        for (int i = 0; i < m; i++) {
            tmp.push_back(nums1[i]);
        } // end for

        for (int i = 0; i < n; i++) {
            tmp.push_back(nums2[i]);
        } // end for

        sort(tmp.begin(), tmp.end());
        nums1.clear(); nums1 = tmp;
    }
};
```