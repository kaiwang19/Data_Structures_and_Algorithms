#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using std::string;

//Function declaration
void helloworld();
void variables();
void input();
void operators();
void strings();
void math();
void conditions();
void switches();
void whiles();
void forloop();

int main()
{
    // helloworld();
    // variables();
    // input();
    // operators();
    // strings();
    // math();
    // conditions();
    // switches();
    // whiles();
    forloop();

    return 0;
}

/*
First function
*/
void helloworld()
{
    std::cout << "Hello world, this is complex~" << std::endl;

    //Both \n and endl are used to break lines.
    cout << "Hello world, we can simplify it!" << endl;

    //However, \n is used more often and is the preferred way.
    cout << "Hello world, we can simplify it!\n";

    cout << "Hello world!";
}

/**
In C++, there are different types of variables (defined with different keywords), for example:

int    [4 bytes] - stores integers (whole numbers), without decimals, such as 123 or -123
float  [8 bytes] - Stores fractional numbers, containing one or more decimals. Sufficient for storing 7 decimal digits, such as 19.99 or -19.99
double [8 bytes] - Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits (safer), such as 19.99 or -19.99
char   [1 byte]  - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
bool   [1 byte]  - stores values with two states: true or false
string [n bytes] - stores text, such as "Hello World". String values are surrounded by double quotes

========
The general rules for constructing names for variables (unique identifiers) are:

Names can contain letters, digits and underscores
Names must begin with a letter or an underscore (_)
Names are case sensitive (myVar and myvar are different variables)
Names cannot contain whitespaces or special characters like !, #, %, etc.
Reserved words (like C++ keywords, such as int) cannot be used as names
*/
void variables()
{

    int myAge = 15;               // Integer (whole number without decimals)F
    int x = 5, y = 6, z = 50;     // declare more than one variable of the same type
    const int myConstantNum = 15; // unchangeable and read-only. myNum will always be 15
    cout << "I am " << myAge << " years old.\n";

    double myDoubleNum = 5.99; // Floating point number (with decimals)
    float myFloatNum = 6.01;   // Floating point number (with decimals), safer
    float f1 = 35e3;           // Scientific Numbers
    double d1 = 12E4;          // Scientific Numbers

    bool isCodingFun = true;
    bool isFishTasty = false;
    cout << isCodingFun << "\n"; // Outputs 1 (true)
    cout << isFishTasty << "\n"; // Outputs 0 (false)

    char myLetter = 'D';         // Character
    cout << myLetter << "\n";    // Output Character
    char a = 65, b = 66, c = 67; // ASCII values
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";

    string myText = "Hello"; // String (text)
    cout << myText;
}

void input()
{
    int x;
    cout << "Type a number: ";       // Type a number and press enter
    cin >> x;                        // Get user input from the keyboard
    cout << "Your number is: " << x; // Display the input value

    string fullName;
    cout << "Type your full name: ";
    getline(cin, fullName); // read a line of text
    cout << "Your name is: " << fullName;
}

void operators()
{
    int x = 16;

    // x %= 3; // x = x % 3
    // cout << x << endl;

    // x &= 3; // x = x & 3 , 0 = 10000 & 11
    // cout << x << endl;

    // x = x | 3;  // 10011 = 10000 | 11
    // cout << x << endl;

    // x ^= 3; // x = x ^ 3, XOR, 10011 = 10000 | 11
    // cout << x << endl;

    // x >>= 3; // x = x >> 3
    // cout << x << endl;

    // x <<= 3; // x = x << 3
    // cout << x << endl;
}

void strings()
{
    string firstName = "John ";
    string lastName = "Doe";

    // concatenation
    string fullName = firstName + " " + lastName;
    cout << fullName << endl;
    fullName = firstName.append(lastName);
    cout << fullName << endl;

    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The length of the txt string is: " << txt.length() << endl;
    cout << "The size of the txt string is: " << txt.size() << endl;
}

void math()
{
    // cout << max(5, 10) << endl;
    // cout << min(5, 10) << endl;
    cout << sqrt(64) << endl;              //  square root
    cout << round(2.6) << endl;            //  rounds a number
    cout << log(2) << endl;                //  natural logarithm
    cout << abs(-1) << endl;               //  Returns the absolute value of x
    cout << acos(0.5) << endl;             //	Returns the arccosine of x, in radians
    cout << asin(0.5) << endl;             //	Returns the arcsine of x, in radians
    cout << atan(1) << endl;               //	Returns the arctangent of x, in radians
    cout << cbrt(8) << endl;               //	Returns the cube root of x
    cout << ceil(2.9) << endl;             //	Returns the value of x rounded up to its nearest integer
    cout << cos(30) << endl;               //	Returns the cosine of x, in radians
    cout << cosh(45) << endl;              //	Returns the hyperbolic cosine of x, in radians
    cout << exp(2) << endl;                //	Returns the value of Ex
    cout << expm1(3) << endl;              //	Returns ex -1
    cout << fabs(-1.2) << endl;            //	Returns the absolute value of a floating x
    cout << fdim(-2, -9) << endl;          //	Returns the positive difference between x and y
    cout << floor(1.9) << endl;            //	Returns the value of x rounded down to its nearest integer
    cout << hypot(3, 4) << endl;           //	Returns sqrt(x2 +y2) without intermediate overflow or underflow
    cout << fma(2.3, 7.127, 6.32) << endl; //	Returns x*y+z without losing precision
    cout << fmax(9.123, 3.43) << endl;     //	Returns the highest value of a floating x and y
    cout << fmin(9.123, 3.43) << endl;     //	Returns the lowest value of a floating x and y
    cout << fmod(9.123, 3.43) << endl;     //	Returns the floating point remainder of x/y
    cout << pow(2, 3) << endl;             //	Returns the value of x to the power of y
    cout << sin(45) << endl;               //	Returns the sine of x (x is in radians)
    cout << sinh(0.5) << endl;             //	Returns the hyperbolic sine of a double value
    cout << tan(30) << endl;               //	Returns the tangent of an angle
    cout << tanh(1) << endl;               //	Returns the hyperbolic tangent of a double value
}

void conditions()
{
    int x = 20;
    int y = 18;
    if (x > y)
    {
        cout << "x is greater than y\n";
    }

    int time = 22;
    if (time < 10)
    {
        cout << "Good morning.\n";
    }
    else if (time < 20)
    {
        cout << "Good day.\n";
    }
    else
    {
        cout << "Good evening.\n";
    }

    string result = (time < 18) ? "Good day." : "Good evening.";
    cout << result << endl;
}

void switches()
{
    int day = 4;
    switch (day)
    {
    case 6:
        cout << "Today is Saturday";
        break; // A break can save a lot of execution time because it "ignores" the execution of all the rest of the code in the switch block.
    case 7:
        cout << "Today is Sunday";
        break;
    default:
        cout << "Looking forward to the Weekend";
    }
}

void whiles()
{
    int i = 0;
    while (i < 5)
    {
        cout << i << "\n";
        i++;
    }

    int j = 0;
    do
    {
        cout << j << "\n";
        j++;
    } while (j < 5);
}

void forloop()
{
    for (int i = 0; i <= 10; i = i + 2)
    {
        cout << i << "\n";
    }

    cout << "====\n";

    for (int i = 0; i < 10; i++)
    {
        if (i == 4)
        {
            break; // The break statement can also be used to jump out of a loop.
        }
        cout << i << "\n";
    }

    cout << "====\n";

    for (int i = 0; i < 10; i++)
    {
        if (i == 4)
        {
            continue; // The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.
        }
        cout << i << "\n";
    }
}
