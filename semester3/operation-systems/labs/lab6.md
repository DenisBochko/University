# Лабораторная работа №6.

## 2 Справка по ps
```bash
man ps

ps --help
```

## 3 Краткая инфа о процессах в текущем терминале
```bash
ps
echo $$
```

## 4 Подробная инфа обо всех процессах
```bash
ps aux
USER               PID  %CPU %MEM      VSZ    RSS   TT  STAT STARTED      TIME COMMAND
denis            55876  72,3  3,6 423451072 301440   ??  R    18сен25 1094:20.03 /Applications/Telegram.app/Conte
_windowserver      588  30,9  2,0 420547136 170944   ??  Ss   31авг25 1352:12.04 /System/Library/PrivateFramework
denis            96630   8,7  1,4 1867067728 116672   ??  S     9:58     3:43.59 /Applications/Yandex Music.app/
denis            58122   8,2  0,1 35667764  10644   ??  S    пн10    7:06.73 /Applications/PuntoSwitcher.app/
denis            69293   2,6  0,8 420589088  67168   ??  S    пн05  186:40.55 /Applications/GoLand.app/Content
_coreaudiod        603   2,6  0,1 427003072  10896   ??  Ss   31авг25  80:11.56 /usr/sbin/coreaudiod
denis            94666   2,5  0,6 412405664  54224   ??  S     8:15     0:57.72 /System/Applications/Utilities/T
root               522   1,7  0,1 426926688   4352   ??  Ss   31авг25  50:02.73 /System/Library/Frameworks/CoreS
root               879   1,4  0,4 445715744  36224   ??  Ss   31авг25 559:49.26 /System/Library/Frameworks/CoreS

top -o cpu # Отсортировать по cpu 
Processes: 488 total, 2 running, 486 sleeping, 2821 threads                                                             09:37:28
Load Avg: 1.45, 1.98, 2.73  CPU usage: 3.38% user, 3.49% sys, 93.12% idle  SharedLibs: 314M resident, 56M data, 29M linkedit.
MemRegions: 0 total, 0B resident, 0B private, 844M shared. PhysMem: 7553M used (1621M wired, 3228M compressor), 69M unused.
VM: 210T vsize, 5703M framework vsize, 48272473(4) swapins, 50845189(0) swapouts.
Networks: packets: 58689228/60G in, 41336882/30G out. Disks: 144468149/3496G read, 38622427/1414G written.

PID    COMMAND      %CPU TIME     #TH    #WQ  #PORT MEM    PURG   CMPRS  PGRP  PPID  STATE    BOOSTS            %CPU_ME
98585  top          10.0 00:01.24 1/1    0    27    8945K- 0B     0B     98585 97827 running  *0[1]             0.00000
588    WindowServer 8.0  22:37:24 19     6    5465  1108M  80M+   334M-  588   1     sleeping *0[1]             0.17756
96630  Яндек?~ 7.8  8.057.70 24 9   1    620   382M+ 838M+ 0B     302M-  96626 96626 sleeping *0[8718+]         0.00000
0     Akernel_task  7.7  22:14:55 563/8  0    0     2559M    304M-0B     0     0     running   0[0]   ]         0.00000
94666  Terminal     3.5  01:17.90 10     3    502   177M   69M+   30M-   94666 1     sleeping *0[3050+]         0.22638
69293  goland       2.9  03:07:29 95     8    667   3445M  0B     2650M- 69293 1     sleeping *10343[6308]      0.00000
603    coreaudiod   2.2  80:43.28 8      1    11128 191M   0B     184M   603   1     sleeping *0[1]             0.07246

top -o mem # Отсортировать по mem
Processes: 497 total, 2 running, 495 sleeping, 2862 threads                                                             09:38:03
Load Avg: 1.38, 1.90, 2.67  CPU usage: 6.7% user, 4.0% sys, 89.91% idle    SharedLibs: 306M resident, 56M data, 28M linkedit.
MemRegions: 0 total, 0B resident, 143M private, 859M shared. PhysMem: 7533M used (1622M wired, 3241M compressor), 88M unused.
VM: 213T vsize, 5703M framework vsize, 48273150(4) swapins, 50845189(0) swapouts.
Networks: packets: 58691610/60G in, 41338483/30G out. Disks: 144470422/3496G read, 38624085/1414G written.

PID    COMMAND      %CPU TIME     #TH   #WQ  #PORT MEM    PURG  CMPRS  PGRP  PPID  STATE    BOOSTS            %CPU_ME %CPU_OTHRS
69293  goland       3.1  03:07:31 95    8    668   3446M  0B    2693M- 69293 1     sleeping *10343[6308]      0.00000 0.00000
0      kernel_task  8.5  22:15:02 563/8 0    0     2559M  0B    0B     0     0     running   0[0]             0.00000 0.00000
21369  com.apple.We 0.4  94:24.28 8     1    92-   1803M- 0B    1476M- 21369 1     sleeping  0[746093]        0.00000 0.00000
588    WindowServer 21.2 22:37:31 20    6    5470+ 1110M  69M   338M-  588   1     sleeping *0[1]             0.63972 0.96174
1365   Safari       0.2  03:57:04 29    20   3171  690M   0B    460M   1365  1     sleeping *1[37570]         0.00000 0.00000
94340  com.apple.We 0.1  02:54.43 4     2    75    386M   0B    332M   94340 1     sleeping  0[47952]         0.00000 0.00000
```

