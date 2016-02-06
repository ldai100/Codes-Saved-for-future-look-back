#include <iostream>
#include <cmath>
using namespace std;


bool check(int q[],int c){
	for(int i=0; i<c;i++){
		if(q[i]==q[c]||abs(q[c]-q[i])==c-i) return false;
	} return true;
}
void print(int q[],int c){
	cout<<"Solution # " << c << endl;
	for(int i=0; i<8;i++){
		for(int j=0;j<8;j++){
			if(q[j]==i) cout<<"Q";
			else cout <<"-";
		}
	cout << endl;
	}
	cout << endl;
}
void backTrack(int *c){
	--*c;
}
	

int main(){
	int q[8], c = 0,  counter = 0;
	q[0]=0;
	
while(true){
	c++;
	if(c==8){print(q, ++counter);
		backTrack(&c);
	} else	q[c]=-1;
	
		while(true){
		 q[c]++;
		if(q[c]==8){  backTrack(&c);
			if(c==-1)return 0;
			else continue;
		}if(check(q,c)) break;
		}	
	}
}
