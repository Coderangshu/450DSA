#include <bits/stdc++.h>
using namespace std;

bool chkRot(string s1,string s2){
	// If string length are not equal then they 
	// aren't rotations of each other.
	if(s1.length()!=s2.length()) return false;
	string t = s1+s1;
	// If string 2 is a subset of two times string 1
	// then it is a rotation of string 1.
	// Here string::npos means "not found".
	return(t.find(s2) != string::npos);
}

int main(){
	string str1 = "AACD", str2 = "ACDA";
	if (chkRot(str1, str2))
		printf("Strings are rotations of each other");
	else
		printf("Strings are not rotations of each other");
	return 0;
}

