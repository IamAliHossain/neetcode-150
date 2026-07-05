#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solution(vector<int> &arr, vector<vector<int>> &ans, vector<int> &combination, int ind, int curr, int target){
        if(curr == target){
            ans.push_back(combination);
            return;
        }
        
        for(int i=ind; i<arr.size(); i++){
            // checking duplicate combinations
            if(i > ind && arr[i] == arr[i - 1])continue;
            if(curr > target) break;
            // take the element
            combination.push_back(arr[i]);
            solution(arr, ans, combination, i+1, curr+arr[i], target);
            
            // skip the element
            combination.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solution(candidates, ans, res, 0, 0, target);

        return ans;
    }
};