# Majority Element

## Problem Description

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

## Code

### first attemp

```C++
class Solution {
public:

    typedef struct COUNT {
        int num;
        int count;
    } count;

    bool isExist(vector<count>& c, int val) {
        for (int i = 0; i < c.size(); i++) { 
            if (c[i].num == val) {
                c[i].count++;
                return true;
            } // end if
        } // end for

        return false;
    } // end isExist()

    int findMax(vector<count>& c) {
        count max = c[0];

        for (int i = 1; i < c.size(); i++) {
            if (c[i].count > max.count) {
                max = c[i];
            } // end if
        } // end for

        return max.num;
    } // end findMax()

    int majorityElement(vector<int>& nums) {
        int m = nums.size() / 2;
        vector<count> c;

        for (int i = 0; i < nums.size(); i++) {
            if (!isExist(c, nums[i])) {
                count tmp;
                tmp.num = nums[i]; tmp.count = 1;
                c.push_back(tmp);
            } // end if
        } // end for

        return findMax(c);
    } // end majorityElement()
};
```

Analysis of This Approach:

Time Complexity: `O(n²)` in the worst case

Each call to `isExist()` performs a linear scan over the `vector<count>`, making the outer loop costly.

Space Complexity: `O(n)`

A new count object is created for each unique number.

Performance: My solution took around 4ms on LeetCode — significantly slower than the top solutions.

Scalability: Not suitable for large inputs, as the nested linear search causes poor scaling.

### Second attemp

```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            } // end if

            if (num == candidate) {
                count++;
            } // end if 
            else {
                count--;
            } // end else
        } // end for

        return candidate;
    } // end majorityElement()
};
```

Core Idea: This algorithm "cancels out" elements that are different from the current candidate.

The majority element (which occurs more than `n/2` times) will always survive these cancellations.

Variables Used:

* `candidate`: stores the current leading candidate

* `count`: tracks the net "support" for the candidate

Time & Space Complexity:

* Time Complexity:	`O(n)`
* Space Complexity:	`O(1)`