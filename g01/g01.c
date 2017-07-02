#include"g01.h"

int main(int argc,char** argv)
{
	GtkBuilder *builder;
	GObject  *window;
	gtk_init(&argc,&argv);
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder,"ty004.ui",NULL);
	window=gtk_builder_get_object(builder,"window");
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_main();
	return 0;
}

