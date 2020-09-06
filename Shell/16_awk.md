# awk

``` shell
file1="111.log"
file2="222.awk"
```

## 运算符

``` awk
= += -= *= /= %= ^= **=     # 赋值
?: < <= > >= != ==          # 关系运算符
|| && !                     # 逻辑运算
~ !~                        # 匹配或不匹配正则
' '                         # 连接
+ - * / %                   # 算数运算符
^ ***                       # 求幂
++ --                       # 自增，自减
$                           # 字段引用
in                          # 数组成员
```

## 内部变量

``` awk
$n              # 当前记录的第n个字段，字段间由FS分隔
$0              # 完整的输入记录
ARGC            # 命令行参数的数目
ARGIND          # 命令行中当前文件的位置(从0开始算)
ARGV            # 包含命令行参数的数组
CONVFMT         # 数字转换格式(默认值为%.6g)ENVIRON环境变量关联数组
ERRNO           # 最后一个系统错误的描述
FIELDWIDTHS     # 字段宽度列表(用空格键分隔)
FILENAME        # 当前文件名
FNR             # 各文件分别计数的行号
FS              # 字段分隔符(默认是任何空格)
IGNORECASE      # 如果为真，则进行忽略大小写的匹配
NF              # 一条记录的字段的数目
NR              # 已经读出的记录数，就是行号，从1开始
OFMT            # 数字的输出格式(默认值是%.6g)
OFS             # 输出记录分隔符（输出换行符），输出时用指定的符号代替换行符
ORS             # 输出记录分隔符(默认值是一个换行符)
RLENGTH         # 由match函数所匹配的字符串的长度
RS              # 记录分隔符(默认是一个换行符)
RSTART          # 由match函数所匹配的字符串的第一个位置
SUBSEP          # 数组下标分隔符(默认值是/034)
```

## 内置函数

``` awk
# 数值函数
atan2(y, x);    # 返回y/x的反正切
cos(x);         # 返回x的余弦值
sin(x);         # 返回x的正弦值
exp(x);         # 返回x的幂函数
log(x);         # 返回x的对数
sqrt(x);        # 返回x的开方
int(x);         # 取整
rand();         # 返回[0, 1]之间的随机数
srand(x);       # 设置以rand()的种子值

# 字符串函数
gsub(reg, str, src);        # 将src中全部的reg匹配之处替换为str，src未给参数默认为$0
sub(reg, str, src);         # 将src中第一个reg匹配之处替换为str，src未给参数默认为$0
substr(str, beg, len);      # 截取str中从第[beg, beg + len)的子串，len为给参数默认为到结尾
index(src, str);            # 返回str在src中的位置，从1开始，不存在返回0
length(str);                # 返回str的长度，src未给参数默认为$0
blength(str);               # 返回str的字节数，src未给参数默认为$0
match(src, reg);            # 返回src中以reg匹配的位置，不存在返回-1
split(src, arr, reg);       # 以reg为分隔符，划分src，将划分的结果储存到arr中，arr[1]代表第一个值，并返回分割的个数
tolower(src);               # 返回src的全部小写
toupper(src);               # 返回src的全部大写
sprintf(format, args...);   # 返回格式化的字符串
strtonum(src);              # 返回src转换的数值，src为0开头视作十进制，0x开头视为十六进制，否则当作浮点数

# 时间函数
mktime("YYYY mm DD HH MM SS");  # 返回秒数
systime();                      # 返回秒数
strftime(format, second);       # 格式化时间

# 位操作函数
and(m, n);      # m & n
or(m, n);       # m | n
xor(m, n);      # m ^ n
lshift(m, n);   # m << n
rshift(m, n);   # m >> n
compl(n);       # ~n

# 其他
close(expr);            # 关闭管道，例如：expr = "grep str"，关闭expr管道
delete arr[n];          # 删除数组元素
exit(n);                # 脚本返回值
flush(expr);            # 刷新文件或管道
getline;                # 读取下一行存入$0
next;                   # 停止当前处理，进行下一行处理
nextfile;               # 停止处理当前文件，进行下一个文件处理
return n;               # 自定义函数返回值
system(expr);           # 执行系统命令
```

## 简单输出

``` shell
# 输出file1全部
awk '{pirnt $0}' ${file1}

# 输出file1每一行的以空格分隔的第一个单词
awk '{print $1}' ${file1}

# 输出每一行的以空格分隔的最后一个单词
awk '{print $(NR)}' ${file1}

# 输出每一行指定以':'分隔符的倒数第二个单词
awk -F ':' '{print $(NF - 1)}' ${file1}

# 输出每一行的单词数
awk '{print NF}' ${file1}

# 输出每一行的行数
awk '{print NR}' ${file1}

# 格式化输出
awk '{printf("%10s %10s\n", $1, $2)}' ${file1}

# 设置变量
awk -v var="Hello" '{printf("%10s %20s\n", $1, var)}' ${file1}
```

## 正则

``` shell
# 正则表达式匹配，输出file1中包含foo的行
awk '$0 ~ /foo/ {print $0}' ${file1}
```

## BEGIN END

``` shell
# BEGIN:用于执行前的操作，END执行后的操作，统计file1中单词的个数
awk 'BEGIN {
    printf("Count : ");
    sum = 0
} {
    sum += NF
} END {
    print sum
}' ${file1}
```

## 数组

``` shell
awk 'BEGIN {
    arr[1] = "one";
    arr[2] = "two";
    arr[3] = "three";
    printf("%s %s %s\n", arr[1], arr[2], arr[3])
}'
```

## 条件判断

``` shell
awk 'BEGIN {
    num=10;
    if (num % 2 == 0)
        print "even"
    else
        print "odd"

    if (num < 10)
        print "gt 10"
    else if (num > 10)
        print "lt 10"
    else
        print "eq 10"
}'
```

## 循环

``` shell
# 返回111
awk 'BEGIN {
    num=3;
    for (i = 0; i < num; i++) {
        print "for";
        if (i < 0)
            break;
    }

    while (1) {
        num--;
        if (num < 0)
            break
        else {
            print "while";
            continue
        }
    }
    exit(111)
}'
```

## 自定义函数

`222.awk`

``` awk
function show(str) {
    print str
}

BEGIN {
    print "BEGIN"
} {
    show($0)
} END {
    print "END"
}
```

``` shell
# 输出全部内容
awk -f ${file2} ${file1}
```
