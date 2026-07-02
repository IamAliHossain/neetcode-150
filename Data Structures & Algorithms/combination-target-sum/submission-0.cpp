/*
    Time Complexity : O(k * 2^n)
    Space Complexity : O(k)
*/


class Solution {
public:
    void solution(vector<int> &arr, vector<vector<int>>&ans, vector<int> &combination, int ind, int curr, int target){
        // when checking index go outside of the array and can't meet the target return from here
        if(ind >= arr.size() || curr >= target){
            // when current meets the target take that combination cause this is valid
            if(curr == target){
                ans.push_back(combination);
            }
            return;
        }
        // taking same elements multiple time
        combination.push_back(arr[ind]);
        solution(arr, ans, combination, ind, curr+arr[ind], target);

        // if this element meet invalid combination then remove/skip the element
        combination.pop_back();
        solution(arr, ans, combination, ind+1, curr, target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        solution(candidates, ans, combination, 0, 0, target);
        return ans;
    }
};