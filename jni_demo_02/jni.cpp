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

JavaVM *vm = NULL;
void*  thream_task(void* args) {

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

    pthread_t tids[5]; 
    for( int i = 0; i < 5; ++i ) {  
        int ret = pthread_create( &tids[i], NULL, thream_task, NULL ); //参数：创建的线程id，
        // 线程参数，线程运行函数的起始地址，运行函数的参数  
        if( ret != 0 ) //创建线程成功返回0  
        {  
            std::cout << "pthread_create error:error_code=" << ret << std::endl;  
        }  
    }  
//    pthread_exit( NULL ); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态  

    // Shutdown the VM.
    vm->DestroyJavaVM();
    std::cout<<"End"<<std::endl;
}












/* vim: set ts=4 sw=4 sts=4 tw=100 */
