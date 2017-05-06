#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_hsfl_mobilecpp1_MainActivity_welcomeFromJNI(JNIEnv *env, jobject instance) {

    std::string welcomeCppStr = std::string("Welcome from JNI C++");

    jclass mainActivityClass = env->GetObjectClass(instance);
    jmethodID methodIdSet = env->GetMethodID(mainActivityClass, "setWelcomeText", "(Ljava/lang/String;)V");

    if (methodIdSet != NULL) {
        jstring str = env->NewStringUTF(welcomeCppStr.c_str());
        env->CallVoidMethod(instance, methodIdSet, str);
    } else{
        __android_log_print(ANDROID_LOG_ERROR, "MobileCPP", "methodId not found");
    }

}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsfl_mobilecpp1_MainActivity_appendWelcomeFromJNI(JNIEnv *env, jobject instance) {

    std::string welcomeCppStr = std::string(" ... and from JNI C++"); // text to append

    // get instance and method ids
    jclass mainActivityClass = env->GetObjectClass(instance);
    jmethodID methodIdGet = env->GetMethodID(mainActivityClass, "getWelcomeText", "()Ljava/lang/String;");
    jmethodID methodIdSet = env->GetMethodID(mainActivityClass, "setWelcomeText", "(Ljava/lang/String;)V");


    if (methodIdGet!=NULL && methodIdSet !=NULL) {
        // get current text from text view
        jobject result = env->CallObjectMethod(instance, methodIdGet);
        jstring currentText = reinterpret_cast<jstring>(result);
        const char *currentTextChars = env->GetStringUTFChars(currentText, NULL);
        std::string *currentTextStr = new std::string(currentTextChars);

        // concatenate strings
        std::string newCppString = std::string(currentTextChars) + welcomeCppStr;
        // AppendText::doAppendSomeText(currentTextStr);

        // create java string from C++ string
        jstring newJavaStr = env->NewStringUTF(newCppString.c_str());

        env->CallVoidMethod(instance, methodIdSet, newJavaStr);

        env->ReleaseStringUTFChars(currentText, currentTextChars);
    }
    else{
        __android_log_print(ANDROID_LOG_ERROR, "MobileCPP", "methodId(s) not found");
    }
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_hsfl_mobilecpp1_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
