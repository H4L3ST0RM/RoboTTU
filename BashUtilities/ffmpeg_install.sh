#!/bin/bash

wget https://github.com/ccrisan/motioneye/wiki/precompiled/ffmpeg_3.1.1-1_armhf.deb
dpkg -i ffmpeg_3.1.1-1_armhf.deb
apt-get install python-pip python-dev curl libssl-dev\
  libcurl4-openssl-dev libjpeg-dev libx264-142 libavcodec56\
  libavformat56 libmysqlclient18 libswscale3 libpq5
