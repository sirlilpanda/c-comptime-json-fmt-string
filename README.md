# c-comptime-json-fmt-string
creates a format string at comp time for json
see main.c for usage
the macro can only be used in a local scope as well.

## usage

```c
#include <stdio.h>
#include <stdint.h>
#include "json.h"

//define all your sensors
int sensor_1 = 4;
double sensor_2 = 4.51231;
int sensor_3 = 54;
int sensor_4 = 2;
unsigned long long sensor_5 = 123123.13473574537542363542;
char* state = "working";

int main(int argc, char const *argv[])
{
    // create the string, this must be done within a local scope
    char* fmt_string = JSON_FMT_STRING( fmt_string, //it needs this
        sensor_1,
        sensor_2,
        sensor_3,
        sensor_4,
        sensor_5,
        state
    );
    puts(fmt_string); 
    //-> {"sensor_1":%d,"sensor_2":%lf,"sensor_3":%d,"sensor_4":%d,"sensor_5":%llu,"state":"%s"}
    // use it just like anyother fmt string
    printf(fmt_string, sensor_1, sensor_2, sensor_3, sensor_4, sensor_5, state);
    printf("\n");
    return 0;
}
```