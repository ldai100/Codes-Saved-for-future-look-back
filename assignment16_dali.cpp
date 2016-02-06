#include <iostream>
#include <cmath>
using namespace std;


bool check(int q[],int c,int n){
	for(int i=0; i<c;i++){
		if(abs(q[c]%n-q[i]%n)==abs(q[c]/n-q[i]/n)) return false;
	} return true;
}
void backTrack(int *c){
	--*c;
}

int main(){
	int c = 0,  counter, n = 0, k = 0, t;
	

label: //multiple while loops, so I'll use goto to come back here.
while(n!=-1){
	counter = 0;
	cout << "Enter n for a nXn board, -1 to exit:";
	cin>>n;
	if(n==-1) break;
	cout << "Enter number of bishops:";
	cin>>k;
	if(n<k) continue;
	int *q = new int[k];
	q[0]=0;
	cout<<n<<" "<<k;
	t=-1; //initialing t;
while(true){
	c++;
	if(c==k){counter++;
		backTrack(&c);
	} else	q[c]=t;  //start at t;
	
		while(true){
		 q[c]++;
		if(q[c]==n*n){  backTrack(&c);
			if(c==-1){
			cout<<" " <<counter<<endl;
			delete []q;
			goto label; // restart the process
			}else continue;
		}
		if(check(q,c,n)) {
			t = q[c]; //updating t;
			break;
		}
		}	
	}
}
return 0;
}
