#include<iostream>
using namespace std;

int solution(int A[], int n, int target){
	int first = 0, last = n - 1;
	int mid;
	while (first != last){
		mid = first + (last - first) / 2;
		if (target == A[mid])return mid;
		if (A[first] <= A[mid]){
			if (A[first] <= target && target < A[mid])
				last = mid;

			else first = mid + 1;
		}
		else{
			if (A[mid] < target && target <= A[last - 1])
				first = mid + 1;
			else last = mid;
		}


	}
	return -1;
}
int main() {

	int A[] = { 7, 0, 1, 2, 4, 5, 6 }, out;
	out = solution(A, 7, 7);
	cout << "the loc is " << out << endl;

	//system("pause");
	return 0;
}