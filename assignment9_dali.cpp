#include <iostream>
using namespace std;

bool check(int q[],int c){
	static int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};
	static int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
	for(int i=0; i<c;i++){
		if(q[i]==q[c]) return false;
		if((mp[i][q[c]]<mp[i][q[i]])&&(wp[q[c]][i]<wp[q[c]][c])) return false;
		if((mp[c][q[i]]<mp[c][q[c]])&&(wp[q[i]][c]<wp[q[i]][i])) return false;
	} return true;
}

void print(int q[],int c){
	cout << "solution # "<< c << endl;
	cout <<"M W"<<endl;	
	for(int i=0;i<3;i++){
		cout<<i<<" "<<q[i]<< endl;
	}
}
void backTrack(int *c){
	--*c;
}
	

int main(){
	int q[3], c = 0, counter=0;
	q[0]=0;
while(true){
	c++;
	if(c==3){print(q,++counter);
		backTrack(&c);
	} else	q[c]=-1;
	
		while(true){
		 q[c]++;
		if(q[c]==3){  backTrack(&c);
			if(c==-1)return 0;
			else continue;
		}if(check(q,c)) break;
		}	
	}
}
