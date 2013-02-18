//mixed.cpp file
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "mixed.h"

using namespace std;

//prototype for LCD function
int lcd(int, int);

Mixed :: Mixed(const int n)
{

	integer = n;
	numerator = 0;
	denominator = 1;
}

Mixed :: Mixed(const int Int, const int Num, const int Den)
{
	//setting values
	integer = Int;
	numerator = Num;
	denominator = Den;

	//catches errors: ex-den. is zero or more than one negative number
	if((Den < 0 && Int < 0)|| (Den < 0 && Num < 0) || 
	  (Int < 0 && Num < 0) || (Den < 0 && Num < 0 && Int <0) 
	  || (Den == 0))
	{
		//sets to default value if an error is cught
		integer = 0;
		denominator = 1;
		numerator = 0;
	}
	
}

// *****************************************************************
// * Function Name: Evaluate *
// * Description: Makes number a decimal
// * Parameter Description: none
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
double Mixed :: Evaluate()
{
	double fraction;

	//casts values to doubles then does the calculations
	fraction = double(integer) + (double(numerator)/double(denominator));

	return fraction;
}

// *****************************************************************
// * Function Name: ToFraction *
// * Description: changes mixed fraction to an improper fraction
// * Parameter Description: none
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
void Mixed :: ToFraction()
{
	//small error checking
	if(integer <0)
	{
		//fixes value if more than one negative
		integer=integer*-1;
		int newnum((denominator*integer)+numerator);
		numerator = newnum;
		integer = 0;
	}
	else
	{
		//if values check out carries on as if normal object
		int newnum((denominator*integer)+numerator);
		numerator = newnum;
		integer = 0;
	}
}


// *****************************************************************
// * Function Name: Simplify *
// * Description: reduces fraction
// * Parameter Description: none
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
void Mixed :: Simplify()
{
	//simpliefies fraction if possible using the lcd function
	int LCD = lcd(numerator, denominator);
	numerator = numerator/LCD;
	denominator= denominator/LCD;
	
}

// *****************************************************************
// * Function Name: overloading the >> opperator *
// * Description: allows use of the >> with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
std :: istream& operator >> (std :: istream& newin, Mixed& i)
{	
	int I, N, D;
	cout << "Please enter a mixed number in the form:"<<
			"integer numerator/denominator: "<<endl;
	scanf("%d %d/%d", &I, &N, &D);


	//error checking
	if((D < 0 && I < 0)|| (D < 0 && N < 0) || 
	  (I < 0 && N < 0) || (D < 0 && N < 0 && I <0) 
	  || (D == 0))
	{
		//setting values to default
		i.setInt(0);
		i.setNum(0);
		i.setDen(1);
	}
	else
	{	
		//if good numbers,sets values to entered numbers
		i.setInt(I);
		i.setNum(N);
		i.setDen(D);
	}

	return newin;
}

//accesors for private data
int Mixed :: getInt() { return integer; }
int Mixed :: getNum() { return numerator; }
int Mixed :: getDen() { return denominator; }
int Mixed :: getInt() const { return integer; }
int Mixed :: getNum() const { return numerator; }
int Mixed :: getDen() const { return denominator; }


void Mixed :: setInt(int i) { integer = i; }
void Mixed :: setNum(int n) { numerator = n; }
void Mixed :: setDen(int d) { denominator = d; }

// *****************************************************************
// * Function Name: overloading the << opperator *
// * Description: allows use of the << with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
std :: ostream& operator << (std :: ostream& newout, const Mixed& o)
{
	//grabs values from the Mixed class using the << overload operator
	
	if (o.getInt() == 0)//prints nothing for the integer if its value is zero
		newout << o.getNum() << '/'<< o.getDen() << endl;
	else if (o.getNum() == 0)//only prints integer if Num is zero
		newout << o.getInt() << endl;
	else//prints normal mixed fraction
		newout << o.getInt() << ' ' << o.getNum() << '/'<< o.getDen() << endl;

	return newout;
}

