#include"clsscr.h"
#include<gtk/gtk.h>

//{{{ define struct

struct MAIN_CONTROL
{
	GtkApplication *app;
	GtkWidget *window;
	GtkWidget *fix;
	GtkWidget *note;
};
struct PAGE1_CONTROL
{
	GtkWidget *fix;
	GtkWidget *lab[3];
	GtkWidget *ed[3];
	GtkWidget *bnt[3];
	GtkWidget *combo;
	GtkWidget *tview;
	GtkWidget *chkbnt;
};
struct PAGE2_CONTROL
{
	GtkWidget *fix;
	GtkWidget *combo;
	GtkWidget *bnt;
	GtkWidget *lab;
	GtkWidget *ed;
};
//}}}
//{{{ define const
#define	tlen				1024
#define win_w				800
#define win_h				600
//边界值
#define margin_w			5
#define margin_h			margin_w
//notebook大小
#define note_w				win_w-2*margin_w
#define note_h				win_h-2*margin_h
//page1控件位置
#define p1_lab1_x			margin_w
#define p1_lab1_y			30
#define p1_ed1_x			p1_lab1_x+60
#define p1_ed1_y			p1_lab1_y-10
#define p1_chk_x			p1_ed1_x+130
#define p1_chk_y			p1_lab1_y
#define p1_bnt1_x			p1_chk_x+100
#define p1_bnt1_y			p1_ed1_y
#define p1_bnt2_x			p1_bnt1_x+120
#define p1_bnt2_y			p1_bnt1_y
#define p1_bnt3_x			p1_bnt2_x+250
#define p1_bnt3_y			p1_bnt2_y
#define p1_lab2_x			p1_lab1_x
#define p1_lab2_y			p1_lab1_y+45
#define p1_combo_x			p1_lab2_x+60
#define p1_combo_y			p1_lab2_y-10

///////////////////
#define t_p1_title			"监听界面"
#define t_p1_lab1			"本机IP："
#define t_p1_bnt1			"开始监听"
#define t_p1_bnt2			"关闭监听"
#define t_p1_bnt3			"装载包文件"
#define t_p1_chk			"保存到文件"
#define t_p1_lab2			"包过滤："
#define t_p1_lab3			"指定IP："
#define t_p1_lab4			"指定端口："
#define t_p1_com1			"捕获全部"
#define t_p1_com2			"ICMP包"
#define t_p1_com3			"入TCP包"
#define t_p1_com4			"入UDP包"
#define t_p1_com5			"出TCP包"
#define t_p1_com6			"出UDP包"
#define t_p1_com7			"点对点TCP"
#define t_p1_com8			"点对点UDP"
#define t_p1_com9			"全部TCP"
#define t_p1_com10			"全部UDP"



//}}}
//{{{ variables
struct MAIN_CONTROL	ws;
struct PAGE1_CONTROL p1;
struct PAGE2_CONTROL p2;

char *p,ch[tlen];
//}}}
//{{{ function
static void activate(GtkApplication *app,gpointer gp);
static void crt_page1();
static void crt_page2();
int main(int argc,char **argv);
static void on_p1_bnt1(GtkWidget *widget,gpointer gp);


