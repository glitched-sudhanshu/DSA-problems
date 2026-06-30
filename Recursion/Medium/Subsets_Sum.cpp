/**
* Question:
* https://www.geeksforgeeks.org/problems/subset-sums2234/1
*/

class Solution {
private:
    // TC: O(2^n)
    // SC: O(2^n)
    // 2^n because for any list with N elements will have these many subsets
    void solve(vector<int> &arr, int idx, vector<int> &res, int curSum) {
        if (idx >= arr.size()) {
            res.push_back(curSum);
            return;
        }

        solve(arr, idx + 1, res, curSum + arr[idx]);
        solve(arr, idx + 1, res, curSum);
    }

public:
    vector<int> subsetSums(vector<int> &arr) {
        // code here
        vector<int> res;
        solve(arr, 0, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
};