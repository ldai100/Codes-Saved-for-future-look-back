#include <iostream>
using namespace std;

class Rat{
private:
	int n;
	int d;
public:

//default constructor
Rat(){
n=0;
d=1;
}
//2 parameter constructor
Rat(int i, int j){
n=i;
d=j;
}

//conversion constructor
Rat(int i){
n=i;
d=1;
}

//accessor functions
int getN(){return n;}
int getD(){return d;}

void setN(int i){n=i;}
void setD(int i){d=i;}

//arithmetic opertors

Rat operator+(Rat r){
Rat t;
t.n=n*r.d+d*r.n;
t.d=d*r.d;
t.reduce();
return t;
}

Rat operator-(Rat r){
Rat t;
t.n=n*r.d-d*r.n;
t.d=d*r.d;
t.reduce();
return t;
}

Rat operator*(Rat r){
Rat t;
t.n=n*r.n;
t.d=d*r.d;
t.reduce();
return t;
}

Rat operator/(Rat r){
Rat t;
t.n=n*r.d;
t.d=d*r.n;
t.reduce();
return t;
}

void reduce(){
int gcd=1;
for(int i=2;i<=min(n,d);i++)
	if(n%i==0&&d%i==0) gcd=i;
n=n/gcd;
d=d/gcd;

}

int min(int a,int b){
if(a>b) return b;
else return a;

}

//2 over loaded i/o operators
friend ostream& operator<<(ostream& os,Rat r);
friend istream& operator>>(istream& is,Rat& r);


}; //end Rat

ostream& operator<<(ostream& os, Rat r){
r.reduce();
if(r.d>r.n) os<<r.n<<"/"<<r.d<<endl;  //if numerator is less, print out regularly
if(r.d==r.n&&r.d!=0)os<<1<<endl;  //if both equal, it equals to 1. except r.d = 0;
if(r.n%r.d==0)os<<r.n/r.d;
if(r.d<r.n&&r.n%r.d!=0)os<<r.n/r.d<<" "<<r.n%r.d<<"/"<<r.d<<endl;
return os;
}

istream& operator>>(istream& is, Rat& r){
is>>r.n>>r.d;
return is;
}

int main(){
Rat x(1,2),y(2,3),z;
z=x+y;
cout << z;
z=x*y;
cout<<z;
z=x-y;
cout<<z;
z=x/y;
cout<<z;

x.setN(3);
y.setD(2);
z=x+y;
cout<<z;

cin>>x;
cout<<x;


return 0;
}
