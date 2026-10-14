#include <iostream>
#include <string>

using namespace std;
void reverseString(string &s,int l,int r){
	if(l >= r){
		return;
	}
	swap(s[l],s[r]);
	reverseString(s,l+1,r-1);
}
int main(){
	string str;
    cout << "Enter a string:";
	cin >> str;
	reverseString(str,0,str.size() - 1);
	cout << "reverse: " << str << endl; 
	return 0;
}