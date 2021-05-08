1、用户信息
git config --global user.name "cuijian2b"
git config --global user.email 1101976450@qq.com
git config --list

2、错误信息处理
git config --global http.sslVerify false
将该值设置成比较大的值
git config --global http.postBuffer 1024288000
Encountered end of file时设置
git config --global --unset https.proxy