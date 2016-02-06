#include <iostream>
#include <cmath>
using namespace std;


bool check(int b[],int c){
	static int refer[8][4]={{-1},{0,-1},{1,-1},{0,1,2,-1},{1,2,3,-1},{0,3,4,-1},{3,4,5,-1},{2,4,6,-1}};
	for(int i=0; i<c;i++){
		if(b[i]==b[c]) return false;
	} 
	for(int j=0; refer[c][j]!=-1;j++){
		if(abs(b[c]-(b[refer[c][j]]))==1) return false;
	}
	return true;

}

void print(int b[]){
	static int c = 0;
	cout<<"Solution # " << ++c << endl;
	cout<<" "<<b[1]<<b[2]<<endl;
	cout<<b[0]<<b[3]<<b[4]<<b[7]<<endl;
	cout<<" "<<b[5]<<b[6]<<endl;

}

void move(int q[],int i){
	if(i==8){
		print(q);
		return;
	}
	
	for(int j=1;j<9;j++){
		q[i]=j;
		if(check(q,i)) move(q,i+1);
	}

}
	

int main(){
	int q[8];
	move(q,0);

return 0;
}
