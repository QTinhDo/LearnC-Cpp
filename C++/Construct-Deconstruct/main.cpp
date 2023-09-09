#include <iostream>

using namespace std;


class Car {
public:
    ~Car()
    {
        cout << "Huy object" << endl;
    };


    Car()
    {
        cout << "Day la mac dinh" << endl;
    }

    Car(string brandCar)
    {
        brand = brandCar;
        cout << "Day la constructor 1 tham so" << endl;
    }

    Car(string brandCar, string colorCar)
    {
        brand = brandCar;
        color = colorCar;
        cout << "Day la constructor 2 tham so" << endl;
    }

    string brand;
    string color;



    void showInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Color: " << color << endl;
    }

};




int main()
{
    //Car car1("Lambogini","Red");
    Car* car1 = new Car("Lambogini","Red");
    cout << "Day la dong cuoi" << endl;
       delete(car1);


    return 0;
}
