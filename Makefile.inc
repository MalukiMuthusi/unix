IMPL_CFLAGS = -std=c99 -D_XOPEN_SOURCE=600 \
	        -D_DEFAULT_SOURCE \
		-g -I${TLPI_INCL_DIR} \
		-pedantic \
		-Wall \
		-W \
		-Wmissing-prototypes \
		-Wno-sign-compare \
		-Wimplicit-fallthrough \
		-Wno-unused-parameter

CFLAGS = ${IMPL_CFLAGS}
IMPL_THREAD_FLAGS = -pthread
CODE_DIR = ..
INCL_DIR = ${CODE_DIR}/lib
#LIB_OBJECT= ${CODE_DIR}/libbi.a
LINUX_LIBRT = -lrt