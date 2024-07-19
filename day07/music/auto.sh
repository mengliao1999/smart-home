#!/bin/bash 

# 录制音频的命令
arecord  -D  "plughw:0,0"  -f  S16_LE  -r  16000  -d  5  -t  wav  smart.wav

# 执行语音识别的应用程序
# > 将asrmain程序的打印信息重定向到speech_asr.txt文件中。
./asrmain > speech_asr.txt

# 运行语音识别提取语音关键字的程序，
./asr_fetch 

# 歌词比较
./cmp_lyric 

# 执行语音合成的程序，将识别的关键字转为为音频文件 
./ttsmain > /dev/null 

# 使用aplay命令播放音频文件 
aplay result.wav

