#include <iostream>
using namespace std;

int main(){
	int i=1;
	retry:
		if((i*i)%2==0||((i*i)/10)%2==0){  
			i++;
			goto retry;			     
	}
		else{
			cout<<i*i<<endl;
	}
		if(i*i/i!=i)
			cout<<"not a perfect square!"<<endl;
		
	return 0;
}
