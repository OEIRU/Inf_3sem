#include <locale> 
#include <fstream> 
#include <float.h> 
#include <conio.h> 
#include <string> 
#include <math.h> 
#include <iomanip> 

using namespace std;
bool Check(double Number, ofstream& fout)
{
    if (isinf(Number))
    {
        if (Number > 0)
            fout << " + Infinity";
        else
            fout << "- Infinity";
        return 0;
    }
    if (_isnan(Number))
    {
        fout << "Not a number";
        return 0;
    }
    return 1;
}


int main()
{
    ifstream fin("Input.txt");

    ofstream fout("Output.txt");
    char buf[50], buf1[50], c;
    unsigned char Result[28];
    int N;
    double DoubleNumber, CheckNumber;
    float FloatNumber;
    fin.getline(buf, 50);
    if (!strcmp(buf, "10 to 16"))
    {
        fin >> N;
        if (N == 4)
        {
            fin >> CheckNumber;
            if (CheckNumber > FLT_MAX)
            {
                fout << "0x7F800000 (+Infinity)";
                return (0);
            }
            FloatNumber = CheckNumber;
            memcpy(Result, &FloatNumber, 4);
        }
        if (N == 8)
        {
            fin >> CheckNumber; // if (CheckNumber > DBL_MAX) { fout << "0x7FF0000000000000 (+Infinity)"; return(0); }
            DoubleNumber = CheckNumber;
            memcpy(Result, &DoubleNumber, 8);
        }
        fout << "0x";
        for (int i = N - 1; i >= 0; i--)
        {
            fout << uppercase << hex << (int)Result[i];
        }
    }
    else if (!strcmp(buf, "16 to 10"))
    {
        fin.get(c);
        fin.get(c);

        fin.getline(buf1, 50);
        fin >> N;
        int i, t, k = 0;
        if (N == 4)
            t = 8;
        if (N == 8)
            t = 16;
        i = 0;
        while (buf1[i] != '\0')
        {
            i++;
        }
        k = i++;
        if (k != 8)
        {
            for (i = 0; i < t - k; i++)
            {
                buf1[i + t - k] = buf1[i];
                buf1[i] = '0';
            }
            buf1[t] = '\0';
        }
        for (int i = 0; i < N; i++)
            Result[i] = strtoul(string(buf1).substr(N * 2 - 2 - i * 2, 2).c_str(), 0, 16);
        if (N == 4)
        {
            memcpy(&FloatNumber, Result, 4); //читаем первые 4 байта строки и записываем в число
            if (Check(FloatNumber, fout))
            {
                fout << setprecision(27) << FloatNumber << '\n';
            }
        }
        else if (N == 8)
        {
            if (!strcmp(buf1, "0x7FF0000000000000"))
            {
                fout << "+Infinity";
                return (0);
            }
            memcpy(&DoubleNumber, Result, 8); //читаем первые 8 байт строки и записываем в число
            if (Check(DoubleNumber, fout))
            {
                fout << setprecision(27) << DoubleNumber << '\n';
            }
        }
    }
}  

