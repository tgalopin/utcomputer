#ifndef LO21_LITERAL_RATIONNAL_H
#define LO21_LITERAL_RATIONNAL_H


#include "literal_interface.h"

/*
 * A rationnal literal represent a fraction value.
 * For instance :
 *      -3/4
 */
struct RationnalLiteral : public NumericLiteralInterface {
private:
    int numerator;
    int denominator;

public:
    RationnalLiteral(int numerator, int denominator): numerator(numerator), denominator(denominator) {}

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    std::string getName() const {
        return "rationnal";
    };

    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    };
};


#endif // LO21_LITERAL_RATIONNAL_H
