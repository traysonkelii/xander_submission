#include <iostream>

#include "testlib.h"

int main(int, char**) {
    {
        // Example of creating an instance of the Proc and running it
        int proc_id = CreateProc("Keyword", "Region Name");
        RunProc(proc_id, 10);
        DestroyProc(proc_id);
    }

    {
        // Make the proc ID field functional so multiple Procs can be created and destroyed

        // int proc_id_one = CreateProc("Keyword", "Region Name");
        // int proc_id_two = CreateProc("OtherKey", "Region Name");
        // RunProc(proc_id_one, 15);
        // RunProc(proc_id_two, 20);

        // DestroyProc(proc_id_one);
        // DestroyProc(proc_id_two);
    }


    {
        // Add a 'name' field to the proc library for instances and print it out
        
        // int proc_id_one = CreateProc("FirstProc", "Keyword", "Region Name");
        // int proc_id_two = CreateProc("SecondProc", "OtherKey", "Region Name");
        
        // somehow print... GetProcName(proc_id_one) ...

        // DestroyProc(proc_id_one);
        // DestroyProc(proc_id_two);
    }

    return 0;
}
