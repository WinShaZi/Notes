//结果每次都相同

//因为引擎返回相同的随机数序列，所以必须在循环外声明引擎对象
//否则每次循环都会创建一个新的引擎（随机数序列不变），而每次都会输出引擎的序列