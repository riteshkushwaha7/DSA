struct Item{
    int value;
    int weight;
};


class Solution {
public:
    static bool comp(Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> a(val.size());
        for (int i = 0; i < val.size(); i++) {
            a[i].value = val[i];
            a[i].weight = wt[i];
        }
        
        sort(a.begin(), a.end(), comp);
        
        double total = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].weight <= capacity) {
                total += a[i].value;
                capacity -= a[i].weight;
            } else {
                total += (double)a[i].value / a[i].weight * capacity;
                break;
            }
        }
        return total;
    }
};
