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
char send_buf[4] = "";

// 接收数据的缓冲区
char recv_buf[128] = {0};

// 语音识别的缓冲区
char asr_buf[128] = {0};

// 命令码的缓冲区 
char cmd_buf[128] = {0};

int retval;
char *retval_p = NULL;
char *str_start = NULL, *str_end = NULL;

int main(int argc, const char *argv[])
{
	FILE *asr_fp = NULL;
	FILE *cmd_fp = NULL;
	FILE *res_fp = NULL;
	char buffer[128] = {0};
	int flag = 0;
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
	// 打开语音识别提取关键字的文件
	asr_fp = fopen("./asr_fetch.txt", "r");
	if (asr_fp == NULL) {
		perror("asr_fetch.txt");
		return -1;
	}
	// 打开命令码的文件
	cmd_fp = fopen("./command.txt", "r");
	if(cmd_fp == NULL) {
		perror("commond.txt");
		return -1;
	}
	// 打开存放客户端从接收服务器数据的文件
	res_fp = fopen("./result.txt", "w");
	if (res_fp == NULL) {
		perror("result.txt");
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

	// 从asr_fetch.txt读取语音是被的关键字
	fread(asr_buf, 1, sizeof(asr_buf),asr_fp);
	printf("asr_buf = %s\n", asr_buf);	
	while(1) {
		// 从commond.txt中读取命令码 
		retval_p = fgets(cmd_buf, sizeof(cmd_buf), cmd_fp);
		if (retval_p == NULL) {
			if(flag == 0) {
				char *str = "你好，主人，我没有听懂，我正在努力提升自己!";
				fwrite(str, 1, strlen(str), res_fp);
			}
			break;
		}
		// 提取命令字符串
		str_start = strstr(cmd_buf, "[\"");
		str_end = strstr(cmd_buf, "\"]");
		if (str_start != NULL && str_end != NULL) {
			// 给buffer缓冲区清空
			memset(buffer, 0 ,sizeof(buffer));
			// 字符串的拷贝
			strncpy (buffer, str_start+2, str_end-(str_start+2));
			// 字符串的比较
			retval = strcmp(asr_buf, buffer);
			if(retval == 0) {
				flag++;
				// 提取命令字符串对应的命令码
				str_start = strstr(cmd_buf, "<");
				str_end = strstr(cmd_buf, ">");
				if(str_start != NULL && str_end != NULL) {
					// 拷贝命令码到send_buf
					strncpy(send_buf, str_start+1, str_end-(str_start+1));
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
						fwrite(recv_buf, 1 , sizeof(recv_buf), res_fp);
						memset(recv_buf, 0, sizeof(recv_buf));
					}

				}
			}
		
		}
	

	}
	// 关闭客户端
	close(sockfd);
	
	return 0;
}

