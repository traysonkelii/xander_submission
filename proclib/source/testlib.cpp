#include "testlib.h"

#include <iostream>
#include <iomanip>

class TheProc {
public:
    TheProc(std::string _key, std::string _region)
        : key(_key)
        , region(_region)
    {

    }

    int Run(int length) {
        std::cout << "Running with N " << length << std::setfill('.') << std::setw(length) << "" << std::endl;
        return static_cast<int>(length + key.length() + region.length());
    }

private:
    std::string key;
    std::string region;
};


namespace {
    TheProc* main_proc;
}


extern "C"
int CreateProc(const char *key, const char *region) {
    main_proc = new TheProc(key, region);
    return 0;
}

extern "C"
int RunProc(int id, int process_length) {
    return main_proc->Run(process_length);
}


extern "C"
int DestroyProc(int id) {
    delete main_proc;
    return 0;
}