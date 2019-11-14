#include <jni.h>
#include <string>

extern "C" std::string getMyString() {

    return "test-123";
}

extern "C" int add(int a, int b) {
    return a + b;
}

extern "C" int sub(int a, int b) {
    return a - b;
}

extern "C" int mul(int a, int b) {
    return a * b;
}

extern "C" int divi(int a, int b) {
    return a / b;
}
