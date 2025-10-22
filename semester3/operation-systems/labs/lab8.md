# Лабораторная работа №8.

# Создали файлы 
```bash
cd ~
echo "user file 1" > u1
echo "user file 2" > u2
echo "user file 3" > u3
```

# Получить развернутый список файлов домашнего каталога и сохранить его в listing1
```bash
ls -la ~ > listing1
cat listing1

total 240
drwxr-x---+  54 denis  staff   1728 22 окт 09:00 .
...
-rw-r--r--    1 denis  staff     12 22 окт 08:58 u1
-rw-r--r--    1 denis  staff     12 22 окт 08:58 u2
-rw-r--r--    1 denis  staff     12 22 окт 08:58 u3
drwxr-xr-x    9 denis  staff    288 15 окт 14:23 University
drwxr-xr-x    5 denis  staff    160  9 сен 21:30 VirtualBox VMs
```

# Просмотреть listing1
```bahs
ls -l | grep listing1
-rw-r--r--    1 denis  staff  3345 22 окт 09:00 listing1
```

# От имени root создать r1, r2, r3 в домашнем каталоге пользователя. Завершить сеанс root.
```bash
MacBook-Air-Denis:denis root# pwd
/Users/denis
MacBook-Air-Denis:denis root# echo "root file 1" > r1
MacBook-Air-Denis:denis root# echo "root file 2" > r2
MacBook-Air-Denis:denis root# echo "root file 3" > r3
MacBook-Air-Denis:denis root# ls -l r1 r2 r3
-rw-r--r--  1 root  staff  12 Oct 22 09:11 r1
-rw-r--r--  1 root  staff  12 Oct 22 09:11 r2
-rw-r--r--  1 root  staff  12 Oct 22 09:11 r3
```

#
```bash
ls -la ~ > listing1
denis@MacBook-Air-Denis ~ % cat listing1 
total 272
drwxr-x---+  58 denis  staff   1856 Oct 22 09:12 .
...
-rw-r--r--    1 denis  staff      0 Oct 22 09:13 listing1
-rw-r--r--    1 root   staff     12 Oct 22 09:11 r1
-rw-r--r--    1 root   staff     12 Oct 22 09:11 r2
-rw-r--r--    1 root   staff     12 Oct 22 09:11 r3
-rw-r--r--    1 root   staff     12 Oct 22 09:09 su1
-rw-r--r--    1 denis  staff     12 Oct 22 08:58 u1
-rw-r--r--    1 denis  staff     12 Oct 22 08:58 u2
-rw-r--r--    1 denis  staff     12 Oct 22 08:58 u3
```

# 
```bash 
denis@MacBook-Air-Denis ~ % echo "append by denis" >> u1
echo "append by denis" >> u2
echo "append by denis" >> u3
denis@MacBook-Air-Denis ~ % echo "try append to r1 by denis" >> r1
echo "try append to r2 by denis" >> r2
zsh: permission denied: r1
zsh: permission denied: r2
```

#
```bash 
MacBook-Air-Denis:denis root# chmod ug-w u1 
MacBook-Air-Denis:denis root# chmod a+w r1
MacBook-Air-Denis:denis root# ls -l u1 r1
-rw-rw-rw-  1 root   staff  12 Oct 22 09:11 r1
-r--r--r--  1 denis  staff  28 Oct 22 09:17 u1
```

# переключаемся на дениса 
```bash
denis@MacBook-Air-Denis ~ % echo "write test to u1" >> u1
echo "write test to r1" >> r1
zsh: permission denied: u1
```

# 
```bash
cat > hello << 'EOF'
#!/bin/sh
echo Hello, World!
echo -n "I'm "
whoami
EOF
```

```bash
hello
zsh: command not found: hello

sh hello
Hello, World!
-n I'm 
denis

chmod +x hello

./hello
denis@MacBook-Air-Denis ~ % ./hello 
Hello, World!
-n I'm 
denis
```

# 
```bash
mkdir -p /home/shared/pub /home/shared/upload /home/shared/temp

chown root:users  /home/shared/pub
chmod 775 /home/shared/pub

chown nobody:users /home/shared/upload
chmod 130 /home/shared/upload  

chown stud:users  /home/shared/temp
chmod 777 /home/shared/temp

ls -ld /home/shared /home/shared/*

drwxr-xr-x  5 root  root   4096 Oct 22 09:12 /home/shared
drwxrwxr-x  2 root  users  4096 Oct 22 09:12 /home/shared/pub
d--x-wx---  2 nobody users 4096 Oct 22 09:12 /home/shared/upload
drwxrwxrwx  2 stud  users  4096 Oct 22 09:12 /home/shared/temp
```

```bash
su denis
# копирование в pub (775, группа users) — доступно
cp u1 u2 u3 r1 r2 r3 /home/shared/pub 2>denis.err || true
ls -l /home/shared/pub | grep -E ' [ur][123]$' | sort

# копирование в upload (130) — можно писать, но нельзя читать содержимое
cp u1 /home/shared/upload
ls -l /home/shared/upload
echo $?

-rw-r--r-- 1 root  root  12 Oct 22 09:03 r1
-rw-r--r-- 1 root  root  12 Oct 22 09:03 r2
-rw-r--r-- 1 root  root  12 Oct 22 09:03 r3
-r--r--r-- 1 root  stud  29 Oct 22 09:06 u1
-rw-rw-r-- 1 root  stud  24 Oct 22 09:01 u2
-rw-rw-r-- 1 denis denis 12 Oct 22 09:01 u3
ls: cannot open directory '/home/shared/upload': Permission denied

su - stud
# удаление в pub разрешено группе (775 на каталоге)
rm /home/shared/pub/r3
ls -l /home/shared/pub | grep -E ' [ur][123]$' | sort
# в upload можно создать и удалить файл по имени, но нельзя листинг
echo "x" > /home/shared/upload/s.txt
rm /home/shared/upload/s.txt
ls -l /home/shared/upload; echo $?
exit

-rw-r--r-- 1 root  root  12 Oct 22 09:03 r1
-rw-r--r-- 1 root  root  12 Oct 22 09:03 r2
-r--r--r-- 1 root  stud  29 Oct 22 09:06 u1
-rw-rw-r-- 1 root  stud  24 Oct 22 09:01 u2
-rw-rw-r-- 1 denis denis 12 Oct 22 09:01 u3
ls: cannot open directory '/home/shared/upload': Permission denied
2


# root может всё
cp /home/denis/u1 /home/shared/temp/
cp /home/denis/r2 /home/shared/temp/
ls -l /home/shared/temp
rm -f /home/shared/temp/u1 /home/shared/temp/r2
ls -l /home/shared/temp

-r--r--r-- 1 root stud 29 Oct 22 09:06 u1
-rw-r--r-- 1 root root 12 Oct 22 09:03 r2
total 0
```

pub (775): чтение/запись для владельца и группы users, удаление файлов возможно при наличии w на каталоге.
upload (130): запись и вход для группы, но без чтения списка; можно копировать и удалять файл, если известно имя, листинг запрещён.
temp (777): всем всё можно.
