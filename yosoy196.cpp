#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include "BigIntegerLibrary.hh"

/*
 * This function receives a BigInteger n and checks if it is a palindrome
 * Return true if n is a palindrome, return false otherwise
 */
bool is_palindrome(BigInteger n){
std::string n1 = bigIntegerToString(n);
string n2=n1;
 reverse(n2.begin(),n2.end());
 return(n2==n1);
}
/*
 * This function receives a BigInteger n and returns the value of n plus the inverse of n.
 */
BigInteger apply196(BigInteger n){
  std::string n1 = bigIntegerToString(n);
  string n2=n1;
  reverse(n2.begin(),n2.end());
  return n+ stringToBigInteger(n2);
}

/*
 * Your main program goes below and should use the two functions above
 */
int main() {
  int lowest;
  int highest;
  int palindrome=0;
  int nolit=0;
  int lit=0;


  cout << "To do this program you should input a range of numbers" << endl;
  cout << "Please enter the lowest number: ";
  cin >> lowest;
  cout<< endl;
  cout << "Please enter the highest number: ";
  cin >> highest;
  cout<< endl;
  for (int copia = lowest; copia<=highest;copia++){
     BigInteger copia1=copia;
  if (is_palindrome (copia1) == true){
    palindrome = palindrome+1;
  }
  else{
    int count=0;
    bool islych = true;
    while (count<=30) {
    copia1=apply196(copia1);
    if (is_palindrome(copia1) == true){
      nolit = nolit+1;
      islych = false;
      break;
    }
    else {
      count=count+1;
    }
   }
   if(islych){
    lit = lit+1;
   }
  }
 }

cout<< "From the "<< lowest << " to the "<< highest << " there are: "<< endl;
cout<< "Palindrome: "<< palindrome<< endl;
cout<< "Non lychrels: "<< nolit<< endl;
cout<< "Lychrels: "<<lit<<endl;

  return 0;
}
