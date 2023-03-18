#include <iostream>
#include <string>
#include <math.h>
#include "ArrayD.h"
#include "TheoryOfNum.h"
#include "Eratoshpen.h"
#define MessegeInStream true


void normalize(int num_, int den_) noexcept {
    int temp = GCD(abs(num_), abs(den_));
    num_ = num_ / temp;
    den_ = den_ / temp;
    if (MessegeInStream) { std::cout << "actual numbers->" << num_ << "/" << den_ << std::endl; }
}

void TwoNumbers(const int32_t getNum, const int32_t getDen) {
    int num_;
    int den_;

    if (getDen > 0 && getNum > 0) {
        num_ = getNum;
        den_ = getDen;
    }
    else if ((getNum < 0 && getNum > 0) || (getDen < 0 && getNum < 0)) {
        num_ = -getNum;
        den_ = -getDen;
    }
    else if (getNum == 0 && getDen != 0) {
        num_ = 0;
        den_ = 1;
    }
    else if (getDen == 0) {
        throw std::exception("divizion by zero");
    }
    else {
        try {
            num_ = getNum;
            den_ = getDen;
        }
        catch (...) {
            throw std::exception("divizion by zero");
        }
        
    }
    normalize(num_, den_);
}

void CheckStreamN() {
    int32_t num = 0, den = 0;

    std::string inpstr;
    std::string snum;
    std::string sden;

    std::getline(std::cin, inpstr);

    bool numcomplete = false;
    // bool dencomplete = false;
    bool delimiter = false;
    int sign = false;

    // format:
    // " 12/4", "12/3  "

    for (int i = 0; i < inpstr.size(); ++i) {
        char temp = inpstr[i];


        if (isdigit(temp)) {

            if (!numcomplete && !delimiter) { // " 12(3)/4", "(1)2/3"
                snum.push_back(temp);
            }
            else if (numcomplete && delimiter) { // "123/(4)5"
                sden.push_back(temp);
            }
            else if (numcomplete && delimiter && !sden.empty()) { // "12/23 4"
                char err[] = "Too many numbers";
                (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
            }

        }
        else if (temp == '/') {
            if (delimiter) { // "12//34"
                char err[] = "Too many delimiters";
                (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
            }
            else { delimiter = true; }

            if (!snum.empty()) {
                numcomplete = true;
            }
            else {
                // "( Notnums )/123"
                char err[] = "Non formated input till delimiter";
                (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
            }

            if (!isdigit(inpstr[i + 1])) { // "123/( &*#^ )"
                char err[] = "Denom not found";
                (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
            }
        }
        else if (temp == '-') {
            if (sign) { // "-1/-2"
                char err[] = "Minus is in not correct place";
                (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
            }
            else if (!snum.empty() || delimiter) { // "23-/12"
                char err[] = "Minus after a num";
                (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
            }
            else {
                sign = true;
            }

        }
        else {
            if (!numcomplete && !delimiter) { // "( ^&%#  )123/4"
                continue;
            }
            else if (delimiter && numcomplete && !sden.empty()) { // "123/4( ^&#% )"
                continue;
            }
            else if (numcomplete && !delimiter && sden.empty()) { // "12( &#^&@ )/3", "12( @&^# )/ 3"
                char error[] = "Following the first numbers is unexpected";
                (MessegeInStream) ? std::cout << error << std::endl : throw std::exception(error);
            }
            else if (numcomplete && delimiter && sden.empty()) { // "123/( -*&^# )4"
                char error[] = "Following the delimiter is unexpected";
                (MessegeInStream) ? std::cout << error << std::endl : throw std::exception(error);
            }

        }

    }

    if (snum.size() == 0) {
        // /123
        char err[] = "Num not found";
        (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);

    }

    if (MessegeInStream) { std::cout << snum << " and " << sden << std::endl; }

    int digit = 0;
    // 145 = 1*10^2 + 4*10^1 + 5*10^0
    while (digit != snum.size()) {
        int temp = snum[snum.size() - digit - 1] - '0';
        temp = temp * pow(10, digit);
        ++digit;
        num += temp;
    }

    digit = 0;
    while (digit != sden.size()) {
        int temp = sden[sden.size() - digit - 1] - '0';
        temp = temp * pow(10, digit);
        ++digit;
        den += temp;
    }
    if (den == 0) {
        if (delimiter) { // "123/0"  
            char err[] = "Devizion by zero";
            (MessegeInStream) ? std::cout << err << std::endl : throw std::exception(err);
        }
        else {
            den = 1;
        }
    }
    if (sign) { num *= -1; };
   
    if (MessegeInStream) { std::cout << "actual numbers->" << num << "/" << den << std::endl; }
    TwoNumbers(num, den);

}


std::vector<int> Decomp(int a) {

    bool flag = false;
    int count = 0;

    std::vector<int> v;

    for (int d = 2; d <= a; ++d) {
        
        flag = false;

        while (a % d == 0) {
            flag = true;
            a /= d;
        }

    };
    return v;

}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> reqs;
    int M = 0;

    for (int i = 0; i < n; ++i) {
        int req;
        std::cin >> req;
        reqs.push_back(req);
        if (req > M) {
            M = req;
        }
    }
    

    std::vector<int> E = Eratosphen(M);
    std::vector<int> v;

    for (int i = 2; i < E.size(); ++i) {
        if (E[i] == 0) {
            v.push_back(i);
        }
    }

    for (int index : reqs) {
        std::cout << v[index-1] << " ";
    }
    return 0;
}