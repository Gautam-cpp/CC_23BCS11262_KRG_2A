#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) v.push_back({nums[i], i});
        
        mergeSort(v, 0, n - 1, counts);
        return counts;
    }

    void mergeSort(vector<pair<int,int>>& v, int left, int right, vector<int>& counts) {
        if(left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(v, left, mid, counts);
        mergeSort(v, mid + 1, right, counts);
        merge(v, left, mid, right, counts);
    }

    void merge(vector<pair<int,int>>& v, int left, int mid, int right, vector<int>& counts) {
        vector<pair<int,int>> temp;
        int i = left, j = mid + 1;
        int rightCount = 0;

        while(i <= mid && j <= right) {
            if(v[j].first < v[i].first) {
                rightCount++;
                temp.push_back(v[j++]);
            } else {
                counts[v[i].second] += rightCount;
                temp.push_back(v[i++]);
            }
        }

        while(i <= mid) {
            counts[v[i].second] += rightCount;
            temp.push_back(v[i++]);
        }

        while(j <= right) {
            temp.push_back(v[j++]);
        }

        for(int k = left; k <= right; k++) {
            v[k] = temp[k - left];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,2,6,1};
    vector<int> res = s.countSmaller(nums);

    for(int x : res) cout << x << " ";
    return 0;
}
