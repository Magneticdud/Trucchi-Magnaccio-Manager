@echo off
setlocal enabledelayedexpansion

echo Ricerca di Visual Studio...

set "VS_PATH="
if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" (
    set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat" (
    set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat"
) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" (
    set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat"
)

if "%VS_PATH%"=="" (
    echo Errore: Visual Studio 2022 non trovato o vcvarsall.bat mancante.
    exit /b 1
)

echo Trovato: %VS_PATH%
call "%VS_PATH%" x64

if errorlevel 1 (
    echo Errore durante la configurazione dell'ambiente.
    exit /b 1
)

echo.
echo Compilazione in corso...

for %%f in (*.c) do (
    if not "%%f"=="compat_dos.h" if not "%%f"=="puttane.c" (
        echo Compilazione di %%f...
        cl /nologo /W3 /D_CRT_SECURE_NO_WARNINGS "%%f" /Fe"%%~nf.exe"
    )
)

echo.
echo Compilazione completata.
pause
