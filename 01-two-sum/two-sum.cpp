class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> indices_vector(2);
      for(int i = 0; i < nums.size(); ++i) {
        for(int n = i + 1; n < nums.size(); ++n) {
          if(nums[i] + nums[n] == target) {
            // indices_vector.push_back(i);
            // indices_vector.push_back(n);
            // std::cout << (int) indices_vector.capacity();
            // return indices_vector;
            indices_vector[0] = i;
            indices_vector[1] = n;
            break;
          }
        }
      }
      return indices_vector;
    }
};
