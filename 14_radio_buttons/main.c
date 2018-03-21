#include <gtk/gtk.h>

int main(int argc, char *argv[]){
	
	GtkWidget *window, *vbox, *radio1, *radio2, *radio3, *radio4;
	
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Radio Buttons");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	vbox = gtk_vbox_new(TRUE, 5);
	
	radio1 = gtk_radio_button_new_with_label_from_widget(NULL, "I want to be clicked!");
	radio2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "Click me instead!");
	radio3 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "No! Click me!");
	radio4 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio3), "No! Click me instead!");
	
	gtk_box_pack_start_defaults(GTK_BOX(vbox), radio1);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), radio2);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), radio3);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), radio4);
	
	gtk_container_add(GTK_CONTAINER(window), vbox);	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}