## 5 Найти процесс init (PID=1)
```bash
denis@MacBook-Air-Denis ~ % ps -fp 1 
  UID   PID  PPID   C STIME   TTY           TIME CMD
    0     1     0   0 31авг25 ??        56:11.51 /sbin/launchd
```

## 6 Перейти в другой терминал и запустить там процесс
```bash
# В другом терминале:
denis@MacBook-Air-Denis GolangProjects % mkdir test 
denis@MacBook-Air-Denis GolangProjects % touch test/main.go
denis@MacBook-Air-Denis GolangProjects % nano test/main.go 
denis@MacBook-Air-Denis GolangProjects % cat test/main.go 
package main

import (
	"fmt"
	"time"
)

func main() {
  for {
    fmt.Println("Привет! Я просто процесс.")
	  time.Sleep(1 * time.Second)
  }
}
denis@MacBook-Air-Denis GolangProjects % go run test/main.go 
Привет! Я просто процесс.
...

# В основом терминале:
denis@MacBook-Air-Denis ~ % ps
  PID TTY           TIME CMD
45682 ttys000    0:00.03 -zsh
45738 ttys002    0:00.02 /bin/zsh -il
45904 ttys003    0:00.07 -zsh
45933 ttys003    0:00.13 go run test/main.go
```

## 7-11 Убиваем процесс 
```bash
  PID TTY           TIME CMD
45682 ttys000    0:00.06 -zsh
45738 ttys002    0:00.02 /bin/zsh -il
45904 ttys003    0:00.09 -zsh
46042 ttys003    0:00.11 go run test/main.go
46046 ttys003    0:00.00 /Users/denis/Library/Caches/go-build/95/951e8be8088df9
denis@MacBook-Air-Denis ~ % kill 46042 46046
denis@MacBook-Air-Denis ~ % ps
  PID TTY           TIME CMD
45682 ttys000    0:00.07 -zsh
45738 ttys002    0:00.02 /bin/zsh -il
45904 ttys003    0:00.09 -zsh
denis@MacBook-Air-Denis ~ % 
```
### Разница: обычный юзер не может убить чужие процессы, root может.

## 12 Запускаем top
top
**ps показывает снимок процессов в момент вызова, а top — интерактивно обновляет в реальном времени, можно сортировать по CPU, памяти и т.д.**

## 13 Найти все процессы, у которых родитель (PPID) = 1
ps -eo pid,ppid,comm | grep " 1 "
# -e - показать все процессы в системе
# -o - какие именно столбцы показывать.

## Работа с jobs, fg, kill и приостановкой процессов
```bash
find / -name "*.html"
find: /usr/sbin/authserver: Permission denied
/usr/local/go/misc/wasm/wasm_exec.html
/usr/local/go/misc/chrome/gophertool/popup.html
/usr/local/go/misc/chrome/gophertool/background.html
/usr/local/go/doc/asm.html
/usr/local/go/doc/go1.17_spec.html
...
^Z
zsh: suspended  find / -name "*.html"

denis@MacBook-Air-Denis ~ % man bash
...
zsh: suspended  man bash

denis@MacBook-Air-Denis ~ % jobs
[1]  - suspended  find / -name "*.html"
[2]  + suspended  man bash
denis@MacBook-Air-Denis ~ % kill %1
denis@MacBook-Air-Denis ~ % 
[1]  - terminated  find / -name "*.html"
denis@MacBook-Air-Denis ~ % fg %2 
[2]  + continued  man bash

exit 
```
