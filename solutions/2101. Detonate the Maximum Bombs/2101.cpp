class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> temp(size(bombs));
        for (int i = 0; i < size(bombs); ++i) {
            for (int j = 0; j < size(bombs); ++j) {
                if (j == i) {
                    continue;
                }
                const int64_t dx = bombs[i][0] - bombs[j][0];
                const int64_t dy = bombs[i][1] - bombs[j][1];
                const int64_t r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r) {
                    temp[i].emplace_back(j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(bombs); ++i) {
            vector<int> stk = { i };
            unordered_set<int> lookup = { i };
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                for (const auto& v : temp[u]) {
                    if (lookup.count(v)) {
                        continue;
                    }
                    lookup.emplace(v);
                    stk.emplace_back(v);
                }
            }
            result = max(result, static_cast<int>(size(lookup)));
            if (result == size(bombs)) {
                break;
            }
        }
        return result;
    }
};