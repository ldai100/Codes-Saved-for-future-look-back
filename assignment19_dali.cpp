#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
string input;
int NumOfLetters;

void findWinner(double score[],int size,char team[]){
	double min=score[0];
	int winningTeam=0;
	for(int i=0;i<size;i++)
		if(min>score[i]){
		min=score[i];
		winningTeam=i;
		}
cout<<"The winning team is team "<<team[winningTeam]<<" with a score of "<<min<<".\n\n";

}


void Sort(char *array, int size){  //bubble sort
char temp;
	for(int i=0;i<size;i++)
		for(int j=0;j<size-1;j++)
			if(array[j]>array[i]){
			temp = array[i];
			array[i]=array[j];
			array[j]=temp;
			}

}


//check if everything is uppercase;
bool checkUpper(string input){
for(int i=0;i<input.length();i++)
	if(!isupper(input[i])) return false;
return true;
}

//check to see if there are the same number of runners for each team;
//It does the checking and everything else!
bool checkTeam(string input){
char* Letters= new char[input.length()]();//worst case, all letters are used once;
NumOfLetters=0;

bool flag=true;
for(int i=0; i<input.length();i++){	//get same letters once to an array;
	for(int j=0;j<NumOfLetters;j++){
		if(Letters[j]==input[i]){
		flag=false;
		break;
		}
		else flag=true;
	}
if(flag){
	Letters[NumOfLetters]=input[i];
	NumOfLetters++;
}

}

int *CountLetters= new int[NumOfLetters]();
double *Scores=new double[NumOfLetters]();

for(int i=0; i<NumOfLetters;i++){
	for(int j=0;j<input.length();j++)
		if(Letters[i]==input[j])CountLetters[i]++; 
}

for(int i=0; i<NumOfLetters;i++){	//check to see if there are equal number of letters;
	if(CountLetters[i]!=CountLetters[0]){
		delete[] Scores;
		delete[] Letters;
		delete[] CountLetters;
		return false;
	}
}
Sort(Letters,NumOfLetters);

for(int i=0;i<input.length();i++)
	for(int j=0;j<NumOfLetters;j++)
		if(input[i]==Letters[j])Scores[j]+=i+1;

cout<<"\nThere are "<<NumOfLetters<<" teams.\n\n";
cout<<"Each team has "<<CountLetters[0]<<" runners.\n\n";
cout<<"Team	Score\n";
for(int i=0;i<NumOfLetters;i++)
	cout<<Letters[i]<<"	"<<(Scores[i]=Scores[i]/CountLetters[0])<<endl;

findWinner(Scores,NumOfLetters,Letters);

delete[] Scores;
delete[] Letters;
delete[] CountLetters;
return true;
}



int main(){
while(true){
cout<<"\nEnter a string of uppercase characters to indicate places(enter done to terminate):";
cin>>input;
if(input=="done") break;
if(!checkUpper(input)){
cout<<"Uppercase letters ONLY! try again.\n";
continue;
}
if(!checkTeam(input)){	//checks and do all the rest;
cout<<"Each team must have the same number of runners! try again.\n";
}

}//while
return 0;
}

