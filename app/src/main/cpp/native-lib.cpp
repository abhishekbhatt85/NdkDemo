#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#include <cpr/cpr.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    //    cpr::Response r = cpr::Get(cpr::Url{ "https://google.com" },cpr::VerifySsl(false));
    cpr::Response r = cpr::Get(cpr::Url{"https://jsonplaceholder.typicode.com/posts"});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;

    __android_log_print(ANDROID_LOG_VERBOSE, "MYTEST ", "%ld", r.status_code);
    __android_log_print(ANDROID_LOG_DEBUG, "MYTEST ", "%s", r.text.c_str());
    return env->NewStringUTF(r.text.c_str());
}