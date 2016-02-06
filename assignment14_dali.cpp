#include <iostream>
#include<vector>

using namespace std;
int main(){
	vector<int> t[3]; // three towers A,B,C represented as an array of 3 vectors
	int n, candidate,to, from, move=0; // move counts the move number
	cout<<"Please enter an ODD number of rings to move: ";
	cin>>n;
	cout<<endl;
 //intitialize the 3 towers
	for(int i=n+1;i>0;i--)
		t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);
 // initialize towers and candidate
	from=0;
	//setting to-tower depending on n
	if(n%2==1)to=1;
	else to=2;
	candidate=1;

while( t[1].size()<n+1){

	cout<<"move number "<<++move<<": Transfer ring "<<candidate<<" from tower "<< char(from+65)<<" to tower "<<char(to+65)<<endl;

	t[to].push_back(candidate);

	t[from].pop_back();
	//setting new from tower
	if(t[(to+1)%3].back()<t[(to+2)%3].back())
		from=(to+1)%3;
	else from=(to+2)%3;

	//setting new candidate
	candidate=t[from].back();
	
	//setting new to tower
	if(n%2==1){
		if(candidate%2==1) 
			to=(from+1)%3;
		else to=(from+2)%3;
	}else {
		if(candidate%2==0)
			to=(from+1)%3;
		else to=(from+2)%3;
	}


}//while
return 0;
}
