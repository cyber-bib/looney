$Root = $PSScriptRoot
$Root = Split-Path -Path $Root -Parent
# $RootName = Split-Path -Path $Root -Leaf
# $ExeName = $RootName

$SourceDir = "${Root}\src"
$BuildDir = "${Root}\build"
$LogDir = "${Root}\log"

$logout = "out"
$logerr = "err"
$logwrn = "wrn"
$logvrb = "verbose"
$logdbg = "dbg"
$loginf = "info"
$logpostfix = ".log"