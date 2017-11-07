#include <jni.h>
#include <string.h>

#include <android/log.h>
#define LOG_TAG "System.out"
#define PRINT_LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define PRINT_LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
//将java字符串转换为c语言字符串（工具方法）
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
     char*   rtn   =   NULL;
     jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
     jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
     jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
     jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
     jsize   alen   =   (*env)->GetArrayLength(env,barr);
     jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
     if(alen   >   0)
     {
      rtn   =   (char*)malloc(alen+1);         //"\0"
      memcpy(rtn,ba,alen);
      rtn[alen]=0;
     }
     (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
     return rtn;
}
JNIEXPORT jstring JNICALL Java_com_infinite_jniapplication_MzUtils_encode(JNIEnv * env, jobject obj, jstring text, jint length){
      char* cstr = Jstring2CStr(env, text);
      int i;
      for(i = 0;i<length;i++){
          *(cstr+i) += 1; //加密算法，将字符串每个字符加1
      }
      return (*env)->NewStringUTF(env,cstr);
}
JNIEXPORT jstring JNICALL Java_com_infinite_jniapplication_MzUtils_decode(JNIEnv * env, jobject obj, jstring text, jint length){
     char* cstr = Jstring2CStr(env, text);
     int i;
     for(i = 0;i<length;i++){
         *(cstr+i) -= 1;
     }
     return (*env)->NewStringUTF(env, cstr);
}

//JNIEXPORT void JNICALL Java_com_infinite_jniapplication_MzUtils_printAndroidLog(JNIEnv * env, jobject obj){
    //打印log输出
    //PRINT_LOGD("我是C语言打印的debug日志");
    //PRINT_LOGI("我是C语言打印的info日志");
    //通过反射来调用java的方法，需要知道方法签名，使用javap得到方法签名
    //在bin/classes目录下执行 javap -s 全类名
    //1、得到类的字节码对象
    //jclass      (*FindClass)(JNIEnv*, const char*);
    //jclass clazz = (*env)->FindClass(env, "com/mwp/ccalljava2/MainActivity");
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //jmethodID methodID = (*env)->GetMethodID(env, clazz, "show", "(Ljava/lang/String;)V");
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //(*env)->CallVoidMethod(env,obj,methodID, (*env)->NewStringUTF(env, "这是弹窗的内容"));
//}

JNIEXPORT void JNICALL Java_com_infinite_jniapplication_MainActivity_cInvokeJava(JNIEnv * env, jobject obj){
    //打印log输出
    //LOGD("我是C语言打印的debug日志");
    //LOGI("我是C语言打印的info日志");
    //通过反射来调用java的方法，需要知道方法签名，使用javap得到方法签名
    //在bin/classes目录下执行 javap -s 全类名
    //1、得到类的字节码对象
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass clazz = (*env)->FindClass(env, "com/infinite/jniapplication/MainActivity");
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID methodID = (*env)->GetMethodID(env, clazz, "showToast", "(Ljava/lang/String;)V");
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,obj,methodID, (*env)->NewStringUTF(env, "这是Toast的内容"));
}