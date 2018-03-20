#include <gtk/gtk.h>

static void destroy(GtkWidget*, gpointer);
static gpointer cc_new_window();
static gpointer cc_new_anim_pane();
static gpointer cc_new_anim_scrolled();
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
	
	//~ GtkWidget *anim_add_button = gtk_button_new_with_label("Add Anim");
	//~ gtk_widget_set_size_request(anim_add_button, 100, 500);
	GtkWidget *anim_scrolled = cc_new_anim_scrolled();
	GtkWidget *frame_pane = cc_new_frame_pane();
	
	gtk_paned_add1(GTK_PANED(tmp_anim_pane), anim_scrolled);	
	gtk_paned_add2(GTK_PANED(tmp_anim_pane), frame_pane);
	
	return tmp_anim_pane;
}

//    +-------------------------+
//    | +||                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    |   |                     |
//    +-------------------------+

static gpointer cc_new_anim_scrolled(){
	
	GtkWidget *tmp_anim_scrolled = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_set_border_width(GTK_CONTAINER(tmp_anim_scrolled), 5);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(tmp_anim_scrolled),
		GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	
	GtkWidget *table = gtk_table_new(10, 1, TRUE);
	GtkWidget *anim_add_button0 = gtk_button_new_with_label("Anim");
	GtkWidget *anim_add_button1 = gtk_button_new_with_label("Anim");
	GtkWidget *anim_add_button2 = gtk_button_new_with_label("+");
	
	gtk_table_attach_defaults(GTK_TABLE(table), anim_add_button0, 0, 1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), anim_add_button1, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), anim_add_button2, 0, 1, 2, 3);
	
	gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(tmp_anim_scrolled), table);
	
	return tmp_anim_scrolled;
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
