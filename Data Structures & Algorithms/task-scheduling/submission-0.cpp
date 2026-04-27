class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        // Count frequency of each task
        for (char task : tasks) {
            mp[task]++;
        }

        // Max heap based on frequency
        priority_queue<int> pq;
        for (auto it : mp) {
            pq.push(it.second);
        }

        // Queue stores {remainingCount, nextAvailableTime}
        queue<pair<int, int>> q;

        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            // Execute task with highest remaining count
            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                // If still remaining, push into cooldown queue
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            // If front task cooldown is over, move back to heap
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};