# grep

``` shell
str="foo"
file1="111.log"
file2="222.log"
```

## 匹配

``` shell
# 输出file1文件中包含str的行
grep "${str}" ${file1}

# 输出包含关键字的行号和行
grep -n "${str}" ${file1}

# 输出不包含关键字的行
grep -v "${str}" ${file1}

# 输出关键字匹配的行的行数
grep -c "${str}" ${file1}

# 输出当前目录下包含关键字的文件的文件名
grep -l "${str}" *

# 输出关键字匹配的行，忽略大小写
grep -i "${str}" ${file1}

# 输出关键字完全匹配的行
grep -x "${str}" ${file1}

# 输出关键字匹配的行及后续2行
grep -A2 "${str}" ${file1}

# 输出关键字匹配的行及前面2行
grep -B2 "${str}" ${file1}

# 输出关键字匹配的行及前后各2行
grep -C2 "${str}" ${file1}

# 以正则表达式形式匹配
grep -e "${str}" ${file1}

# 将file2内容作为关键字与file1进行匹配
grep -f ${file2} ${file1}

# 递归搜索当前路径下包含str的行
grep -r "${str}" ./
```
