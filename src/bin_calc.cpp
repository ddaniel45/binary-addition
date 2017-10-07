#include "bin_calc.h"
int bin_calc::determine_bits_size(int dec) {
    if(dec <= 15) { return 4; }
    if(dec <= 255) { return 8; }
    if(dec <= 65535) { return 16; }
    if(dec <= 2147483647) { return 32; }
}
void bin_calc::setDec(int dec, int ab, int custom_bit) {
    string bin;
    if(custom_bit == 0) {
        bin = dec2bin(dec,determine_bits_size(dec));
    } else {
        bin = dec2bin(dec,custom_bit);
    }

    std::vector<int> temp;
    for(unsigned int i = 0; i < bin.length(); i++) {
        temp.push_back(bin[i] - '0');
    }
    if(ab == 0) {
        bin_calc::a = temp;
    } else {
        bin_calc::b = temp;
    }
}

void bin_calc::setBin(string bin, int ab) {
    std::vector<int> temp;
    for(unsigned int i = 0; i < bin.length(); i++) {
        temp.push_back(bin[i] - '0');
    }
    if(ab == 0) {
        bin_calc::a = temp;
    } else {
        bin_calc::b = temp;
    }
}

string bin_calc::getBin(int ab) {
    stringstream ss;
    if(ab == 0) {
        for(auto& x : a) {
            ss << x;
        }
        return ss.str();
    } else {
         for(auto& x : b) {
            ss << x;
        }
        return ss.str();
    }
}

int bin_calc::add() {
    vector<int> a_,b_,finals;
    a_ = a;
    b_ = b;

    std::reverse(a_.begin(),a_.end());
    std::reverse(b_.begin(),b_.end());

    int carry = 0;
    unsigned i = 0;
    for(int& ax : a_) {
        int bx = b_[i];
        i++;

            // addition table
            if(carry == 0 && ax == 0 && bx == 0) { finals.push_back(0); carry = 0; continue; }
            if(carry == 0 && ax == 0 && bx == 1) { finals.push_back(1); carry = 0; continue; }
            if(carry == 0 && ax == 1 && bx == 0) { finals.push_back(1); carry = 0; continue; }
            if(carry == 0 && ax == 1 && bx == 1) { finals.push_back(0); carry = 1; continue; }

            if(carry == 1 && ax == 0 && bx == 0) { finals.push_back(1); carry = 0; continue; }
            if(carry == 1 && ax == 0 && bx == 1) { finals.push_back(0); carry = 1; continue; }
            if(carry == 1 && ax == 1 && bx == 0) { finals.push_back(0); carry = 1; continue; }
            if(carry == 1 && ax == 1 && bx == 1) { finals.push_back(1); carry = 1; continue; }
            //

    }

    std::reverse(finals.begin(),finals.end());


    stringstream ss;
     for(auto& x : finals) {
            ss << x;
        }
    return bin2dec(ss.str());
}
string bin_calc::dec2bin(int dec, int bits) {
    long i = dec;
    std::vector<int> rem;

    while(i != 0) {
        rem.push_back(i % 2);
        i /= 2;
    }
    int actual_bits = bits - rem.size();
    if(actual_bits > 0) {
        const int a_size = rem.size();
        for(int i = 0; i < actual_bits; i++) {
            rem.push_back(0);
        }
    }
    std::reverse(rem.begin(),rem.end());
    stringstream ss;

    for(auto& x : rem) {
        ss << x;
    }
    return ss.str();
}
int bin_calc::bin2dec(string bin) {
    std::vector<int> temp,f;
    int ff = 0;

    for(unsigned int i = 0; i < bin.length(); i++) {
        temp.push_back(bin[i] - '0');
    }

    std::reverse(temp.begin(),temp.end());
    unsigned int au = 0;
    for(int& x : temp) {
        int u = x * pow(2,au);
        f.push_back(u);
        au++;
    }
    for(int& x : f) {
        ff += x;
    }
    return ff;
}
