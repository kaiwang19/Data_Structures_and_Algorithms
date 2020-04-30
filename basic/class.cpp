#include <iostream>
#include <string>

using namespace std;
using std::string;

class MyClass
{                    // The class
public:              // Access specifier
    int myNum;       // Attribute (int variable)
    string myString; // Attribute (string variable)
    void myMethod(); // Method/function declaration
};

// Method/function definition outside the class
void MyClass::myMethod()
{
    cout << "Hello World!";
}

void MyClassTest()
{
    MyClass myObj; // Create an object of MyClass

    // Access attributes and set values
    myObj.myNum = 15;
    myObj.myString = "Some text";

    // Print attribute values
    cout << myObj.myNum << "\n";
    cout << myObj.myString << "\n";

    // Call the method
    myObj.myMethod();
}

class MyCar
{
public:
    int speed(int maxSpeed);
};

int MyCar::speed(int maxSpeed)
{
    return maxSpeed;
}

void MyCarTest()
{
    MyCar myCar;              // Create an object of Car
    cout << myCar.speed(200); // Call the method with an argument
}

// A constructor in C++ is a special method that is automatically called when an object of a class is created.
class MyConstructor
{
public:
    MyConstructor()
    {
        cout << "Hello World!";
    }
};

void MyConstructorTest()
{
    MyConstructor myObj;
}

class Car
{                 // The class
public:           // Access specifier
    string brand; // Attribute
    string model; // Attribute
    int year;     // Attribute
    Car(string x, string y, int z)
    { // Constructor with parameters
        brand = x;
        model = y;
        year = z;
    }
};

void CarTest()
{
    // Create Car objects and call the constructor with different values
    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Ford", "Mustang", 1969);

    // Print values
    cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
    cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
}

/*
In C++, there are three access specifiers:

public - members are accessible from outside the class
private - members cannot be accessed (or viewed) from outside the class
protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
*/

class Employee
{
private:
    // Private attribute
    int salary;

public:
    // Setter
    void setSalary(int s)
    {
        salary = s;
    }
    // Getter
    int getSalary()
    {
        return salary;
    }
};

void EmployeeTest()
{
    Employee myObj;
    myObj.setSalary(50000);
    cout << myObj.getSalary();
}

/*
Inheritance
In C++, it is possible to inherit attributes and methods from one class to another. We group the "inheritance concept" into two categories:

> derived class (child) - the class that inherits from another class
> base class (parent) - the class being inherited from
*/
// Base class
class Vehicle
{
public:
    string brand = "Ford";
    void honk()
    {
        cout << "Tuut, tuut! \n";
    }
};

// Derived class (child)
class HisCar : public Vehicle
{
public:
    string model = "Mustang";
};

// Derived class (grandchild)
class TomCar : public HisCar
{
};

void HisCarTest()
{
    HisCar hisCar;
    hisCar.honk();
    cout << hisCar.brand + " " + hisCar.model << endl;

    TomCar tomCar;
    tomCar.honk();
    cout << tomCar.brand + " " + tomCar.model << endl;
}

// Base class
class OneClass
{
public:
    void myFunction()
    {
        cout << "Some content in parent class.";
    }
};

// Another base class
class MyOtherClass
{
public:
    void myOtherFunction()
    {
        cout << "Some content in another class.";
    }
};

// Derived class
class MyChildClass : public OneClass, public MyOtherClass
{
};

void MultipleInheTest()
{
    MyChildClass myObj;
    myObj.myFunction();
    myObj.myOtherFunction();
}

/*
[protected], is similar to [private].
But it can also be accessed in the inherited class
*/

// Base class
class Worker
{
protected: // Protected access specifier
    int salary;
};

// Derived class
class Programmer : public Worker
{
public:
    int bonus;
    void setSalary(int s)
    {
        salary = s;
    }
    int getSalary()
    {
        return salary;
    }
};

void ProgrammerTest()
{
    Programmer myObj;
    myObj.setSalary(50000);
    myObj.bonus = 15000;
    cout << "Salary: " << myObj.getSalary() << "\n";
    cout << "Bonus: " << myObj.bonus << "\n";
}

/*
Polymorphism
Polymorphism means "many forms", and it occurs when we have many classes that are related to each other by inheritance.

Inheritance lets us inherit attributes and methods from another class. 
Polymorphism uses those methods to perform different tasks. This allows us to perform a single action in different ways.
*/
// Base class
class Animal
{
public:
    void animalSound()
    {
        cout << "The animal makes a sound \n";
    }
};

// Derived class
class Pig : public Animal
{
public:
    void animalSound()
    {
        cout << "The pig says: wee wee \n";
    }
};

// Derived class
class Dog : public Animal
{
public:
    void animalSound()
    {
        cout << "The dog says: bow wow \n";
    }
};

void AnimalTest()
{
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    myAnimal.animalSound();
    myPig.animalSound();
    myDog.animalSound();
}

int main()
{
    MyClassTest();
    MyCarTest();
    MyConstructorTest();
    CarTest();
    EmployeeTest();
    HisCarTest();
    MultipleInheTest();
    ProgrammerTest();
    AnimalTest();

    return 0;
}