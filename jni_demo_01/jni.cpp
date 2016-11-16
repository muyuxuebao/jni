/**
 * @file jni.cpp
 * @author yinliang(yinliang@jd.com)
 * @date 2016/11/16 14:29:38
 * @brief 
 *  
 **/







int main() {
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;
    long status;
    jclass testCls;
    jmethodID testMid;
    jobject testJobj;envjobject tookitReturnObj;
    //设置Java类的路径
    options[0].optionString = "-Djava.class.path=. ;D:\\workspace\\my\\JniTest\\jnitest.jar";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_TRUE;
    status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
}













/* vim: set ts=4 sw=4 sts=4 tw=100 */
