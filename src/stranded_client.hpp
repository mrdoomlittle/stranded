# ifndef __stranded__client__hpp
# define __stranded__client__hpp
# include <firefly/ffly_engine.hpp>
# include <boost/cstdint.hpp>
# include <eint_t.hpp>
# include <firefly/system/event.hpp>
# include <firefly/types/colour_t.hpp>
# include <firefly/graphics/fill_pixmap.hpp>
# include <firefly/types/coords_t.hpp>
namespace mdl { class stranded_client
{
	public:
	stranded_client(uint_t __wd_xaxis_len, uint_t __wd_yaxis_len)
	: wd_xaxis_len(__wd_xaxis_len), wd_yaxis_len(__wd_yaxis_len), _ffly_client(__wd_xaxis_len, __wd_yaxis_len) {}

	boost::int8_t init();
	boost::int8_t begin();
	boost::int8_t de_init();

	static void engine_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal, void *__this);

	ffly_client _ffly_client;

	firefly::graphics::colour_t bg_colour = {
		.r = 40,
		.g = 43,
		.b = 48,
		.a = 255
	};

	uint_t const wd_xaxis_len, wd_yaxis_len;
} ;
}

# endif /*__stranded__client__hpp*/
