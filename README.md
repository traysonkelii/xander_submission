## Initial setup

created a `start.sh` script to facilitate building via a simple one line command:

```
bash start.sh
```

This simply ran the `cmake` commands with simple debugging and then runs the build.

## Implementation #1

```
    {
        // Make the proc ID field functional so multiple Procs can be created and destroyed

        // int proc_id_one = CreateProc("Keyword", "Region Name");
        // int proc_id_two = CreateProc("OtherKey", "Region Name");
        // RunProc(proc_id_one, 15);
        // RunProc(proc_id_two, 20);

        // DestroyProc(proc_id_one);
        // DestroyProc(proc_id_two);
    }
```

Raw testing caused the following error:

```
Running with N 14..............
Running with N 15...............
Running with N 20....................
XanderOne(61190,0x10f1a2e00) malloc: *** error for object 0x7f9487c05a80: pointer being freed was not allocated
```

Essentially the original file only pointed to one instance and was "double freeing" the same block of memory upon delete.

We can fix this by creating a map of `TheProc` instances and referring to them when deleting (or using).

## Implementation #2

```
{
    // Add a 'name' field to the proc library for instances and print it out

    // int proc_id_one = CreateProc("FirstProc", "Keyword", "Region Name");
    // int proc_id_two = CreateProc("SecondProc", "OtherKey", "Region Name");

    // somehow print... GetProcName(proc_id_one) ...

    // DestroyProc(proc_id_one);
    // DestroyProc(proc_id_two);
}
```

Define a new string member variable `name` within the existing `TheProc` class.

Create the functionality for `GetProcName` to access `name` and define the new method in the `testlib.h` file.

Update `main.cpp` to test all functionality
