#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(int argc, char *argv[]){
	double x,y;
	int count=0;
	srand(time(NULL));
	for(int i=0;i<1000000;i++){
		x=(float)rand()/RAND_MAX;
		y=(float)rand()/RAND_MAX;
		if(x*x+y*y<=1) count++;
	}
	cout <<"PI = "<<4*(float)count/1000000<<endl;

	return 0;

}
