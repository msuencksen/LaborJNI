#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_hsfl_mobilecpp1_MainActivity_welcomeFromJNI(JNIEnv *env, jobject instance) {

    __android_log_print(ANDROID_LOG_ERROR, "MobileCPP", "JNI method started! "); // logged to logcat

    std::string welcomeCppStr = std::string("Welcome from JNI C++");

    // TODO: CALL JAVA METHOD


}


