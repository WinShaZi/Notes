# dialog

``` shell
# 安装dialog
sudo yum install -y dialog

title="标题"
content="内容"
file="111.log"
tempfile="tempfile"
height=20
width=60
```

## 选项

``` txt
--add-widget                    继续下个对话框，直到按下ESC或者CANCEL
--aspect Ration                 指定窗口的宽高比
--backtitle Title               指定显示在屏幕顶部背景上的标题
--begin X Y                     指定窗口左上角的起始位置
--cancel-label Label            指定CANCEL按钮的代替标签
--clear                         用指定默认的对话框背景色来清空屏幕内容
--colors                        在对话文本中嵌入ANSI色彩编码
--cr-wrap                       在对话文本中允许使用换行符并强制转换
--create-rc File                将示例配置文件的内容复制到指定的file中
--defaultno                     将YES/NO对话框默认选项设为NO
--defualt-item String           设定复选框列表，表单或菜单对话框中的默认项
--exit-label Label              设定EXIT按钮的代替标签
--extra-button                  在OK与CANCEL之间添加一个额外按钮
--extra-label Label             指定额外按钮的代替标签
--help                          显示dialog命令的帮助信息
--help-button                   在OK和CANCEL按钮之后显示一个HELP按钮
--help-label Label              指定HELP按钮的代替标签
--help-status                   当指定HELP按钮后，在帮助信息后写入多选列表，单选列表或表单信息
--ignore                        忽略dialog不能识别的选项
--input-fd Fd                   指定STDIO之外的另一个文件描述符
--insecure                      在password部件中键入内容时显示*号
--item-help                     为多选列表，单选列表或菜单中的每个标号在屏幕底部添加一个帮助栏
--keep-window                   不要清除屏幕上显示过的部件
--max-input Size                指定输入的最大字符串长度，默认为2048
--nocancel                      隐藏CANCEL按钮
--no-collapse                   不要将对话文本中的制表符转换为空格
--no-kill                       将tailboxbg对话框放在后台，并静止该进程的SIGHUP信号
--no-label Label                为NO按钮指定代替标签
--no-shadow                     不要显示对话窗口的阴影效果
--ok_label Label                为OK按钮指定代替标签
--output-fd Fd                  指定STDOUT之外的另一个文件描述符
--print-maxsize                 将对话框窗口的最大尺寸打印到输出中
--print-size                    将每个对话框的大小打印到输出中
--print-version                 将dialog的版本号打印到输出中
--separator-output              一次一行的输出checklist部件的结果
--separator String              指定用于分割部件输出的字符串
--separator-widget String       指定用于分割部件输出的字符串
--shadow                        在每个窗口的右下角绘制阴影
--single-quoted                 需要时对多选列表的输出采用单引号
--sleep Second                  在处理完成对话窗口之后延迟指定秒数
--stderr                        将输出发送到STDERR，默认行为
--tab-correct                   将制表符转换为空格
--tab-len N                     指定制表符的长度，默认为8
--timeout Second                指定无用户输入时，Second秒后退出并返回错误码
--title Title                   指定对话框的标题
--trim                          从对话文本中删除前导空格和换行符
--visit-items                   修改对话框中制表符的停留位置，使其包括选项列表
--yes-label Label               为YES按钮指定代替标签
```

## 简单界面

``` shell
# 消息框，仅提醒
dialog --no-shadow --title ${title} --infobox ${content} ${height} ${width}

# 消息框，有确认键
dialog --no-shadow --title ${title} --msgbox ${content} ${height} ${width}

# 确认框，添加确认取消键
dialog --no-shadow --title ${title} --yesno ${content} ${height} ${width}

# 输入框
dialog --no-shadow --title ${title} --inputbox ${content} ${height} ${width}

# 密码框，输入显示*
dialog --no-shadow --insecure --title ${title} --passwordbox ${content} ${height} ${width}

# 文本框，显示file文件中的内容
dialog --no-shadow --title ${title} --textbox ${file} ${height} ${width}

# 文本显示
dialog --no-shadow --title ${title} --tailbox ${file} ${height} ${width}

# 文本显示，后台
dialog --no-shadow --title ${title} --tailboxbg ${file} ${height} ${width}

# 菜单框，代表有5个选项
# 序号  内容
dialog --no-shadow --title ${title} --menu ${content} ${height} ${width} 5 \
    1 "one" \
    2 "two" \
    3 "three"

# 可编辑菜单框
# 序号  内容
dialog --no-shadow --title ${title} --inputmenu ${file} ${height} ${width} 5 \
    1 "one" \
    2 "two" \
    3 "three"

# 单选框
# 序号  内容  状态
dialog --no-shadow --title ${title} --radiolist ${content} ${height} ${width} 5 \
    1 "one"     on  \
    2 "two"     off \
    3 "three"   off

# 复选择框
# 标签  内容  序号
dialog --no-shadow --title ${title} --checklist ${content} ${height} ${width} 5 \
    "1" "one"   1 \
    "2" "two"   2 \
    "3" "three" 3

# 文件选择框
dialog --no-shadow --title "${title}" --fselect ${HOME} ${height} ${width}

# 日期框
dialog --no-shadow --title ${title} --calendar ${content} ${height} ${width}

# 指定日期，2020-02-20
dialog --no-shadow --title ${title} --calendar ${content} ${height} ${width}  20 02 2020

# 时间框
dialog --no-shadow --title ${title} --timebox ${content} ${height} ${width}

# 指定时间，12:34:56
dialog --no-shadow --title ${title} --timebox ${content} ${height} ${width} 12 34 56

# 倒计时10s
dialog  --no-shadow --title ${title} --pause ${content} ${height} ${width} 10

# 进度条，进度为33
dialog --no-shadow --title ${title} --gauge ${content} ${height} ${width} 33

# 实时动态进度条
for i in {1..100}; do echo ${i}; done | dialog --no-shadow --title ${title} --gauge ${content} ${height} ${width}

# 框架
# 标签  序号  标签缩进  输入框内容  输入框显示序号对应内容  标签缩进长度  输入框显示长度 输入框允许输入长度
# 输入框允许输入长度为0则不限制
dialog --title ${title} --form ${content} ${height} ${width} 4 \
    "one_:"     1 3 "one"   1 10 7 5 \
    "two_:"     2 3 "two"   2 10 7 5 \
    "three_:"   3 1 "three" 3 10 7 5 \
    "four_:"    4 2 "four"  4 10 7 5

# 密码框架
# 标签  序号  标签缩进  输入框内容  输入框显示序号对应内容  标签缩进长度  输入框显示长度 输入框允许输入长度
# 输入框允许输
dialog --insecure --title ${title} --passwordform ${content} ${height} ${width} 4 \
    "one_:"     1 3 "" 1 10 7 5 \
    "two_:"     2 3 "" 2 10 7 5 \
    "three_:"   3 1 "" 3 10 7 5 \
    "four_:"    4 2 "" 4 10 7 5
```

## 获取输入

``` shell
# 将输入内容定向到tempfile文件中
dialog --no-shadow --title ${title} --inputbox ${content} ${height} ${width} 2>${tempfile}
# 获取对话框的选择，确认：0，取消：1
echo "$?"
```
