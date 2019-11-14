# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# 第三方so的名字注意不是libthree-lib,动态库标志，导入第三方标志
add_library(three-lib SHARED IMPORTED)
# 这两个属性必须靠在一起，下边是对上边的解释；第三方so名字，设置so的路径armeabi-v7a等
set_target_properties(three-lib PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libthree-lib.so)

# 自定义jni的名字，动态库标示，jni源文件
add_library(native-lib SHARED native-lib.cpp)
# 配置include路径(如果需要使用.h文件的话)，这里没有用到，可以去掉
target_include_directories(native-lib PRIVATE ${CMAKE_SOURCE_DIR}/../myinclude)

find_library(log-lib log)

# 链接所有的.cpp .so，（.h文件不需要），第三方so的名称
target_link_libraries(native-lib three-lib ${log-lib})
