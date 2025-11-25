# Лабораторная работа №11

Задание №1 - Навигация по дискам и каталогам

```cmd
C:
cd \
cd "Program Files"
cd ..
D:
cls
```

Создание и переименование каталогов

```cmd
md Practica
cd Practica
md Ученик
ren Ученик Студент
cd ..
dir

26.11.2025  01:40    <DIR>          Practica
01.09.2024  15:36    <DIR>          PycharmProjects
25.02.2025  20:53    <DIR>          Saved Games
23.03.2025  01:54    <DIR>          scoop
10.10.2025  22:01    <DIR>          sdk
25.02.2025  20:53    <DIR>          Searches
```

Создание структуры каталогов

```cmd
md "D:\Иванов\Иван\Иванович"
```

Задание №2 - Создание структуры каталогов на диске C

```cmd
C:
md "C:\task\temp\temp1"
dir C:\task\temp

 Содержимое папки C:\task\temp

26.11.2025  01:41    <DIR>          .
26.11.2025  01:41    <DIR>          ..
26.11.2025  01:41    <DIR>          temp1
```

Удаление каталогов

```cmd
rd "C:\task\temp\temp1"
```

Задание №3 - Удаление структуры каталогов

```cmd
rd "D:\Practica\Студент"
rd "D:\Practica"
rd "C:\task\temp"
rd "C:\task"
```

Работа с файлами - создание файла

```cmd
C:\Users\andrn>Copy Con Практика.Txt
Задание выполнено
^Z
Скопировано файлов:         1.
```

Просмотр содержимого файла

```cmd
C:\Users\andrn>Type Практика.Txt
Задание выполнено
```

Задание №4 - Создание файла на диске C

```cmd
C:
copy con 100.Txt
Интерфейс командной строки
^Z
type 100.Txt
```

Переименование файлов

```cmd
D:
ren Практика.Txt Example.Txt
ren Example.Txt Example.Doc
```

Удаление файла

```cmd
del Example.Doc
```

Объединение файлов

```cmd
copy con 1.Txt
Работа с
^Z
copy con 2.Txt
командной
^Z
copy con 3.Txt
строкой
^Z
copy 1.Txt + 2.Txt + 3.Txt 4.Txt
type 4.Txt
```

Копирование файлов

```cmd
md COPYR
copy 4.Txt C:
copy C:\Windows\*.txt COPYR
dir COPYR
```

Задание №5 - Создание файла с сложной структурой

```cmd
C:
md 100\200
copy con 100\200\300.txt
Содержимое файла 300.txt
^Z
dir 100\200

C:\Users\andrn>dir 100\200
 Содержимое папки C:\Users\andrn\100\200

26.11.2025  01:49    <DIR>          .
26.11.2025  01:49    <DIR>          ..
26.11.2025  01:49                43 300.txt
```

Удаление созданной структуры

```cmd
del 100\200\300.txt
rd 100\200
rd 100
dir

НЕТ такого
```

Итоговое задание

```cmd
md Tom1\Tom2
copy con Tom1\Tom2\Test.Txt
Итоговое задание
^Z
ren Tom1\Tom2\Test.Txt Tom1\Tom2\Samba.Doc
type Tom1\Tom2\Samba.Doc
```

Очистка и финальные операции

```cmd
del Tom1\Tom2\Samba.Doc
rd Tom1\Tom2
rd Tom1
md Master
copy C:\Windows\*.gif Master
dir Master
```
