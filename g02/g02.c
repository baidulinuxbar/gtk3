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
	crt_page2();
	gtk_notebook_append_page(GTK_NOTEBOOK(ws.note),p2.fix,p2.lab[0]);
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
	g_signal_connect(p1.bnt[1],"clicked",G_CALLBACK(on_p1_bnt2),NULL);
	p1.lab[1]=gtk_label_new(t_p1_lab2);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.lab[1],p1_lab2_x,p1_lab2_y);
	p1.combo=gtk_combo_box_text_new();
	gtk_widget_set_size_request(p1.combo,125,20);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"0",t_p1_com1);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"1",t_p1_com2);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"2",t_p1_com3);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"3",t_p1_com4);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"4",t_p1_com5);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"5",t_p1_com6);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"6",t_p1_com7);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"7",t_p1_com8);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"8",t_p1_com9);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p1.combo),"9",t_p1_com10);
	gtk_combo_box_set_active(GTK_COMBO_BOX(p1.combo),0);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.combo,p1_combo_x,p1_combo_y);
	p1.lab[1]=gtk_label_new(t_p1_lab3);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.lab[1],p1_lab3_x,p1_lab3_y);
	p1.ed[1]=gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(p1.ed[1]),12);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.ed[1],p1_ed2_x,p1_ed2_y);
	p1.lab[1]=gtk_label_new(t_p1_lab4);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.lab[1],p1_lab4_x,p1_lab4_y);
	p1.ed[2]=gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(p1.ed[2]),6);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.ed[2],p1_ed3_x,p1_ed3_y);
	p1.lab[2]=gtk_label_new("运行状态：等待中");
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.lab[2],p1_lab5_x,p1_lab5_y);
	p1.store=gtk_list_store_new(7,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,\
			G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	p1.model=GTK_TREE_MODEL(p1.store);
	p1.list=gtk_tree_view_new_with_model(p1.model);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list1,p1.render,"text",0,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list2,p1.render,"text",1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list3,p1.render,"text",2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list4,p1.render,"text",3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list5,p1.render,"text",4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list6,p1.render,"text",5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	p1.render=gtk_cell_renderer_text_new();
	p1.column=gtk_tree_view_column_new_with_attributes(t_p1_list7,p1.render,"text",6,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(p1.list),p1.column);
	gtk_widget_set_size_request(p1.list,p1_list_w,p1_list_h);
	p1.scroll=gtk_scrolled_window_new(NULL,NULL);
	gtk_widget_set_size_request(p1.scroll,p1_list_w,p1_list_h);
	gtk_widget_show(p1.scroll);
	gtk_widget_set_vexpand(p1.scroll,TRUE);
	gtk_widget_set_hexpand(p1.scroll,TRUE);
	gtk_container_add(GTK_CONTAINER(p1.scroll),p1.list);
	gtk_fixed_put(GTK_FIXED(p1.fix),p1.scroll,p1_list_x,p1_list_y);
}
//}}}
//{{{static void crt_page2()
static void crt_page2()
{
	p2.lab[0]=gtk_label_new(t_p2_lab1);
	p2.fix=gtk_fixed_new();
	p2.combo=gtk_combo_box_text_new();
	gtk_widget_set_size_request(p2.combo,125,20);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p2.combo),"0",t_p2_com1);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p2.combo),"1",t_p2_com2);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p2.combo),"2",t_p2_com3);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(p2.combo),"3",t_p2_com4);
	gtk_combo_box_set_active(GTK_COMBO_BOX(p2.combo),0);
	gtk_fixed_put(GTK_FIXED(p2.fix),p2.combo,p2_combo_x,p2_combo_y);
	p2.bnt=gtk_button_new_with_label(t_p2_bnt1);
	gtk_fixed_put(GTK_FIXED(p2.fix),p2.bnt,p2_bnt_x,p2_bnt_y);
	p2.lab[1]=gtk_label_new(t_p2_lab2);
	gtk_fixed_put(GTK_FIXED(p2.fix),p2.lab[1],p2_lab_x,p2_lab_y);
	p2.ed=gtk_text_view_new();
	gtk_widget_set_size_request(p2.ed,p2_ed_w,p2_ed_h);
	p2.buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(p2.ed));
	gtk_text_buffer_get_iter_at_offset(p2.buffer,&p2.iter,0);
	gtk_text_buffer_create_tag(p2.buffer,tag_pal,"pixels_above_lines",30,NULL); //文字上方30像素的空余
	gtk_text_buffer_create_tag(p2.buffer,tag_pbl,"pixels_below_lines",30,NULL); //文字下方30像素的空余
	gtk_text_buffer_create_tag(p2.buffer,tag_lmarg,"left_margin",5,NULL); //文字左方5像素的空余
	gtk_text_buffer_create_tag(p2.buffer,tag_red_fg,"foreground","red",NULL);//红色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_blue_fg,"foreground","blue",NULL);//蓝色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_yellow_fg,"foreground","yellow",NULL);//黄色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_magenta_fg,"foreground","#FF00FF",NULL);//洋红色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_green_fg,"foreground","green",NULL);	//绿色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_gray_fg,"foreground","gray",NULL);	//灰色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_black_fg,"foreground","black",NULL);	//黑色前景
	gtk_text_buffer_create_tag(p2.buffer,tag_gray_bg,"background","gray",NULL);	//灰色背景
	gtk_text_buffer_create_tag(p2.buffer,tag_yellow_bg,"background","yellow",NULL);	//黄色背景
	gtk_text_buffer_create_tag(p2.buffer,tag_blue_bg,"background","blue",NULL);	//蓝色背景
	gtk_text_buffer_create_tag(p2.buffer,tag_green_bg,"background","green",NULL);	//绿色背景
	gtk_text_buffer_create_tag(p2.buffer,tag_black_bg,"background","black",NULL);	//黑色背景
	gtk_text_buffer_create_tag(p2.buffer,tag_underline,"underline",PANGO_UNDERLINE_SINGLE,NULL);//下划线样式
	gtk_text_buffer_create_tag(p2.buffer,tag_bold,"weight",PANGO_WEIGHT_BOLD,NULL); //粗体
	gtk_text_buffer_create_tag(p2.buffer,tag_italic,"style",PANGO_STYLE_ITALIC,NULL); //斜体
	gtk_text_buffer_create_tag(p2.buffer,tag_strike,"strikethrough",TRUE,NULL); //删除线
	gtk_text_buffer_create_tag(p2.buffer,tag_quarter,"scale",(double)0.25,NULL); //1/4大小字体
	gtk_text_buffer_create_tag(p2.buffer,tag_des,"scale",PANGO_SCALE_XX_SMALL,NULL);//特小小
	gtk_text_buffer_create_tag(p2.buffer,tag_es,"scale",PANGO_SCALE_X_SMALL,NULL);//特小
	gtk_text_buffer_create_tag(p2.buffer,tag_small,"scale",PANGO_SCALE_SMALL,NULL);	//小
	gtk_text_buffer_create_tag(p2.buffer,tag_med,"scale",PANGO_SCAEL_MEDIUM,NULL); //普通
	gtk_text_buffer_create_tag(p2.buffer,tag_large,"scale",PANGO_SCALE_LARGE,NULL);//大字体
	gtk_text_buffer_create_tag(p2.buffer,tag_elrg,"scale",PANGO_SCALE_X_LARGE,NULL);//超大
	gtk_text_buffer_create_tag(); //超大大
	gtk_text_buffer_insert(p2.buffer,&p2.iter,"this is a test\n",strlen("this is a test\n"));
	gtk_text_buffer_insert_with_tags_by_name(p2.buffer,&p2.iter,"this is a test 这是一个测试\n",-1,tag_pal,tag_lmarg,tag_red_fg,NULL); //上方空余30pix，左方空余5像素，红色字体
	gtk_fixed_put(GTK_FIXED(p2.fix),p2.ed,p2_ed_x,p2_ed_y);
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
//{{{static void on_p1_bnt2(GtkWidget *widget,gpointer gp)
static void on_p1_bnt2(GtkWidget *widget,gpointer gp)
{
	GtkTreeIter iter;
	//gdk_threads_enter();
	p1.store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(p1.list)));
	gtk_list_store_append(p1.store,&iter);
	memset(ch,0,sizeof(ch));
	gtk_list_store_set(p1.store,&iter,0,0,1,"icmp",2,"25",3,"456",4,"202.102.134.68",5,"192.168.1.122",6,"60",-1);
	//gdk_threads_leave();
}
//}}}


