# sed

``` shell
str1="foo"
str2="bar"
str3="bug"
file1="111.log"
file2="222.log"
file3="SedScript"
```

## 替换

``` shell
# 替换第3处匹配
sed "s/${str1}/${str2}/3" ${file1}

# 替换全部匹配内容
sed "s/${str1}/${str2}/g" ${file1}

# 将替换之后的匹配行打印出来
sed -n "s/${str1}/${str2}/p" ${file1}

# 直接修改源文件
sed -i "s/${str1}/${str2}/g" ${file1}

# 用脚本中的sed命令执行
sed -f ${file3} ${file1}

# 将替换之后的结果写入到文件file2
sed "s/${str1}/${str2}/w ${file2}" ${file1}

# 将!作为字符串分隔符
sed "s!${str1}!${str2}!" ${file1}

# 只替换第2行匹配
sed "2 s/${str1}/${str2}/g" ${file1}

# 替换2，4行的匹配
sed "2,4 s/${str1}/${str2}/g" ${file1}

# 替换第2行到最后一行的匹配
sed "2,$ s/${str1}/${str2}/g" ${file1}

# 文本过滤后替换
sed "/${str3}/s/${str1}/${str2}/g" ${file1}

# 命令组合
sed "{
    2 s/${str1}/${str2}/g
    2 s/${str2}/${str3}/g
}" ${file1}

sed "2 {
    s/${str1}/${str2}/g
    s/${str2}/${str3}/g
}" ${file1}
```

## 删除

``` shell
# 删除全部行
sed "d" ${file1}

# 删除第2行
sed "2 d" ${file1}

# 删除2到4行
sed "2,4 d" ${file1}

# 删除2到最后一行
sed "2,$ d" ${file1}

# 文本过滤后删除
sed "/${str3}/d" ${file1}

# 删除两个匹配之间所有的行
sed "/${str1}/,/${str2}/d" ${file1}
```

## 插入

``` shell
# 在第2行之前插入
sed "2 i ${str1}" ${file1}

# 在第2行之后插入
sed "2 a ${str1}" ${file1}

# 插入两行
sed '2 i\
str1\
str2' ${file1}
```

## 修改

``` shell
# 修改第2行
sed "2 c ${str1}" ${file1}

# 修改2到4行
sed "2,4 c ${str1}" ${file1}

# 文本过滤
sed "/${str3}/c ${str1}" ${file1}
```

## 转换

``` shell
# 字符对应转换
sed "y/${str1}/${str2}/" ${file1}
```

## 打印

``` shell
# 只显示文本过滤之后的行
sed -n "/${str1}/p" ${file1}

# 只打印2,4行
sed -n "2,4 p" ${file1}

# 只打印行号
sed -n "=" ${file1}

# 打印文本和不可见字符
sed -n "l" ${file1}
```

## 写入

``` shell
# 写入file1的2到4行到file2中
sed "2,4 w ${file2}" ${file1}

# 写入file1的匹配行到file2中
sed "/${str3}/w ${file2}" ${file1}
```

## 读取

``` shell
# 从file2读取全部插入到file1第2行之后
sed "2 r ${file2}" ${file1}

# 插入到file1的2到4行每一行之后
sed "2,4 r ${file2}" ${file1}

# 文本匹配后读取
sed "/${str3}/r ${file2}" ${file1}
```
