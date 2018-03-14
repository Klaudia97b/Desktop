@echo off
echo preprocessing %1.c
icpp %1.c %1.pre
echo compiling %1.pre to ..\cip\%1.cip
syn %1.pre ..\cip\%1.cip %2 %3 %4 > %TMP%\m.msg
type %TMP%\m.msg
