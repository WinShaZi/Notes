
# 这是一级标题

## 这是二级标题

### 这是三级标题

#### 这是四级标题

##### 这是五级标题

###### 这是六级标题

``` markdown
# 这是一级标题

## 这是二级标题

### 这是三级标题

#### 这是四级标题

##### 这是五级标题

###### 这是六级标题
```

# 文字形式

**这是加粗的文字**  
*这是倾斜的文字*  
***这是斜体加粗的文字***  
~~这是加删除线的文字~~

``` markdown
**这是加粗的文字**  
*这是倾斜的文字*  
***这是斜体加粗的文字***  
~~这是加删除线的文字~~
```

# 引用

>这是引用的内容
>>这是引用的内容
>>>这是引用的内容

``` markdown
>这是引用的内容
>>这是引用的内容
>>>这是引用的内容
```

# 分割线

---

``` markdown
---
```

# 图片

![YuruCamp](https://fp1.fghrsh.net/2020/07/01/f7473bd6707d4571568bff01a7b45cea.jpg "摇曳露营")

``` markdown
![YuruCamp](https://fp1.fghrsh.net/2020/07/01/f7473bd6707d4571568bff01a7b45cea.jpg "摇曳露营")
```

# 链接

[百度](http://baidu.com "baidu.com")

``` markdown
[百度](http://baidu.com "baidu.com")
```

# 无序列表

- 一级列表
  - 二级列表
    - 三级列表
- 一级列表

``` markdown
- 一级列表
  - 二级列表
    - 三级列表
- 一级列表
```

# 有序表

1. 一级列表
    1. 二级列表
        1. 三级列表
2. 一级列表

``` markdown
1. 一级列表
    1. 二级列表
        1. 三级列表
2. 一级列表
```

# 表格

表__头|表__头|表____头
:-|:-:|-:
内容|内容|内容
内容|内容|内容

``` markdown
表__头|表__头|表____头
:-|:-:|-:
内容|内容|内容
内容|内容|内容
```

# 代码

`main.c`

``` C
＃include <stdio.h>

int main()
{
    printf("Hello World!\n");

    return 0;
}
```

```` markdown
`main.c`

``` c
＃include <stdio.h>

int main()
{
    printf("Hello World!\n");

    return 0;
}
```
````

# 流程图

``` flow
st=>start: 开始
inputCountry=>inputoutput: 输入国籍
isChina=>condition: 是否是中国?
openBaidu=>operation: 打开百度:>https://www.baidu.com
openGoogle=>subroutine: 打开C盘|Google:>C:/
ed=>end: 结束

st->inputCountry->isChina
isChina(yes)->openBaidu->ed
isChina(no)->openGoogle(right)->ed
```

```` markdown
``` flow
st=>start: 开始
inputCountry=>inputoutput: 输入国籍
isChina=>condition: 是否是中国?
openBaidu=>operation: 打开百度:>https://www.baidu.com
openGoogle=>subroutine: 打开C盘|Google:>C:/
ed=>end: 结束

st->inputCountry->isChina
isChina(yes)->openBaidu->ed
isChina(no)->openGoogle(right)->ed
```
````
