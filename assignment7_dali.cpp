#include<iostream>
#include<cmath>
using namespace std;

bool check(int b[8],int refer[8][4],int c){
	for(int i=0;i<c;i++){
		if(b[c]==b[i]) return false;
	}
	for(int j=0;refer[c][j]!=-1;j++){
		if(abs(b[c]-(b[refer[c][j]]))==1) return false;
		if(refer[c][j]==-1) return true;
	}
}

void backTrack(int *c){
	--*c;
}

void print(int b[8],int counter){
	cout<<"solution#"<<counter<<endl;
	cout<<" "<<b[1]<<b[2]<<endl;
	cout<<b[0]<<b[3]<<b[4]<<b[7]<<endl;
	cout<<" "<<b[5]<<b[6]<<endl;
}

int main(){
	int b[8], c=0, counter=0;
	int refer[8][4]={{-1},{0,-1},{1,-1},{0,1,2,-1},{1,2,3,-1},{0,3,4,-1},{3,4,5,-1},{2,4,6,-1}};

	while(true){
		if(c==8) {
			print(b,++counter);
			backTrack(&c);
		} else b[c]=0;

		while(c<8){
			++b[c];	
			if(b[c]==9) {  
				backTrack(&c);
				if(c==-1) return 0;
				else continue;
		}
			if(check(b,refer,c)) break;
		}
	c++;
	}
}
