# include "stranded_client.hpp"
/*
# include <errno.h>
# include <X11/keysymdef.h>
# include <firefly/system/keyborad.hpp>
# include <firefly/system/keyc_to_keysym.hpp>
*/
# include <firefly/types/err_t.h>
# include <firefly/system/errno.h>
# include <firefly/system/io.h>
mdl::firefly::types::err_t mdl::stranded_client::init() {
	firefly::types::err_t any_err;
	if ((any_err = this->ffc.init()) != FFLY_SUCCESS) {
		firefly::system::io::printf(stdout, "failed to initalize firefly client.\n");
		return any_err;
	}
/*
	mdl::firefly::types::init_opt_t init_options = {
		.cam_xlen = 256,
		.cam_ylen = 256
	};

	init_options.add_bse_room = true;
	init_options.change_room = true;
	init_options.add_bse_layer = true;
	init_options.obj_manger_ptr = nullptr;
	init_options.uni_init = true;

	firefly::types::err_t any_err;
	if ((any_err = this->_ffly_client.init(init_options)) != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to init ffly_client, ffly_errno: %d\n", ffly_errno);
		return any_err;
	}

	firefly::gui::btn btn;

	firefly::types::id_t bse_room_id = this->_ffly_client.bse_room_id;
	firefly::room_manager& room_manager = this->_ffly_client.room_manager;
	firefly::asset_manager& asset_manager = this->_ffly_client.asset_manager;

	if ((any_err = room_manager.add_room(this->sp_room_id, true)) != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to add room, ffly_errno: %d\n", ffly_errno);
		return any_err;
	}

	uint_t btn_count = sizeof(_bse_room::btn_indx)/sizeof(this->bse_room.btn_indx[0]);
	char const *text[btn_count] = {
		"Singleplayer",
		"Multiplayer",
		"Options",
		"Uni Editor",
		"Exit"
	};

	firefly::gui::btn_manager *btn_manager = firefly::room_manager::get_btn_manager(bse_room_id, &room_manager);

	for (std::size_t o = 0; o != btn_count; o ++) {
		btn.load_btn_ast(asset_manager.load_asset("../assets/template", firefly::asset_manager::AST_PNG_FILE), &asset_manager);
		btn.create_btn(bse_room.btn_indx[o], btn_manager, firefly::types::__coords__<uint_t>(0, (btn.get_pm_size().yaxis_len * o)  + (8 * o) + 24));

		if (btn_manager->set_text(bse_room.btn_indx[o], text[o], "../assets/TECHNOLIN.ttf", 0, 0, 2, true) == FFLY_FAILURE) return FFLY_FAILURE;

		btn.center_btn(room_manager.get_btn(bse_room_id, bse_room.btn_indx[o]), this->wd_xaxis_len, 0);

		btn_manager->enable_btn(bse_room.btn_indx[o]);
		btn_manager->event_bind(bse_room.btn_indx[o]);
		btn_manager->enable_hover(bse_room.btn_indx[o]);
		btn_manager->enable_press(bse_room.btn_indx[o]);
	}

	mdl::firefly::types::shape_info_t shape_info;

	mdl::firefly::types::_3d_coords_t<> obj_0 = {44, 3, 0};
	mdl::firefly::types::coords_t<> vertice_coords[][2] = {
		{{0, 0}, {1, 1}},
		{{14, 0}, {15, 1}},
		{{0, 14}, {1, 15}},
		{{14, 14}, {15, 15}}
	};

	mdl::firefly::types::coords_t<> face_coords[][2] = {
		{{2, 0}, {13, 1}},
		{{14, 2}, {15, 13}},
		{{2, 14}, {13, 15}},
		{{0, 2}, {1, 13}}
	};

	shape_info.vertice_coords = vertice_coords;
	shape_info.face_coords = face_coords;

	this->_ffly_client.entity_manager.add_entity(obj_0, shape_info, 16, 16, 1, any_err);
	if (any_err != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to add entity, ffly_errno: %d\n", ffly_errno);
		return any_err;
	}

	for (uint_t x = 0; x != 16; x ++) {
		for (uint_t y = 0; y != 16; y ++) {
			uint_t point = (x + (y * 16)) * 4;
			this->_ffly_client.obj_manager->get_pixmap(0)[point] = 3;
			this->_ffly_client.obj_manager->get_pixmap(0)[point + 1] = 3;
			this->_ffly_client.obj_manager->get_pixmap(0)[point + 2] = 3;
			this->_ffly_client.obj_manager->get_pixmap(0)[point + 3] = 245;
		}
	}
	if ((any_err = this->_ffly_client.entity_manager.init_cam(0, 128, 128)) != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to init camera for entity with id of 0, ffly_errno: %d\n", ffly_errno);
		return any_err;
	}
*/
}

