
extern "C" {
    #include "dstc.h"
    DSTC_CLIENT(do_number_stuff, float,, int,)
    DSTC_CLIENT(do_string_stuff, char, [128])
}

void waitForServiceAvailable() {
    while (!dstc_remote_function_available( (void*) dstc_do_number_stuff)
      &&  (!dstc_remote_function_available( (void*) dstc_do_string_stuff)))
    {
        dstc_process_events(500000);
    }
}

int main() {
    waitForServiceAvailable();

    dstc_do_number_stuff(1242.512, 123);
    dstc_do_string_stuff("blah blah blah");
    dstc_process_events(100000);
}