class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
          map<int, vector<int>> two_sum;
          for(int i = 0; i < nums.size(); ++i) {
               for(int j = i + 1; j < nums.size(); ++j) {
                    two_sum.insert({nums.at(i) + nums.at(j),{i, j}});
               }
          }

          vector<vector<int>> results;
          for(int i = 0; i < nums.size(); ++i) {
               for(auto tmp = two_sum.lower_bound(0 - nums.at(i)), end = two_sum.upper_bound(0 - nums.at(i)); tmp != end; ++tmp) {
               // auto match = two_sum.equal_range(0 - nums.at(i));
               // for (auto& tmp = match.first; q != p.second; ++q) {
               // if(tmp != two_sum.end()) {
                    if(tmp->first == 0 - nums.at(i)){
                         cout << i << tmp->second.at(0) << tmp->second.at(1) << endl;
                         // if(i != tmp->second.at(0) && i != tmp->second.at(1) && i < tmp->second.at(0) || i < tmp->second.at(1)) {
                         if(i < tmp->second.at(0)) {
                              results.push_back({nums.at(i), nums.at(tmp->second.at(0)), nums.at(tmp->second.at(1))});
                         }
                    }
               }
          }

          return results;
     }
};
