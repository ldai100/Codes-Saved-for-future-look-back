#include <iostream>
#include <cmath>
using namespace std;


bool check(int q[],int c){
	for(int i=0; i<c;i++){
		if(q[i]==q[c]||abs(q[c]-q[i])==c-i) return false;
	} return true;
}
void print(int q[]){
	static int c = 0;
	c++;
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
void move(int q[],int i){
	if(i==8){
		print(q);
		return;
	}
	
	for(int j=0;j<8;j++){
		q[i]=j;
		if(check(q,i)) move(q,i+1);
	}

}
	

int main(){
	int q[8];
	move(q,0);

return 0;
}
