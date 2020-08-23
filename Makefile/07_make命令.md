# make命令

## 编译

    make
    命令行指定变量
    make var="Are you ok?"

## 清理

    make clean

## 指定文件

    make -f FILENAME
    make -file FILENAME

## 执行过程

    只显示过程而不执行
    make -n

## 不显示执行过程

    make -s

## 忽略错误行为

    make -i

## 出错执行

    出错则跳过该命令，继续执行下面命令
    make -k

## 指定文件夹下

    make -C FOLDER

## 重新编译

    make -B
