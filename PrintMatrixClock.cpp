class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> Nums;
        Nums.clear();
        int endX,endY;
        int rows = matrix.size();
        int colums = matrix[0].size();
        if(rows <=0||colums<=0)
            return Nums;
        int start = 0;
        while(rows < 2*start && colums < 2*start){
            endX = rows - start -1;
            endY = colums - start - 1;
            for(int i = start; i <= endX ; i++){
                Nums.push_back(matrix[start][i]);
            }
            if(start < endY){
                for(int i = start; i<=endY;i++)
                    Nums.push_back(matrix[i][endX]);
            }
            if(start < endY && start < endX){
                for(int i = endX-1; i >=start; i--)
                    Nums.push_back(matrix[endY][i]);
            }
            if(start < endX && start < endY-1){
                for(int i = endY-1; i>=start+1; i--)
                    Nums.push_back(matrix[start][i]);
            }
            start++;
        }
        return Nums;
    }
};
