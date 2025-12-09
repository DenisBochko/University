# Лабораторная работа №12

5 Пакетный файл для архивации каталогов (archive_folders.bat)

```cmd
@ECHO OFF
chcp 65001 >nul
SETLOCAL ENABLEDELAYEDEXPANSION

REM ================== Общие сведения о пакетном файле ==================
SET "SCRIPT_NAME=%~nx0"
SET "SCRIPT_AUTHOR=Бочко Денис"
SET "SCRIPT_DESC=Архивация файлов по каталогам и удаление архивов"
SET "SCRIPT_USAGE=%SCRIPT_NAME% ^<путь_к_каталогу^> ^<путь_к_архиватору^>"

REM ================== Точка входа ==================
:START
IF "%~1"=="" GOTO :USAGE
IF /I "%~1"=="/?" GOTO :USAGE

REM Контроль верности командной строки (ровно два параметра)
IF "%~3" NEQ "" (
    ECHO [ОШИБКА] Неверное количество параметров.
    ECHO Ожидалось: %SCRIPT_USAGE%
    GOTO :END
)

SET "ROOT_DIR=%~1"
SET "ARCHIVER=%~2"

REM Проверка существования каталога
IF NOT EXIST "%ROOT_DIR%\" (
    ECHO [ОШИБКА] Каталог "%ROOT_DIR%" не существует.
    GOTO :END
)

REM Проверка существования архиватора
IF NOT EXIST "%ARCHIVER%" (
    ECHO [ОШИБКА] Архиватор "%ARCHIVER%" не найден.
    GOTO :END
)

REM Сохранение текущего каталога
SET "OLD_DIR=%CD%"

REM ================== Меню выбора операции ==================
:MENU
ECHO.
ECHO ===========================================
ECHO   1 - Архивировать файлы по каталогам
ECHO   2 - Удалить архивные файлы (*.zip)
ECHO   0 - Выход
ECHO ===========================================
ECHO.

SET "CHOICE_NUM="
SET /P "CHOICE_NUM=Введите номер операции (0,1,2): "

IF "%CHOICE_NUM%"=="0" GOTO :RESTORE_DIR
IF "%CHOICE_NUM%"=="1" GOTO :DO_ARCHIVE
IF "%CHOICE_NUM%"=="2" GOTO :DO_CLEAN

ECHO [ОШИБКА] Некорректный выбор. Допустимо: 0, 1 или 2.
GOTO :MENU

REM ================== Вывод справки ==================
:USAGE
ECHO Имя:        %SCRIPT_NAME%
ECHO Назначение: %SCRIPT_DESC%
ECHO Применение: Архивирование файлов в каждом каталоге по отдельности
ECHO             и удаление созданных архивов (ZIP).
ECHO Автор:      %SCRIPT_AUTHOR%
ECHO.
ECHO Использование:
ECHO   %SCRIPT_USAGE%
ECHO.
ECHO Параметры:
ECHO   путь_к_каталогу   - корневой каталог
ECHO   путь_к_архиватору - полный путь к 7z.exe
ECHO.
ECHO Пример:
ECHO   %SCRIPT_NAME% "D:\Data" "C:\Program Files\7-Zip\7z.exe"
GOTO :END

REM ================== Архивация ==================
:DO_ARCHIVE
PUSHD "%ROOT_DIR%"
CALL :ARCHIVE_DIR "%CD%"
FOR /D /R %%D IN (*) DO CALL :ARCHIVE_DIR "%%D"
POPD
GOTO :RESTORE_DIR

:ARCHIVE_DIR
SET "DIR_PATH=%~1"
IF "%DIR_PATH%"=="" GOTO :EOF

SET "ARCHIVE_PATH=%DIR_PATH%.zip"

SET "HAS_FILES="
FOR %%F IN ("%DIR_PATH%\*") DO (
    IF EXIST "%%F" (
        SET "HAS_FILES=1"
        GOTO :FILES_FOUND
    )
)

:FILES_FOUND
IF NOT DEFINED HAS_FILES (
    ECHO [ИНФО] Каталог "%DIR_PATH%" пуст — пропуск.
    GOTO :EOF
)

ECHO [ИНФО] Архивация: "%DIR_PATH%"
"%ARCHIVER%" a "%ARCHIVE_PATH%" "%DIR_PATH%\*" >NUL

IF ERRORLEVEL 1 (
    ECHO [ОШИБКА] Не удалось создать архив "%ARCHIVE_PATH%"
) ELSE (
    ECHO [OK] Архив создан: "%ARCHIVE_PATH%"
)
GOTO :EOF

REM ================== Удаление архивов ==================
:DO_CLEAN
FOR /R "%ROOT_DIR%" %%F IN (*.zip) DO DEL /Q "%%~fF"
ECHO [ИНФО] Удаление архивов завершено.
GOTO :RESTORE_DIR

REM ================== Восстановление каталога ==================
:RESTORE_DIR
IF DEFINED OLD_DIR PUSHD "%OLD_DIR%" & POPD
GOTO :END

:END
ENDLOCAL
```

