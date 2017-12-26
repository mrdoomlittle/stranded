# ifndef __stranded__client__hpp
# define __stranded__client__hpp
# include <firefly/ffly_engine.hpp>
# include <firefly/types/pixelmap_t.h>
# include <firefly/graphics/image.h>
# include <mdlint.h>
# define WIDTH 400
# define HEIGHT 400
# define TITLE "Stranded - r0.001"
using namespace mdl::firefly;
namespace mdl { class stranded_client
{
	public:
	graphics::imagep bg;

	types::err_t init(u16_t __wd_width, u16_t __wd_height);
	types::err_t begin();
	types::err_t de_init();
	types::err_t static engine_loop(i8_t __report, ffly_client::portal_t *__portal, void *__arg_p);
	ffly_client ffc;
};
}
# endif /*__stranded__client__hpp*/
