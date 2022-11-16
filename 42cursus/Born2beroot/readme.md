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