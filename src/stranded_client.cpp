# include "stranded_client.hpp"
# include <math.h>

# include <firefly/graphics/skelmap_loader.hpp>
# include <firefly/graphics/draw_rect.hpp>
# include <to_string.hpp>
# include <strcmb.hpp>
# include <firefly/skelfont.hpp>
# include <firefly/graphics/fill_pixmap.hpp>
# include <firefly/graphics/draw_text.hpp>
# define CONNECT__
# include <firefly/graphics/draw_pixel.hpp>

# include <firefly/maths/rotate_point.hpp>
# include <firefly/tests/layering.hpp>
# include <firefly/graphics/scale_pixmap.hpp>
# include <firefly/graphics/png_loader.hpp>
#define WX 640
#define HX 480
static mdl::firefly::types::skelfont_t *my_skelfont;
boost::int8_t mdl::stranded_client::init() {
	static ffly_client ffc(this-> win_xlen, this-> win_ylen);
	this-> ffc = &ffc;

	ffc.layer.add_layer(256, 256, 10, 10);
/*
	mdl::firefly::graphics::colour_t colour = {
		.r = 124,
		.g = 12,
		.b = 0,
		.a = 254
	};

	boost::uint8_t *img = nullptr;
	uint_t size[2] = {0};

	firefly::graphics::load_png_file("../test.png", img, size);

	uint_t layer_id = ffc.layer.add_layer(400, 400, 0, 0);

	firefly::graphics::scale_pixmap(img, size[0], size[1], 6);

	printf("nX: %d, nY: %d\n", size[0], size[1]);
	firefly::graphics::draw_pixmap(0, 0, ffc.layer.get_layer_pixmap(layer_id), 400, 400, img, size[0], size[1]);

	//mdl::firefly::graphics::fill_pixmap(ffc.layer.get_layer_pixmap(1), 400, 400, colour);

	for (std::size_t y = 200; y != 200 + 8; y ++) {
		for (std::size_t x = 200; x != 200 + 8; x ++) {
			std::size_t nx = x - 200, ny = y - 200;

			firefly::maths::rotate_point(nx, ny, 45.0, x, y);

			if (nx > 399 || ny > 399 || nx < 0 || ny < 0) return -1;

			firefly::graphics::draw_pixel(nx, ny, colour, ffc.layer.get_layer_pixmap(0), 400);
		}
	}
*/
	//firefly::tests::layering(55, 50, 55, 50, &ffc.layer, 5, 22, 200);
}

void mdl::stranded_client::ffc_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal) {
#ifdef CONNECT__
	if (!__portal-> server_connected())
		__portal-> connect_to_server("192.168.0.100", 0, 0);


	if (!__portal-> server_connected()) return;
# else
usleep(10000);
# endif
}

boost::int8_t mdl::stranded_client::begin() {
	this-> ffc-> begin("Stranded Demo", mdl::stranded_client::ffc_loop);
}

int main(int argc, char const *argv[]) {
	mdl::stranded_client client(640, 480);

	if (client.init() == -1) return 1;

	if (client.begin() == -1) return 1;

	printf("clean up\n");
	client.ffc-> cu_clean();
	return 0;

}
