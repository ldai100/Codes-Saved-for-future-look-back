#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int q[8], c = 0, counter = 0, i;
	q[0]=0;
nc: c++;
	if(c==8) goto print;
	q[c]=-1;
nr: q[c]++;
	if(q[c]==8) goto backTrack;
	for(i=0;i<c;i++)
		if(q[i]==q[c]||abs(q[c]-q[i])==c-i) goto nr;
	goto nc;
backTrack:
	c--;
	if(c==-1) return 0;
		goto nr;
print:
	counter++;
	cout<<"solution #" <<counter<<":"<<endl;
	for(i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i != q[j]) cout<<"-";
			else cout<<"Q";
		}
		cout << endl;
	}
	goto backTrack;
}
