#include "bin_calc.h"


using namespace std;

int main()
{
    bin_calc calc;
    calc.setDec(8520352,0,32);
    calc.setDec(6425875,1,32);
    cout << calc.add();
    return 0;
}
