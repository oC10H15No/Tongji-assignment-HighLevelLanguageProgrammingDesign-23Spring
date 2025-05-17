/* 2351050 杨瑞晨 信05 */

#include <iostream>
#include <conio.h>
using namespace std;

#include "7-b2.h"
#include "cmd_console_tools.h"


/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/

static int is_chinese(char ch)
{
    unsigned char chu = (unsigned char)ch;
    if (chu >= 0xA1 && chu <= 0xFE) {
        return 1;
    }
    else
        return 0;
}

static int get_menu_count(const char menu[][MAX_ITEM_LEN]) {
    int count = 0;
    while (menu[count][0] != '\0') {
        count++;
    }
    return count;
}

static void draw_border(const struct PopMenu* new_para)
{
    const int X = new_para->start_x;
    const int Y = new_para->start_y;

    cct_gotoxy(X, Y);
    cct_setcolor(new_para->bg_color, new_para->fg_color);
    cout << "╔";
    for (int i = 1; i <= new_para->width / 2; i++)
        cout << "═";
    cout << "╗";
    
    int title_width = strlen(new_para->title);
    if (title_width % 2 != 0) {
        title_width++;
    }
    int title_x = X + 2 + new_para->width / 2 - title_width / 2;
    if (title_x % 2 != 0) {
        title_x--;
    }
    cct_showstr(title_x, Y, new_para->title, new_para->bg_color, new_para->fg_color, 1);

    for (int j = 1; j <= new_para->high; j++) {
        cct_gotoxy(X, Y + j);
        cout << "║";
        for (int k = 1; k <= new_para->width; k++)
            cout << " ";
        cout << "║";
    }
    cct_gotoxy(X, Y + new_para->high + 1);
    cout << "╚";
    for (int i = 1; i <= new_para->width / 2; i++)
        cout << "═";
    cout << "╝";
    cct_setcolor();
}

static void display_menu(const char menu[][MAX_ITEM_LEN], struct PopMenu* new_para, int selected_index, int start_index)
{
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);  // 获取控制台尺寸信息

    const int X = new_para->start_x;
    const int Y = new_para->start_y;
    
    cct_setcolor(new_para->bg_color, new_para->fg_color);
   
    for (int i = 0; i < new_para->high; i++) {
        int menu_index = start_index + i;
        if (menu_index >= get_menu_count(menu)) {
            break;
        }
        

        cct_gotoxy(X + 2, Y + i + 1);
        int remaining_width = new_para->width;

        if (menu_index == selected_index) {
            cct_setcolor(new_para->fg_color, new_para->bg_color); // 反色显示
        }

        int j;
        for (j = 0; remaining_width > 0; j++) {
            if (is_chinese(menu[menu_index][j])) {
                int tx, ty;
                cct_getxy(tx, ty);

                if (remaining_width < 2) {
                    j++;
                    remaining_width--;
                    cout << " ";
                    break;
                }
                else if (tx == cols - 1) {
                    cout << " ";
                    j++;
                    remaining_width--;
                }
                else {
                    cout << menu[menu_index][j] << menu[menu_index][j + 1];
                    j++; // 跳过下一个字节
                    remaining_width -= 2;
                }
            }
            else {
                if (menu[menu_index][j] != '\0') {
                    cout << menu[menu_index][j];
                    remaining_width--;
                }
                else {
                    break; // 结束当前行输出
                }
            }
        }
        while (remaining_width > 0) {
            cout << " ";
            remaining_width--;
        }
        if (menu_index == selected_index) {
            cct_setcolor(new_para->bg_color, new_para->fg_color); // 恢复颜色
        }
    }
    cct_setcolor();
}

static void get_new_para(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, struct PopMenu* new_para)
{
    int title_width = strlen(original_para->title);
    if (strlen(original_para->title) % 2 != 0)
        title_width++;

    new_para->title = original_para->title;
    new_para->start_x = original_para->start_x;
    new_para->start_y = original_para->start_y;
    new_para->bg_color = original_para->bg_color;
    new_para->fg_color = original_para->fg_color;

    int menu_count = get_menu_count(menu);
    if (original_para->high >= menu_count)
        new_para->high = menu_count;
    else
        new_para->high = original_para->high;
    if (original_para->width % 2 != 0)
        new_para->width = original_para->width + 1;
    else
        new_para->width = original_para->width;
    if (new_para->width < title_width) {
        new_para->width = title_width;
    }
}

// 处理菜单项选择
static int handle_menu_selection(const char menu[][MAX_ITEM_LEN], struct PopMenu* new_para)
{
    int menu_count = get_menu_count(menu);
    int selected_index = 0;
    int start_index = 0;
    int key = 0;
    cct_setcursor(CURSOR_INVISIBLE);
    while (key != 13) { // Enter key
        display_menu(menu, new_para, selected_index, start_index);
        key = _getch();

        switch (key) {
            case 72: // 上方向键
                if (selected_index > 0) {
                    selected_index--;
                    if (selected_index < start_index) {
                        start_index--;
                    }
                }
                break;
            case 80: // 下方向键
                if (selected_index < menu_count - 1) {
                    selected_index++;
                    if (selected_index >= start_index + new_para->high) {
                        start_index++;
                    }
                }
                break;
        }
    }
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    return selected_index;
}
/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    struct PopMenu new_parameter;
    struct PopMenu *new_para = &new_parameter;
    get_new_para(menu, original_para, new_para);
    draw_border(new_para);
    int selected_index = handle_menu_selection(menu, new_para);

    return selected_index + 1; //按需返回
}
