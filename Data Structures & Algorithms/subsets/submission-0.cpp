/*
    Time Complexity : O(2^n * n) ---> O(n * 2^n) this is exponential time-complexity
    Auxilary stack space : O(n) hence : Space Complexity : O(n) 


    This would be solved using backtracking technique, since there are two options 
            1. take or 
            2. skip

                        Space Tree for input : [1, 2, 3] and subset[]



                                                    subset[]
                                                (start = 0, value = 1)
                                      /                                    \
                                    /                                        \
                                Take 1                                      Skip 1
                            subset[1]                                       subset[]
                         /              \                           /                       \
                        /                \                        /                           \
                (start=1, val = 2)    (start=1, val=2)      (start=1, val = 2)             (startx=1, val = 2)
                Take 2                  Skip 2                  Take 2                          Skip 2
        subset[1,2]                  subset[1]                  subset[2]                       subset[]
            /     \                      /    \                 /       \                   /            \
           /       \                    /      \               /         \                 /              \ 
        Take 3      Skip 3            Take 3   Skip 3       Take 3      Skip 3          Take 3          Skip 3
subset[1,2,3]    subset[1,2]   subset[1,3]    subset[1]   subset[2,3]    subset[2]      subset[3]      subset[]
start = 3       start = 3       start = 3     start = 3   start = 3       start = 3   start = 3       start = 3

whenver start == 3, subset will be added to ans array, this is the logic of the code .


*/

class Solution {
public:
    void solution(vector<vector<int>> &ans, vector<int>& nums, vector<int> &subset, int start, int end){
        
        // add subset at end of array from each of the space tree
        if(start == end){
            ans.push_back(subset);
            return ;
        }

        /* taking the element at this index and going next index, recursively find all subsets */
        subset.push_back(nums[start]);
        solution(ans, nums, subset, start+1, end);
        
         /* skiping the element at this index and going next index, recursively find all subsets */
        subset.pop_back();
        solution(ans, nums, subset, start+1, end);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        solution(ans, nums, subset, 0, n);
        return ans;
    }
};