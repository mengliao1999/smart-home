#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char buf[1024] = {0}; // 定义一个缓冲区，存放数据

	FILE *src_fp = NULL;  // 源文件的流指针
	FILE *dest_fp = NULL; // 目标文件的流指针 
	char *retval_P = NULL; // 接收返回值
	
	char *str_start = NULL;  // 存放关键信息前边的子字符串的起始地址
	char *str_end = NULL;    // 存放关键信息后边的子字符串的其实地址


	// 使用fopen函数打开源文件  speech_asr.txt 
	src_fp = fopen("./speech_asr.txt", "r");
	if(src_fp == NULL) {
		printf("open speech_asr.txt failed!\n");
		return -1;
	}

	// 使用fopen函数打开目标文件  word-of-song.txt 
	dest_fp = fopen("./word-of-song.txt", "w");
	if(dest_fp == NULL) {
		printf("open ./word-of-song.txt failed!\n");
		return -1;
	}

	while(1) {
		// 从speech_asr.txt文件中读取信息
		retval_P = fgets(buf, sizeof(buf), src_fp);
		if (retval_P == NULL) {
			break; // 退出while循环
		}
		// 从读取的信息中检索子字符串
		str_start = strstr(buf, "[\"");   //   \ ---》 转义字符 
		str_end = strstr(buf, "\"]");
		// 如果检索到之后，str_start和str_end都不是NULL
		if (str_start != NULL && str_end != NULL) {
			// 提取关键信息，并将结果写到result.txt文件中 
			fwrite(str_start+2, 1, str_end - 3 - (str_start + 2), dest_fp);
		}
	}

	// 关闭文件
	fclose(src_fp);
	fclose(dest_fp);

	return 0;
}
