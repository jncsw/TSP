@echo off
:loop
tasklist | find /i "TSP.exe"&&echo  [ %time:~,-3% ]´æÔÚ½ø³Ì||start "" ".\TSP.exe"&&echo starting
ping -n 5 127.1>nul
goto :loop