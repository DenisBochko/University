# Лабораторная работа №9.

## 2. Сравнение прав доступа директорий `/bin` и `/tmp`
```bash
ls -ld /bin /tmp

drwxr-xr-x 2 root root 4096 Oct 28 10:00 /bin
drwxrwxrwt 26 root root 5168 Oct 28 10:04 /tmp
```

- `/bin` доступна только для чтения и исполнения обычным пользователям.  
- `/tmp` доступна всем, но sticky-bit (`t`) защищает файлы от удаления другими пользователями.

## 3. Создание файла с правом только на чтение владельцу
```bash
touch secret.txt
chmod 400 secret.txt
ls -l secret.txt

-r--------  1 denis  staff  0 29 окт 08:51 secret.txt
```

## 4. Поведение при снятии права исполнения с директории

Если у других пользователей есть запись, но нет исполнения, они не смогут открыть каталог, а значит не смогут даже добавить туда файл.

## 5. Поиск всех файлов с установленным suid-битом
```bash
find / -perm -4000  

/usr/bin/top
/usr/bin/atq
/usr/bin/crontab
/usr/bin/atrm
/usr/bin/newgrp
/usr/bin/su
/usr/bin/batch
/usr/bin/at
/usr/bin/quota
/usr/bin/sudo
/usr/bin/login
/usr/libexec/security_authtrampoline
/usr/libexec/authopen
...
```

## 6. Пользователи с оболочкой /bin/false
```bash
grep '/bin/false' /etc/passwd
nobody:*:-2:-2:Unprivileged User:/var/empty:/usr/bin/false
daemon:*:1:1:System Services:/var/root:/usr/bin/false
_taskgated:*:13:13:Task Gate Daemon:/var/empty:/usr/bin/false
_networkd:*:24:24:Network Services:/var/networkd:/usr/bin/false
_installassistant:*:25:25:Install Assistant:/var/empty:/usr/bin/false
_lp:*:26:26:Printing Services:/var/spool/cups:/usr/bin/false
_postfix:*:27:27:Postfix Mail Server:/var/spool/postfix:/usr/bin/false
_scsd:*:31:31:Service Configuration Service:/var/empty:/usr/bin/false
```