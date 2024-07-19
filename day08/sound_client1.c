#include <stdio.h>
#include <sys/types.h>       
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 接收socket函数的返回值，
int sockfd = 0; 

// 定义客户端链接服务器地址的结构体变量
struct sockaddr_in  server_addr;

// 发送数据缓冲区
char send_buf[4] = "421";

// 接收数据的缓冲区
char recv_buf[128] = {0};
int retval;

int main(int argc, const char *argv[])
{
	/*
	 * ip地址：
	 * 	 	使用wifi上网查看wlan的IP地址
	 * 	 	使用有线网上网查看以太网的IP地址
	 * 端口号：8888
	 * */
	if (argc != 3) {
		printf("commond : %s  <windows ip addr>  <port number>\n", argv[0]);
		return -1;
	}
	
	// 使用socket函数创建网络套接字
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == 0) {
		perror("socket");
		return -1;
	}
	// 对server_addr变量初始化 
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	// 连接服务器端
	retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (retval == -1) {
		perror("connect");
		return -1;
	}

	// 客户端给服务器端发送数据
	retval = send(sockfd, send_buf, 3, 0);
	if (retval == -1) {
		perror("send");
		return -1;
	} else {
		memset(send_buf, 0, sizeof(send_buf));
	}
	// 客户端从服务器端接收数据 
	retval = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
	if(retval == -1) {
		perror("recv");
		return -1;
	} else {
		printf("%s\n", recv_buf);
		memset(recv_buf, 0, sizeof(recv_buf));
	}

	// 关闭客户端
	close(sockfd);
	
	return 0;
}

