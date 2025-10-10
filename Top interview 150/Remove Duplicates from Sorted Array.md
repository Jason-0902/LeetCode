# Remove Duplicates from Sorted Array

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    nums.erase(nums.begin()+j);
                    --j;
                } // end if
            } // end for
        } // end for

        return nums.size();
    } // end removeDuplicates()
};
```