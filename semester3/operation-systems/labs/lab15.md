# Лабораторная работа №15

```cmd
@echo off
chcp 65001 >nul
SETLOCAL ENABLEDELAYEDEXPANSION

REM Проверка аргументов
IF "%~2"=="" (
    ECHO [ОШИБКА] Не указаны файлы или каталог назначения.
    ECHO Использование: %~nx0 file1 [file2 ...] destination_folder
    GOTO :END
)

REM Определяем последний аргумент как папку назначения
SET "DEST=%~nx0"
SET "DEST="
FOR %%A IN (%*) DO SET "DEST=%%A"

REM Проверка существования каталога назначения
IF NOT EXIST "%DEST%" (
    ECHO [ИНФО] Каталог назначения "%DEST%" не существует. Создаём.
    MD "%DEST%"
    IF ERRORLEVEL 1 (
        ECHO [ОШИБКА] Не удалось создать каталог "%DEST%".
        GOTO :END
    )
)

REM ================== Копирование файлов ==================
ECHO [ИНФО] Копирование файлов в каталог "%DEST%".

REM Перебор всех аргументов кроме последнего
SET IDX=0
SET COUNT=0
FOR %%F IN (%*) DO SET /A COUNT+=1

SET IDX=0
FOR %%F IN (%*) DO (
    SET /A IDX+=1
    IF !IDX! LSS %COUNT% (
        IF EXIST "%%F" (
            COPY "%%F" "%DEST%\" >NUL
            IF ERRORLEVEL 1 (
                ECHO [ОШИБКА] Не удалось скопировать "%%F"
            ) ELSE (
                ECHO [OK] Скопирован: "%%F"
            )
        ) ELSE (
            ECHO [ВНИМАНИЕ] Файл "%%F" не найден.
        )
    )
)

:END
ECHO.
ECHO [ИНФО] Операция завершена.
pause
```

## Результат работы

```cmd
C:\Users\andrn\test>DIR /S /B
C:\Users\andrn\test\archive_folders.bat
C:\Users\andrn\test\copy_files.bat
C:\Users\andrn\test\dir1
C:\Users\andrn\test\dir2
C:\Users\andrn\test\minimal_boot.bat
C:\Users\andrn\test\dir1\text4.txt
C:\Users\andrn\test\dir2\text.txt
C:\Users\andrn\test\dir2\text2.txt
C:\Users\andrn\test\dir2\text3.txt

C:\Users\andrn\test>copy_files.bat dir2\text.txt dir2\text2.txt dir2\text3.txt "C:\Users\andrn\test\dir1"
[ИНФО] Копирование файлов в каталог ""C:\Users\andrn\test\dir1"".
[OK] Скопирован: "dir2\text.txt"
[OK] Скопирован: "dir2\text2.txt"
[OK] Скопирован: "dir2\text3.txt"

[ИНФО] Операция завершена.
Press any key to continue . . .

C:\Users\andrn\test>DIR /S /B
C:\Users\andrn\test\archive_folders.bat
C:\Users\andrn\test\copy_files.bat
C:\Users\andrn\test\dir1
C:\Users\andrn\test\dir2
C:\Users\andrn\test\minimal_boot.bat
C:\Users\andrn\test\dir1\text.txt
C:\Users\andrn\test\dir1\text2.txt
C:\Users\andrn\test\dir1\text3.txt
C:\Users\andrn\test\dir1\text4.txt
C:\Users\andrn\test\dir2\text.txt
C:\Users\andrn\test\dir2\text2.txt
C:\Users\andrn\test\dir2\text3.txt

C:\Users\andrn\test>
```
