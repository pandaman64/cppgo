package main

//#cgo LDFLAGS: -L. -limpl -lstdc++
//#include "impl.h"
import "C"

func main() {
    lesser := C.initialize(0)
    defer C.release(lesser)
    greater := C.initialize(1000)
    defer C.release(greater)

    C.bark(lesser, C.CString("meow"))
    C.bark(greater, C.CString("bowwow"))
}

