#include <bits/stdc++.h>
using namespace std;

void printDups(char *s){
	// A array of 256 characters is taken with 0 initiated in
	// each of them(done by calloc itself).
	int *count = (int*)calloc(256,sizeof(int));
	for(int i=0;*(s+i);i++) count[*(s+i)]++;
	for(int i=0;i<256;i++) if(count[i]>1) cout<<char(i)<<"'s frequency is: "<<count[i]<<endl;
	free(count);
}

int main(){
	char str[] = "test string";
	printDups(str);
	return 0;
}
