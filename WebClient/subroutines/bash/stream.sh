#!/bin/bash
raspivid -o - -t 0 -fps 20 -b 600000 -h 240 -w 426 |

ffmpeg \
        -re -ar 44100 -ac 2 -acodec pcm_s16le \
        -f s16le -ac 2 -i /dev/zero -f h264 \
        -thread_queue_size 1024 -i - -vcodec copy \
        -acodec aac -ab 128k -g 50 \
        -strict experimental -f flv \
        rtmp://x.rtmp.youtube.com/live2/sch6-s2hc-1j61-bq8x &