// *****************************************************************
// * Function Name: overloading the < comparison *
// * Description: allows use of the < with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool operator < (const Mixed m1, const Mixed m2)
{
	//declaring temp values
	Mixed temp = m1;
	Mixed temp2 = m2;
	int lhs, rhs;

	//converts temp values to fractions
	temp.ToFraction();
	temp2.ToFraction();

	//calculates values
	lhs = temp.numerator*temp2.denominator;
	rhs = temp2.numerator*temp.denominator;

	if (lhs<rhs)
		return true;
	else 
		return false;

}

// *****************************************************************
// * Function Name: overloading the > comparison *
// * Description: allows use of the > with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool operator > (const Mixed m1, const Mixed m2)
{
	//declaring temp values
	Mixed temp = m1;
	Mixed temp2 = m2;
	int lhs, rhs;

	//stting temps to fractions
	temp.ToFraction();
	temp2.ToFraction();

	//calculating values
	lhs = temp.numerator*temp2.denominator;
	rhs = temp2.numerator*temp.denominator;

	if (lhs>rhs)
		return true;
	else 
		return false;
}

// *****************************************************************
// * Function Name: overloading the <= comparison *
// * Description: allows use of the <= with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool operator <= (const Mixed m1, const Mixed m2)
{
	//declaring temp values
	Mixed temp = m1;
	Mixed temp2 = m2;
	int lhs, rhs;

	//converting temps to improper fractions
	temp.ToFraction();
	temp2.ToFraction();

	//Doing calculations
	lhs = temp.numerator*temp2.denominator;
	rhs = temp2.numerator*temp.denominator;

	if (lhs<=rhs)
		return true;
	else 
		return false;	
}

// *****************************************************************
// * Function Name: overloading the >= comparison *
// * Description: allows use of the >= with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool operator >= (const Mixed m1, const Mixed m2)
{
	//declaring temp values
	Mixed temp = m1;
	Mixed temp2 = m2;
	int lhs, rhs;

	//converting temps to improper fractions
	temp.ToFraction();
	temp2.ToFraction();

	//Calculations
	lhs = temp.numerator*temp2.denominator;
	rhs = temp2.numerator*temp.denominator;

	if (lhs>=rhs)
		return true;
	else 
		return false;
}
// *****************************************************************
// * Function Name: overloading the == comparison *
// * Description: allows use of the == with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool operator == (const Mixed m1, const Mixed m2)
{
	//declaring temp values
	Mixed temp = m1;
	Mixed temp2 = m2;
	int lhs, rhs;

	//converting values to fractions
	temp.ToFraction();
	temp2.ToFraction();

	//Calculations
	lhs = temp.numerator*temp2.denominator;
	rhs = temp2.numerator*temp.denominator;

	if (lhs==rhs)
		return true;
	else 
		return false;	
}

// *****************************************************************
// * Function Name: overloading the != comparison *
// * Description: allows use of the != with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool operator != (const Mixed m1, const Mixed m2)
{
	//declaring temp values
	Mixed temp = m1;
	Mixed temp2 = m2;
	int lhs, rhs;

	//converting temps 
	temp.ToFraction();
	temp2.ToFraction();

	//Great Scott! More calculating
	lhs = temp.numerator*temp2.denominator;
	rhs = temp2.numerator*temp.denominator;

	if (lhs!=rhs)
		return true;
	else 
		return false;	
}

// *****************************************************************
// * Function Name: overloading the + opperator *
// * Description: allows use of the + with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
const Mixed operator + (const Mixed &m1, const Mixed &m2) 
{

	//declaring temp values
	Mixed result;

	Mixed temp, temp2;
	temp = m1;
	temp2 = m2;
	temp.ToFraction();
	temp2.ToFraction();

	//calculating individual Mixed fraction Values
	result.denominator = (temp.denominator*temp2.denominator);
	result.numerator = (temp.numerator*temp2.denominator)+(temp2.numerator*temp.denominator);

	//if both num and int are negative, takes abs val of num
	if(result.integer < 0 && result.numerator < 0)
		result.numerator = (result.numerator)*-1;
	
	//Simplify end result
	result.Simplify();

	return result;
}

