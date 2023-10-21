#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <cmath>

using namespace std;

// Define a struct to store Euclidean algorithm results.
struct EuclidResult
{
    int d; // Greatest common divisor
    int a;
    int b;
};

// Function to calculate 'base' raised to the power of 'exponent'.
long power(int base, int exponent)
{
    long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result = result * base;
    }
    return result;
}

// Function to find prime factors of a number 'n'.
vector<int> primeFactors(int n)
{
    vector<int> result;
    while (n % 2 == 0)
    {
        result.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            result.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        result.push_back(n);

    return result;
}

// Function to perform the Euclidean algorithm for finding GCD and coefficients.
EuclidResult Euclid(int a, int b)
{
    if (a == b)
    {
        EuclidResult result;
        result.d = a;
        result.a = 1;
        result.b = 0;
        return result;
    }
    if (a > b)
    {
        EuclidResult result = Euclid(a - b, b);
        result.b = result.b - result.a;
        return result;
    }
    else
    {
        EuclidResult result = Euclid(a, b - a);
        result.a = result.a - result.b;
        return result;
    }
}

// Function to check the validity of the public key.
bool isValid(int p, int q, int e, int cipher)
{
    try
    {
        if (p == q || p > q)
            throw logic_error("Public key is not valid!\n");

        if (Euclid(e, cipher).d != 1)
            throw runtime_error("Public key is not valid!\n");

        return true;
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
        return false;
    }
}

int main()
{
    int e = 0;
    int n = 0;
    int m = 0;
    int d = 0;

    // Create a map to map integers to characters.
    map<int, char> num_char_table;
    int x = 5;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        num_char_table.insert(pair<int, char>(x, i));
        x++;
    }

    num_char_table.insert(pair<int, char>(31, ' '));
    num_char_table.insert(pair<int, char>(32, '\"'));
    num_char_table.insert(pair<int, char>(33, ','));
    num_char_table.insert(pair<int, char>(34, '.'));
    num_char_table.insert(pair<int, char>(35, '\''));

    // Taking inputs
    long encoded_message = 0;
    cin >> e >> n;
    cin >> m;

    vector<int> numbers;
    while (cin >> encoded_message)
    {
        numbers.push_back(encoded_message);
        char separator;
        cin.get(separator);
        if (separator == '\n')
        {
            break;
        }
    }

    // Checking if the public key is valid or not.
    vector<int> prime_factors = primeFactors(n);
    int p = 0, q = 0;
    p = prime_factors.at(prime_factors.size() - 2);
    q = prime_factors.at(prime_factors.size() - 1);
    int cipher = (p - 1) * (q - 1);
    vector<char> final_decoded;

    if (isValid(p, q, e, cipher))
    {
        int euclid_alpha = Euclid(e, cipher).a;
        d = euclid_alpha % cipher;
        cout << p << " " << q << " " << cipher << " " << d << endl;

        for (unsigned i = 0; i < numbers.size(); i++)
        {
            long decrypted_value = power(numbers[i], d) % n;
            cout << decrypted_value << " ";
            final_decoded.push_back(num_char_table.at(decrypted_value));
        }
        final_decoded.push_back('\n');
        cout << endl;

        for (unsigned i = 0; i < final_decoded.size(); i++)
        {
            cout << final_decoded[i];
        }
    }

    return 0;
}