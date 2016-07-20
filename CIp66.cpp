#include<stdio.h>
#include<stdlib.h>
using namespace std;

int Find(int A[], int len){
	//剑指p66旋转数组中的最小数字
	//if (A == NULL || len <= 0)
	//	throw new std::exception("Invalid Input");
	int ind1 = 0;
	int ind2 = len - 1;
	int mid = ind1;

	while (A[ind1] >= A[ind2]){
		if (ind2 - ind1 == 1){
			mid = ind2;
			break;
		}
		mid = (ind1 + ind2) / 2;
		if (A[mid] >= A[ind1])
			ind1 = mid;
		else if (A[mid] <= A[ind2])
			ind2 = mid;
	}
	return A[mid];
}

void main()
{
	int A[] = {3,4,5,1,2};
	int backvalue = 0;
	backvalue = Find(A, 5);
	int flag = 0;
}