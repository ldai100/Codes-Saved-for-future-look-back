#include <iostream>
using namespace std;


const int rows = 5;
const int cols = 6;
static int path[rows][cols];


int cost(int i, int j){
	static int weight[rows][cols]={
	{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4}};

	static int memo[rows][cols]={0};
	//base case
		if(j==0)
		return weight[i][0];
		if(memo[i][j]!=0) return memo[i][j];

	//recursive call
	int left = weight[i][j]+cost(i,j-1);
	int up = weight[i][j]+cost((i-1+rows)%rows,j-1);
	int down = weight[i][j]+cost((i+1)%rows,j-1);

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

	return memo[i][j]=min;
	}

void getPath(int chooser, int col){
	if(col==-1) return;
	getPath(path[chooser][col],col-1);
	cout<<chooser<<" ";
}


int main(){
	int ex[rows];

	// get the shortest path out of each cell on the right
	for(int i=0;i<rows;i++)
		ex[i]=cost(i,cols-1);

	//now find the smallest of them
	int min = ex[0];
	int chooser=0;//chooser of the column where it ends;
	for(int j=0;j<rows;j++){
		if(ex[j]<min) {
			min=ex[j];
			chooser=j;
		}//if
	}//for
	cout<<"the shortest path is of length "<<min << endl;		
	cout<<"The path is:\n";
	getPath(chooser,cols-1);
	cout<< endl;

	

return 0;
}

