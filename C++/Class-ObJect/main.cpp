#include <iostream>

using namespace std;


class Car {
public:
    static Car oto;
    Car* oto2;



    string brand;
    string color;
    int year = 0;

    void getCar(Car x);

    void input()
    {
        cout << "Nhap mau sac: " << endl;
        cin >> color;
        cout << "Nhap nam san xuat: " << endl;
        cin >> year;
    }

    void showInfo()
    {
        if (!brand.empty())
            cout << "Brand: " << brand << endl;
        cout << "Color: " << color << endl;
        if (year > 0)
            cout << "Year: " << year << endl;
    }
};


void Car::getCar(Car x)
{
    cout << "Xe dang lay la: ";
    cout << x.brand << endl;
}




int main()
{
    Car Lambogini;
    Car Volkswagen;
    Lambogini.brand = "Lambogini";
    Lambogini.color = "Red";

    Volkswagen.input();

    /* Handle */
    Lambogini.showInfo();
    cout << endl;
    Volkswagen.showInfo();
    cout << endl;
    Lambogini.getCar(Lambogini);


    return 0;
}
