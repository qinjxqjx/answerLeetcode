#include<iostream>
using namespace std;

int solution(int A[], int n){
	int ind = 2, count = 1, max = 1;
	for (int i = 2; i != n; ++i){
		if (A[i] != A[i - 2]){
			A[ind++] = A[i];
		}
	}
	for (int i = 0; i != ind; ++i)
		cout << A[i];
	cout << endl;
	return ind;
}
int main() {

	int A[] = { 1, 1, 1, 1, 2, 2, 3, 3, 4 }, out;
	out = solution(A, 9);
	cout << "the length is " << out << endl;

	//system("pause");
	return 0;
}