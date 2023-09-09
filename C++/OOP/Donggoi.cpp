#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
    int age;
    int score;
public:

    void setName(string name1)
    {
        name = name1;
    }

    string getName()
    {
        return name;
    }

};


int main()
{
    Person p1;
    p1.setName("Tinh");
    cout << p1.getName() << endl;

    return 0;
}