mdl::firefly::types::err_t mdl::stranded_client::begin() {
/*
	firefly::types::err_t any_err;
	if ((any_err = this->_ffly_client.begin("Stranded Alpha", &stranded_client::engine_loop, this)) != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to begin, ffly_errno: %d\n", ffly_errno);
		return any_err;
	}
*/
	return FFLY_SUCCESS;
}

void mdl::stranded_client::engine_loop(i8_t __info, ffly_client::portal_t *__portal, void *__arg) {
/*
	stranded_client *_this = (stranded_client *)__arg;
	static ffly_client *ffc_ptr = __portal->ffc_ptr;

	firefly::types::event_t static event;
	while(firefly::poll_event(event)) {
		switch(event.event_desc.event_id) {
			case firefly::system::event_id::gui_btn: {
					mdl::firefly::types::btn_event_t *btn_event = (mdl::firefly::types::btn_event_t *)event.event_data;
					if (btn_event->btn_id == 4 && event.event_desc.event_type == firefly::system::GUI_BTN_PRESS) ffc_ptr->shutdown();
				break;
			}
			break;
			case firefly::system::event_id::key:
				if (event.event_desc.event_type == firefly::system::KEY_PRESS) {
					KeySym ks = firefly::system::keyc_to_keysym(__portal->wd_handle, *(uint_t *)event.event_data);
					switch(ks) {
						case XK_w:
							printf("w key pressed.\n");
						break;
						case XK_s:
							printf("s key pressed.\n");
						break;
						case XK_d:
							printf("d key pressed.\n");
						break;
						case XK_a:
							printf("a key pressed.\n");
						break;
					}
					printf("----------->key_sym: %d\n", ks);
				}
			break;
			case firefly::system::event_id::btn:

			break;
		}

		printf("pev_collapse called.\n");
		firefly::pev_collapse(event.event_desc.event_id);
	}

	printf("%d FPS\n", __portal->fps_count());
	//printf("camera_coords: %dx%dx%d\n", );
	usleep(1000);

	firefly::graphics::fill_pixmap(ffc_ptr->layer.get_layer_pixmap(0), _this->wd_xaxis_len, _this->wd_yaxis_len, _this->bg_colour);
	ffc_ptr->entity_manager.draw_cam(0, 0, 0, ffc_ptr->layer.get_layer_pixmap(0), _this->wd_xaxis_len, _this->wd_yaxis_len);
//	if (ffc_ptr->room_manager.get_croom_id == _this->sp_room_id) {

//	}
*/
}

int main() {
/*
	mdl::firefly::types::uni_prop_t uni_prop = {
		.xaxis_len = mdl::firefly::data::uni_dlen::UNI_DLEN_1024,
		.yaxis_len = mdl::firefly::data::uni_dlen::UNI_DLEN_1024,
		.zaxis_len = mdl::firefly::data::uni_dlen::UNI_DLEN_8
	};

	mdl::stranded_client stranded_client(640, 480, uni_prop);
	if (stranded_client.init() != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to init.\n");
		return -1;
	}

	if (stranded_client.begin() != FFLY_SUCCESS) {
		fprintf(stderr, "stranded_client: failed to begin.\n");
		return -1;
	}
*/
	return 0;
}
