#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "integration.h"

/* ********************************************************** */
/* *********************** Save Data ************************ */
/* ********************************************************** */
void save()
{
    int i;
    FILE *stream;
    stream = fopen("integration.txt", "w");
    for(i = 0; i < N; i++)
    {
        fprintf(stream, "%.5f\t%.5f\t%.5f\n", dx[i], AreaNC[i], ErrNC[i]);
    }
    fprintf(stream, "\n\n");
    for(i = 0; i < N; i++)
    {
        fprintf(stream, "%.5f\t%.5f\t%.5f\n", dx[i], AreaT[i], ErrT[i]);
    }
    fprintf(stream,"\n\n");
    for(i = 0; i < N; i++)
    {
        fprintf(stream, "%.5f\t%.5f\t%.5f\n", dx[i], AreaS[i], ErrS[i]);
    }
}