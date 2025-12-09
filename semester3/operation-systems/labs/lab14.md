# Лабораторная работа №14

```cmd
@echo off
chcp 65001 >nul

rem 1 — открыть файл в Блокноте (не блокируя выполнение)
start notepad "%~f0"

rem 2 — цвет зелёный
color 0A

rem 3 — справка
help > help.txt

rem 4 — PATH
if exist "C:\Windows" (
    set "PATH=C:\Windows;%PATH%"
) else (
    if exist "C:\Windows\System32" (
        set "PATH=C:\Windows\System32;%PATH%"
    )
)

rem 5 — информация о системе
echo Количество процессоров: %NUMBER_OF_PROCESSORS%
echo Архитектура: %PROCESSOR_ARCHITECTURE%
echo Идентификатор: %PROCESSOR_IDENTIFIER%
echo Level: %PROCESSOR_LEVEL%
echo Revision: %PROCESSOR_REVISION%
echo Prompt: %PROMPT%
echo SystemDrive: %SystemDrive%
echo WinDir: %WinDir%
echo.

rem 6 — вывод PATH
echo PATH:
echo %PATH%
echo.

pause
```
