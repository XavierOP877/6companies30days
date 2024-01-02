class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        for (auto& query : queries) {
            int k = query[0], trim = query[1];
            vector<pair<string, int>> trimmed_nums;
            for (int i = 0; i < nums.size(); ++i) {
                trimmed_nums.emplace_back(nums[i].substr(nums[i].size() - trim), i);
            }
            sort(trimmed_nums.begin(), trimmed_nums.end());
            answer.push_back(trimmed_nums[k - 1].second);
        }
        return answer;
    }
};