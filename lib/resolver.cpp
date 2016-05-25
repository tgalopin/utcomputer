#include "resolver.h"
#include "literal/atom.h"
#include "exception/undefined_atom.h"

LiteralVector Resolver::resolve(LiteralVector tokens) const {
    LiteralVector resolved;

    // For each atom token, replace it by its resolved components from the repositories
    for (LiteralVector::iterator iterator = tokens.begin(); iterator != tokens.end(); ++iterator) {
        if (shared_ptr<AtomLiteral> atom = dynamic_pointer_cast<AtomLiteral>(*iterator)) {
            if (operatorsMap.find(atom->getValue()) != operatorsMap.end()) {
                // This atom is an operator
                resolved.push_back(operatorLiteralDefinition.createInstance(atom->getValue()));
            } else if (variablesMap.find(atom->getValue()) != variablesMap.end()) {
                // This atom is a variable
                resolved.push_back(variablesMap.at(atom->getValue()));
            } else if (programsMap.find(atom->getValue()) != programsMap.end()) {
                // This atom is a program
                LiteralVector program = programsMap.at(atom->getValue());

                for (LiteralVector::iterator programIt = program.begin(); programIt != program.end(); ++programIt) {
                    resolved.push_back(*programIt);
                }
            } else {
                throw UndefinedAtomException(atom->getValue());
            }
        } else if (shared_ptr<NumericLiteral> numericLiteral = dynamic_pointer_cast<NumericLiteral>(*iterator)) {
            resolved.push_back(numericLiteral);
        } else if (shared_ptr<OperatorLiteral> operatorLiteral = dynamic_pointer_cast<OperatorLiteral>(*iterator)) {
            resolved.push_back(operatorLiteral);
        }
    }

    return resolved;
}
