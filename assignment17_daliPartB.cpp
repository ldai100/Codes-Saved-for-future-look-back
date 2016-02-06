#include <iostream>
using namespace std;


const int rows = 5;
const int cols = 6;
int path[rows][cols];
int last[rows];
int memo[rows][cols]={0};


void cost(){
	static int weight[rows][cols]={
	{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4}};


	//fill in the rest memo;
for(int j=0;j<cols;j++){
	for(int i=0;i<rows;i++){
		// set leftmost column to weight array;
		if(j==0) memo[i][0]=weight[i][0];
		else{

		int left = memo[i][j-1];
		int up = memo[(i-1+rows)%rows][j-1];
		int down = memo[(i+1)%rows][j-1];

			int min = left;
			path[i][j]=i;
		
			if(up<min){
				min = up;
				path[i][j] = (i-1+rows)%rows;
			}
			if(down<min){
				min = down;
				path[i][j]=(i+1)%rows;
			}
		memo[i][j]=weight[i][j]+min;
		}
	}
}
//fill in last array to compare in the main function;
for(int i=0;i<rows;i++)
	last[i]=memo[i][cols-1];

}//cost;

void getPath(int chooser, int col){
	if(col==-1) return;
	getPath(path[chooser][col],col-1);
	cout<<chooser<<" ";
}


int main(){

	//now find the smallest of them
	cost();
	int min = last[0];
	int chooser=0;//chooser of the column where it ends;
	for(int j=0;j<rows;j++){
		if(last[j]<min) {
			min=last[j];
			chooser=j;
		}//if
	}//for
	
	cout<<"the shortest path is of length "<<min << endl;		
	cout<<"The path is:\n";
	getPath(chooser,cols-1);
	cout<< endl;

return 0;
}

