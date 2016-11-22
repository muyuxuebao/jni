/**
 * @file jni.cpp
 * @author yinliang(yinliang@jd.com)
 * @date 2016/11/16 14:29:38
 * @brief 
 *  
 **/



#include <jni.h>
#include <stdio.h>
#include <cassert>
#include <iostream>

int main() {
    const int kNumOptions = 3;
    JavaVMOption options[kNumOptions] = {
        { const_cast<char*>("-Xmx128m"), NULL },
        { const_cast<char*>("-verbose:gc"), NULL },
        { const_cast<char*>("-Djava.class.path=/home/liang/jni_example"), NULL }
    };

    JavaVMInitArgs vm_args;
    vm_args.version = JNI_VERSION_1_6;
    vm_args.options = options;
    vm_args.nOptions = sizeof(options) / sizeof(JavaVMOption);
    assert(vm_args.nOptions == kNumOptions);

    JNIEnv* env = NULL;
    JavaVM* jvm = NULL;
    int res = JNI_CreateJavaVM(&jvm, reinterpret_cast<void**>(&env), &vm_args);
    if (res != JNI_OK) {
        std::cerr << "FAILED: JNI_CreateJavaVM " << res << std::endl;
        return -1;
    }

    const char* kClassName = "Main";
    jclass cls = env->FindClass(kClassName);
    if (cls == NULL) {
        std::cerr << "FAILED: FindClass" << std::endl;
        return -1;
    }

    const char* kMethodName = "main";
    jmethodID mid =
        env->GetStaticMethodID(cls, kMethodName, "([Ljava/lang/String;)V");
    if (mid == NULL) {
        std::cerr << "FAILED: GetStaticMethodID" << std::endl;
        return -1;
    }

    const jsize kNumArgs = 1;
    jclass string_cls = env->FindClass("java/lang/String");
    jobject initial_element = NULL;
    jobjectArray method_args = env->NewObjectArray(kNumArgs, string_cls, initial_element);

    jstring method_args_0 = env->NewStringUTF("Hello, Java!");
    env->SetObjectArrayElement(method_args, 0, method_args_0);

    env->CallStaticVoidMethod(cls, mid, method_args);
    jvm->DestroyJavaVM();

    return 0;
}





int main1(int argc, char** argv) {


    JavaVM *vm;
    JNIEnv *env;
    JavaVMInitArgs vm_args;
    vm_args.version = JNI_VERSION_1_2;
    vm_args.nOptions = 0;
    vm_args.ignoreUnrecognized = 1;

    //Construct a VM
    jint res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);

    // Construct a String
    jstring jstr = env->NewStringUTF("Hello World");

    // First get the class that contains the method you need to call
    jclass clazz = env->FindClass("java/lang/String");

    // Get the method that you want to call
    jmethodID to_lower = env->GetMethodID(clazz, "toLowerCase",
            "()Ljava/lang/String;");
    // Call the method on the object
    jobject result = env->CallObjectMethod(jstr, to_lower);

    // Get a C-style string
    const char* str = env->GetStringUTFChars((jstring) result, NULL);

    printf("%s\n", str);

    // Clean up
    env->ReleaseStringUTFChars(jstr, str);

    // Shutdown the VM.
    vm->DestroyJavaVM();
}







/* vim: set ts=4 sw=4 sts=4 tw=100 */
