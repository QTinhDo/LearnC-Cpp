#include <iostream>

using namespace std;

class Hinh {
public:
    virtual float dienTich() = 0;
    virtual void chuVi() = 0;

};

class Tron : public Hinh {
private:
    int r;
public:
    Tron(int r)
    {
        this->r = r;
    }
    float dienTich()
    {
        cout << "Dien tich hinh tron: " << 3.14 * r * r <<endl;
    }
    void chuVi()
    {
        cout << "Chu vi hinh tron: " << 3.14 * r * 2 <<endl;
    }
};

class Vuong : public Hinh {
private:
    int a;
public:
    Vuong(int a)
    {
        this->a = a;
    }
    float dienTich()
    {
        cout << "Dien tich hinh tron = " <<  a * a << endl;
        return a * a;
    }
    void chuVi()
    {
        cout << "Chu vi hinh tron: " << 4 * a <<endl;
    }
};

void tinhDienTich(Hinh &p) {
    cout << "Dien tich: " << p.dienTich() << endl;
}

int main()
{
    Tron tron(4);
    Vuong vuong(4);

    tinhDienTich(vuong);

    return 0;
}
