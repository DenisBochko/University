# Лабораторная работа №12

5 Пакетный файл для архивации каталогов (archive_folders.bat)

```cmd
@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

REM ================== Общие сведения о пакетном файле ==================
SET "SCRIPT_NAME=%~nx0"
SET "SCRIPT_AUTHOR=Бочко Денис Андреевич>"
SET "SCRIPT_DESC=Архивация файлов по каталогам и удаление архивов"
SET "SCRIPT_USAGE=%SCRIPT_NAME% <путь_к_каталогу> <путь_к_архиватору>"

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
ECHO   путь_к_каталогу   - корневой каталог, в котором обрабатываются все
ECHO                       подкаталоги.
ECHO   путь_к_архиватору - полный путь к консольному архиватору (например, 7z.exe).
ECHO.
ECHO Примеры:
ECHO   %SCRIPT_NAME% "D:\Data" "C:\Tools\7z.exe"
ECHO.
ECHO При запуске без параметров или с ключом /? выводится эта справка.
ECHO В процессе работы запросы с клавиатуры принимают ТОЛЬКО числовой ввод.
GOTO :END

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
IF NOT EXIST "%ROOT_DIR%\NUL" (
    ECHO [ОШИБКА] Каталог "%ROOT_DIR%" не существует.
    GOTO :END
)

REM Проверка существования архиватора
IF NOT EXIST "%ARCHIVER%" (
    ECHO [ОШИБКА] Архиватор "%ARCHIVER%" не найден.
    GOTO :END
)

REM Сохранение текущего каталога, чтобы не менять его снаружи
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

REM Ввод только числа
SET "CHOICE_NUM="
SET /P "CHOICE_NUM=Введите номер операции (0,1,2): "

IF "%CHOICE_NUM%"=="0" GOTO :RESTORE_DIR
IF "%CHOICE_NUM%"=="1" GOTO :DO_ARCHIVE
IF "%CHOICE_NUM%"=="2" GOTO :DO_CLEAN

ECHO [ОШИБКА] Некорректный выбор. Допустимо: 0, 1 или 2.
GOTO :MENU

REM ================== Режим архивации ==================
:DO_ARCHIVE
ECHO.
ECHO [ИНФО] Запуск архивации в каталоге "%ROOT_DIR%".
ECHO [ИНФО] Архиватор: "%ARCHIVER%".
ECHO.

PUSHD "%ROOT_DIR%" REM переходим в ROOT_DIR, а прошлый добавляется в стек
IF ERRORLEVEL 1 (
    ECHO [ОШИБКА] Не удалось перейти в каталог "%ROOT_DIR%".
    GOTO :RESTORE_DIR
)

REM Сначала архивируем сам корневой каталог
CALL :ARCHIVE_DIR "%CD%"

REM Затем рекурсивно все подкаталоги
FOR /D /R %%D IN (*) DO (
    CALL :ARCHIVE_DIR "%%D"
)

POPD
GOTO :RESTORE_DIR

REM ---------- Процедура архивации одного каталога ----------
:ARCHIVE_DIR
REM %~1 - полный путь к каталогу
SET "DIR_PATH=%~1"

REM Защита от пустых значений
IF "%DIR_PATH%"=="" GOTO :EOF

REM Имя архива: полный путь каталога + .zip
SET "ARCHIVE_PATH=%DIR_PATH%.zip"

REM Если в каталоге нет файлов (только подкаталоги), то архиватор может ругаться.
REM Проверяем наличие хотя бы одного файла.
SET "HAS_FILES="
FOR %%F IN ("%DIR_PATH%\*") DO (
    IF EXIST "%%F" (
        SET "HAS_FILES=1"
        GOTO :HAS_FILES_FOUND
    )
)

:HAS_FILES_FOUND
IF NOT DEFINED HAS_FILES (
    ECHO [ИНФО] Каталог "%DIR_PATH%" пуст (нет файлов). Пропуск.
    GOTO :EOF
)

ECHO [ИНФО] Архивация каталога: "%DIR_PATH%"
ECHO        Архив: "%ARCHIVE_PATH%"

REM Вызов архиватора. Для 7z, например:
REM "%ARCHIVER%" a "архив" "каталог\*"
"%ARCHIVER%" a "%ARCHIVE_PATH%" "%DIR_PATH%\*" >NUL
IF ERRORLEVEL 1 (
    ECHO [ОШИБКА] Не удалось создать архив "%ARCHIVE_PATH%".
) ELSE (
    ECHO [OK] Архив создан: "%ARCHIVE_PATH%"
)

GOTO :EOF

REM ================== Режим удаления архивов ==================
:DO_CLEAN
ECHO.
ECHO [ИНФО] Удаление архивов *.zip в дереве "%ROOT_DIR%".
ECHO.

REM Текущий каталог не меняем, работаем с полным путём
FOR /R "%ROOT_DIR%" %%F IN (*.zip) DO (
    DEL /Q "%%~fF" REM преобразует к полному пути
)

ECHO.
ECHO [ИНФО] Удаление архивов завершено.
GOTO :RESTORE_DIR

REM ================== Восстановление исходного каталога ==================
:RESTORE_DIR
IF DEFINED OLD_DIR (
    PUSHD "%OLD_DIR%" >NUL 2>&1
    POPD >NUL 2>&1
)
GOTO :END

:END
ENDLOCAL
```
