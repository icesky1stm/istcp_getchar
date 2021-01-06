# istcp_getchar
一个监听端口收到的所有消息的微型小工具，做通讯测试。
按位接收报文，即使对方发送的报文格式不符合约定的格式，也可以实时输出到屏幕上，方便观察实际情况并有方向的调整。

## 安装
在istcp_getchar目录下，执行make命令。

## 运行
执行:
`istcp_getchar  端口号`
则会监听该端口下的请求的报文内容并打印到屏幕上。

