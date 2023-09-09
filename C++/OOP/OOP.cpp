#include <iostream>

using namespace std;

class SinhVien{
public:
    static int count;
    SinhVien()
    {
        count++;
    }



    void showSL()
    {
        cout << count << endl;
    }


};

int SinhVien::count = 0;

int main()
{
    SinhVien sv1;
    SinhVien sv2;
    SinhVien sv3;

    sv1.showSL();
    sv2.showSL();
    sv3.showSL();

    return 0;
}
