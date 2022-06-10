#define MiniGUIMain \
MiniGUIAppMain (int args, const char* argv[]);\
int main_entry (int args, const char* argv[]) \
{\
int iret = MiniGUIAppMain(args, argv);\
}\
int MiniGUIAppMain

int MiniGUIMain(int args, const char* argv[]) {
	printf("hi\n");
	return 0;
}
