# zenity

``` shell
# 安装dialog
sudo yum install -y zenity

title="标题"
content="内容"
file="111.log"
width=600
height=400
```

## 简单界面

``` shell
# 消息框
zenity --info --title=${title} --text=${content}

# 问题框
zenity --question --title=${title} --text=${content}

# 错误框
zenity --error --title=${title} --text=${content}

# 输入框
zenity --entry --title=${title} --text=${content}

# 密码框
zenity --password --title=${title}

# 文本框
zenity --text-info --title=${title} --filename=${file} --width=${width} --height=${height}

# 日期框
zenity --calendar --title=${title} --text=${content}

# 缩放框
zenity --scale --title=${title} --text=${content}

# 进度框
zenity --progress --title=${title} --text=${content}

# 图标框
zenity --notification --title=${title} --text=${content}

# 文件选择框
zenity --file-selection --title=${title} --text=${content}
```
