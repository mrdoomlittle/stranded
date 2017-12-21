# ifndef __stranded__client__hpp
# define __stranded__client__hpp
# include <firefly/ffly_engine.hpp>
# include <firefly/types/pixelmap_t.h>
# include <mdlint.h>
# define WIDTH 400
# define HEIGHT 400
# define TITLE "Stranded - r0.001"
namespace mdl { class stranded_client
{
	public:
	firefly::graphics::imagep bg;

	firefly::types::err_t init(u16_t __wd_width, u16_t __wd_height);
	firefly::types::err_t begin();
	firefly::types::err_t de_init();
	firefly::types::err_t static engine_loop(i8_t __report, ffly_client::portal_t *__portal, void *__arg_p);
	ffly_client ffc;
};
}
# endif /*__stranded__client__hpp*/
