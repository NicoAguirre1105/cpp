#include <iostream>
#include <cstdlib>

using namespace std;

class Two
{
    double a;
    double b;
    public:

    Two (double x, double y)
    {
        a = x - y > 0 ? x : y;
        b = x - y > 0 ? y : x;
    }

    double study(double x)
    {
        if(x - a > 0)
        {
            double aux = b;
            b = a;
            a = x;
            return aux;
        } else if (x - b > 0)
        {
            double aux = b;
            b = x;
            return aux;
        }
        return x;
    }

    void print()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class Three : Two
{
    double c;
    public:
    Three(double aa, double bb, double cc): Two(aa, bb), c(Two::study(cc)) {}

    double study(double x)
    {
        double res = Two::study(x);
        if (res - c > 0)
        {
            double aux = c;
            c = res;
            return aux;
        }
        return res;
    }

    void print()
    {
        Two::print();
        cout << "c = " << c << endl;
    }

};

int main()
{
    double x = 13;
    double y = 2;
    double z = 5;
    Two P(x, y);
    Three Q(x, y, z);
    P.study(20);
    P.print();
    Q.print();


    return EXIT_SUCCESS;
}