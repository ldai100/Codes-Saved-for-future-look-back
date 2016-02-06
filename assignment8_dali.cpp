#include<iostream>
#include<cmath>
using namespace std;

bool ok(int b[8][8]){
  for(int c=0; c<8; c++){
    for(int r=0; r<8; r++){
	if(b[r][c]==1){
	   for(int i=0; i<c;i++)
		if(b[r][i]==1) return false;
	   for(int i=1; (r-i)>=0 && (c-i) >=0;i++) 			
		if(b[r-i][c-i]==1) return false;
	   for(int i=1;(r+i)<8 && (c-i)>=0;i++)
		if(b[r+i][c-i]==1) return false;
	}	
    }
  }
return true;
}		


void print(int b[8][8],int c){
	cout << "Solution #" << c << ":"<< endl;
	for(int i=0; i<8; i++){
		for(int j=0;j<8;j++){
			if(b[i][j]==1) cout << "Q";
			else cout <<"-";
		}
	cout << endl;
	}
}

int main(){
	int board[8][8]={0}, count = 0;
	for(int i0=0;i0<8;i0++)
	for(int i1=0;i1<8;i1++)
	for(int i2=0;i2<8;i2++)
	for(int i3=0;i3<8;i3++)		
	for(int i4=0;i4<8;i4++)
	for(int i5=0;i5<8;i5++)
	for(int i6=0;i6<8;i6++)
	for(int i7=0;i7<8;i7++){
		board[i0][0]=1;
		board[i1][1]=1;
		board[i2][2]=1;
		board[i3][3]=1;
		board[i4][4]=1;
		board[i5][5]=1;
		board[i6][6]=1;
		board[i7][7]=1;
	if(ok(board)) print(board,++count);
		board[i0][0]=0;
		board[i1][1]=0;
		board[i2][2]=0;
		board[i3][3]=0;
		board[i4][4]=0;
		board[i5][5]=0;
		board[i6][6]=0;
		board[i7][7]=0;
	
	}
return 0;
}
