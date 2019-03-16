#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    vector<int> res;
    int n = nums.size();
    if (n < 2) {
        return res;
    }
    unordered_map<int, int> table;
    for (int i = 0; i < n; i++) {
        if (table.find(target - nums[i]) != table.end()) {
            res.push_back(table[target - nums[i]]);
            res.push_back(i);
            break;
        }
        table[nums[i]] = i;
    }
    return res;
}

int main() {
    int n;
    cout << "input the size of vector:" << endl;
    cin >> n;
    cout << "construct vector:" << endl;
    vector<int> nums;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    cout << "input target" << endl;
    int target;
    cin >> target;
    vector<int> res = two_sum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
