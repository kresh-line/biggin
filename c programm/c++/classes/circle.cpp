#include <iostream>
using namespace std;

class circle {

        double aktina;
    public:
        void setAktina(double a) {
            //if (a >= 0)
               aktina = a;
            //else
                //aktina = -a;
    }
        double give_emvadon(){
            return 3.14 * aktina * aktina;
    }
        double give_perimetro() {
            return 2 * 3.14 * aktina;
        }
};

int main() {
    circle c1;
    c1.setAktina(3.5);
    cout << "Emvadon kyklou : " << c1.give_emvadon() << endl;
    cout << "Perimetros kyklou : " << c1.give_perimetro() << endl;
    return 0;
}