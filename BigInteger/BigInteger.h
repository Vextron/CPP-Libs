#include<vector>

using namespace std;

namespace BigInteger {

    class BigInteger {

        public:
            
            static vector<long> Resize(vector<long> a, unsigned int size);

            static vector<long> Sum(vector<long> a, vector<long> b);

            static vector<long> Product(vector<long> a, vector<long> b);

            static vector<long> ToBigInt(long n);
    };
}