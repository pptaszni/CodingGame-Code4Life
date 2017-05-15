#ifndef MOLECULES
#define MOLECULES

#include <iostream>

struct Molecules
{
    Molecules() = default;
    Molecules(const Molecules& m) = default;
    int A;
    int B;
    int C;
    int D;
    int E;
    int Sum() const
    {
        return A + B + C + D + E;
    }
    friend bool operator<(const Molecules& left, const Molecules& right)
    {
        return left.Sum() < right.Sum();
    };
    friend bool operator==(const Molecules& left, const Molecules& right)
    {
        return left.Sum() == right.Sum();
    };
    friend std::ostream& operator<<(std::ostream& stream, const Molecules& m)
    {
        stream << "[" << m.A << ", " << m.B << ", " << m.C << ", " << m.D << ", " << m.E << "]";
        return stream;
    };
};



#endif // MOLECULES
