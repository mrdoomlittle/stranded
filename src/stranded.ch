# ifndef __qg__stranded__ch__
# define __qg__stranded__ch__
#include <boost/numeric/ublas/matrix.hpp>
# include <boost/cstdint.hpp>
# include "types.hpp"
#include <cstring>
namespace ub = boost::numeric::ublas;
void update_window(qg::uni_part_t ** __universe, boost::uint8_t * __rwindow, boost::uint16_t __w_size[2], int unsigned * __p_count, qg::coord_t cam_pos, boost::uint16_t __u_size[2], 
qg::player_info * main_player);
//void render_universe();
//void render_window();
//void update_window(ub::matrix<ub::matrix<qg::uni_part_t> * __uni, boost::uint8_t * __win, boost::uint16_t wsize[2], int unsigned * pcount, qg::coord_t * cam_pos);
# endif /*__qg__stranded__ch__*/
