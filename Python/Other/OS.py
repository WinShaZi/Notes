import os
import sys
import stat

# 文件状态
# os.F_OK       文件存在
# os.R_OK       文件可读
# os.W_OK       文件可写
# os.X_OK       文件可执行
print(os.access('tempfile', os.F_OK))

path = os.getcwd()

# 改变当前路径
os.chdir('../')
print(os.getcwd())
os.chdir(path)

# 返回指定目录下所有的文件
print(os.listdir('../'))

# 创建文件
fd = os.open('tempfile', os.O_CREAT)
os.close(fd)

# 更改文件或目录权限
os.chmod('tempfile', stat.S_IRWXO | stat.S_IRWXU | stat.S_IRWXG)

# 重命名文件或目录
os.rename('tempfile', 'temptxt')

# 递归重命名文件或目录
os.renames('temptxt', 'tempfile')

# 删除文件
os.remove('tempfile')

# 创建文件夹
os.mkdir('tempdir', 777)

# 删除空目录
os.rmdir('tempdir')

# 递归创建文件夹
os.makedirs('tempdir/a/b/c')

# 递归删除空目录
os.removedirs('tempdir/a/b/c')

# 获取文件信息
print(os.stat(sys.argv[0]))
