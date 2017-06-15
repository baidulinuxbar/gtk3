#include"clsscr.h"
#include<gtk/gtk.h>

static void onbt1(GtkWidget *widget,gpointer gp)
{
	gchar ch[256];
	memset(ch,0,sizeof(ch));
	snprintf(ch,sizeof(ch),"风急天高猿啸哀，渚清沙白鸟飞回。");
	GtkDialogFlags flags=GTK_DIALOG_DESTROY_WITH_PARENT;
	GtkWidget *dialog;
	dialog=gtk_message_dialog_new(
			GTK_WINDOW(gp),
			flags,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_CLOSE,
			ch
			);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}
static void onbt2(GtkWidget *widget,gpointer gp)
{
	GtkDialogFlags flags=GTK_DIALOG_DESTROY_WITH_PARENT;
	GtkWidget *dialog;
	dialog=gtk_message_dialog_new(
			GTK_WINDOW(gp),
			flags,
			GTK_MESSAGE_OTHER,
			GTK_BUTTONS_YES_NO,
			"hello world"
			);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

int main(int argc,char **argv)
{
	GtkBuilder *builder;
	GObject *window,*button1,*button2;
	gtk_init(&argc,&argv);
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder,"ty002.ui",NULL);
	window=gtk_builder_get_object(builder,"window");
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	button1=gtk_builder_get_object(builder,"button1");
	g_signal_connect(button1,"clicked",G_CALLBACK(onbt1),window);
	button2=gtk_builder_get_object(builder,"button2");
	g_signal_connect(button2,"clicked",G_CALLBACK(onbt2),window);
//	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}


