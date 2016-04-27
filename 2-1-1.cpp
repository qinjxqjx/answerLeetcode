#include<iostream>
using namespace std;


int solution( int A[],int n){
	int ind = 1, count = 1, max = 1;
	for (int i = 1; i != n; ++i){
		if (A[i] != A[i - 1]){
			A[ind++] = A[i];
			count = 1;
		}
		else ++count;
		if (max < count)max = count;
	}
	for (int i = 0; i != ind; ++i)
		cout << A[i];
		cout<< endl;
	return max;
}
int main() {

	int A[] = {1,1,1,1,2,2,3},out;
	out = solution(A,7);
	cout << "the length is " << out << endl;
	
	//system("pause");
	return 0;
}