#include <iostream>

using namespace std;


class Parent {
public:

    int tu;
    int mau;
    Parent(int a, int b)
    {
        tu = a;
        mau = b;
    }
    void show()
    {
        cout << tu << "/" <<  mau << endl;
    }

    Parent operator+(Parent ps)
    {
        Parent pst(0,0);

        pst.tu = tu * ps.mau + ps.tu * mau;
        pst.mau = ps.mau * mau;

        return pst;
    }

};




int main()
{
    Parent p1(2,3);
    Parent p2(4,5);

    Parent p3 = p1 + p2;

    p3.show();

    return 0;
}
