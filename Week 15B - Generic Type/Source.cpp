#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
typename enable_if<is_floating_point<T>::value, T>::type

half(T value) {
    return value / 2;
}

int half(int);

int main()
{
    double a = 7.0;
    float b = 5.0f;
    int c = 3;

    cout << half(a) << endl;
    cout << half(b) << endl;
    cout << half(c) << endl;

    return 0;
}

int half(int value) {
    return static_cast<int>(round(static_cast<double>(value) / 2));
}