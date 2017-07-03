#include"g10.h"
//{{{int main(int argc,char **argv)
int main(int argc,char **argv)
{
	int status;
	ws.app=gtk_application_new(NULL,G_APPLICATION_FLAGS_NONE);
	g_signal_connect(ws.app,"activate",G_CALLBACK(activate),NULL);
	status=g_application_run(G_APPLICATION(ws.app),argc,argv);
	g_object_unref(ws.app);
	return status;
}//}}}
//{{{static void activate(GtkApplication *app,gpointer gp)
static void activate(GtkApplication *app,gpointer gp)
{
	ws.window=gtk_application_window_new(ws.app);
	gtk_window_set_title(GTK_WINDOW(ws.window),"g10 demo");
	gtk_window_set_default_size(GTK_WINDOW(ws.window),win_w,win_h);
	ws.fix1=gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(ws.window),ws.fix1);
	crt_notebook(gp);
	gtk_widget_show_all(ws.window);
}//}}}
//{{{void crt_notebook(gpointer gp)
void crt_notebook(gpointer gp)
{
	ws.note=gtk_notebook_new();
	gtk_widget_set_size_request(ws.note,note_w,note_h);
	gtk_fixed_put(GTK_FIXED(ws.fix1),ws.note,5,5);
	ws.lab[0]=gtk_label_new("监听界面");
	ws.fix_note[0]=gtk_fixed_new();
	ws.bnt1=gtk_button_new_with_label("开始监听");
	gtk_fixed_put(GTK_FIXED(ws.fix_note[0]),ws.bnt1,40,10);
	ws.lab[4]=gtk_label_new("notebook界面一");
	gtk_fixed_put(GTK_FIXED(ws.fix_note[0]),ws.lab[4],300,300);
	gtk_notebook_append_page(GTK_NOTEBOOK(ws.note),ws.fix_note[0],ws.lab[0]);
	g_signal_connect(ws.bnt1,"clicked",G_CALLBACK(onbnt1),NULL);
	ws.lab[1]=gtk_label_new("包查看界面");
	ws.fix_note[1]=gtk_fixed_new();
	ws.bnt2=gtk_button_new_with_label("包选择");
	gtk_fixed_put(GTK_FIXED(ws.fix_note[1]),ws.bnt2,140,10);
	ws.lab[3]=gtk_label_new("notebook界面二");
	gtk_fixed_put(GTK_FIXED(ws.fix_note[1]),ws.lab[3],300,300);
	gtk_notebook_append_page(GTK_NOTEBOOK(ws.note),ws.fix_note[1],ws.lab[1]);
	g_signal_connect(ws.bnt2,"clicked",G_CALLBACK(onbnt2),NULL);
}//}}}
//{{{static void onbnt1(GtkWidget *widget,gpointer gp)
static void onbnt1(GtkWidget *widget,gpointer gp)
{
	g_print("on test!\n");
}//}}}
//{{{static void onbnt2(GtkWidget *widget,gpointer gp)
static void onbnt2(GtkWidget *widget,gpointer gp)
{
	g_print("this is page two test!\n");
}//}}}


