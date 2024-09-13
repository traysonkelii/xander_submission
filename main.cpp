#include <iostream>

#include "testlib.h"

int main(int, char**) {
    {
        // Create multiple Proc instances with names
        int proc_id_one = CreateProc("First Name", "Keyword", "Region Name");
        int proc_id_two = CreateProc("Second Name", "OtherKey", "Region Name");
        int proc_id_three = CreateProc("Third Name", "AnotherKey", "Region Name");

        // Run the Procs
        RunProc(proc_id_one, 15);
        RunProc(proc_id_two, 20);
        RunProc(proc_id_three, 25);

        // Retrieve and print the names of the Procs
        std::cout << "Proc one name: " << GetProcName(proc_id_one) << std::endl;
        std::cout << "Proc two name: " << GetProcName(proc_id_two) << std::endl;
        std::cout << "Proc three name: " << GetProcName(proc_id_three) << std::endl;

        // Destroy the Procs
        DestroyProc(proc_id_one);
        DestroyProc(proc_id_two);
        DestroyProc(proc_id_three);
    }

    return 0;
}
