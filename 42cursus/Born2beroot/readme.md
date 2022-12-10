# ss -tunlp 에서 dhcp client 지우기 (68포트)
DHCP 대신 Static IP로 설정
ip route 명령어로 현재 할당된 아이피 설정 후
/etc/network/interfaces 접속하여 할당된 아이피로 고정

# 파티션 설정 방법
Set vdisk to 8gb
and install as partition crypted lvm

# ufw?
install sudo
use command
sudo ufw

sudo ufw default deny

# Important commands
su
su [username]
sudo

# Set ssh port
/etc/ssh/sshd_config

# Difference beteween aptitude, and apt?

aptitude
GUI but also have cli mode
Has more functions such as storing unused pkg during updrage
when removing unused pkg, aptitude will remove other unused pkg (in apt, auto-remove, autoremove)


apt
CLI
/etc/apt/sources.list


apt-cache search 'python' | head -n4
aptitude search 'python' | head -n4

# How to connect to ssh?
just type
ssh 

# Difference between SE-Linux and AppArmor

SELinux
MAC
RedHat
(User, Apllication, Process) > Subject
(File, Socker, Driver)

AppArmor
SUSE, Debian
MAC Model
Focus on protecting applications

# Unimplimented
SSH
Password Policy
SE Linux, AppArmor
How to add user and group?

# some hmm points.
%% awk means esacped % percent
 lsblk lists information about all available or the specified
       block device

# journalctl
Show the systemd logs
_comm shows specific logs

# free?
-m megabytes

fdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')


# Todos??
visudoser..
password policy pwquality

# re-start

https://www.youtube.com/watch?v=_mgFFt9xTG0

0. su
1. apt install sudo
2. apt install vim

edit sshd
/etc/ssh/sshd_config

3. apt install ufw
sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow 4242
sudo ufw enable

su
vi /etc/group

add soulee after sudo group

4. sudo groupadd user42
5. sudo usermod -G user42 soulee
6. sudo vi /etc/login.defs
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2 

7. sudo vi /etc/security/pwqulity.conf
minlen = 8
maxrepeat = 3
dcredit = -1
ucredit = -1
difok = 7
reject_username
enforce_for_root

8. chage -M 30 -m 2 -W 7 soulee
chage -M 30 -m 2 -W 7 root

9. sudo visudo
Defaults    badpass_message="custommsg"
Defaults    authfail_message="custommsg"
Defaults    log_input
Defaults    log_output
Defaults    requiretty
Defaults    iolog_dir="/var/log/sudo/"
Defaults    passwd_tries=3

and changed the secure path

10. make some script
chmod 777 monitoring.sh

crontab -e
*/10 * * * * /home/[username]/monitoring.sh

if you want to shutdown service,
you can just type
sudo service cron stop

11.
sudo apt install php php-cli php-fpm php-json php-pdo php-mysql php-zip php-gd  php-mbstring php-curl php-xml php-pear php-bcmath

vi /etc/php/[version]/fpm/php.ini
and de-comment cgi.fix_pathinfo=1

vi /etc/lighttpd/conf-available/15-fastcgi-php.conf
comment socket
and add
"socket" => "/var/run/php"
...

sudo lighttpd-enable-mod fastcgi
sudo lighttpd-enable-mod fastcgi-php
sudo serice lighttpd force-reload
sudo ufw allow 80

11. remove 68 in ss
ip addr

ip route

vi /etc/network/interfaces
add
auto enp0s3
iface enp0s3 inet static
netmask 255.255.255.0
gatewaty 10.0.2.2

ifdown enp0s3
ifup enp0s3
shutdown -r now

12. port foward
in vbox, network setting
add port 4242 and 80

13. install maria-db
sudo apt install mariadb-server mariadb-client
sudo mysql_secure_installation

14. install wordpress
sudo wget -O "https://wordpress.org/latest.tar.gz"
sudo tar -xvzf latest.tar.gz -C /var/www/html

15. setup mysql
sudo mysql -u  root -p

CREATE DATABASE wordpress;
CREATE USER 'username'@'localhost' IDENTIFIED BY 'password';
GRANT ALL ON wordpress.* TO 'username'@'localhost' IDENTIFIED BY 'password' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EXIT;

# In defence
When excuting sudo, it will excuted on other shell.
1. adduser
2. usermod -G [group] [username] (Secondary group)
3. chage -l [username]
4. passwd


hostname [hostname]
ufw status numbered
ufw delete allow 8080
sudo sytemctl disable cron

apache2??
LVM 장점
새로운 블럭 장치가 추가된 경우 기존 파일시스템
변경 없이 볼륨을 키울수 있다

여러 물리적 디스크를 묶을수 있다

스냅샷을 생성할수 있다

vProc number of cores
pProc Number of sockets

LVM 쓰는 이유?
user 만들고 group
hostname 변경하기
hostctl set-hostname --static [hostname]
