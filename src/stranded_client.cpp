# include "stranded_client.hpp"
boost::int8_t mdl::stranded_client::init() {
	mdl::firefly::types::init_opt_t init_options = {
		.cam_xlen = 256,
		.cam_ylen = 256
	};

	this-> _ffly_client.layer.add_layer(640, 640, 0, 0);

	this-> _ffly_client.init(init_options);
}

boost::int8_t mdl::stranded_client::begin() {
	this-> _ffly_client.begin("Stranded Alpha", &stranded_client::engine_loop, this);
}

void mdl::stranded_client::engine_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal, void *__this) {
	stranded_client *_this = (stranded_client *)__this;

	firefly::system::event event;

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
		}
	}

	printf("%d FPS\n", __portal-> fps_count());
	usleep(10000);

	firefly::graphics::fill_pixmap(__portal-> _this-> layer.get_layer_pixmap(0), _this-> wd_xaxis_len, _this-> wd_yaxis_len, _this-> bg_colour);
}

int main() {
	mdl::stranded_client stranded_client(640, 640);
	stranded_client.init();
	stranded_client.begin();
}
