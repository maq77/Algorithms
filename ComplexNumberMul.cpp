#include <iostream>
#include <sstream>
using namespace std;

class Complex {
public:
    double real;
    double imag;
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    friend istream& operator>>(istream& in, Complex& A) {
        string input;
        in >> input;

        size_t plus_pos = input.find('+');
        size_t i_pos = input.find('i');

        if (plus_pos == string::npos || i_pos == string::npos || plus_pos >= i_pos) {
            in.setstate(ios::failbit);
            return in;
        }

        try {
            A.real = stod(input.substr(0, plus_pos));
            A.imag = stod(input.substr(plus_pos + 1, i_pos - plus_pos - 1));
        }
        catch (...) {
            in.setstate(ios::failbit);
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Complex& A) {
        out<< A.real;
        cout << " + ";
        out<< A.imag;
        cout << "i";
        return out;
    }
    Complex& operator*(Complex& B) {
        Complex res(0,0);
        double ac = this->real * B.real;
        double bd = this->imag * B.imag;
        res.imag = (this->real + this->imag) * (B.real + B.imag) - ac - bd;
        res.real = ac - bd;
        return res;
    }



};


int main()
{
    //(2 + 3i)(1 + 2i) = [2 – 6] + [4 + 3]i = (–4 + 7i)
    Complex a, b,c;
    cin >> a >> b;
    c = a * b;
    //double c = Complex_Mul(a, b);
    cout << "\nOutput : " << c;

    return 0;
}
