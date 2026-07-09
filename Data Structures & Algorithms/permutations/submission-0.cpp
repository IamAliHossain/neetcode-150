/*
    Final complexity:

    Time Complexity: O(n × n!)
    n! because there are n! different permutations.

    n because each complete permutation of length n must be copied (or output).
    Auxiliary Space Complexity: O(n)
    Recursion stack: O(n)
    vis[] array: O(n)


    nums = [1,2,3]
Level 0                      []

                    /         |         \
Level 1           [1]        [2]        [3]

                /    \      /   \      /   \
Level 2      [1,2] [1,3] [2,1] [2,3] [3,1] [3,2]

            |      |      |      |      |      |
Level 3     123     132    213    231    312    321


*/

class Solution {
public:
    

    void solution(vector<int> &nums, vector<vector<int>> &ans, vector<int> &perm, vector<bool> &vis){
        if( perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(vis[i])continue;

            vis[i] = true;
            perm.push_back(nums[i]);
            
            solution(nums, ans, perm, vis);
            perm.pop_back();
            vis[i] = false;
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<bool> vis(nums.size(), false);

        solution(nums, ans, permutation, vis);

        return ans;
    }
};