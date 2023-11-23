//
// Created by trebuszeq on 22/11/23.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include <array>
using namespace std;


#include "main.h"
bool validateInput(string input, bool isInt)
{
    if (isInt) {
        int inputInt;
        try {
            inputInt = stoi(input);
        }
        catch (exception e) {
            return false;
        }
        return true;
    } else if (!isInt) {
        float inputFLoat;
        try {
            inputFLoat = stof(input);
        }
        catch (exception e) {
            return false;
        }
        return true;
    }
}
void clearTerminal()
{
    try
    {
        system("cls");
    }
    catch (exception e)
    {
        system("clear");
    }
}

int collectInputInt(string message)
{
    string input;
    bool truth;

    do {
        cout << message << endl;
        cin >> input;
        cout << endl;
        truth = validateInput(input, true);
        if (!truth) cout << "Nieprawidlowa wartosc.\n\n";
        else break;
    } while (true);
    return stoi(input);
}

float collectInputFloat(string message)
{
    string input;
    bool truth;
    float inputF;

    do
    {
        cout << message << endl;
        cin >> input;
        cout << endl;
        truth = validateInput(input, false);
        if (!truth) cout << "Nieprawidlowa wartosc\n\n";
        else if (truth)
        {
            inputF = stof(input);
            if (inputF > 0) break;
            else cout << "Nieprawidlowa wartosc.\n\n";
        }
    } while(true);
    return inputF;
}

// pokazuje wiadomosc i opcje przekazane w argumencie
void showOptions(string options[], int arrLength, string message)
{
    cout << message << endl;
    cout << "0. Wyczysc terminal.\n";
    for(int i = 0; i < arrLength - 1; i++)
    {
        cout << to_string(i + 1) + ". " + options[i] + ".\n";
    }
    cout << to_string(arrLength) + ". Wyjscie.\n\n";
}

// zadanie 1 - pola prostokatow
void zadanie1()
{
    float dlugosc1 = collectInputFloat("Wprowadz dlugosc pierwszego prostokata.");
    float szerokosc1 = collectInputFloat("Wprowadz szerokosc pierwszegp prostokata.");
    float dlugosc2 = collectInputFloat("Wprowadz dlugosc drugiego prostokata.");
    float szerokosc2 = collectInputFloat("Wprowadz szerokosc prostokata.");

    float pole1 = dlugosc1 * szerokosc1;
    float pole2 = dlugosc2 * szerokosc2;

    if(pole1 > pole2) cout << "Pole pierwszego prostokata jest wieksze.";
    else if(pole1 < pole2) cout << "Pole drugiego prostokatne jest wieksze.";
    else cout << "Pola prostokatow sa rowne.";
}

// program glowny

void zadanie2()
{

}

void zadanie3()
{

}

void zadanie4()
{

}

int main()
{
    string input;
    int inputInt;
    string options[4] =  {
        "Zadanie 1 - pole prostokata",
        "Zadanie 2 - wartosc funkcji",
        "Zadanie 3 - program obliczajacy",
        "Zadanie 4 - korepetytor dodawania"
    };

    do
    {
        showOptions(options, 4, "Opcje:");

        inputInt = collectInputInt("Prosze wprowadzic numer zadania:");
        cout << inputInt;

        switch(inputInt)
        {
            case 0:
                clearTerminal();
                break;

            case 1:
                zadanie1();
                break;

            case 2:
                zadanie2();
                break;

            case 3:
                zadanie3();
                break;

            case 4:
                zadanie4();
                break;

            case 5:
                exit(true);

            default:
                cout << "Brak wybranej opcji.\n\n";
                cout << endl;
                break;
        }
    } while (true);
}