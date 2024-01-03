class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> people_knowing_secret(n + 1, 0);
        people_knowing_secret[1] = 1;
        for (int day = 2; day <= n; ++day) {
            for (int shared_day = day - delay; shared_day >= max(1, day - forget + 1); --shared_day) {
                people_knowing_secret[day] += people_knowing_secret[shared_day];
                people_knowing_secret[day] %= MOD;
            }
        }
        int total_people = 0;
        for (int day = max(1, n - forget + 1); day <= n; ++day) {
            total_people += people_knowing_secret[day];
            total_people %= MOD;
        }
        return total_people;
    }
};