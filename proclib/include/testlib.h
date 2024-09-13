#pragma once

#if (defined(_MSC_VER))
#define PLATFORM_EXPORT __declspec(dllexport)
#elif defined(__APPLE__) || defined(__clang__) || defined(__GNUC__)
#define PLATFORM_EXPORT __attribute__ ((visibility("default")))
#else
#define PLATFORM_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // The C interface down into a c++ library


    // Create an instance of the Proc and return an ID
    PLATFORM_EXPORT int CreateProc(const char* key, const char* region);

    // Run Proc for the specified ID
    PLATFORM_EXPORT int RunProc(int id, int process_length);

    // shutdown the proc and free memory
    PLATFORM_EXPORT int DestroyProc(int id);




#ifdef __cplusplus
}
#endif
