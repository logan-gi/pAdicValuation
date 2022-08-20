// Program finds the p-adic valuation and absolute value of a rational number n based on its prime base

#include <iostream>
#include <cstdlib>

using namespace std;

const long TENBIL = 100000;
int exponent(0);
int base;
long long num, denom;
char ans, answer;

long long gcf(long long number);
// Searches for greatest common factor among numerator and denominator

long long gcfCheck(long long numb1, long long denum);
// Redundant greatest common factor check

bool ifPrime(int numb2);
// Checks if value input is a prime number

void fractionFinder(long double numb);
// Converts decimal to fraction

int pValuation(int expo, int base1, long ration);
// Determines the p-valuation of the rational number input

int main()
{
    double long rational;
    do {
        cout << "What prime would you like to use?" << endl;
        cin >> base;
        if (ifPrime(base)) {
        cout << "Are you entering a fraction or decimal?\n";
        cin >> ans;
        if (ans == 'F' || ans == 'f') {
            cout << "Enter your numerator:" << endl;
            cin >> num;
            num = abs(num);
            cout << "Enter your denominator:" << endl;
            cin >> denom;
            denom = abs(denom);
            long hold = num;
            num = num / gcfCheck(hold, denom);
            denom = denom / gcfCheck(hold, denom);
        }
        if (ans == 'D' || ans == 'd') {
            cout << "Enter a rational number (up to 5 decimal points):\n";
            cin >> rational;
            rational = abs(rational);
            fractionFinder(rational);
        }
        cout << "Your p-adic valuation for the rational number \""
             << static_cast<double>(num) / denom << "\" aka \""
             << num << "/" << denom
             << "\" in the " << base << "-adic set is: "
             << pValuation(exponent, base, num)
                - pValuation(exponent, base, denom) << endl;
        cout << "The absolute value of \"" << static_cast<double>(num) / denom << "\" is "
             << (1.0)/(pow(base, (pValuation(exponent, base, num)
                                    - pValuation(exponent, base, denom)))) << endl;
    } else
            cout << "Invalid input\n";
        cout << "Would you like to find another?\n";
        cout << "Enter 'Y' or 'N'\n";
        cin >> answer;
        cout << endl;
    } while (answer == 'Y' || answer == 'y');
    return 0;
}


bool ifPrime(int numb2)
{
    if (numb2 == 0 || numb2 == 1)
        return false;
    for (int i=2; i <= numb2/2; ++i)
        if (numb2 % i == 0)
            return false;
    return true;
}

int pValuation (int expo, int base1, long ration)
{
    if (ration % base1 != 0)
        return expo;
    for (int i=1; pow(base1, i) <= ration; i++)
    {
        int power = pow(base1, i);
        if (ration % power != 0)
            break;
        if (ration == power)
            return i;
        expo = i;
    }
    return expo;
}

void fractionFinder(double long numb)
{
    long long frac = (numb)*TENBIL;
    num = (frac)/gcf(frac);
    denom = (TENBIL)/gcf(frac);
    long check = num;
    num = num/gcfCheck(check, denom);
    denom = denom/gcfCheck(check, denom);
}

long long gcf(long long number)
{
    if (number % (TENBIL/10) == 0)
        return (TENBIL/10);
    for(long long i=number/2; i > 0; i--)
        if (number % i == 0 && TENBIL % i == 0)
            return i;
}

long long gcfCheck(long long numb1, long long denum) {
    for (long i = numb1; i > 0; i--)
        if (numb1 % i == 0 && denum % i == 0)
            return i;
    return 1;
}