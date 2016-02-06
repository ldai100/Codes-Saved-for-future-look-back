#include <iostream>
using namespace std;

int main(){
int a[5];
int i = 0;
retry:
	cout << a[i];
	i +=2;
if(i<5) goto retry;

return 0;
}
