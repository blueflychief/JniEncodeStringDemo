#使用的ndk库函数版本号。一般和SDK的版本相对应，各个版本在NDK目录下的platforms文件夹中
APP_PLATFORM = android-8

#编译成什么类型的cpu的so, 拥有三个属性armeabi  armeabi-v7a  x86可以全选 也可以只用一个，如果全选也可以使用all.
APP_ABI := all

#如何连接c++标准库
#   stlport_static    静态链接
#   stlport_shared    动态链接
#   system    系统默认
APP_STL := stlport_static
#编译版本，如果是DEBUG版本就会带上调试信息。可以使用gdb-server进行动态断点低调试。
#                                debug   调试版本    so中带调试信息，
#                                release  发布版本   so不带调试信息
APP_OPTIM := release
