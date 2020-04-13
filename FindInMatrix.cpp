//面试题3:二位数组中的查找，矩阵每行每列都是排好序的
//从右上角或者左下角进行查找


#include<iostream>
using namespace std;
bool Find(int* matrix, int rows, int colums, int num){
	bool result = false;
	if(matrix!=NULL && rows>0 && colums>0){
		int row=0, colum=colums-1;
		while(row < rows && colum >= 0){
			if(matrix[row*colums + colum] == num){
			result = true;
			break; 
			}else if(matrix[row*colums + colum] > num){
				colum--;
			}else{
				row++;
			}
			
		}
	}
	return result;	
}
bool Find1(int* matrix, int rows, int colums,int num){
	bool result = false;
	if(matrix!=NULL && rows>0 && colums >0){
		int row = rows-1,colum=0;
		while(colum < colums && row>=0){
			if(matrix[row*colums+colum]==num){
				result = true;
				break;
			}else if(matrix[row*colums+colum]>num){
				row--;
			}else{
				colum++;
			}
		}
	}
	return result;

}

int main()
{
	int matrix[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int r = 4;
	int c = 4;
	int num = 16;
	cout << Find(*matrix,r,c,num) << endl;
	cout << Find1(*matrix,r,c,num) << endl;
	return 0;
 } 
