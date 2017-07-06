#include"clsscr.h"
#include<gtk/gtk.h>

struct win_st
{
	GtkApplication *app;
	GtkWidget	*window;
	GtkWidget	*fix1;
	GtkWidget	*bnt1;
	GtkWidget	*bnt2;
	GtkWidget	*ed01;
	GtkWidget	*lab[5];
	GtkWidget	*note;
	GtkWidget	*fix_note[4];
	PangoFontDescription *pfd;
};
#define	win_w				800
#define win_h				600
#define note_w				780
#define note_h				580
#define p1_st1				"<span color=\"#0000ff\">本机IP：</span>"
#define p1_lab1_x			5
#define p1_lab1_y			20
#define p1_ed1_x			p1_lab1_x+50
#define p1_ed1_y			p1_lab2_y-10



struct win_st	ws;
char ch[1024];

static void onbnt1(GtkWidget *widget,gpointer gp);
static void onbnt2(GtkWidget *widget,gpointer gp);
static void activate(GtkApplication *app,gpointer gp);
int main(int argc,char **argv);
void crt_notebook(gpointer gp);		//used to create notebook control


