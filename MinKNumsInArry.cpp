class Solution {
public:
    //方法1:先排好序，取最小的k个数即可然后
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int length = input.size();
        if(k<=0||k>length)
            return res;
        sort(input.begin(), input.end());
        for(int i = 0; i< k;i++)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};


class Solution {
public:
    //方法2:借助于快速排序中的parition思想
    int Partition(vector<int>& input, int begin, int end){
        int low = begin;
        int high = end;
        int pivot = input[low];
        while(low<high){
            if(low<high && pivot <= input[high] )
                high--;
            input[low]=input[high];
            if(low<high && pivot >= input[low])
                low++;
            input[high]=input[low];
            //input[low]=pivot;
        }
        input[low]=pivot;
        return low;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int length = input.size();
        //vector<int> res;
        if(length == k) return input;
        if(length < k||length == 0)
            return vector<int>();
        if(k<=0)
            return vector<int>();
        int start = 0;
        int end = length - 1;
        int index = Partition(input, start, end);
        while(index!=(k-1)){
            if(index < k-1){
                start = index+1;
                index = Partition(input,start,end);
            }
            else{
                end = index-1;
                index = Partition(input, start, end);
            }
        }
        vector<int> res(input.begin(),input.begin()+k);
        return res;
    }
};



class Solution {
public:
	//方法3:利用红黑树实现
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
         
        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=input.begin();
        for(;vec_it!=input.end();vec_it++)
        {
            //将前k个元素插入集合
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else
            {
                //第一个元素是最大值
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if(*vec_it<*(leastNums.begin()))
                {
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }
         
        return vector<int>(leastNums.begin(),leastNums.end());
    }
};

