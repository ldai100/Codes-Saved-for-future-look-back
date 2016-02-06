#include <iostream>
#include <cmath>
using namespace std;

	typedef char box[5][7];
	box bb,wb,wq,bq, *board[8][8];

bool check(int q[],int c){
	for(int i=0; i<c;i++){
		if(q[i]==q[c]||abs(q[c]-q[i])==c-i) return false;
	} return true;
}
void print(int q[],int c, box *b[8][8]){
	int i,j,k,l;	
	cout<<endl<< endl<<endl << "solution #" <<c<<":"<<endl;
	//inserting white and black queens;
	for(i=0;i<8;i++){
		if((i+q[i])%2==0)
			b[i][q[i]]=&bq;
		else b[i][q[i]]=&wq;	
	}
	//printing completed board;
	for(i=0;i<8;i++)
	for(k=0;k<5;k++){

	for(j=0;j<8;j++)
	for(l=0;l<7;l++)
	cout << (*b[i][j])[k][l];
	cout << endl;
	}
	//reseting the board to its original state;
	for(i=0;i<8;i++)
		if((i+q[i])%2==0)
			b[i][q[i]]=&wb;
		else b[i][q[i]]=&bb;	
		

}
void backTrack(int *c){
	--*c;
}
	

int main(){
	int q[8], c = 0,  counter = 0;
	q[0]=0;
	int i,j;
	//fill wq
	for(i=0;i<5;i++)
		for(j=0;j<7;j++){
			if(i<4&&i>1&&j<6&&j>0) wq[i][j]=' ';
			else if((i==1)&&(j%2==1)) wq[i][j]=' ';
			else wq[i][j]=char(219);
		}
	//fill bq
	for(i=0;i<5;i++)
		for(j=0;j<7;j++){
			if(i<4&&i>1&&j<6&&j>0) bq[i][j]=char(219);
			else if((i==1)&&(j%2==1)) bq[i][j]=(219);
			else bq[i][j]=' ';
		}

	//fill bb and wb
	for(i=0;i<5;i++)
		for(j=0;j<7;j++){
		wb[i][j]=' ';
		bb[i][j]=char(219);
		}
	//fill board
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if((i+j)%2==0)board[i][j]=&wb;
			else board[i][j]=&bb;
	
while(true){
	c++;
	if(c==8){print(q, ++counter, board);
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
