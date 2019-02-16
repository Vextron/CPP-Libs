#include "BigInteger.h";

using namespace std;

namespace BigInteger {

    vector<long> Resize(vector<long> a, unsigned int size)
    {
        vector<long> b;

        b.resize(size, 0);

        int i = b.size() - 1;

        while (!a.empty())
        {

            b[i] = a.back();
            a.pop_back();

            i--;
        }

        return b;
    }

    vector<long> Sum(vector<long> a, vector<long> b)
    {
        vector<long> c;
        vector<long> d;

        if (a.size() > b.size())
            b = Resize(b, a.size());

        else
            a = Resize(a, b.size());

        unsigned int carry = 0;

        for (int i = a.size() - 1; i >= 0; i--)
        {

            long digit = (a.at(i) + b.at(i) + carry) % 10;
            long nextCarry = (int)((a.at(i) + b.at(i) + carry) / 10);

            c.push_back(digit);

            carry = nextCarry;
        }

        if (carry != 0)
            c.push_back(carry);

        while (!c.empty())
        {

            d.push_back(c.back());
            c.pop_back();
        }

        return d;
    }

    vector<long> Product(vector<long> a, vector<long> b)
    {
        vector<long> c;
        vector<long> d;

        vector<long> temp;

        for (int i = b.size() - 1; i >= 0; i--)
        {

            unsigned int carry = 0;

            for (int j = a.size() - 1; j >= 0; j--)
            {

                long digit = (a.at(j) * b.at(i) + carry) % 10;
                long nextCarry = (int)((a.at(j) * b.at(i) + carry) / 10);

                c.push_back(digit);
                carry = nextCarry;
            }

            if (carry != 0)
                c.push_back(carry);

            while (!c.empty())
            {

                d.push_back(c.back());
                c.pop_back();
            }

            d.resize(d.size() + b.size() - 1 - i, 0);

            temp = Sum(temp, d);
            d.resize(0);
        }

        return temp;
    }

    vector<long> ToBigInt(long n)
    {
        vector<long> res;
        vector<long> res2;

        while (n != 0)
        {
            res.push_back(n % 10);

            n = (int)(n / 10);
        }

        while (!res.empty())
        {
            res2.push_back(res.back());
            res.pop_back();
        }

        return res2;
    }
}