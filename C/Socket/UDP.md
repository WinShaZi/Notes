# UDP

## 服务端

    # 创建服务端套接字
    socket()
      ↓
    # 将服务端套接字绑定到指定IP地址和端口号
    bind()
      ↓
    # 向客户端发送数据或者接收客户端的数据
    sendto()/recvfrom()
      ↓
    # 关闭套接字
    close()

## 客户端

    # 创建客户端套接字
    socket()
      ↓
    # 向服务端发送数据或者接收客户端的数据
    sendto()/recvfrom()
      ↓
    # 关闭套接字
    close()
