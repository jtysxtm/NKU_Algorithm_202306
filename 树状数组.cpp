#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index < BIT.size()) {  // 树状数组求和
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }

    void update(vector<int>& BIT, int index, int val) {
        while (index > 0) {   // 树状数组更新
            BIT[index] += val;
            index -= index & (-index);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_copy(nums);  // 复制输入向量

        sort(nums_copy.begin(), nums_copy.end()); // 对复制的向量进行排序

        vector<int> BITS(n + 1, 0);  // 初始化树状数组
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // 计算重要逆序对
            count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
            // 更新树状数组
            update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
        }
        return count;  // 返回计数器
    }

};

int main()
{
    Solution solution;
    vector<int>nums = { 11, 6, 5, 2, 1, 8, 3, 4 };

    cout << solution.reversePairs(nums) << endl;
    return 0;
}