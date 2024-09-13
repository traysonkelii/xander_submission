#include "testlib.h"

#include <iostream>
#include <iomanip>
#include <map>

class TheProc {
public:
    TheProc(const std::string& _name, const std::string& _key, const std::string& _region)
        : name(_name), key(_key), region(_region)
    {

    }

    int Run(int length) {
        std::cout << "Running " << name << " with N " << length << std::setfill('.') << std::setw(length) << "" << std::endl;
        return static_cast<int>(length + key.length() + region.length());
    }

    const std::string& GetName() const {
        return name;
    }

private:
    std::string name;
    std::string key;
    std::string region;
};

// Store each instance with a unique ID
namespace {
    std::map<int, TheProc*> proc_map;
    int next_proc_id = 1; // Simple incrementing ID generator
}

extern "C"
int CreateProc(const char *name, const char *key, const char *region) {
    int proc_id = next_proc_id++;
    proc_map[proc_id] = new TheProc(name, key, region);
    return proc_id;
}

extern "C"
int RunProc(int id, int process_length) {
    std::map<int, TheProc*>::iterator it = proc_map.find(id);
    if (it != proc_map.end()) {
        return it->second->Run(process_length);
    } else {
        std::cerr << "Error: Proc ID " << id << " not found." << std::endl;
        return -1;
    }
}

extern "C"
const char* GetProcName(int id) {
    std::map<int, TheProc*>::iterator it = proc_map.find(id);
    if (it != proc_map.end()) {
        return it->second->GetName().c_str();
    } else {
        std::cerr << "Error: Proc ID " << id << " not found." << std::endl;
        return nullptr;
    }
}

extern "C"
int DestroyProc(int id) {
    std::map<int, TheProc*>::iterator it = proc_map.find(id);
    if (it != proc_map.end()) {
        delete it->second;
        proc_map.erase(it);
        return 0;
    } else {
        std::cerr << "Error: Proc ID " << id << " not found." << std::endl;
        return -1;
    }
}