class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> indices_vector;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums.at(i) + nums.at(j) == target) {
                    indices_vector.push_back(i);
                    indices_vector.push_back(j);
                    break;
                }
            }
        }
        return indices_vector;
    }
};
