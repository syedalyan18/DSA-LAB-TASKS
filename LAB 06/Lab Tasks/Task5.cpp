#include <iostream>
using namespace std;

void factorial(int val,int &fact){
	if(val <= 0){
		return;
	}
	fact *= val;
	factorial(val-1,fact);
}
int main(){
	cout << "Enter number:";
	int val;
	cin >> val;
	int fact = 1;
	factorial(val,fact);
	cout << "factorial:" << fact << endl;
	return 0;
}