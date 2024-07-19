#include <stdio.h>
#include <string.h>


int main(int argc, const char *argv[])
{
	FILE *song_fp = NULL;
	FILE *music_fp = NULL;
	FILE *result_fp = NULL;
	char song_buf[128] = {0};  // 将语音是被的歌词放到song_buf缓冲区中
	char *retval_p = NULL;
	char music_buf[128] = {0}; // 存music.txt文件中的歌词
	char lyric_buf[128] = {0}; // 存放music.txt提取的歌词
	char *str_start = NULL;
	char *str_end = NULL;

	int retval;
	int flag = 0;
	song_fp = fopen("./word-of-song.txt","r");
	if (song_fp == NULL) {
		perror("word-of-song.txt");
		return -1;
	}
	music_fp = fopen("./music.txt", "r");
	if (music_fp == NULL) {
		perror ("music.txt");
		return -1;
	}
	result_fp = fopen("./result.txt", "w");
	if (result_fp == NULL) {
		perror("result.txt");
		return -1;
	}
	// 从语音识别的文件中读取歌词
	retval_p = fgets(song_buf, sizeof(song_buf),song_fp);
	printf("%s\n", song_buf);
	if (retval_p == NULL) {
		perror("fgets");
		return -1;
	}

	while(1) {
		retval_p = fgets(music_buf, sizeof(music_buf), music_fp);
		printf("%s\n", music_buf);
		if (retval_p == NULL) {  // 读到文件的结尾
			if (flag == 0) {
				char *str = "曲库中不存在此音乐";
				fwrite(str,1,strlen(str),result_fp);
			}
			break;
		}
		str_start = strstr(music_buf, "[\"");
		str_end = strstr (music_buf,"\"]");
		if (str_start != NULL && str_end != NULL) {
			memset(lyric_buf,0,128);
			// 字符串拷贝的函数
			strncpy(lyric_buf, str_start+2, str_end-str_start-2);
			printf("%s\n", lyric_buf);
			// 字符串比较函数, 两个字符串相等返回0
			retval = strcmp(song_buf,lyric_buf);
			if(retval == 0) {
				flag++;
				// 提取歌词对应的歌名 
				str_start = strstr(music_buf, "《");
				str_end = strstr(music_buf, "》");
				if(str_start != NULL && str_end != NULL) {
					fwrite(str_start+3, 1, str_end-(str_start+3), result_fp);	
				}
			}
		}
	}
	fclose(music_fp);
	fclose(result_fp);
	fclose(song_fp);
	return 0;
}
