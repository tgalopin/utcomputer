#ifndef LO21_OPERATOR_NUMERATOR_H
#define LO21_OPERATOR_NUMERATOR_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class NumeratorOperator: public OperatorInterface {
public:
    /**
     * @inheritdoc
     */
    void apply(LiteralsStack &stack) const override;

    /**
     * @inheritdoc
     */
    int getPriority() const override {
        return 0;
    }
};

#endif // LO21_OPERATOR_NUMERATOR_H
