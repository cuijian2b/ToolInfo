# 1、C++编译环境
yum list gcc-c++
yum install gcc-c++.x86_64
gcc -g test.c -o test
检查是否安装 rpm -qa|grep gdb

# 2、启动gdb
gdb out.c 
gdb -q out.c //表示不打印gdb版本信息，界面较为干净；

# 3、gdb命令行
list(简写 l)： 查看源程序代码
run(简写 r) ：运行程序直到遇到 结束或者遇到断点等待下一个命令
break(简写 b) ：格式 b 行号，在某行设置断点；
info breakpoints ：显示断点信息
continue（简写 c)： 继续执行程序，直到下一个断点或者结束；
next（简写 n ）：单步执行程序，但是遇到函数时会直接跳过函数，不进入函数；
step(简写 s) ：单步执行程序，但是遇到函数会进入函数；
until+行号： 运行至某行，不仅仅用来跳出循环；
finish： 运行程序，直到当前函数完成返回，并打印函数返回时的堆栈地址和返回值及参数值等信息；
call 函数(参数)：调用程序中可见的函数，并传递“参数”，如：call gdb_test(55)；
print、whatis命令查看变量值、属性

# 3、gdb调试运行中的程序
attach