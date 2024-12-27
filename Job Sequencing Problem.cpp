class Solution {
public:
    struct Job {
        int id, profit, deadline;
    };

    static bool comp(Job val1, Job val2) {
        return val1.profit > val2.profit;
    }

    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        vector<Job> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {id[i], profit[i], deadline[i]};
        }
        sort(a.begin(), a.end(), comp);

        int maxd = 0, total = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            maxd = max(maxd, a[i].deadline);
        }

        vector<int> hash(maxd + 1, -1);
        for (int i = 0; i < n; i++) {
            for (int j = a[i].deadline; j > 0; j--) {
                if (hash[j] == -1) {
                    cnt++;
                    hash[j] = a[i].id;
                    total += a[i].profit;
                    break;
                }
            }
        }
        return {cnt, total};
    }
};
