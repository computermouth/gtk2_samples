#include <gtk/gtk.h>

static void destroy(GtkWidget*, gpointer);

int main(int argc, char *argv[]){
	
	GtkWidget *window, *label;
	
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello World");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_widget_set_size_request(window, 200, 100);
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
	
	label = gtk_label_new("Hello World");
	gtk_label_set_selectable(GTK_LABEL(label), TRUE);
	
	gtk_container_add(GTK_CONTAINER(window), label);	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

static void destroy(GtkWidget *window, gpointer data){
	gtk_main_quit();
}
