class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX, best = 0;
        
        for (int p : prices) {
            min_so_far = std::min(min_so_far, p);
            best = std::max(best, p - min_so_far);
        } // end for

        return best;
    } // end maxProfit
};