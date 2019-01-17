// Copyright (C) 2018, Jaguar Land Rover
// This program is licensed under the terms and conditions of the
// Mozilla Public License, version 2.0.  The full text of the 
// Mozilla Public License is at https://www.mozilla.org/MPL/2.0/
//
// Author: Magnus Feuer (mfeuer1@jaguarlandrover.com)
//
// Running example code from README.md in https://github.com/PDXOSTC/dstc
//

#include <stdio.h>
#include <stdlib.h>
#include "dstc.h"
#include "struct.h"

// The deserializer decodes the incoming data and calls the
// print_struct() function in this file.
//
DSTC_SERVER(print_struct, struct name_and_age,)

//
// Print out name and age.
// Invoked by deserilisation code generated by DSTC_SERVER() above.
// Please note that the arguments must match between the function below
// and the macro above.
//
void print_struct(struct name_and_age arg)
{
    printf("Name: %s\n", arg.name);
    printf("Age:  %d\n", arg.age);
}

int main(int argc, char* argv[])
{
    // Process incoming events for ever
    dstc_process_events(-1);

    exit(0);
}


