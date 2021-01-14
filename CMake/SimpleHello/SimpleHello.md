# SimpleHello

## 解析CMakeLists.txt

``` txt
# 声明项目，第一个参数为项目名称，第二个参数为语言列表（第二个参数可有可无）
PROJECT (HELLO CXX)

# 设置变量，指定${SRC_LIST}为main.cpp
# 也指定多个文件，如：SET(SRC_LIST main.cpp test.cpp)
# 若文件名中有空格，如：SET(SRC_LIST "main test.cpp")
# 列表分割可以使用空格或者分号
SET(SRC_LIST main.cpp)

# 向终端发送信息
# STATUS：输出普通信息
# SEND_ERROR：输出错误信息，终止当前cmake
# FATAL_ERROR：立即终止所有cmake
MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})

# 变量${HELLO_BINARY_DIR}和变量${HELLO_SOURCE_DIR}为隐式变量
# 分别代表HEllO项目的二进制文件输出路径，源码路径
# 变量组成语法：ProjectName_BINARY_DIR，ProjectName_SOURCE_DIR
MESSAGE(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DIR})

# 使用${SRC_LIST}源码列表生成二进制文件hello
ADD_EXECUTABLE(hello ${SRC_LIST})

```
