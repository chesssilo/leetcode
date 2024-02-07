// Time complexity: O(nklogk)
// Space complexity: O(nk)
class Solution {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> keyToAnagrams;

    for (const string& str : strs) {
        string key = str;
        ranges::sort(key);
        keyToAnagrams[key].push_back(str);
    }

    for (const auto& [_, anagrams] : keyToAnagrams)
        ans.push_back(anagrams);

    return ans;    
};