// *****************************************************************
// * Function Name: overloading the - opperator *
// * Description: allows use of the - with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
const Mixed operator - (const Mixed &m1, const Mixed &m2)
{
	//declaring temp values
	Mixed result;

	Mixed temp, temp2;
	temp = m1;
	temp2 = m2;
	temp.ToFraction();
	temp2.ToFraction();

	//calculating individual values of the mixed fraction
	result.denominator = (temp.denominator*temp2.denominator);
	result.numerator = (temp.numerator*temp2.denominator)-(temp2.numerator*temp.denominator);

	//makes num positive if both int and num are neg
	if(result.integer < 0 && result.numerator < 0)
		result.numerator = (result.numerator)*-1;

	result.Simplify();

	return result;

}

// *****************************************************************
// * Function Name: overloading the * opperator *
// * Description: allows use of the * with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
const Mixed operator * (const Mixed &m1, const Mixed &m2)
{
	//declaring temp values
	Mixed temp, temp2;
	temp=m1;
	temp2=m2;
	Mixed result;

	//converts temp to fractions
	temp.ToFraction();
	temp2.ToFraction();

	result.numerator = temp.numerator*temp2.numerator;
	result.denominator = temp.denominator*temp2.denominator;

	if(result.integer < 0 && result.numerator < 0)
		result.numerator = (result.numerator)*-1;

	return result;
}

// *****************************************************************
// * Function Name: overloading the / opperator *
// * Description: allows use of the / with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
const Mixed operator / (const Mixed &m1, const Mixed &m2)
{	
	//declaring temp values
	Mixed temp, temp2, temp3;
	temp=m1;
	temp2=m2;
	Mixed result;

	//converting temps to fractions
	temp.ToFraction();
	temp2.ToFraction();

	//assigning temp values
	temp3=temp2;
	temp2.numerator=temp3.denominator;
	temp2.denominator=temp3.numerator;

	//Calculations...
	result.numerator = temp.numerator*temp2.numerator;
	result.denominator = temp.denominator*temp2.denominator;

	if(result.integer < 0 && result.numerator < 0)
		result.numerator = (result.numerator)*-1;

	return result;
}

// *****************************************************************
// * Function Name: overloading the pre++ opperator *
// * Description: allows use of the pre++ with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
Mixed Mixed :: operator ++ ()
{
	//changes value first then returns value
	++integer;
	
	return *this;
}

// *****************************************************************
// * Function Name: overloading the post++ opperator *
// * Description: allows use of the post++ with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
Mixed Mixed :: operator ++ (int)
{
	//returns copy then changes
	Mixed temp =*this;

	integer++;
	
	return temp;
}

// *****************************************************************
// * Function Name: overloading the pre-- opperator *
// * Description: allows use of the pre-- with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
Mixed Mixed :: operator -- ()
{
	//changes value first then returns value
	integer--;
	
	return *this;
}

// *****************************************************************
// * Function Name: overloading the post-- opperator *
// * Description: allows use of the post-- with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
Mixed Mixed :: operator -- (int)
{
	//returns copy then changes
	Mixed temp =*this;

	--integer;
	
	return temp;
}



// *****************************************************************
// * Function Name: overloading the < opperator *
// * Description: allows use of the < with objects
// * Date: 02/15/2013 Date of function modification) */
// * Author: Nicholas Castelli 
// * Inspired by Dr. gaitros, who was inspired by Eulcid
// *****************************************************************
int lcd(int a, int b)
{
	int temp;
	while(b!=0)//Does not run if Den == 0
	{
		temp = b;
		b=a%b;
		a = temp;
	}

	return a;
}


