# kdialog

``` shell
# 安装dialog
sudo yum install -y kdialog

title="标题"
content="内容"
file="111.log"
width=600
height=400
```

## 选项

``` txt
--separate-output       为多选框和单选列表菜单返回按行分开的选项
```

## 简单界面

``` shell
# 消息框
kdialog --title ${title} --msgbox ${content}

# sorry消息框
kdialog --title ${title} --sorry ${content}

# error消息框
kdialog --title ${title} --error ${content}

# warning，yes/no框
kdialog --title ${title} --warningyesno ${content}

# warning，continue/cancel框
kdialog --title ${title} --warningcontinuecancel ${content}

# warning，yes/no/cancel框
kdialog --title ${title} --warningyesnocancel ${content}

# 确认框
kdialog --title ${title} --yesno ${content}

# 确认取消框
kdialog --title ${title} --yesnocancel ${content}

# 文本框
kdialog --title ${title} --textbox ${file} ${width} ${height}

# 输入框
kdialog --title ${title} --inputbox ${content}

# 密码框
kdialog --title ${title} --password ${content}

# 菜单框
# 序号  内容
kdialog --title ${title} --menu ${content} \
    1 "one"     \
    2 "two"     \
    3 "three"

# 单选框
# 序号  内容  状态
kdialog --title ${title} --radiolist ${content} \
    1 "one"     on \
    2 "two"     off \
    3 "three"   off

# 多选框
# 序号  内容  状态
kdialog --title ${title} --checklist ${content} \
    1 "one"     on \
    2 "two"     off \
    3 "three"   off
```
