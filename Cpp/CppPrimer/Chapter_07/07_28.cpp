//如果都返回的是Screen，则move和set都修改的是副本，
//原始的myScreen并没有被修改，myScreen.display(cout);
//语句最终打印出来还是（5， 5， ‘X’）的值