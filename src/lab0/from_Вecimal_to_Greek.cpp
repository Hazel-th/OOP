// Copyright 2023 SomeName
#include <string>
#include "from_Вecimal_to_Greek.h"

using namespace std;

string if_number(char num){
    string res;
    switch (num)
    {
        case '1':
            res+="on";
            break;
        case '2':
            res+="yirmi";
            break;
        case '3':
            res+="otuz";
            break;
        case '4':
            res+="kirk";
            break;
        case '5':
            res+="elli";
            break;
        case '6':
            res+="altmiş";
            break;
        case '7':
            res+="yetmiş";
            break;
        case '8':
            res+="seksen";
            break;
        case '9':
            res+="doksan";
            break;
        default:
            res = "error";
            break;
    }
    return res;
}   

string if_digit(char num){
    string res;
    switch (num)
    {
        case '0':
            res+="sifir";
            break;
        case '1':
            res+="bir";
            break;
        case '2':
            res+="iki";
            break;
        case '3':
            res+="üç";
            break;
        case '4':
            res+="dört";
            break;
        case '5':
            res+="beş";
            break;
        case '6':
            res+="alti";
            break;
        case '7':
            res+="yedi";
            break;
        case '8':
            res+="sekiz";
            break;
        case '9':
            res+="dokuz";
            break;
        default:
           res = "error";
            break;
    }
    return res;
}

string from_Becimal_to_Greek(string inputnum){
    string res = "";
    int siz = inputnum.size();
    if (siz == 2){
        res += if_number(inputnum[0]);
        if (inputnum[siz-1] == '0' or res == "error"){
            return res;
        }
        res+=" ";
        
    }

    res+=if_digit(inputnum[siz-1]);

    return res;
}