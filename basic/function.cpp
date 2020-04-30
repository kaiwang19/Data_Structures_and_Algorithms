#include <iostream>
#include <string>

using namespace std;
using std::string;

void myName(string fname = "Tom")
{
    cout << fname << " Refsnes\n";
}

void myAge(string fname, int age)
{
    cout << fname << " Refsnes. " << age << " years old. \n";
}

// Pass by references
void swapNums(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

int plusFuncInt(int x, int y) {
  return x + y;
}

//With function overloading, multiple functions can have the same name with different parameters
double plusFuncDouble(double x, double y) {
  return x + y;
}

int main()
{
    myName();
    myName("Liam");
    myName("Jenny");
    myName("Anja");

    myAge("Liam", 3);
    myAge("Jenny", 14);
    myAge("Anja", 30);

    int firstNum = 10;
    int secondNum = 20;
    cout << "Before swap: "
         << "\n";
    cout << firstNum << " " << secondNum << "\n";
    swapNums(firstNum, secondNum);
    cout << "After swap: "
         << "\n";
    cout << firstNum << " " << secondNum << "\n";

    return 0;
}
