// Copyright (C) 2018, Jaguar Land Rover
// This program is licensed under the terms and conditions of the
// Mozilla Public License, version 2.0.  The full text of the 
// Mozilla Public License is at https://www.mozilla.org/MPL/2.0/
//
// Author: Magnus Feuer (mfeuer1@jaguarlandrover.com)
//
// Running example code from README.md in https://github.com/PDXOSTC/dstc
//

#include <stdlib.h>
#include "dstc.h"
#include "rmc_log.h"

// Generate serializer functionality and the callable client function
// dstc_message().
// A call to dstc_print_name_and_age will trigger a call to
// print_name_and_age() in all (server) nodes that have loaded this library.
//
DSTC_CLIENT_SIGNAL(print_name_and_age, char, [32], int,)

int main(int argc, char* argv[])
{
    // Wait for function to become available on one or more servers.
    while(!dstc_get_remote_count("print_name_and_age")) 
        dstc_process_events(500000);

    // Make the call
    dstc_print_name_and_age("Bob Smith", 25);

    // Process events for another 100 msec to ensure that the call gets out.
    dstc_process_events(100000);
}
