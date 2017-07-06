#include"g02.h"

//{{{static void activate(GtkApplication *app,gpointer gp)
static void activate(GtkApplication *app,gpointer gp)
{
	ws.window=gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(ws.window),"notebook demo");
	gtk_window_set_default_size(GTK_WINDOW(ws.window),win_w,win_h);
	gtk_window_set_position(GTK_WINDOW(ws.window),GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(ws.window),FALSE);
	ws.fix=gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(ws.window),ws.fix);
	ws.note=gtk_notebook_new();
	gtk_widget_set_size_request(ws.note,note_w,note_h);
	crt_page1();
	gtk_notebook_append_page(GTK_NOTEBOOK(ws.note),p1.fix,p1.lab[0]);
	gtk_fixed_put(GTK_FIXED(ws.fix),ws.note,margin_w,margin_h);
	gtk_widget_show_all(ws.window);
}
//}}}
//{{{static void crt_page1()
static void crt_page1()
{
	p1.lab[0]=gtk_label_new(t_p1_title);
	p1.fix=gtk_fixed_new();
	p1.lab[1]=gtk_label_new(t_p1_lab1);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.lab[1],p1_lab1_x,p1_lab1_y);
	p1.ed[0]=gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(p1.ed[0]),12);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.ed[0],p1_ed1_x,p1_ed1_y);
	p1.chkbnt=gtk_check_button_new_with_label(t_p1_chk);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.chkbnt,p1_chk_x,p1_chk_y);
	p1.bnt[0]=gtk_button_new_with_label(t_p1_bnt1);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.bnt[0],p1_bnt1_x,p1_bnt1_y);
	g_signal_connect(p1.bnt[0],"clicked",G_CALLBACK(on_p1_bnt1),NULL);
	p1.bnt[1]=gtk_button_new_with_label(t_p1_bnt2);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.bnt[1],p1_bnt2_x,p1_bnt2_y);
	p1.bnt[2]=gtk_button_new_with_label(t_p1_bnt3);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.bnt[2],p1_bnt3_x,p1_bnt3_y);
	p1.lab[1]=gtk_label_new(t_p1_lab2);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.lab[1],p1_lab2_x,p1_lab2_y);
	
}
//}}}
//{{{int main(int argc,char **argv)
int main(int argc,char **argv)
{
	int status;
	ws.app=gtk_application_new(NULL,G_APPLICATION_FLAGS_NONE);
	g_signal_connect(ws.app,"activate",G_CALLBACK(activate),NULL);
	status=g_application_run(G_APPLICATION(ws.app),argc,argv);
	g_object_unref(ws.app);
	return status;
}
//}}}
//{{{static void on_p1_bnt1(GtkWidget *widget,gpointer gp)
static void on_p1_bnt1(GtkWidget *widget,gpointer gp)
{
	memset(ch,0,sizeof(ch));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(p1.chkbnt)))
		snprintf(ch,sizeof(ch),"选择保存文件");
	else
		snprintf(ch,sizeof(ch),"不保存文件");
	GtkDialogFlags flag=GTK_DIALOG_DESTROY_WITH_PARENT;
	GtkWidget *dialog=gtk_message_dialog_new(
			GTK_WINDOW(ws.window),
			flag,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_CLOSE,
			ch);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}
//}}}


