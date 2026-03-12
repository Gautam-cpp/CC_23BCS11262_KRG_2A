#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& nums, int maxOps, int mid){
    int ops = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > mid){
            ops += (nums[i] - 1) / mid;
        }
    }
    return ops <= maxOps;

}

int solve(vector<int>& nums, int maxOps) {
    int l = 1;
    int h = *max_element(nums.begin(), nums.end());
    int ans = h;

    while(l <= h){
        int mid = l + (h - l) / 2;
        if(possible(nums, maxOps, mid)){
            ans = mid;
            h = mid - 1;
        } 
        else l = mid + 1;
        
    }
    return ans;
}

int main() {
    vector<int> nums = {6, 3};
    int maxOps = 2;
    cout << solve(nums, maxOps) << endl; 
    return 0;
}