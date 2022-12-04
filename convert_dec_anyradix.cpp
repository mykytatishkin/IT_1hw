/*
    convert_dec_anyradix.cpp
    Converter from decimal to any radix

    Created by ITFuc-22 20222121 Mykyta Tishkin on 04.12.2022
    
    UPD: Algorithm was given on the lesson
*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <unistd.h> // for sleep()
using namespace std;

void conBf(long double decNum, int radix) // Converting before point
{
    double bfPart, afPart; long int x, y, i; int numberASCII[10];

    afPart = modf(decNum, &bfPart);  // Dividing number after point and before point
    for(i = 0; bfPart > 0; i++) // Converting after point part of number
    {
        x = floor(bfPart/radix);
        y = bfPart - x * radix;
        if (y > 9) 
            numberASCII[i] = y + 55;
        else 
            numberASCII[i] = y;
        bfPart = x;
        
        //    UPD: Code from lesson
    }

    for (i = i - 1; i >= 0; i--) // Printing before point nums after converting
    {
        if(numberASCII[i] > 9)
            cout << (char)numberASCII[i];
        else 
            cout << numberASCII[i]; 
    }
}

void conAf(long double decNum, int radix, int S) // Сonvetring after point
{
    double x, y, bfPart, afPart; long int j; long int numberASCII[S];

    afPart = modf(decNum, &bfPart);
    for(long int i = 0; i <= S; i++)
    {
        y = floor(afPart * radix);
        if(y > 9)
            numberASCII[i] = y + 55;
        else
            numberASCII[i] = y;

        x = afPart * radix - y;
        afPart = x;
    }
    
    cout << ".";
    
    for(long int i = 0; i < S; i++)  // Printing after point nums after converting
    {
        if(numberASCII[i] > 9)
            cout << (char)numberASCII[i];
        else 
            cout << numberASCII[i]; 
    }
}

double sFunc(double E_sup, int radix)
{
    double sRet;

    sRet = (log(1 / E_sup)) / (log(radix));
    sRet = ceil(sRet);
    return sRet;
}

int main()
{
    double E_sup, S, Sdecimal; long double initNum; int radix;

    cout << "Enter init num: "; cin >> initNum;
    cout << "Enter radix: "; cin >> radix;
    cout << "Enter precission of the converted number: "; cin >> E_sup;

    S = sFunc(E_sup, radix);        // Calculating amount of numbers after point in finish  number 
    Sdecimal = sFunc(E_sup, 10);    // Calculating amount of numbers after point in initial number

    cout << "Init data: ";
    std::cout << '-' << std::flush;
    for (int i = 0; i < 2;i++) {
        sleep(1);
        std::cout << "\b\\" << std::flush;
        sleep(1);
        std::cout << "\b|" << std::flush;
        sleep(1);
        std::cout << "\b/" << std::flush;
        sleep(1);
        std::cout << "\b-" << std::flush;
    }
    std::cout << " finished\n";
    
    cout << "   1.1 The initial decimal number: x_10 = " << fixed << setprecision(Sdecimal) << initNum << endl;
    cout << "   1.2 The radix of the target numeral system: r = " << radix << endl;
    cout << "   1.3 The required precission of the coverted number: epsilon_sup = " << scientific << E_sup << fixed << endl;
    cout << "THE RESULTS OF THE CONVERSION:" << endl;
    cout << "   2.1 The required number of the significant numerals s = " << S << endl;
    cout << "   2.2 The result of the conversion: x_" << radix << " = ";
    conBf(initNum, radix);
    conAf(initNum, radix, S);

    return 0;
}