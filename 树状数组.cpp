#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index < BIT.size()) {  // ��״�������
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }

    void update(vector<int>& BIT, int index, int val) {
        while (index > 0) {   // ��״�������
            BIT[index] += val;
            index -= index & (-index);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_copy(nums);  // ������������

        sort(nums_copy.begin(), nums_copy.end()); // �Ը��Ƶ�������������

        vector<int> BITS(n + 1, 0);  // ��ʼ����״����
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // ������Ҫ�����
            count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
            // ������״����
            update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
        }
        return count;  // ���ؼ�����
    }

};

int main()
{
    Solution solution;
    vector<int>nums = { 11, 6, 5, 2, 1, 8, 3, 4 };

    cout << solution.reversePairs(nums) << endl;
    return 0;
}