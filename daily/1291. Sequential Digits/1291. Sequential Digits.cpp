// 2026/7/13

class Solution {
public:

    const vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for (int i = 0; i < numbers.size(); ++i) {

            int num = 0;

            for (int j = i; j < numbers.size(); ++j) {
                num = num * 10 + numbers[j];
                if (num >= low && num <= high) {
                    result.push_back(num);
                } // end if

                if (num > high) {
                    break;
                } // end if
            } // end for
        } // end for

        std::sort(result.begin(), result.end());

        return result;
    } // end sequentialDigits()
};