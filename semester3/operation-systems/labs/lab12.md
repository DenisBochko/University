# Лабораторная работа №12

1 Пакетный файл для обновления архива (update_archive.bat)

```cmd
@echo off
REM Выбор архиватора
echo Выбор архиватора:
echo 1 - WinRAR
echo 2 - 7-Zip
echo 3 - WinZIP

set /p choice="Выберите архиватор (1-3): "

REM Имя архива передано первым параметром
set archive_name=%1

if "%choice%"=="1" (
    REM Обновление архива через WinRAR (u = update)
    "C:\Program Files\WinRAR\WinRAR.exe" u "%archive_name%"
) else if "%choice%"=="2" (
    REM 7-Zip: режим u также обновляет
    "C:\Program Files\7-Zip\7z.exe" u "%archive_name%"
) else if "%choice%"=="3" (
    REM WinZIP
    "C:\Program Files\WinZIP\WZIP32.EXE" -u "%archive_name%"
) else (
    echo Неверный выбор
)
```

2 Пакетный файл для очистки подкаталога (clean_subdir.bat)

```cmd
@echo off
REM Подтверждение удаления файлов
set /p confirm="Вы уверены, что хотите очистить подкаталог? (y/n): "

if "%confirm%"=="y" (
    REM Удаление всех файлов в текущем каталоге
    del /Q *.*
    echo Подкаталог очищен
) else (
    echo Операция отменена
)
```

3 Пакетный файл для проверки на вирусы (antivirus_check.bat)

```cmd
@echo off
REM Выбор диска для антивирусной проверки
echo Выбор диска:
echo 1 - C:
echo 2 - D:
echo 3 - E:

set /p drive="Выберите диск (1-3): "

REM Путь к антивирусу передаётся параметром %1
set antivirus=%1

if "%drive%"=="1" (
    %antivirus% C:\
) else if "%drive%"=="2" (
    %antivirus% D:\
) else if "%drive%"=="3" (
    %antivirus% E:\
) else (
    echo Неверный выбор
)
```

4 Пакетный файл для выбора редактора (editor_choice.bat)

```cmd
@echo off
REM Имя файла передаётся параметром %1
set filename=%1

echo Выбор редактора:
echo 1 - Notepad
echo 2 - Notepad++
echo 3 - VS Code
set /p editor="Выберите редактор (1-3): "

if "%editor%"=="1" (
    REM Открытие в стандартном Notepad
    notepad "%filename%"
) else if "%editor%"=="2" (
    REM Notepad++
    "C:\Program Files\Notepad++\notepad++.exe" "%filename%"
) else if "%editor%"=="3" (
    REM Visual Studio Code
    code "%filename%"
) else (
    echo Неверный выбор
)
```

5 Пакетный файл для архивации каталогов (archive_folders.bat)

```cmd
@echo off
REM %1 - каталог, %2 - архиватор (например 7z.exe)
set target_dir=%1
set archiver=%2

REM Перебор всех подпапок
for /d %%i in ("%target_dir%\*") do (
    echo Архивация каталога %%i

    REM Создание архива
    %archiver% a "%%i.zip" "%%i\*"

    REM Удаление ZIP внутри папок (если было)
    del "%%i\*.zip" 2>nul
)
```

6 Пакетный файл для создания студенческих каталогов (create_student_dirs.bat)

```cmd
@echo off
REM %1 - список курсов, %2 - список групп
set courses=%1
set groups=%2

set /p max_students="Введите максимальное число студентов в группе: "

for %%c in (%courses%) do (
    for %%g in (%groups%) do (
        REM Создание каталога группы
        md "Kurs%%c\Group%%g" 2>nul

        REM Создание подкаталогов студентов
        for /l %%s in (1,1,%max_students%) do (
            md "Kurs%%c\Group%%g\Student%%s" 2>nul
        )
    )
)
echo Структура каталогов создана
```

7 Пакетный файл для перехода в личный каталог (goto_student_dir.bat)

```cmd
@echo off
set course=%1

echo Выбор группы:
echo 1 - Group1
echo 2 - Group2
echo 3 - Group3
set /p group="Выберите группу (1-3): "

if "%group%"=="1" (
    cd "Kurs%course%\Group1"
) else if "%group%"=="2" (
    cd "Kurs%course%\Group2"
) else if "%group%"=="3" (
    cd "Kurs%course%\Group3"
) else (
    echo Неверный выбор
)
```

8 Пакетный файл для установки даты и времени (set_datetime.bat) (требует прав администратора)

```cmd
@echo off

set new_date=%1
set new_time=%2

date %new_date%
time %new_time%

echo Дата и время установлены
```

9 Пакетный файл для очистки студенческих каталогов (clean_student_dirs.bat)

```cmd
@echo off
REM %1 - список курсов
set courses=%1

for %%c in (%courses%) do (
    del /s "Kurs%%c\*.bak"
    del /s "Kurs%%c\*.tmp"
    del /s "Kurs%%c\*.temp"
)

echo Очистка завершена
```

10 Пакетный файл для вывода списка файлов студентов (list_student_files.bat)

```cmd
@echo off
set group=%1
echo Выбор направления вывода:
echo 1 - На экран
echo 2 - В файл
echo 3 - На принтер
set /p output="Выберите направление вывода (1-3): "

if "%output%"=="1" (
    dir /s "Group%group%"
) else if "%output%"=="2" (
    dir /s "Group%group%" > student_files.txt
) else if "%output%"=="3" (
    dir /s "Group%group%" > PRN
) else (
    echo Неверный выбор
)
```

11 Пакетный файл для архивации каталога студента (archive_student.bat)

```cmd
@echo off

REM %1 — путь к каталогу студента
if exist "%1" (
    cd "%1"

    REM Архивация WinRAR
    "C:\Program Files\WinRAR\WinRAR.exe" a -r "student_backup.zip" *.*

    echo Каталог заархивирован
) else (
    echo Каталог не существует
)
```

12 Пакетный файл для постраничного вывода файла (page_view.bat)

```cmd
@echo off
REM Постраничный вывод файла с MORE

set filename=%1
more < "%filename%"
```

13 Пакетный файл для обновления документов (update_documents.bat)

```cmd
@echo off

set source_dir=%1
set target_dir=%2

REM Копирование только изменённых файлов
xcopy "%source_dir%\*.doc" "%target_dir%" /D /Y
xcopy "%source_dir%\*.txt" "%target_dir%" /D /Y

echo Документы обновлены
```

14 Пакетный файл для копирования документов студентов (copy_student_docs.bat)

```cmd
@echo off

REM Поиск всех DOC и TXT рекурсивно
for /r %%i in (*.doc *.txt) do (
    copy "%%i" "%USERPROFILE%\Documents\"
)

echo Документы скопированы в Мои документы
```

15 Пакетный файл для проверки документов в каталоге (check_documents.bat)

```cmd
@echo off

set check_dir=%1

REM Проверяем, есть ли файлы DOC или TXT
dir "%check_dir%\*.doc" "%check_dir%\*.txt" >nul 2>&1

if %errorlevel%==0 (
    echo Найдены документы:
    dir "%check_dir%\*.doc" "%check_dir%\*.txt" /b
) else (
    echo Документы не найдены
)
```
