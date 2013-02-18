/*
Name: Nicholas Castelli
Program: Programming Assignment #3
Recitation Time: Thursday 5:15-6:30
*/
#ifndef MIXED_H
#define MIXED_H
#include <iostream>
using namespace std;

class Mixed
{
public:

	//default constructors
	Mixed(const int n = 0);

	Mixed(const int Int, const int Num, const int Den);

	double Evaluate();

	void ToFraction();

	void Simplify();
	
	//accesor functions
	int getInt() const;
	int getNum() const;
	int getDen() const;
	int getInt();
	int getNum();
	int getDen();
	void setInt(int);
	void setNum(int);
	void setDen(int);

	//overloads the '>>' operator
	friend std :: istream& operator >> (std::istream& newin, Mixed& i);

	//overloads the '<<' operator
	friend std :: ostream& operator << (std::ostream& newout, const Mixed& o);

	//overloads the '<' operator
	friend bool operator < (const Mixed m1,const Mixed m2);

	//overloads the '>' operator
	friend bool operator > (const Mixed m1, const Mixed m2);

	//overloads the '<=' operator
	friend bool operator <= (const Mixed m1, const Mixed m2);

	//overloads the '>=' operator
	friend bool operator >= (const Mixed m1, const Mixed m2);

	//overloads the '==' operator
	friend bool operator == (const Mixed m1, const Mixed m2);

	//overloads the '!=' operator
	friend bool operator != (const Mixed m1, const Mixed m2);

	//overloads the '+' operator
	friend const Mixed operator + (const Mixed &m1, const Mixed &m2);

	//overloads the '-' operator
	friend const Mixed operator - (const Mixed &m1, const Mixed &m2);

	//overloads the '*' operator
	friend const Mixed operator * (const Mixed &m1, const Mixed &m2);

	//overloads the '/' operator
	friend const Mixed operator / (const Mixed &m1, const Mixed &m2);

	//overloads the 'pre ++' operator
	 Mixed operator ++ ();

	 //overloads the 'post ++' operator
	 Mixed operator ++ (int);

	 //overloads the 'pre --' operator
	 Mixed operator -- ();

	 //overloads the 'post --' operator
	 Mixed operator -- (int);

private: 
	//private data
	int integer;
	int numerator;
	int denominator;
	
};

#endif


