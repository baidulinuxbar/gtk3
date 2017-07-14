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
	GtkListStore *store;
	GtkWidget *list;
	GtkTreeModel *model;
	GtkTreeViewColumn *column;
	GtkCellRenderer *render;
	GtkWidget	*scroll;
};
struct PAGE2_CONTROL
{
	GtkWidget *fix;
	GtkWidget *combo;
	GtkWidget *bnt;
	GtkWidget *lab[2];
	GtkWidget *ed;
	GtkTextBuffer *buffer;
	GtkTextIter	iter;
	GtkWidget *scroll;
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
//{{{page1控件位置
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
#define p1_lab3_x			p1_combo_x+135
#define p1_lab3_y			p1_lab2_y
#define p1_ed2_x			p1_lab3_x+95
#define p1_ed2_y			p1_combo_y
#define p1_lab4_x			p1_ed2_x+135
#define p1_lab4_y			p1_lab3_y
#define p1_ed3_x			p1_lab4_x+80
#define p1_ed3_y			p1_ed2_y
#define p1_lab5_x			p1_ed3_x+95
#define p1_lab5_y			p1_lab4_y
#define p1_list_x			margin_w
#define p1_list_y			p1_lab2_y+45
#define p1_list_w			win_w-20
#define p1_list_h			win_h-180
//}}}
//{{{page2控件位置
#define p2_combo_x			margin_w
#define p2_combo_y			30
#define p2_bnt_x			p2_combo_x+160
#define p2_bnt_y			p2_combo_y
#define p2_lab_x			p2_bnt_x+120
#define p2_lab_y			p2_bnt_y+10
#define p2_ed_x				margin_w
#define p2_ed_y				p2_combo_y+40
#define p2_ed_w				200
#define p2_ed_h				100
//}}}
///////////////////
//{{{page1控件文本
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
#define t_p1_list1			"序  号"
#define t_p1_list2			" 类  型 "
#define t_p1_list3			"  源端口  "
#define t_p1_list4			" 目标端口 "
#define t_p1_list5			"      源IP      "
#define t_p1_list6			"     目标IP     "
#define t_p1_list7			"  包长度  "
//}}}
//{{{page2控件文本
#define t_p2_lab1			"包查看界面"
#define t_p2_com1			"查看包信息"
#define t_p2_com2			"查看IP包头"
#define t_p2_com3			"查看数据包头"
#define t_p2_com4			"查看数据信息"
#define t_p2_bnt1			"查  看"
#define t_p2_lab2			"静态"
//定义textview字体属性
#define tag_pal				"pal"			//pixels_above_lines
#define tag_lmarg			"lmarg"			//left-margin
#define tag_pbl				"pbl"			//pixels_below_lines
#define tag_red_fg			"red_fg"		//foreground red
#define tag_blue_fg			"blue_fg"		//foreground blue
#define tag_yellow_fg		"yellow_fg"		//foreground_yellow
#define tag_magenta_fg		"magenta_fg"	//foreground_magenta #FF00FF
#define tag_green_fg		"green_fg"		//foreground_green
#define tag_gray_fg			"gray_fg"		//foreground_gray
#define tag_black_fg		"black_fg"		//foreground_gray
#define tag_gray_bg			"gray_bg"		//background_gray
#define tag_yellow_bg		"yellow_bg"		//background_yellow
#define tag_blue_bg			"blue_bg"		//background_blue
#define tag_green_bg		"green_bg"		//background_green
#define tag_black_bg		"black_bg"		//background_black
//style
#define tag_underline		"underline"		//underline PANGO_UNDERLINE_SINGLE
#define tag_bold			"bold"			//weight PANGO_WEIGHT_BOLD
#define tag_italic			"italic"		//style PANGO_STYLE_ITALIC
#define tag_strike			"strike"		//strikethrough	 TRUE
//font size
#define tag_quarter			"quarter sized"		//scale 0.25
#define tag_des				"double_extra_small"	//scale PANGO_SCALE_XX_SMALL
#define tag_es				"extra_small"	//scale PANGO_SCALE_X_SMALL
#define tag_small			"small"			//scale PANGO_SCALE_SMALL
#define tag_med				"medium"		//scale PANGO_SCALE_MEDIUM
#define tag_large			"large"			//scale PANGO_SCALE_LARGE
#define tag_elrg			"extra large"	//scale PANGO_SCALE_X_LARGE
#define tag_delrg			"double extra large"	//scale PANGO_SCALE_XX_LARGE
#define tag_dsz				"double size"	//scale 2.0
//font name
#define tag_fsong			"FangSong"		//FangSong
#define tag_song			"SimSun"		//SimSun
#define tag_nsong			"NSimSun"		//NSimSun
#define tag_kai				"KaiTi"			//KaiTi
#define tag_yahei			"YaHei Consolas Hybrid"	//YaHei Consolas Hybrid


//}}}

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
static void on_p1_bnt2(GtkWidget *widget,gpointer gp);


