#include <iostream>
#include <string>

using namespace std;
bool palindrome(string &s,int l,int r){
	if(l >= r){
		return true;
	}
	if(s[l] != s[r]){
		return false;
	}
	return palindrome(s,l+1,r-1);
}
int main(){
	string str;
	cout << "Enter string:";
	cin >> str;
	if(palindrome(str,0,str.size() - 1)){
		cout << "Palindrome " << endl;
	}else{
		cout << "Not Palidrome " <<endl;
	}
	return 0;
}