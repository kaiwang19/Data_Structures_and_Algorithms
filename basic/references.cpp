#include <iostream>
#include <string>

using namespace std;
using std::string;

int main()
{
    string food = "Pizza"; // food variable
    string &meal = food;   // reference to food
    cout << food << "\n";  // Outputs Pizza
    cout << meal << "\n";  // Outputs Pizza

    // get the memory address of a variable;
    cout << &food << "\n";; // Outputs 0x6dfed4
    cout << &meal << "\n";; // Outputs 0x6dfed4
}
