#include<iostream>
using namespace std;

class Complex{
private:
	//complex number= a+bi where a is real and bi is imaginary;
	//in this case I guess i = bi;
	double r;  //real number;
	double i;  //imaginary number;
public:
	//default constructor given by the problem;
	Complex();
//overloading +;
Complex operator+(Complex t){
	Complex p;
	p.r=r+t.r;
	p.i=i+t.i;
return p;
}
//overloading -; a+bi - a - bi=a-a+bi-bi;
Complex operator-(Complex t){
	Complex p;
	p.r=r-t.r;
	p.i=i-t.i;
return p;	
}

//overloading multiplication: (a+bi)*(c+di)=ac+adi+bci+bidi(-bd)
Complex operator*(Complex t){
	Complex p;
	p.r=r*t.r+i*t.i;
	p.i=r*t.i+t.r*i;
return p;
}

//overloading division
Complex operator/(Complex t){
	Complex p;
	p.r=((r*t.r)-(i*t.i))/((t.r*t.r)-(t.i*t.i));
	p.i=(t.r*i+r*t.i)/((t.r*t.r)-(t.i*t.i));
return p;
}

//getters and setters;
double getR(){return r;}
double getI(){return i;}
void setR(double n){r=n;}
void setI(double n){i=n;}

friend ostream& operator<<(ostream& os, Complex c){
os<<c.r<<"+"<<c.i;  //in the form of a+bi;
return os;
}

friend istream& operator>>(istream& is, Complex& c){
is>>c.r>>c.i;
return is;
}

};//Complex class


int main(){


return 0;
}
