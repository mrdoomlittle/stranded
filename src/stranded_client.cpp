# include "stranded_client.hpp"
# include <firefly/types/err_t.h>
# include <firefly/system/errno.h>
# include <firefly/system/io.h>
# include <firefly/keycodes.h>
# include <firefly/types/wd_ed_t.h>
# include <firefly/system/event_field.h>
# include <firefly/graphics/colour.hpp>
# include <firefly/data/mem_set.h>
# include <firefly/graphics/fill.h>
# include <firefly/graphics/colour.hpp>
# include <firefly/system/err.h>
# include <firefly/graphics/png_loader.h>
# include <firefly/graphics/image.h>
# include <firefly/graphics/copy.h>
# include <firefly/types/id_t.h>
# include <firefly/data/mem_cpy.h>
# include <firefly/memory/mem_free.h>
mdl::firefly::types::err_t mdl::stranded_client::init(u16_t __wd_width, u16_t __wd_height) {
	firefly::types::err_t err;
	if (_err(err = this->ffc.init(__wd_width, __wd_height, TITLE))) {
		firefly::system::io::fprintf(ffly_err, "failed to init firefly.\n");
		return err;
	}

	uint_t no = this->ffc.layer_m.add_layer(__wd_width, __wd_height, 0, 0, nullptr, err);
	if (_err(err)) {
		firefly::system::io::fprintf(ffly_err, "failed to add layer.\n");
		return err;
	}

	firefly::types::id_t id = this->ffc.asset_m.load_asset("assets", "test", _ffly_ak_png_file, 0, err);
	if (_err(err)) {
		firefly::system::io::fprintf(ffly_err, "failed to load asset.\n");
		return err;
	}

	this->bg = (firefly::graphics::imagep)this->ffc.asset_m.get_asset_data(id);
	if (_err(err = firefly::graphics::pixelcopy(this->ffc.layer_m.get_layer_pixelmap(no), this->bg->pixels, this->bg->width*this->bg->height))) {
		firefly::system::io::fprintf(ffly_err, "failed to copy pixels.\n");
		return err;
	}

/*
	if (_err(err = firefly::graphics::pixelfill(this->ffc.layer_m.get_layer_pixelmap(no), __wd_width*__wd_height, firefly::graphics::mk_colour(0xFF, 0xFF, 0x0, 0xFF)))) {
		firefly::system::io::fprintf(ffly_err, "failed to fill base layer.\n");
		return err;
	}
*/
	return FFLY_SUCCESS;
}

mdl::firefly::types::err_t mdl::stranded_client::begin() {
	firefly::types::err_t err;
	if (_err(err = this->ffc.begin(&stranded_client::engine_loop, (void*)this))) {
		firefly::system::io::fprintf(ffly_out, "failed to ignite engine.\n");
		return err;
	}
	return FFLY_SUCCESS;
}

# include <firefly/system/event_kind.h>
# include <firefly/types/event_t.h>
# include <firefly/system/event.h>
# include <firefly/firefly.hpp>
mdl::firefly::types::err_t mdl::stranded_client::engine_loop(i8_t __report, ffly_client::portal_t *__portal, void *__arg_p) {
	mdl::firefly::system::io::printf("fps: %u\n", __portal->get_fps());
	mdl::stranded_client *_this = reinterpret_cast<mdl::stranded_client*>(__arg_p);

	mdl::firefly::types::event_t *event;
	while(mdl::firefly::poll_event(event)) {
		switch(event->kind) {
			case _ffly_wd_ek_key_press:

			break;
			case _ffly_wd_ek_closed:
				mdl::firefly::system::io::printf("shuting down.\n", __portal->get_fps());
				__portal->shutdown();
			break;
		}
		mdl::firefly::free_event(__portal->get_ffc_p(), event);
	}

	return FFLY_SUCCESS;
}

mdl::firefly::types::err_t mdl::stranded_client::de_init() {
	firefly::types::err_t err;
	if (_err(err = this->ffc.de_init())) {
		firefly::system::io::fprintf(ffly_err, "failed to de-init firefly.\n");
		return err;
	}
	return FFLY_SUCCESS;
}

int main() {
	mdl::stranded_client stranded;
	if (_err(stranded.init(WIDTH, HEIGHT))) {
		mdl::firefly::system::io::fprintf(ffly_err, "stranded: failed to init.\n");
		return FFLY_FAILURE;
	}

	if (_err(stranded.begin())) {
		mdl::firefly::system::io::fprintf(ffly_err, "stranded: failed to begin.\n");
		return FFLY_FAILURE;
	}

	if (_err(stranded.de_init())) {
		mdl::firefly::system::io::fprintf(ffly_err, "stranded: failed to de-init.\n");
		return FFLY_FAILURE;
	}
	return FFLY_SUCCESS;
}
