#include <gtk/gtk.h>

static void destroy(GtkWidget*, gpointer);
static gpointer cc_new_window();
static gpointer cc_new_anim_pane();
static gpointer cc_new_frame_pane();
static gpointer cc_new_canvas_pane();

int main(int argc, char *argv[]){
	
	GtkWidget *window, *anim_pane, *label;
	
	gtk_init(&argc, &argv);
	
	window = cc_new_window();	
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

//    +-------------------------+
//    |                         |
//    |                         |
//    |                         |
//    |                         |
//    |                         |
//    |                         |
//    |                         |
//    |                         |
//    +-------------------------+

static gpointer cc_new_window(){
	
	GtkWidget *tmp_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(tmp_window), "Hello World");
	gtk_container_set_border_width(GTK_CONTAINER(tmp_window), 10);
	gtk_widget_set_size_request(tmp_window, 800, 500);
	
	g_signal_connect(G_OBJECT(tmp_window), "destroy", G_CALLBACK(destroy), NULL);
	
	GtkWidget *anim_pane = cc_new_anim_pane();
	
	gtk_container_add(GTK_CONTAINER(tmp_window), anim_pane);
	
	return tmp_window;
}

//    +-------------------------+
//    | + |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    +-------------------------+

static gpointer cc_new_anim_pane(){
	
	GtkWidget *tmp_anim_pane = gtk_hpaned_new();
	
	GtkWidget *anim_add_button = gtk_button_new_with_label("Add Anim");
	gtk_widget_set_size_request(anim_add_button, 100, 500);
	GtkWidget *frame_pane = cc_new_frame_pane();
	
	gtk_paned_add1(GTK_PANED(tmp_anim_pane), anim_add_button);	
	gtk_paned_add2(GTK_PANED(tmp_anim_pane), frame_pane);
	
	return tmp_anim_pane;
}

//    +-------------------------+
//    | + | + |                 |
//    |   |   |                 |
//    |   |   |                 |
//    |   |   |                 |
//    |   |   |                 |
//    |   |   |                 |
//    |   |   |                 |
//    |   |   |                 |
//    +-------------------------+

static gpointer cc_new_frame_pane(){
	
	GtkWidget *tmp_frame_pane = gtk_hpaned_new();
	
	GtkWidget *frame_add_button = gtk_button_new_with_label("Add FRAME");
	gtk_widget_set_size_request(frame_add_button, 100, 500);
	GtkWidget *canvas_pane = cc_new_canvas_pane();
	
	gtk_paned_add1(GTK_PANED(tmp_frame_pane), frame_add_button);	
	gtk_paned_add2(GTK_PANED(tmp_frame_pane), canvas_pane);
	
	return tmp_frame_pane;
}

//    +-------------------------+
//    | + | + |             |   |
//    |   |   |             |   |
//    |   |   |             |   |
//    |   |   |             |   |
//    |   |   |             |   |
//    |   |   |             |   |
//    |   |   |             |   |
//    |   |   |             |   |
//    +-------------------------+

static gpointer cc_new_canvas_pane(){
	
	GtkWidget *tmp_canvas_pane = gtk_hpaned_new();
	
	GtkWidget *canvas_button = gtk_button_new_with_label("Canvas");
	gtk_widget_set_size_request(canvas_button, 400, 500);
	GtkWidget *tools_button = gtk_button_new_with_label("Tools");
	
	gtk_paned_add1(GTK_PANED(tmp_canvas_pane), canvas_button);
	gtk_paned_add2(GTK_PANED(tmp_canvas_pane), tools_button);
	
	return tmp_canvas_pane;
}

static void destroy(GtkWidget *window, gpointer data){
	gtk_main_quit();
}
