// io.h
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Citanie slov zo suboru

#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int get_word(char *s, int max, FILE *f);

#endif // IO_H
