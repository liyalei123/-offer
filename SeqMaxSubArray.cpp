//面试题31:连续子数组的最大和


class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        int len = array.size();
        int cur_sum = array[0];
        int max_sum = array[0];
        for(int i = 1; i < len; i++){
            if(cur_sum <= 0)
                cur_sum = array[i];
            else
                cur_sum += array[i];
            
            if(cur_sum > max_sum )
                max_sum = cur_sum;
        }
        return max_sum;
    }
};
