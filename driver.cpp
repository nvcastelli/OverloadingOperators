// main.cpp -- Bob Myers
// Rewritten by Dr.David Gaitros 
//
// Driver program to demonstrate the behavior of the Mixed class
// 
// You can add more tests of your own, or write other drivers to test your
// class -- this is NOT a comprehensive set of tests.  This is just a
// sample, which should help check whether your function declarations are
// appropriate, and can test a few sample cases.

#include <iostream>
#include "mixed.h"

using namespace std;

int main()
{

  // demonstrate behavior of the two constructors and the << overload
  
  Mixed  m1(0,-35,10), m2(-1,2,4), m3(4), m4(-11), m5(2,2,3), m6(-2,2,3);
  Mixed  m7(0,2,4), m8(0,12,24); 
  Mixed  m9(1,2,3), m10(1,90,100);
  Mixed  x(1,1,2), y(2,3,4);  

  cout<< " Declaring m1 through m10 for testing " << endl;


  cout <<"M1 ->" <<m1 <<endl;
  cout <<"M2 ->" <<m2 <<endl;
  cout <<"m3 ->" <<m3<<endl;
  cout <<"m4 ->" <<m4<<endl;
  cout <<"m5 ->" <<m5<<endl;
  cout <<"m6 ->" <<m6<<endl;
  cout <<"m7 ->" <<m7<<endl;
  cout <<"m8 ->" <<m8<<endl;
  cout <<"m9 ->" <<m9<<endl;
  cout <<"m10->" <<m10<<endl;
  
  cout << "m1 + 10=" << m1+10 << endl;
  cout << "m1 - 10=" << m1-10 << endl;
  cout << "m5 / (-2)=" << m5/(-2) << endl;
  cout << "m5 * 2=" << m5*2 << endl;
  cout << "10 + m1 ="<< 10+m1<< endl; 
 
  
  if(m3>3) cout << "M3 "<< m3 <<" is greater than 3" << endl ;
      else cout << "m3" << m3 << "is not greater than 3" << endl; 

  if(m7==m8) cout << "M7 "<<m7 <<" equal to m8 " << m8 << endl;
      else cout << "M7" << m7 << "is not equal to m8" << m8 << endl; 
  if(m9<=m10) cout << "M9 "<< m9 <<" is less  than or equal to m10"<<m10<< endl ;
  else cout << "M7" << m7 << "is less than m10" << m10 << endl; 

  
  char answer;
  
  
  // Trying Simplify
  cout << "Test of Simplify Function" << endl;
  cout << "m1 is " << m1 << " Simplified is " ; 
  m1.Simplify();
  cout<< m1<< endl;

  // Trying ToFraction
  cout << "Test of ToFraction" << endl;
  cout << "m5 is " << m5 << " converted to fraction is " ;
  
  m5.ToFraction();
  cout << m5 << endl;
  
 
  m1=m1+4; 
  cout << "M1 with the constant 4 added is " << m1 << endl; 

  // demonstrate >> overload
   
  cout << "Testing Logical operators " << endl;
  cout << "X is defined as " << x << endl;
  cout << "Y is defined as " << y << endl; 
    // demonstrate comparison overloads
  if (x < y)	cout << "(x < y) is TRUE\n";
  if (x > y)	cout << "(x > y) is TRUE\n";
  if (x <= y)	cout << "(x <= y) is TRUE\n";
  if (x >= y)	cout << "(x >= y) is TRUE\n";
  if (x == y)	cout << "(x == y) is TRUE\n";
  if (x != y)	cout << "(x != y) is TRUE\n";
 
  // demonstrating Evaluate
  cout << "\nDecimal equivalent of " << x << " is " << x.Evaluate() << '\n';
  cout << "Decimal equivalent of " << y << " is " << y.Evaluate() << "\n\n";
  
  // demonstrating arithmetic overloads
  cout << "Testing Arithmetic operators " << endl; 
  cout << "(x + y) = " << (x + y) << '\n';
  cout << "(x - y) = " << (x - y) << '\n';
  cout << "(x * y) = " << (x * y) << '\n';
  cout << "(x / y) = " << (x / y) << '\n';
  
  // demonstrating arithmetic that uses conversion constructor
  //  to convert the integer operand to a Mixed object
  cout << "Demonstrating that the constructor was done properly" << endl;
  cout << endl; 
  cout << "(x + 10) = " << x + 10 << '\n';
  cout << "(x - 4) = " << x - 4 << '\n';
  cout << "(x * -13) = " << x * -13 << '\n';
  cout << "(x / 7) = " << x / 7 << '\n';

  cout << "Testing the >> overload operator " << endl;
  cout << "Enter in 5 6/7 " ;
  cin >>m1;
  cin >> m2;
  cout << "\n " << m1 << " was entered " << endl;

  cout << "	rollin'" <<endl;

  cout << m1++;
  cout << ++m1;
  cout << m2--;
  cout << --m2;
  
  return 0;
}




