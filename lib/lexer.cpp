#include "lexer.h"

LiteralVector Lexer::tokenize(string command) const {
    // Vector of found tokens
    LiteralVector tokens;

    // Initialization of variables
    LiteralDefinitionVector::const_iterator iterator;
    smatch matchs;
    string match;
    regex pattern;
    bool definitionFound;

    // While the command is not fully parsed
    while (command.size() > 0) {
        definitionFound = false;

        // We iterate over each literal definition trying to find one matching
        for (iterator = definitions.begin(); !definitionFound && iterator != definitions.end(); ++iterator) {
            // The pattern is defined by the LiteralDefinition object.
            // We try to match if at the beginning of the command: we use ^ to do so.
            // We also want to remove the matched string: we catch it using the parenthesis.
            pattern = regex("^(" + (*iterator)->getPattern() + ")");

            // If we found the right literal definition, we build a literal using it
            if (regex_search(command, matchs, pattern)) {
                match = matchs[1].str();

                // We remove the matched element from the command
                command = command.substr(match.length());

                // We create a literal using the definition
                tokens.push_back((*iterator)->createInstance(match));
                cout << (*iterator)->createInstance(match)->toString() << endl;

                // Stop the for here
                definitionFound = true;
            }
        }

        if (!definitionFound) {
            // We found not literal definition matching the given string: invalid synthax
            throw InvalidSyntaxException(command);
        }
    }

    return tokens;
}