## Результат работы

```cmd
C:\Users\andrn\test>DIR /S /B
C:\Users\andrn\test\archive_folders.bat
C:\Users\andrn\test\dir1
C:\Users\andrn\test\dir1\dir2
C:\Users\andrn\test\dir1\text4.txt
C:\Users\andrn\test\dir1\dir2\text.txt
C:\Users\andrn\test\dir1\dir2\text2.txt
C:\Users\andrn\test\dir1\dir2\text3.txt

C:\Users\andrn\test>archive_folders.bat
Имя:        archive_folders.bat
Назначение: Архивация файлов по каталогам и удаление архивов
Применение: Архивирование файлов в каждом каталоге по отдельности
            и удаление созданных архивов (ZIP).
Автор:      Бочко Денис

Использование:
  archive_folders.bat <путь_к_каталогу> <путь_к_архиватору>

Параметры:
  путь_к_каталогу   - корневой каталог
  путь_к_архиватору - полный путь к 7z.exe

Пример:
  archive_folders.bat "D:\Data" "C:\Program Files\7-Zip\7z.exe"

C:\Users\andrn\test>archive_folders.bat "C:\Users\andrn\test" "C:\Program Files\7-Zip\7z.exe"

===========================================
  1 - Архивировать файлы по каталогам
  2 - Удалить архивные файлы (*.zip)
  0 - Выход
===========================================

Введите номер операции (0,1,2): 1
[ИНФО] Архивация: "C:\Users\andrn\test"
[OK] Архив создан: "C:\Users\andrn\test.zip"
[ИНФО] Архивация: "C:\Users\andrn\test\dir1"
[OK] Архив создан: "C:\Users\andrn\test\dir1.zip"
[ИНФО] Архивация: "C:\Users\andrn\test\dir1\dir2"
[OK] Архив создан: "C:\Users\andrn\test\dir1\dir2.zip"

C:\Users\andrn\test>DIR /S /B
C:\Users\andrn\test\archive_folders.bat
C:\Users\andrn\test\dir1
C:\Users\andrn\test\dir1.zip
C:\Users\andrn\test\dir1\dir2
C:\Users\andrn\test\dir1\dir2.zip
C:\Users\andrn\test\dir1\text4.txt
C:\Users\andrn\test\dir1\dir2\text.txt
C:\Users\andrn\test\dir1\dir2\text2.txt
C:\Users\andrn\test\dir1\dir2\text3.txt

C:\Users\andrn\test>archive_folders.bat "C:\Users\andrn\test" "C:\Program Files\7-Zip\7z.exe"

===========================================
  1 - Архивировать файлы по каталогам
  2 - Удалить архивные файлы (*.zip)
  0 - Выход
===========================================

Введите номер операции (0,1,2): 2
[ИНФО] Удаление архивов завершено.

C:\Users\andrn\test>DIR /S /B
C:\Users\andrn\test\archive_folders.bat
C:\Users\andrn\test\dir1
C:\Users\andrn\test\dir1\dir2
C:\Users\andrn\test\dir1\text4.txt
C:\Users\andrn\test\dir1\dir2\text.txt
C:\Users\andrn\test\dir1\dir2\text2.txt
C:\Users\andrn\test\dir1\dir2\text3.txt

C:\Users\andrn\test>
```
