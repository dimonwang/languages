#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SUB_STR "[表情]"

bool isEmoji(const char *str) {
    unsigned int codepoint = 0;
    int num_bytes = 0;
    
    // UTF-8编码规则
    if ((str[0] & 0xF0) == 0xF0) {
        codepoint = str[0] & 0x07;
        num_bytes = 4;
    } else if ((str[0] & 0xE0) == 0xE0) {
        codepoint = str[0] & 0x0F;
        num_bytes = 3;
    } else if ((str[0] & 0xC0) == 0xC0) {
        codepoint = str[0] & 0x1F;
        num_bytes = 2;
    } else {
        codepoint = str[0];
        num_bytes = 1;
    }
    
    for (int i = 1; i < num_bytes; i++) {
        if ((str[i] & 0xC0) != 0x80) {
            return false;  // 非法UTF-8编码
        }
        codepoint = (codepoint << 6) | (str[i] & 0x3F);
    }
    
    // Emoji Unicode范围
    if ((codepoint >= 0x1F300 && codepoint <= 0x1F64F) ||
        (codepoint >= 0x2700 && codepoint <= 0x27BF) ||
        (codepoint >= 0x1F680 && codepoint <= 0x1F6FF) ||
        (codepoint >= 0x1F900 && codepoint <= 0x1F9FF) ||
        (codepoint >= 0x2600 && codepoint <= 0x26FF)) {
        return true;  // 是Emoji
    }
    
    return false;  // 不是Emoji
}

char* substituteEmoji(const char *str) {
    const char *ptr = str;
    unsigned  int spaces = 0;
    unsigned  int emoji_cnt= 0;
    while (*ptr != '\0') {
        // 移动到下一个字符
        int num_bytes = 1;
        if ((ptr[0] & 0xF0) == 0xF0) {
            num_bytes = 4;
        } else if ((ptr[0] & 0xE0) == 0xE0) {
            num_bytes = 3;
        } else if ((ptr[0] & 0xC0) == 0xC0) {
            num_bytes = 2;
        }
        
        if (isEmoji(ptr)) {
            emoji_cnt++;
            spaces +=  num_bytes;
        }
        
        ptr += num_bytes;
    }

    //do it
    int result_len = strlen(str)+strlen(SUB_STR)*emoji_cnt-spaces+1;
    char *result = malloc(result_len);
    if (result == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    memset(result, 0, result_len);
    char* result_ptr = result;

    ptr = str;
    while (*ptr != '\0') {
        // 移动到下一个字符
        int num_bytes = 1;
        if ((ptr[0] & 0xF0) == 0xF0) {
            num_bytes = 4;
        } else if ((ptr[0] & 0xE0) == 0xE0) {
            num_bytes = 3;
        } else if ((ptr[0] & 0xC0) == 0xC0) {
            num_bytes = 2;
        }
        
        if (isEmoji(ptr)) {
            strcpy(result_ptr, SUB_STR);
            result_ptr += strlen(SUB_STR);
        } else {
            memcpy(result_ptr, ptr, num_bytes);
            result_ptr += num_bytes;
        }
        
        ptr += num_bytes;
    }

    return result;
}


void traverseUTF8(const char *str) {
    const char *ptr = str;
    while (*ptr != '\0') {
        if (isEmoji(ptr)) {
            printf("Emoji: %s\n", ptr);
        }
        
        // 移动到下一个字符
        int num_bytes = 1;
        if ((ptr[0] & 0xF0) == 0xF0) {
            num_bytes = 4;
        } else if ((ptr[0] & 0xE0) == 0xE0) {
            num_bytes = 3;
        } else if ((ptr[0] & 0xC0) == 0xC0) {
            num_bytes = 2;
        }
        
        ptr += num_bytes;
    }
}

int main() {
    const char *str = "Hello 😀 World! 😄 字符串: Hello 😀 World! 😄";
    
    printf("字符串: %s\n", str);
    
    traverseUTF8(str);

    char* r = substituteEmoji(str);
    if (r  != NULL) printf("%s\n",r);
    free(r);
    
    return 0;
}
