# include <firefly/ffly_engine.hpp>
# include <firefly/graphics/fill_pixmap.hpp>
# include <firefly/types/colour_t.hpp>
# include <cstdio>
# include <firefly/keycodes.h>
# include <boost/cstdint.hpp>
# include <firefly/obj_manager.hpp>
# include <firefly/system/event.hpp>
static mdl::firefly::obj_manager *obj_manager;
static int unsigned xpos = 33, ypos = 33;
void game_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal) {
	mdl::firefly::system::event event;

	while(__portal-> poll_event(event)) {
		switch(event.event_type) {
			case mdl::firefly::system::event::KEY_PRESSED:
				if (event.key_code == X11_LT_D) {
					xpos ++;
					obj_manager-> set_xaxis(0, xpos);
				}
				if (event.key_code == X11_LT_A) {
					xpos --;
					obj_manager-> set_xaxis(0, xpos);
				}
				if (event.key_code == X11_LT_W) {
					ypos --;
					obj_manager-> set_yaxis(0, ypos);
				}
				if (event.key_code == X11_LT_S) {
					ypos ++;
					obj_manager-> set_yaxis(0, ypos);
				}
			break;
		}
	}

//	usleep(1000);

	printf("%d FPS\n", __portal-> fps_count());

	mdl::firefly::graphics::colour_t colour = {38, 60, 94, 255};
	mdl::firefly::graphics::fill_pixmap(__portal-> _this-> layer.get_layer_pixmap(0), 640, 640, colour);

	obj_manager-> manage();
}

int main() {
	mdl::ffly_client *client = new mdl::ffly_client(640, 640);
	mdl::firefly::types::init_opt_t init_options = {
		.cam_xlen = 256,
		.cam_ylen = 256
	};

	client-> layer.add_layer(640, 640, 0, 0);
	mdl::firefly::graphics::colour_t colour = {38, 60, 94, 255};
	mdl::firefly::graphics::fill_pixmap(client-> layer.get_layer_pixmap(0), 640, 640, colour);

	mdl::firefly::obj_manager obj_mana(client-> layer.get_layer_pixmap(0), 640, 640, 1);
	obj_manager = &obj_mana;
	obj_mana.add(64, 64, 1, 33, 33, 0);
	obj_mana.enable_bound(0);
	obj_mana.set_xaxis_bound(0, 1, 640);
	obj_mana.set_yaxis_bound(0, 1, 640);
	obj_mana.enable_gravity(0);

	client-> init(init_options);
	client-> begin("Stranded Alpha", game_loop);
	delete client;

	return 0;
}
