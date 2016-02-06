#include <iostream>
#include <cmath>
using namespace std;


bool check(int q[],int c){
	for(int i=0; i<c;i++){
		if(q[i]==q[c]||abs(q[c]-q[i])==c-i) return false;
	} return true;
}

void backTrack(int *c){
	--*c;
}

int solution(int* q, int size){
	int c = 0, counter = 0;
	q[0]=0;

while(true){
	c++;
	if(c==size){
		counter++;
		backTrack(&c);
	} else q[c]=-1;
	
		while(true){
		q[c]++;
		if(q[c]==size){ backTrack(&c);
			if(c==-1) { 

			return counter;
			} else continue;
		}if(check(q,c)) break;
		} //while
	} //while

} // solution function
	

int main(){
	int size;

	cout << "Enter your n to see the number of possible solution for n queens:";
	cin>>size;
	for(int i=1;i<=size;i++){
		int* q = new int[i];

		cout << "There are " << solution(q, i) << " solutions to the "<< i << " queens problem." << endl;
	
		delete[] q;
	}

	return 0;
}
