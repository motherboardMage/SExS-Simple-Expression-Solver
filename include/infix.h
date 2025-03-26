#ifndef INFIX_H
#define INFIX_H

enum precedence {
    ROUND_BRACKET,
    EXPONENT,
    MULTIPLY_DIVIDE,
    ADD_SUBTRACT,
};

extern calculateInfix(char *eqn);
#endif INFIX_H