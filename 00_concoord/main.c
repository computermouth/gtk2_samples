#include <gtk/gtk.h>

static void destroy(GtkWidget*, gpointer);
static gpointer cc_new_window();
static gpointer cc_new_anim_pane();

int main(int argc, char *argv[]){
	
	GtkWidget *window, *anim_pane, *label;
	
	gtk_init(&argc, &argv);
	
	window = cc_new_window();
	
	label = gtk_label_new("Hello World");
	gtk_label_set_selectable(GTK_LABEL(label), TRUE);
	gtk_container_add(GTK_CONTAINER(window), label);	
	
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

static gpointer cc_new_window(){
	
	GtkWidget *tmp_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(tmp_window), "Hello World");
	gtk_container_set_border_width(GTK_CONTAINER(tmp_window), 10);
	gtk_widget_set_size_request(tmp_window, 200, 100);
	
	g_signal_connect(G_OBJECT(tmp_window), "destroy", G_CALLBACK(destroy), NULL);
	
	return tmp_window;
}

static gpointer cc_new_anim_pane(){
	
	GtkWidget *tmp_anim_pane = gtk_hpaned_new();
	
	return window;
}

static void destroy(GtkWidget *window, gpointer data){
	gtk_main_quit();
}
