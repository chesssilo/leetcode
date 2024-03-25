// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<long long> mostFrequentIDs(const vector<int>& nums, const vector<int>& freq) {
    vector<long long> ans;
    unordered_map<int, long long> idToFreqMap;
    map<long long, int> freqToIdCountMap;
    
    for (int i = 0; i < nums.size(); ++i) {
      if (idToFreqMap[nums[i]]) {
        --freqToIdCountMap[idToFreqMap[nums[i]]];

        if(freqToIdCountMap[idToFreqMap[nums[i]]] == 0)              
          freqToIdCountMap.erase(idToFreqMap[nums[i]]);
      }

      idToFreqMap[nums[i]] += freq[i];
      ++freqToIdCountMap[idToFreqMap[nums[i]]];
      ans.push_back(freqToIdCountMap.rbegin()->first);
    }
    
    return ans;
  }
};