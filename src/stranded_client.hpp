# ifndef __stranded__client__hpp
# define __stranded__client__hpp
# include <firefly/ffly_client.hpp>
# include <firefly/graphics/png_loader.hpp>
# include <boost/cstdint.hpp>
# include <eint_t.hpp>
namespace mdl { class stranded_client
{
	public:
	stranded_client(uint_t __win_xlen, uint_t __win_ylen)
	: win_xlen(__win_xlen), win_ylen(__win_ylen) {}

	boost::int8_t init();
	boost::int8_t begin();

	void static ffc_loop(boost::int8_t __info, mdl::ffly_client::portal_t *__portal);

	ffly_client *ffc = nullptr;

	uint_t const win_xlen, win_ylen;
} ;
}

# endif /*__stranded__client__hpp*/
