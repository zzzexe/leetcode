#include <iostream>
#include <vector>
using namespace std;

int lcs_helper(const vector<int>& nums1, int end1, const vector<int>& nums2, int end2) {
    if (end1 < 0 || end2 < 0) {
        return 0;
    }
    if (nums1[end1] == nums2[end2]) {
        return lcs_helper(nums1, end1 - 1, nums2, end2 - 1) + 1;
    } else {
        return max(lcs_helper(nums1, end1 - 1, nums2, end2), lcs_helper(nums1, end1, nums2, end2 - 1));
    }
}

int lcs(const vector<int>& nums1, const vector<int>& nums2) {
    return lcs_helper(nums1, nums1.size() - 1, nums2, nums2.size() - 1);
}

int main() {
    int tmp;
    int x1;
    cin >> x1;
    vector<int> nums1(x1, 0);
    for (int i = 0; i < x1; i++) {
        cin >> tmp;
        nums1[i] = tmp;
    }
    int x2;
    cin >> x2;
    vector<int> nums2(x2, 0);
    for (int i = 0; i < x2; i++) {
        cin >> tmp;
        nums2[i] = tmp;
    }
    cout << lcs(nums1, nums2) << endl;
    return 0;
}
