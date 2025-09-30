# Лабораторная работа №5.

```bash
ls

Applications	Documents	GolandProjects	Movies		Postman		University
CPP_test	Downloads	GolangProjects	Music		Public		VirtualBox VMs
Desktop		go		Library		Pictures	PycharmProjects

ls -l

drwx------@   5 denis  staff   160 22 дек  2024 Applications
drwxr-xr-x    9 denis  staff   288 11 май 16:26 CPP_test
drwx------+   4 denis  staff   128 16 сен 11:10 Desktop
drwx------@  14 denis  staff   448 10 сен 15:40 Documents
drwx------@ 267 denis  staff  8544 24 сен 14:33 Downloads
drwxr-xr-x@   5 denis  staff   160 10 окт  2024 go
drwxr-xr-x@  17 denis  staff   544 29 сен 20:23 GolandProjects
drwxr-xr-x   14 denis  staff   448 14 июл 11:52 GolangProjects
drwx------@ 107 denis  staff  3424  3 сен 08:53 Library
drwx------@   6 denis  staff   192 23 ноя  2024 Movies
drwx------+   7 denis  staff   224 16 май  2024 Music
drwx------@  19 denis  staff   608  9 сен 22:59 Pictures
drwxr-xr-x@   3 denis  staff    96 12 фев  2025 Postman
drwxr-xr-x+   4 denis  staff   128 18 авг  2023 Public
drwxr-xr-x    3 denis  staff    96 22 дек  2024 PycharmProjects
drwxr-xr-x    9 denis  staff   288 17 сен 13:17 University
drwxr-xr-x    5 denis  staff   160  9 сен 21:30 VirtualBox VMs
```

```bash
cd /

denis@MacBook-Air-Denis / % ls >> ~/filelist.lst
denis@MacBook-Air-Denis / % cat ~/filelist.lst 
Applications
bin
cores
dev
etc
home
Library
opt
private
sbin
System
tmp
Users
usr
var
Volumes
```

```bash
cd ~
denis@MacBook-Air-Denis ~ % ls -laR
total 256
drwxr-x---+  51 denis  staff   1632 30 сен 20:17 .
drwxr-xr-x    5 root   admin    160 31 авг 21:11 ..
-rw-r--r--@   1 denis  staff    148 27 июл 15:47 .bash_profile
drwxr-xr-x@   5 denis  staff    160 25 сен 15:01 .cache
-r--------    1 denis  staff      8 18 авг  2023 .CFUserTextEncoding
drwxr-xr-x@   4 denis  staff    128 16 сен 16:27 .config
drwx------    3 denis  staff     96  4 мар  2024 .cups
drwxr-xr-x@   6 denis  staff    192 12 мар  2025 .dbclient
drwx------@   3 denis  staff     96 30 сен 14:58 .dlv
drwxr-xr-x@  16 denis  staff    512 29 сен 10:55 .docker
-rw-r--r--@   1 denis  staff  18436 29 сен 17:40 .DS_Store
-rw-r--r--    1 denis  staff     54 20 авг  2024 .gitconfig
drwxr-xr-x    5 denis  staff    160  4 янв  2024 .idlerc
-rw-r--r--@   1 denis  staff   1508 27 июл 15:47 .jetbrains.vmoptions.sh
...
```

```bash
mkdir -p src dst temp
echo "произвольное содержимое" >> src/f1.txt
touch user.txt
touch txt

cp user.txt src
cp txt src

denis@MacBook-Air-Denis ~ % ls -l src                   
total 8
-rw-r--r--  2 denis  staff  48 30 сен 20:26 f1.txt
-rw-r--r--  2 denis  staff   0 30 сен 20:29 txt
-rw-r--r--  2 denis  staff   0 30 сен 20:29 user.txt

ln src/f1.txt dst/f1.txt
ln src/user.txt dst/user.txt
ln src/txt dst/txt

ln -s src/f1.txt f1.txt
ln -s src/user.txt user.txt
ln -s src/txt txt

denis@MacBook-Air-Denis ~ % ls -l
total 0
drwx------@   5 denis  staff   160 22 дек  2024 Applications
drwxr-xr-x    9 denis  staff   288 11 май 16:26 CPP_test
drwx------+   4 denis  staff   128 16 сен 11:10 Desktop
drwx------@  14 denis  staff   448 10 сен 15:40 Documents
drwx------@ 267 denis  staff  8544 24 сен 14:33 Downloads
drwxr-xr-x    5 denis  staff   160 30 сен 20:33 dst
lrwxr-xr-x    1 denis  staff    10 30 сен 20:35 f1.txt -> src/f1.txt
drwxr-xr-x@   5 denis  staff   160 10 окт  2024 go
drwxr-xr-x@  17 denis  staff   544 29 сен 20:23 GolandProjects
drwxr-xr-x   14 denis  staff   448 14 июл 11:52 GolangProjects
drwx------@ 107 denis  staff  3424  3 сен 08:53 Library
drwx------@   6 denis  staff   192 23 ноя  2024 Movies
drwx------+   7 denis  staff   224 16 май  2024 Music
drwx------@  19 denis  staff   608  9 сен 22:59 Pictures
drwxr-xr-x@   3 denis  staff    96 12 фев  2025 Postman
drwxr-xr-x+   4 denis  staff   128 18 авг  2023 Public
drwxr-xr-x    3 denis  staff    96 22 дек  2024 PycharmProjects
drwxr-xr-x    5 denis  staff   160 30 сен 20:29 src
drwxr-xr-x    2 denis  staff    64 30 сен 20:25 temp
lrwxr-xr-x    1 denis  staff     7 30 сен 20:36 txt -> src/txt
drwxr-xr-x    9 denis  staff   288 17 сен 13:17 University
lrwxr-xr-x    1 denis  staff    12 30 сен 20:36 user.txt -> src/user.txt
drwxr-xr-x    5 denis  staff   160  9 сен 21:30 VirtualBox VMs
```

```bash
denis@MacBook-Air-Denis ~ % cat src/f1.txt
произовальное содержание
denis@MacBook-Air-Denis ~ % cat dst/f1.txt
произовальное содержание
denis@MacBook-Air-Denis ~ % cat f1.txt    
произовальное содержание

denis@MacBook-Air-Denis ~ % mv src/f1.txt temp
denis@MacBook-Air-Denis ~ % cat src/f1.txt    
cat: src/f1.txt: No such file or directory
denis@MacBook-Air-Denis ~ % cat dst/f1.txt    
произовальное содержание
denis@MacBook-Air-Denis ~ % cat f1.txt        
cat: f1.txt: No such file or directory

denis@MacBook-Air-Denis ~ % rm temp/f1.txt 
denis@MacBook-Air-Denis ~ % cat src/f1.txt
cat: src/f1.txt: No such file or directory
denis@MacBook-Air-Denis ~ % cat dst/f1.txt
произовальное содержание
denis@MacBook-Air-Denis ~ % cat f1.txt    
cat: f1.txt: No such file or directory

# Жесткая ссылка указывает на тот же самый inode и не зависит от имени файла.
# Мягкая ссылка хранит текстовый путь. Путь меняется - симлинк умирает
```

```bash
find . -maxdepth 1 -name '*.txt'
```
