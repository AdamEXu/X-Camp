#include <iostream>
using namespace std;
int main() {
   char op = '*';
   float a = 100045698398643986896000000, b= 1000089968349859345000;
   // cout << "Enter operator either + or - or * or /: ";
   // cin >> op;
   cout<<"The operator is "<<op<<endl;
   // cout << "Enter two operands: ";
   // cin>> a >> b;
   cout<<"a = "<<a<<" b = "<<b<<endl;
   switch(op) {
      case '+':
         cout <<"Sum of"<<a<<"and"<<b<<"is"<< a+b;
      break;
      case '-':
         cout <<"Difference of"<<a<<"and"<<b<<"is"<<a-b;
      break;
      case '*':
         cout <<"Product of"<<a<<"and"<<b<<"is"<<a*b;
      break;
      case '/':
         cout <<"Division of"<<a<<"and"<<b<<"is"<<a/b;
      break;
      default:
         // If the operator is other than +, -, * or /, error message is shown
         cout << "Error! operator is not correct";
      break;
   }
   return 0;
}