LOCAL_PATH := $(call my-dir)
    include $(CLEAR_VARS)
    #编译生成的文件的类库叫什么名字
    LOCAL_MODULE    := MzUtils
    #要编译的c文件
    LOCAL_SRC_FILES := MzUtils.c
    include $(BUILD_SHARED_LIBRARY)