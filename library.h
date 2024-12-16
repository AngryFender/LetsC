#ifndef LETSC_LIBRARY_H
#define LETSC_LIBRARY_H

#ifdef DLL_EXPORT
#define CALL __attribute__((visibility("default")))
#else
#define CALL
#endif

#ifdef __cplusplus
extern "C"{
#endif

CALL void hello();

#ifdef __cplusplus
}
#endif

#endif //LETSC_LIBRARY_H
