# include "stranded_client.hpp"
# include <errno.h>
boost::int8_t mdl::stranded_client::init() {
	mdl::firefly::types::init_opt_t init_options = {
		.cam_xlen = 256,
		.cam_ylen = 256
	};

	init_options.add_bse_room = true;
	init_options.change_room = true;
	init_options.add_bse_layer = false;

	this-> _ffly_client.layer.add_layer(640, 480, 0, 0);

	this-> _ffly_client.init(init_options);

	firefly::gui::btn btn;

	firefly::types::id_t bse_room_id = this-> _ffly_client.bse_room_id;
	firefly::room_manager& room_manager = this-> _ffly_client.room_manager;
	firefly::asset_manager& asset_manager = this-> _ffly_client.asset_manager;


	uint_t btn_count = sizeof(_bse_room::btn_indx)/sizeof(this-> bse_room.btn_indx[0]);
	char const *text[btn_count] = {
		"Singleplayer",
		"Multiplayer",
		"Options",
		"Uni Editor",
		"Exit"
	};
	firefly::gui::btn_manager& btn_manager = firefly::room_manager::get_btn_manager(bse_room_id, &room_manager);

	for (std::size_t o = 0; o != btn_count; o ++) {
		btn.load_btn_ast(asset_manager.load_asset("../assets/template", firefly::asset_manager::AST_PNG_FILE), &asset_manager);
		btn.create_btn(bse_room.btn_indx[o], &btn_manager, firefly::types::__coords__<uint_t>(0, (btn.get_pm_size().yaxis_len * o)  + (8 * o) + 24));

		if (btn_manager.set_text(bse_room.btn_indx[o], text[o], "../assets/TECHNOLIN.ttf", 0, 0, 2, true) == FFLY_FAILURE) return FFLY_FAILURE;

		btn.center_btn(room_manager.get_btn(bse_room_id, bse_room.btn_indx[o]), this-> wd_xaxis_len, 0);

		btn_manager.enable_btn(bse_room.btn_indx[o]);
		btn_manager.event_bind(bse_room.btn_indx[o]);
		btn_manager.enable_hover(bse_room.btn_indx[o]);
		btn_manager.enable_press(bse_room.btn_indx[o]);
	}

//	firefly::types::btn_t *my_btn = room_manager.get_btn(bse_room_id, btn_id);
}

boost::int8_t mdl::stranded_client::begin() {
	this-> _ffly_client.begin("Stranded Alpha", &stranded_client::engine_loop, this);
}

void mdl::stranded_client::engine_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal, void *__this) {
	stranded_client *_this = (stranded_client *)__this;

	static firefly::system::event event;

	while(__portal-> poll_event(event)) {
		switch(event.event_type) {
			case mdl::firefly::system::event::KEY_PRESSED:
				if (event.key_code == mdl::firefly::system::event::WD_KEY_D) {
					printf("key 'WD_KEY_D' was pressed.\n");

				} else if (event.key_code == mdl::firefly::system::event::WD_KEY_A) {
					printf("key 'WD_KEY_A' was pressed.\n");

				} else if (event.key_code == mdl::firefly::system::event::WD_KEY_W) {
					printf("key 'WD_KEY_W' was pressed.\n");

				} else if (event.key_code == mdl::firefly::system::event::WD_KEY_S) {
					printf("key 'WD_KEY_S' was pressed.\n");

				}
			break;
			case mdl::firefly::system::event::BTN_PRESS: {
				mdl::firefly::types::btn_event_t *btn_event = (mdl::firefly::types::btn_event_t *)event.data;
				if (btn_event-> btn_id == 4) __portal-> _this-> shutdown();
				printf("button with the id of %d has been pressed.\n", btn_event-> btn_id);
				break;
			}
	//		default:
	//			printf("event that was captured was not recognized.\n");
	//		break;
		}
	}

	printf("%d FPS\n", __portal-> fps_count());
	usleep(1000);

	firefly::graphics::fill_pixmap(__portal-> _this-> layer.get_layer_pixmap(0), _this-> wd_xaxis_len, _this-> wd_yaxis_len, _this-> bg_colour);
}

int main() {
	try {
	mdl::stranded_client stranded_client(640, 480);
	if (stranded_client.init() == FFLY_FAILURE) return 1;
	stranded_client.begin();

	printf("%d\n", errno);
	printf("back to main function\n");
	exit(1);
	} catch(...) {
		printf("failed to close app.\n");
	}

	return 0;
}
