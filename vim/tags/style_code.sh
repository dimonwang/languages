#!/bin/sh
source_dir=`find ./ -maxdepth 1 -type d | egrep -v "svn|svrconfig|common|res|proto|^\./$"`
for dir in ${source_dir}
do
    find ${dir} -regex '.*\.\(h\|c\|cpp\|hpp\)' -type f | xargs -n 1 ./astyle --style=allman --indent-classes --indent-switches --indent-namespaces --indent-preproc-block --indent-preproc-define --indent-col1-comments --pad-oper --pad-header --unpad-paren --align-pointer=type --keep-one-line-statements --suffix=none 
    find $(dir) -regex '.*\.\(h\|c\|cpp\|hpp\)' -type f | xargs dos2unix
done
