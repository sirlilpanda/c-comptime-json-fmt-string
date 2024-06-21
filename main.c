#include <stdio.h>
#include <stdint.h>
#include "json.h"

int sensor_1 = 4;
double sensor_2 = 4.51231;
int sensor_3 = 54;
int sensor_4 = 2;
unsigned long long sensor_5 = 123123.13473574537542363542;
char* state = "working";

int main(int argc, char const *argv[])
{
    char* fmt_string = JSON_FMT_STRING( fmt_string, //it needs this
        sensor_1,
        sensor_2,
        sensor_3,
        sensor_4,
        sensor_5,
        state
    );
    // puts(fmt_string);
    printf(fmt_string, sensor_1, sensor_2, sensor_3, sensor_4, sensor_5, state);
    printf("\n");
    return 0;
}
