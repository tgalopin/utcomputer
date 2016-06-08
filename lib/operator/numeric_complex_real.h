#ifndef LO21_NUMERIC_COMPLEX_REAL_H
#define LO21_NUMERIC_COMPLEX_REAL_H


#include "interface.h"

using namespace std;

class NumericComplexReal : public OperatorInterface {
public:
    /**
     * @inheritdoc
     */
    void apply(LiteralsStack &stack) const override;

    /**
     * @inheritdoc
     */
    int getPriority() const {
        return 0;
    }
};


#endif //LO21_NUMERIC_COMPLEX_REAL_H
