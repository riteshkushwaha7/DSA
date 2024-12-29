class Solution{
public:
    int pageFaults(int N, int C, int pages[]) {
        unordered_map<int, list<int>::iterator> cache; 
        list<int> lru;                                 
        int faults = 0;

        for (int i = 0; i < N; i++) {
            int page = pages[i];

            if (cache.find(page) == cache.end()) {
                faults++;

                if (lru.size() == C) {
                    int leastUsed = lru.back();
                    lru.pop_back();
                    cache.erase(leastUsed);
                }
            } else {
                lru.erase(cache[page]);
            }

            lru.push_front(page);
            cache[page] = lru.begin();
        }
        return faults;
    }
};
