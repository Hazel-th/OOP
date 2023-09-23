// Copyright 2023 SomeName
#include <string>
#include <exception>
#include "from_Decimal_to_Turkish.h"

using namespace std;

bool isNumber(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

string validation(const string& inputnum) {
    if (!isNumber(inputnum) || inputnum.size() >= 3 || stoi(inputnum) >= 100 || stoi(inputnum) < 0 ) {
        throw invalid_argument("It is not a number or number not in [0;99]");
    }
    return inputnum;
}


string Tens(char num){
    switch (num)
    {
        case '1':
            return "on";
        case '2':
            return "yirmi";
        case '3':
            return "otuz";
        case '4':
            return "kirk";
        case '5':
            return "elli";
        case '6':
            return "altmiş";
        case '7':
            return "yetmiş";
        case '8':
            return "seksen";
        case '9':
            return "doksan";
        default:
            return "error";
    }
}   

string Ones(char num){

    switch (num)
    {
        case '0':
            return "sifir";
        case '1':
            return "bir";
        case '2':
            return "iki";
        case '3':
            return "üç";
        case '4':
            return "dört";
        case '5':
            return "beş";
        case '6':
            return "alti";
        case '7':
            return "yedi";
        case '8':
            return "sekiz";
        case '9':
            return "dokuz";
        default:
           return "error";
    }
}

string from_Decimal_to_Turkish(string inputnum) {
    try {
        string strnum = validation(inputnum);
        string res = "";
        int number_of_digits_in_a_number = strnum.size();
        if (number_of_digits_in_a_number == 2) {
            res += Tens(strnum[0]);
            if (strnum[number_of_digits_in_a_number - 1] == '0' || res == "error") {
                return res;
            }
            res += " ";
        }

        res += Ones(strnum[number_of_digits_in_a_number - 1]);

        return res;
    } catch (const exception& e) {
        return e.what();
    }
}







