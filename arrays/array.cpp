#include <iostream>
#include <string>

using namespace std;
using std::string;

int main()
{
    int myNum[3] = {10, 20, 30};

    string myArray[4];

    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};

    for (int i = 0; i < 4; i++)
    {
        cout << cars[i] << "\n";
    }

    string myCars[] = {"Volvo", "BMW", "Ford"}; // size of array is always 3

    string hisCars[5] = {"Volvo", "BMW", "Ford"}; // size of array is 5, even though it's only three elements inside it
}

