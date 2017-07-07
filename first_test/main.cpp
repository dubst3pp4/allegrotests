#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

/**
 * here we go
 */
int main(){
	ALLEGRO_DISPLAY *display = NULL;

	if(!al_init()){
		al_show_native_message_box(NULL, NULL, NULL,
		        "failed to initialize allegro!", NULL, NULL);
		return -1;
	}
	std::cout << "allegro successfully initialized." << std::endl;

	if(!(display = al_create_display(640, 480))){
		al_show_native_message_box(NULL, NULL, NULL,
		        "failed to initialize display!", NULL, NULL);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font24 = al_load_font("Ubuntu.ttf", 24, 0);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(
		font24,
		al_map_rgb(255, 0, 255),
		50, 50,
		0,
		"Hello world, this is 24 point."
	);
	al_flip_display();

	al_rest(5.0);
	al_destroy_display(display);

	return 0;
}
