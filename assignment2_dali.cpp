#include <iostream>
using namespace std;
void right_shift(int a[], int size){
	int temp = a[size - 1];
	for (int i = size - 1; i > 0; i--)
		a[i] = a[i-1];
	a[0] = temp;
}

bool equivalent(int a[], int b[], int n){
for(int i=0; i<n;i++){
	for(int j=0; j<n;j++){
		if(a[j] != b[j])break;
		if(a[n-1]==b[n-1])return true;
}	right_shift(a,n);

}
 return false;
}

void printA(int a[], int n){
	for(int i = 0; i < 5; i++)
		cout << a[i] << " ";
}
int main(){
	int a[5] = {1,2,3,4,5};
	int b[5] = {3,4,5,1,2};
	cout << "a: ";
	printA(a,5);
	cout << endl << "b: ";
	printA(b,5);
	string equiv = "";
	if(!equivalent(a,b,5)) equiv = " not";
	cout << endl << "are" << equiv << " shift equivalent!" << endl;
	return 0;
}
