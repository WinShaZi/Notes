# echo

``` shell
var="Hello World!"
```

## 普通输出字符串

``` shell
echo "Hello World!"

echo Hello World!

echo "${var}"

echo ${var}

# 输出
# => Hello World!
```

## 字符转义

``` shell
echo "\"${var}\""

# 输出
# => "Hello World!"

echo '\"${var}\"'

# 输出
# => \"${var}\"
```

## 制表符转义

``` shell
echo -e "${var}\n${var}"

# 输出
# => Hello World!
# => Hello World!

echo -e "${var} \c"
echo -e "${var}"

# 输出
# => Hello World! Hello World!
```

## 输出到文件

``` shell
echo ${var} > FILE
```

## 显示命令执行

``` shell
echo `COMMAND`
```
