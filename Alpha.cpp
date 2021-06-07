#include <iostream>
#include <string>

using namespace std;
int _totalAsciiSum = 0;
inline long int totalAsciiSum(string input)
{
    long int tot = 0;
    for (long int i = 0; i < input.size(); i++)
        tot += (int)(input[i] % 12);
    return tot;
}
string Alphicage(string input)
{
    const int a = 5;
    const int A = 10;
    const int b = 15;
    const int B = 20;
    const int c = 25;
    const int C = 30;
    const int d = 35;
    const int D = 40;
    const int e = 45;
    const int E = 50;
    const int f = 55;
    const int F = 60;

    int *CentralizedTo64 = new int[input.size()];

    for (long int i = 0; i < input.size(); i++)
    {
        CentralizedTo64[i] = (input[i] + i + (_totalAsciiSum % 12)) % 64;
    }

    string R_ID = "";

    for (long int i = 0; i < input.size(); i++)
    {
        if (CentralizedTo64[i] <= 0)
        {
            R_ID += "0";
        }
        else if (CentralizedTo64[i] < a)
        {
            R_ID += to_string(CentralizedTo64[i]);
        }
        else if (CentralizedTo64[i] - a < 10)
        {
            if (CentralizedTo64[i] - a == 0)
            {
                R_ID += "a";
            }
            else
            {
                R_ID += "a" + to_string(CentralizedTo64[i] - a);
            }
        }
        else if (CentralizedTo64[i] - A < 10)
        {
            if (CentralizedTo64[i] - A == 0)
            {
                R_ID += "A";
            }
            else
            {
                R_ID += "A" + to_string(CentralizedTo64[i] - A);
            }
        }
        else if (CentralizedTo64[i] - b < 10)
        {
            if (CentralizedTo64[i] - b == 0)
            {
                R_ID += "b";
            }
            else
            {
                R_ID += "b" + to_string(CentralizedTo64[i] - b);
            }
        }
        else if (CentralizedTo64[i] - B < 10)
        {
            if (CentralizedTo64[i] - B == 0)
            {
                R_ID += "B";
            }
            else
            {
                R_ID += "B" + to_string(CentralizedTo64[i] - B);
            }
        }
        else if (CentralizedTo64[i] - c < 10)
        {
            if (CentralizedTo64[i] - c == 0)
            {
                R_ID += "c";
            }
            else
            {
                R_ID += "c" + to_string(CentralizedTo64[i] - c);
            }
        }
        else if (CentralizedTo64[i] - C < 10)
        {
            if (CentralizedTo64[i] - C == 0)
            {
                R_ID += "C";
            }
            else
            {
                R_ID += "C" + to_string(CentralizedTo64[i] - C);
            }
        }
        else if (CentralizedTo64[i] - d < 10)
        {
            if (CentralizedTo64[i] - d == 0)
            {
                R_ID += "d";
            }
            else
            {
                R_ID += "d" + to_string(CentralizedTo64[i] - d);
            }
        }
        else if (CentralizedTo64[i] - D < 10)
        {
            if (CentralizedTo64[i] - D == 0)
            {
                R_ID += "D";
            }
            else
            {
                R_ID += "D" + to_string(CentralizedTo64[i] - D);
            }
        }
        else if (CentralizedTo64[i] - e < 10)
        {
            if (CentralizedTo64[i] - e == 0)
            {
                R_ID += "e";
            }
            else
            {
                R_ID += "e" + to_string(CentralizedTo64[i] - e);
            }
        }
        else if (CentralizedTo64[i] - E < 10)
        {
            if (CentralizedTo64[i] - E == 0)
            {
                R_ID += "E";
            }
            else
            {
                R_ID += "E" + to_string(CentralizedTo64[i] - E);
            }
        }
        else if (CentralizedTo64[i] - f < 10)
        {
            if (CentralizedTo64[i] - f == 0)
            {
                R_ID += "f";
            }
            else
            {
                R_ID += "f" + to_string(CentralizedTo64[i] - f);
            }
        }
        else if (CentralizedTo64[i] - F < 10)
        {
            if (CentralizedTo64[i] - F == 0)
            {
                R_ID += "F";
            }
            else
            {
                R_ID += "F" + to_string(CentralizedTo64[i] - F);
            }
        }
    }

    return R_ID;
}
inline string _generate_alpha(string input)
{
    _totalAsciiSum = totalAsciiSum(input);
    string __HASH = input.length() % 64 == 0 ? input + input[0] : input;
    do
    {
        __HASH = Alphicage(__HASH);
    } while (__HASH.length() < ((__HASH.length() % 64) + 1) * 64);
    return __HASH.substr(__HASH.length() - 64, 64);
}
inline string addSalt(string data, string salt)
{
    string _last_data = "";
    for (int i = 0; i < salt.length(); i++)
    {
        _last_data = salt.at(i);
        data.insert((salt.length() + i) % data.length(), _last_data);
    }
    return data;
}
int main(int argc, char *argv[])
{
    if (argc == 1){
        cout << "can't run hash function: arg error";
        exit(0);
    }
    string input = argv[1];
    string salt = argc == 3?argv[2]:"";
    input = addSalt(input, salt);
    _totalAsciiSum = totalAsciiSum(input);
    string hashedData = "Alpha( " + _generate_alpha(input) + " )";
    cout << hashedData << endl;
    return 0;
}