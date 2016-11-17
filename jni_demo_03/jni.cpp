/**
 * @file jni.cpp
 * @author yinliang(yinliang@jd.com)
 * @date 2016/11/16 14:29:38
 * @brief 
 *  
 **/



#include<jni.h>
#include<stdio.h>
#include <pthread.h>
#include <iostream>
#include <boost/thread/thread.hpp>

JavaVM *vm = NULL;
void  thream_task() {

    JNIEnv *env;
    vm->AttachCurrentThread((void **)&env, NULL);  

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

    vm->DetachCurrentThread();
}

int main() {
    std::cout<<"Start"<<std::endl;
    JNIEnv *env;
    JavaVMInitArgs vm_args;
    vm_args.version = JNI_VERSION_1_2;
    vm_args.nOptions = 0;
    vm_args.ignoreUnrecognized = 1;

    //Construct a VM
    jint res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);


    boost::thread_group threadGroup;
    for (int i = 0; i < 10000; i++) {
        threadGroup.create_thread(thream_task);
    }
    threadGroup.join_all();
    // Shutdown the VM.
//    vm->DestroyJavaVM();
    std::cout<<"End"<<std::endl;
}












/* vim: set ts=4 sw=4 sts=4 tw=100 */
