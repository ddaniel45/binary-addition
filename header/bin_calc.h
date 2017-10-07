#ifndef BIN_CALC_H
#define BIN_CALC_H

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctgmath>

using namespace std;

class bin_calc
{
    public:
        int determine_bits_size(int dec);
        void setDec(int dec, int ab, int custom_bit = 0);
        void setBin(string bin, int ab);
        string getBin(int ab);

        int add();
        int bin2dec(string bin);
        string dec2bin(int dec, int bits);

    private:
        std::vector<int> a,b;
};

#endif // BIN_CALC_H
