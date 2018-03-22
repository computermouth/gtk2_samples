#include <gtk/gtk.h>

static void highlight_all(GtkWidget*, GdkEvent*, gpointer);

int main(int argc, char *argv[]){
	
	GtkWidget *window, *vbox, *hbox, *question, *label, *entry, *pass;
	
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Password");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gchar * str = g_strconcat("What is the password for ", g_get_user_name(), "?", NULL);
	question = gtk_label_new(str);
	label = gtk_label_new("Password:");
	
	entry = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry), "untitled_000");
	g_signal_connect(GTK_ENTRY(entry), "focus-in-event", G_CALLBACK(highlight_all), NULL);
	
	pass = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(pass), FALSE);
	gtk_entry_set_invisible_char(GTK_ENTRY(pass), '*');
	
	hbox = gtk_hbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), pass);
	
	vbox = gtk_vbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), question);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), entry);
	
	gtk_container_add(GTK_CONTAINER(window), vbox);	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

static void highlight_all(GtkWidget *widget, GdkEvent *event, gpointer data){
	printf("ey\n");
	//~ guint16 len = gtk_entry_get_text_length( GTK_ENTRY(widget));
	
	gtk_editable_select_region(GTK_EDITABLE(widget), 0, GTK_ENTRY(widget)->text_length);
	
}
