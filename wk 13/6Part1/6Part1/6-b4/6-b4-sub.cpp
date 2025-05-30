/* 2351050 杨瑞晨 信05 */
#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    if (str == NULL)
        return 0;
    for (i = 0; *str != '\0'; str++, i++)
        ;
    return i;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    while (*s1)
        s1++;
    if (s2 == NULL)
        return p;
    while (*s2) {
        *s1++ = *s2++;
    }
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    int i = len;
    if (s1 == NULL)
        return p;
    while (*s1)
        s1++;
    if (s2 == NULL)
        return p;
    while (i-- && (*s1++ = *s2++))
        ;
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    if (s2 == NULL) {
        *s1 = '\0';
        return p;
    }
    while (*s1++ = *s2++)
        ;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p = s1;
    int i = len;
    if (s1 == NULL)
        return p;
    if (s2 == NULL)
        return p;
    for (; i-- > 0 && *s2 != '\0'; )
        *s1++ = *s2++;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (*s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;

    while (*s1 && *s2) {
        char c1 = *s1;
        char c2 = *s2;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 32;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 32;
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = len;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (i && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        i--;
    }
    return i ? *s1 - *s2 : 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = len;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;

    while (i && *s1) {
        char c1 = *s1;
        char c2 = *s2;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 32;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 32;
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
        i--;
    }
    return i ? *s1 - *s2 : 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    while (*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p += 32; 
        }
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    int i = 0;
    while (*str){
        if (*str == ch)
            return i + 1;
        i++;
        str++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    int index = 1; 
    if (str == NULL || substr == NULL)
        return 0;
    if (tj_strlen(substr) > tj_strlen(str))
        return 0;
    while (*str != '\0') {
        const char* s1 = str;
        const char* s2 = substr;
        while (*s1 == *s2 && *s2 != '\0') {
            s1++;
            s2++;
        }
        if (*s2 == '\0') {
            return index; 
        }
        index++;
        str++;
    }
    return 0; 
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    if (str == NULL)
        return 0; 
    const char* end = str; 
    while (*end != '\0') {
        end++; 
    }
    end--; 
    while (end >= str) {
        if (*end == ch) {
            return end - str + 1; 
        }
        end--; 
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    if (tj_strlen(substr) > tj_strlen(str))
        return 0;

    const char* end = str + tj_strlen(str) - tj_strlen(substr);
    while (end >= str) {
        const char* s1 = end; // 指向当前位置的指针
        const char* s2 = substr; // 指向子字符串的指针
        // 逐个比较字符，直到子字符串结束或者字符不匹配
        while (*s1 == *s2 && *s2 != '\0') {
            s1++;
            s2++;
        }
        // 如果子字符串全部匹配，则返回子字符串在主字符串中的位置（从1开始）
        if (*s2 == '\0') {
            return end - str + 1;
        }
        end--; // 移动指针到前一个字符
    }

    return 0; // 返回0表示未找到子字符串
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str) {
        return NULL;
    }
    char* start = str;
    char* end = str + tj_strlen(str) - 1;
    while (end > start) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}
