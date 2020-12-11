import pymysql


def ShowAll(cursor):
    # 获取全部查询结果
    resultMap = cursor.fetchall()
    for row in resultMap:
        print('{:<5s} {:<15s} {:<25s}'.format(str(row[0]), str(row[1]), str(row[2])))


db = pymysql.connect(host='localhost', port=3306, user='root', password='asdf', database='testdb')
cursor = db.cursor()

# 返回查询结果的行数
rowCount = cursor.execute('SELECT * FROM temp')
print('Result Row Count : {:d}'.format(rowCount))
ShowAll(cursor)

# 插入两条数据
rowCount = cursor.execute('INSERT INTO temp (string) VALUES (\'AAA\'), (\'BBB\')')
print('Result Row Count : {:d}'.format(rowCount))

# 获取单个查询结果
cursor.execute('SELECT * FROM temp')
resultArr = cursor.fetchone()
print('{:<5s} {:<15s} {:<25s}'.format(str(resultArr[0]), str(resultArr[1]), str(resultArr[2])))
resultArr = cursor.fetchone()
print('{:<5s} {:<15s} {:<25s}'.format(str(resultArr[0]), str(resultArr[1]), str(resultArr[2])))
# 获取多个查询结果
resultMap = cursor.fetchmany(5)
for row in resultMap:
    print('{:<5s} {:<15s} {:<25s}'.format(str(row[0]), str(row[1]), str(row[2])))

# 更改两条数据
rowCount = cursor.execute('UPDATE temp SET string = \'update\' WHERE ID > 5')
print('Result Row Count : {:d}'.format(rowCount))
cursor.execute('SELECT * FROM temp')
ShowAll(cursor)

# 删除两条数据
rowCount = cursor.execute('DELETE FROM temp WHERE ID > 5')
print('Result Row Count : {:d}'.format(rowCount))
cursor.execute('SELECT * FROM temp')
ShowAll(cursor)

cursor.close()
db.close()
