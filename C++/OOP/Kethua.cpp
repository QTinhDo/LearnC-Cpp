#include <iostream>

using namespace std;

class Person {
public:
    virtual void showInfo()
    {
        cout << "I am Person";
    }


};

class Student : public Person {
public:
    void showInfo()
    {
        cout << "I am Student";
    }
};


int main()
{
    Person* sv = new Student;
    sv->showInfo();

    return 0;
}
