#include "logic_or.h"


void LogicOrOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("Equals operator requires 2 operands");
    }
    int firstLogicalValue = 1;
    int secondLogicalValue = 1;

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);


    if(firstNumeric->toString()=="0"){
        firstLogicalValue = 0;
    }
    if(secondNumeric->toString()=="0"){
        secondLogicalValue = 0;
    }
    if(firstLogicalValue + secondLogicalValue==2){
        firstLogicalValue = 0; //in order to have 1 as the pushed value
    }
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(firstLogicalValue+secondLogicalValue)));





}
