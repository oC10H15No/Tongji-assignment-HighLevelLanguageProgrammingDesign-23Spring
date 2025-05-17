/* 2351050 ���� ��05 */

#include <iostream>
#include <conio.h>
using namespace std;

#include "7-b2.h"
#include "cmd_console_tools.h"


/* 1���������ͷ�ļ�
   2����������ȫ�ֱ�����������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */

/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
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
    cout << "�X";
    for (int i = 1; i <= new_para->width / 2; i++)
        cout << "�T";
    cout << "�[";
    
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
        cout << "�U";
        for (int k = 1; k <= new_para->width; k++)
            cout << " ";
        cout << "�U";
    }
    cct_gotoxy(X, Y + new_para->high + 1);
    cout << "�^";
    for (int i = 1; i <= new_para->width / 2; i++)
        cout << "�T";
    cout << "�a";
    cct_setcolor();
}

static void display_menu(const char menu[][MAX_ITEM_LEN], struct PopMenu* new_para, int selected_index, int start_index)
{
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);  // ��ȡ����̨�ߴ���Ϣ

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
            cct_setcolor(new_para->fg_color, new_para->bg_color); // ��ɫ��ʾ
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
                    j++; // ������һ���ֽ�
                    remaining_width -= 2;
                }
            }
            else {
                if (menu[menu_index][j] != '\0') {
                    cout << menu[menu_index][j];
                    remaining_width--;
                }
                else {
                    break; // ������ǰ�����
                }
            }
        }
        while (remaining_width > 0) {
            cout << " ";
            remaining_width--;
        }
        if (menu_index == selected_index) {
            cct_setcolor(new_para->bg_color, new_para->fg_color); // �ָ���ɫ
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

// ����˵���ѡ��
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
            case 72: // �Ϸ����
                if (selected_index > 0) {
                    selected_index--;
                    if (selected_index < start_index) {
                        start_index--;
                    }
                }
                break;
            case 80: // �·����
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
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    struct PopMenu new_parameter;
    struct PopMenu *new_para = &new_parameter;
    get_new_para(menu, original_para, new_para);
    draw_border(new_para);
    int selected_index = handle_menu_selection(menu, new_para);

    return selected_index + 1; //���践��
}
