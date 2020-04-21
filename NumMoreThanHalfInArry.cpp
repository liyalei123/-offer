//面试题29:数组中出现次数超过一半的数字
//采用阵地攻守的思想
//第一个数字作为士兵守阵地，count=1
//遇到相同的元素，count++
//遇到不同的元素就是敌人，同归于尽，count--，当遇到
//count为0的情况，又以新元素作为士兵，依次进行下去最后留在
//阵地上的士兵可能是主元素
//再加一次循环，记录这个士兵的个数看是否大于数组的一半


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if(length <= 0)
            return 0;
        int times=1;
        int result = numbers[0];
        for(int i = 0; i < length; i++){
            if(times == 0){
                result = numbers[i];
                times++;
            }
            else{
                if(result == numbers[i])
                    times++;
                else 
                    times--;
            }
        }
        times =0;
        for(int i=0;i<length;i++){
            if(result==numbers[i])
                times++;
        }
        if(times*2<= length)
            return 0;
        return result;
    }
};
