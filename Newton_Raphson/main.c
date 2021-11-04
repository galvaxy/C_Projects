#include <stdio.h>
#include <math.h>
#include "newton_raphson.h"
#include "global_variables.h"

int main()
{
    initialize();
    calculate();
    display();
    write();

    return 0;
}