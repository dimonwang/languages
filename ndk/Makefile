NDK:=ndk-build
.PHONY: all
all:
	${NDK} NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=Android.mk
clean:
	${NDK} clean NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=Android.mk
	rm -rf obj libs
