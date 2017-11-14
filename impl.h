#ifndef IMPL_H
#define IMPL_H

#ifdef __cplusplus
extern "C" {
#endif
 
typedef struct {
    void *impl;
} handle_t;

handle_t initialize(int mode);
void release(handle_t handle);
void bark(handle_t handle, char const* message);

#ifdef __cplusplus
}
#endif

#endif 

