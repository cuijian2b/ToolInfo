# 系统信息
ps -u
ps　-ef 查看所有进程
grep -v grep 是在列出的进程中去除含有关键字“grep”的进程。
kill -9 会强行杀掉指定进程，这样就成功清除了同名进程。
xargs kill -9
fg %number 就一恢复某个后台运行的命令到前台了
ulimit -c unlimited 允许生成dump文件
ulimit -c查询配置信息

# 写入
命令：sh xxx.sh 1>/dev/null 2>&1 &
解释：
/dev/null代表linux的空设备文件，所有往这个文件里面写入的内容都会丢失，俗称“黑洞”。
&是表明1是标准输出

# 查询
pwd 打印绝对路径
