# 连接MySQL

## 结构化执行

``` shell
# 一般连接
mysql -uUsername -pPassword -e "
    -- SQL
"

# 指定数据库连接
mysql -uUsername -pPassword Database -e "
    -- SQL
"
```

## 非结构化执行

``` shell
mysql -uUsername -pPassword << EOF
    -- SQL
EOF
```
