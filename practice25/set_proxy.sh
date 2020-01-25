#!/bin/bash
# set_proxy.sh
sudo echo "PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games\" " >> ~/set.sh
sudo echo "export http_proxy=\"http://2017vskokane:Vishal@12@196.1.114.80:2222\";" >> ~/set.sh
sudo echo "export https_proxy=\"http://2017vskokane:Vishal@12@196.1.114.80:2222\";" >> ~/set.sh
sudo echo "export ftp_proxy=\"ftp://2017vskokane:Vishal@12@196.1.114.80:2222/\";">> ~/set.sh;
sudo echo "export socks_proxy=\"socks://2017vskokane:Vishal@12@196.1.114.80:2222/\"">> ~/set.sh;

sudo echo "export HTTP_PROXY=\"http://2017vskokane:Vishal@12@196.1.114.80:2222\";" >> ~/set.sh
sudo echo "export HTTPS_PROXY=\"http://2017vskokane:Vishal@12@196.1.114.80:2222\";" >> ~/set.sh
sudo echo "export FTP_PROXY=\"ftp://2017vskokane:Vishal@12@196.1.114.80:2222/\";">> ~/set.sh;
sudo echo "export SOCKS_PROXY=\"socks://2017vskokane:Vishal@12@196.1.114.80:2222/\"">> ~/set.sh;
