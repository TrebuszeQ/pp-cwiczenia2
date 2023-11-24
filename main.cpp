//
// Created by trebuszeq on 22/11/23.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;


// funkcja sprawdza czy wartosc jest porzadanego typu int lub float
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
        float inputFloat;
        try {
            inputFloat = stof(input);
        }
        catch (exception e) {
            return false;
        }
        return true;
    }
}

// funkcja wyswietla message i pobiera wartosc typu int, jesli jest prawidlowa zwraca ja. Obsluguje liczby ujemne.
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

// funkcja wyswietla message i pobiera wartosc typu float, jesli jest prawidlowa zwraca ja
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

// funkcja wyswietla message i pobiera wartosc typu float, jesli jest prawidlowa zwraca ja. Obsluguje wartosci ujemne.
float collectInputFloatNeg(string message)
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
        else if (truth) return inputF = stof(input);
    } while(true);
}


// pokazuje wiadomosc i opcje przekazane w argumencie
void showOptions(string options[], int arrLength, string message)
{
    cout << endl << message << endl;
    for(int i = 0; i < arrLength; i++)
    {
        cout << to_string(i + 1) + ". " + options[i] + ".\n";
    }
    cout << to_string(arrLength + 1) + ". Wyjscie.\n\n";
}

// program oblicza pole dwoch prostokatow i porownuje je
void zadanie1()
{
    cout << "Program oblicza pole dwoch prostokatow i porownuje je.";
    float dlugosc1 = collectInputFloat("Wprowadz dlugosc pierwszego prostokata.");
    float szerokosc1 = collectInputFloat("Wprowadz szerokosc pierwszegp prostokata.");
    float dlugosc2 = collectInputFloat("Wprowadz dlugosc drugiego prostokata.");
    float szerokosc2 = collectInputFloat("Wprowadz szerokosc prostokata.");

    float p1 = dlugosc1 * szerokosc1;
    float p2 = dlugosc2 * szerokosc2;

    if(p1 > p2) printf("Pole pierwszego prostokata jest wieksze od pola drugiego: %.2f > %.2f.", p1, p2);
    else if(p1 < p2) printf("Pole drugiego prostokatne jest wieksze od pola pierwszego: %.2f > %.2f.", p1, p2);
    else printf("Pola prostokatow sa rowne: %.2f = %.2f.", p1, p2);
    cout << endl;
}

// program oblicza wartosc funkcji okreslonej wzorem
void zadanie2()
{
    cout << "Program oblicza wartosc funkcji okreslonej wzorem: " << endl;
    cout << "y(x) = {" << endl;
    cout << "1/4x^2 dla x nalezacego do <-4, 10>" << endl;
    cout << "x - 3.3 dla x > 10" << endl;
    cout << "cos(x) + 1 dla x < -4" << endl;
    cout << "}" << endl;

    float x = collectInputFloatNeg("Podaj liczbe rzeczywista dla zmiennej x.");

    // nie mozna uzyc switch dla typu float
    if(x <= 10 && x >= -4) printf("y(%.2f) = %.2f.", x, 1.0/4.0 * (x * x) + 1.0);
    else if(x > 10) printf("y(%.2f) = %.2f.", x, x - 3.3);
    else printf("y(%.2f) = %.2f.", x, cos(x) + 1.0);
    cout << endl;
}

void zadanie3()
{
    bool truth = true;
    float result;

    while (truth)
    {
        cout << "Program oblicza objetosc kuli (K), stozka (S), lub walca (W).\n";
        char input;
        cout << "Podaj litere odpowiadajaca figurze.\n";
        cin >> input;
        input = _toupper(input);

        switch(input)
        {
            case 'K':
            {
                float r = collectInputFloat("Podaj promien kuli.\n");
                result = 4.0 / 3.0 * M_PI * (r * r * r);
                truth = false;
                break;
            }

            case 'S':
            {
                float r = collectInputFloat("Podaj promien stozka.\n");
                float h = collectInputFloat("Podaj wysokosc stozka.\n");
                result = 1.0 / 3.0 * h * M_PI * (r * r);
                truth = false;
                break;
            }

            case 'W':
            {
                float r = collectInputFloat("Podaj promien walca.\n");
                float h = collectInputFloat("Podaj wysokosc walca.\n");
                result = M_PI * (r * r) * h;
                truth = false;
                break;
            }

            default:
                cout << "Brak wybranej opcji.\n";
                break;
        }
    }

    printf("Wynik wynosi %.2f\n", result);
}

// Program wyswietla dwie przypadkowe liczby z przedzialu <0, 499>.
void zadanie4()
{
    srand(time(0));
    cout << "Program wyswietla dwie przypadkowe liczby z przedzialu <0, 499> i pyta o wynik dodawania.\n";

    int x = rand()%500;
    int y = rand()%500;
    int result = x + y;
    cout << x << " + " << y << " = ? \n";
    int input = collectInputInt("Podaj wynik.");
    if (result == input) cout << "Prawidlowy wynik, gratulacje!\n";
    else printf("Niestety poprawna odpowiedz to: %i.\n", result);
}

// program glowny
int main()
{
    string input;
    int inputInt;
    string options[4] =  {
        "Zadanie 1 - pole prostokata",
        "Zadanie 2 - wartosc funkcji",
        "Zadanie 3 - objetosci figur geometrycznych",
        "Zadanie 4 - korepetytor dodawania"
    };

    do
    {
        showOptions(options, 4, "Opcje:");

        inputInt = collectInputInt("Prosze wprowadzic numer zadania:");
        cout << inputInt;

        switch(inputInt)
        {
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