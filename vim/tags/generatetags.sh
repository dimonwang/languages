#!/bin/sh
# generate tag file for lookupfile plugin
echo -e "!_TAG_FILE_SORTED\t2\t/2=foldcase/" > filenametags
#find . -not -regex '.*\.\(d\|o\|tmp\|gcda\|gcno\|svn-base\)' -type f -printf "%f\t%p\t1\n" | sort -f >> filenametags 
find . -regex '.*\.\(h\|c\|cpp\|hpp\|xml\|cc\)' -type f -printf "%f\t%p\t1\n" | sort -f >> filenametags 
# ctags
/usr/bin/ctags -R --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+liaS --extra=+q --language-force=c++

#cscope
find . -regex '.*\.\(h\|c\|cpp\|hpp\|xml\|cc\)' -type f > cscope.files
cscope -uRbq -i cscope.files
