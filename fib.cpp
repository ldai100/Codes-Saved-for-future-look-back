#include<iostream>
using namespace std;

static unsigned long a[100]={0};

int fib(int n){
	if(n==0||n==1) return a[n]=1;
	if(a[n]!=0) return a[n];
	else return a[n] = fib(n-1) + fib(n-2);
}

int main(){
	int n;
	cin>>n;
	fib(n);

	for(int i=0;i<n;i++)
	cout << a[i] << endl;
return 0;
}
