# Merge Sorted Array

## Problem Description
You are given two integer arrays nums1 and nums2, both sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

The goal is to merge nums1 and nums2 into a single array sorted in non-decreasing order.

## Key Points

* Both arrays are already sorted.

* nums1 has enough space to hold elements from both arrays.

* After merging, the result should also be sorted in non-decreasing order.

## My First Attempt

Initially, I didn’t realize the arrays were already sorted, so I wrote a solution that simply pushes all elements into a temporary array and sorts it again.

```C++
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
