
# default qmake is in /usr/local/bin/qmake and is qt4?

prog=file-explorer

#/Applications/Qt5.10.1/5.10.1/clang_64/bin/qmake ${prog}.pro
/opt/Qt5.6.3/5.6.3/gcc_64/bin/qmake ${prog}.pro

make

./${prog}

