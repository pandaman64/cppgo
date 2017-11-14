#include "impl.h"

#include <iostream>
#include <string>

// C++ implementation
struct Base {
    virtual ~Base(){}
    virtual void bark(std::string message) = 0;
};

struct Lesser : Base {
    Lesser(){}

    virtual void bark(std::string message) {
        std::cout << "this is lesser one: " << message << "!" << std::endl;
    }
};

struct Greater : Base {
    Greater(){}

    virtual void bark(std::string message) {
        std::cout << "this is greater one: " << message << "!" << std::endl;
    }
};

// C interface
handle_t initialize(int mode) {
    if (mode >= 100) {
        return { new Greater() };
    } else {
        return { new Lesser() };
    }
}

void release(handle_t handle) {
    Base *b = static_cast<Base*>(handle.impl);
    delete b;
}

void bark(handle_t handle, char const* message) {
    Base *b = static_cast<Base*>(handle.impl);
    b->bark(message);
}

