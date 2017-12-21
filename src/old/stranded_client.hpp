# ifndef __stranded__client__hpp
# define __stranded__client__hpp
# include <firefly/ffly_engine.hpp>
/*
# include <firefly/firefly.hpp>
# include <boost/cstdint.hpp>
# include <eint_t.hpp>
# include <firefly/system/event.hpp>
# include <firefly/types/colour_t.hpp>
# include <firefly/graphics/fill_pixmap.hpp>
# include <firefly/types/coords_t.hpp>
# ifdef __WITH_UNI_MANAGER
#	include <firefly/types/uni_prop_t.hpp>
# endif
# include <firefly/types/event_t.hpp>
# include <firefly/types/event_desc_t.hpp>
# include <firefly/gui/btn.hpp>
# include <firefly/types/id_t.hpp>
# include <firefly/room_manager.hpp>
# include <firefly/types/btn_event_t.hpp>
# include <firefly/data/uni_dlen.hpp>
# include <firefly/types/err_t.h>
*/
namespace mdl { class stranded_client
{
	public:
	firefly::types::err_t init();
	firefly::types::err_t begin();
	firefly::types::err_t de_init();
	void static engine_loop(i8_t ____info, ffly_client::portal_t *__portal, void *__arg);


	ffly_client ffc;





























/*
	stranded_client(u16_t __wd_xaxis_len, u16_t __wd_yaxis_len, firefly::types::uni_prop_t __uni_prop)
	: wd_xaxis_len(__wd_xaxis_len), wd_yaxis_len(__wd_yaxis_len), _ffly_client(__wd_xaxis_len, __wd_yaxis_len, __uni_prop) {}

	firefly::types::err_t init();
	firefly::types::err_t begin();
	firefly::types::err_t de_init();
	void static engine_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal, void *__this);

	ffly_client _ffly_client;

	firefly::graphics::colour_t bg_colour = {
		.r = 40,
		.g = 43,
		.b = 48,
		.a = 255
	};

	firefly::types::id_t sp_room_id;
	struct _sp_room {


	} sp_room;

	struct _bse_room {
	*/
		/*
			0-> singleplayer
			1-> multiplayer
			2-> options
			3-> uni editor
			4-> edit
		*/
	/*
		uint_t btn_indx[5];
	} bse_room;

	private:
	u16_t const wd_xaxis_len, wd_yaxis_len;
*/
} ;
}

# endif /*__stranded__client__hpp*/
