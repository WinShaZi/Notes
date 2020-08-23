# bash命令

    如果一个命令失败就立即退出
    bash -e test.sh

    读入命令但是不执行它们
    bash -n test.sh

    置换时把未设置的变量看做出错
    bash -u test.sh

    当读入Shell输入行时把它们显示出来
    bash -v test.sh
    
    执行命令时把命令和它们的参数显示出来
    bash -x test.sh
