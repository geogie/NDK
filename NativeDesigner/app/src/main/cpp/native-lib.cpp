#include <jni.h>
#include <string>
#include <android/log.h>
// 日志定义
#define LOG_TAG  "测试-"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// 第三方so中的方法引入
extern "C" std::string getMyString();
extern "C" int add(int a,int b);
extern "C" int sub(int a,int b);
extern "C" int mul(int a,int b);
extern "C" int divi(int a,int b);

using namespace std;
// 自动生成部分
extern "C" JNIEXPORT jstring JNICALL
Java_cn_george_nativedesigner_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

// 在本文件中调用第三方so中的代码
extern "C" JNIEXPORT jstring JNICALL
Java_cn_george_nativedesigner_MainActivity_customPrint(
        JNIEnv *env,
jobject /* this */) {
std::string hello = "Hello from C++";
    LOGD("测试-2-%s",getMyString().c_str());
return env->NewStringUTF(getMyString().c_str());
}

extern "C" JNIEXPORT int JNICALL
Java_cn_george_nativedesigner_MainActivity_add(
        JNIEnv *env,
        jobject /* this */,jint a,jint b) {
    LOGD("加法");
    return add(a,b);
}

extern "C" JNIEXPORT int JNICALL
Java_cn_george_nativedesigner_MainActivity_sub(
        JNIEnv *env,
        jobject /* this */,jint a,jint b) {
    LOGD("减法");
    return sub(a,b);
}

extern "C" JNIEXPORT int JNICALL
Java_cn_george_nativedesigner_MainActivity_mul(
        JNIEnv *env,
        jobject /* this */,jint a,jint b) {
    LOGD("乘法");
    return mul(a,b);
}

extern "C" JNIEXPORT int JNICALL
Java_cn_george_nativedesigner_MainActivity_divi(
        JNIEnv *env,
        jobject /* this */,jint a,jint b) {
    LOGD("除法");
    return divi(a,b);
}
