//5
#include <iostream>
using namespace std;

class complex{ 
    private:    
        double re; 
        double im; 
    
    public: 
        complex() {}; 
        complex(double param_re, double param_im) {
            this->re=param_re;
            this->im=param_im;
        }
        
        double getRe(){
            return re;
        } 
        
        double getIm(){
            return im; 
        }

        complex complex_conjugate() { 
            complex conjugate(this->re,-(this->im));
            return conjugate;
        }

        complex sum(complex c2){
            complex c3;
            c3.re = this->re + c2.getRe();
            c3.im = this->im + c2.getIm();
            return c3;
        }

        complex product(complex c2){
            complex c3;
            c3.re = (this->re*c2.getRe() - this->im*c2.getIm());
            c3.im = (this->re*c2.getRe() + this->im*c2.getIm());
            return c3;
        }

        void write(){
            cout << this->re << this->im << "i" << endl;
        }
};

int main(){
    complex c1(2, 3), c2(4, 5), c3, c4;
    c3 = c1.sum(c2);
    c4 = c1.product(c2);
    c3.write();
    c4.write();
    return 0;
}