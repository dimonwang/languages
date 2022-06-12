INSTALL_DIR=/home/d/codes/languages/libtool/helloworld/tmp/
.PHONY:all
all:
	mkdir -p tmp
	libtool --mode=compile --tag=CC gcc -c test.c && \
	libtool --mode=link --tag=CC gcc -o libtest.la -rpath ${INSTALL_DIR} test.lo && \
	libtool --mode=install --tag=CC install -c libtest.la ${INSTALL_DIR} && \
	libtool --finish ${INSTALL_DIR}

clean:
	rm -rf libtest.* tmp *.lo *.o .libs
