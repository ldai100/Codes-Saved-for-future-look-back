#include <iostream>
#include <cmath>
using namespace std;


bool check(int q[],int c){
	static int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};
	static int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
	for(int i=0; i<c;i++){
		if(q[i]==q[c]) return false;
		if((mp[i][q[c]]<mp[i][q[i]])&&(wp[q[c]][i]<wp[q[c]][c])) return false;
		if((mp[c][q[i]]<mp[c][q[c]])&&(wp[q[i]][c]<wp[q[i]][i])) return false;

	}
	return true;

}

void print(int q[]){
	static int c = 0;
	cout<<"Solution # " << ++c << endl;
	cout<< "M W"<< endl;
	for(int i=0; i<3;i++){
		cout<<i<<" "<<q[i]<<endl;
	}

}

void move(int q[],int i){
	if(i==3){
		print(q);
		return;
	}
	
	for(int j=0;j<3;j++){
		q[i]=j;
		if(check(q,i)) move(q,i+1);
	}

}
	

int main(){
	int q[3];
	move(q,0);

return 0;
}
