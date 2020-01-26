#!/bin/bash

sudo -v

sudo apt install cmake libpcre3-dev zlib1g-dev libgcrypt11-dev libicu-dev python

CURR_DIR=$(pwd)

cd ..
git clone https://github.com/artyom-beilis/cppcms.git cppcms
cd cppcms
mkdir build
cd build
cmake . .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
sudo make install

cd ../../$CURR_DIR

sudo -A apt-get update
sudo -A apt-get install -y --no-install-recommends pkg-config
sudo -A apt-get install -y --no-install-recommends autoconf
sudo -A apt-get install -y --no-install-recommends libpulse-dev:amd64
sudo -A apt-get install -y --no-install-recommends libgtk-3-dev:amd64