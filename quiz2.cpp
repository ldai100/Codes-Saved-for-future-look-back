#include<iostream>
#include<vector>
using namespace std;

//without function;
vector<int> merge(vector<int> a, vector<int> b){
vector<int> c;
int helper[a.size()+b.size()], asize=a.size(), bsize=b.size(), temp;


//merging all the objects into one helper array;
for(int i=0;i<asize;i++){
	helper[i]=a.back();
	a.pop_back();
}

for(int j=asize;j<bsize;j++){
	helper[j]=b.back();
	b.pop_back();
}
//bubble sort the array;
for(int k=0;k<asize+bsize;k++)
	for(int l=0;l<asize+bsize-1;l++)
		if(helper[l]<helper[k]){
			temp = helper[k];
			helper[k]=helper[l];
			helper[l]=temp;
		}
//push everything in sorted helper array to vector c;
for(int o=0;o<asize+bsize;o++){
	c.push_back(helper[o]);
}

return c;
}

//with function
//sorting function
void sort(int *array,int size){
int temp;
for(int k=0;k<size;k++)
	for(int l=0;l<size-1;l++)
		if(array[l]<array[k]){
			temp = array[k];
			array[k]=array[l];
			array[l]=array[k];
		}

}

vector<int> merge2(vector<int> a, vector<int> b){
vector<int> c;
int helper[a.size()+b.size()], asize=a.size(), bsize=b.size();

//merging all the objects into one helper array;
for(int i=0;i<asize;i++){
	helper[i]=a.back();
	a.pop_back();
}

for(int j=asize;j<bsize;j++){
	helper[j]=b.back();
	b.pop_back();
}

sort(helper,asize+bsize);

//push everything in sorted helper array to vector c;
for(int o=0;o<asize+bsize;o++){
	c.push_back(helper[o]);
}

return c;

}


int main(){
return 0;
}
