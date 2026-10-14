#include <iostream>
using namespace std;

int sumofdigit(int digit){
	if(digit <= 0){
		return 0;
	}
	return digit%10 + sumofdigit(digit/10);
}
int main(){
	int val;
    cout << "Enter a number:";
	cin >> val;
	cout << "sum of digit:" << sumofdigit(val) << endl;
	return 0;
}