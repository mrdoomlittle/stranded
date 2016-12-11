# ifndef __qg__stranded__hpp__
# define __qg__stranded__hpp__
// include the cuda header file
# include "stranded.ch"
# include <boost/cstdlib.hpp>
# include <boost/cstdint.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <chrono>
# include <iostream>
//#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
# include "types.hpp"
namespace ub = boost::numeric::ublas;
namespace qg { class stranded
{
    public:
/*
    typedef struct {
        boost::uint8_t r, g, b, a;
    } rgba_colour_t;

    typedef struct {
        // the xlength and ylength of the player
        boost::uint16_t cam_xlen = 0, cam_ylen = 0;
        // the xlength and ylength of the player
        boost::uint16_t player_xlen = 0, player_ylen = 0;
        // starting point of player e.g. where the player will be placed
        boost::uint16_t plstart_xpos = 0, plstart_ypos = 0;
        rgba_colour_t background_colour = {0, 0, 0, 0};
        boost::uint16_t window_xlen = 0, window_ylen = 0;
    } init_details_t ;

    typedef struct {

        rgba_colour_t rgba_colour = {0, 0, 0, 0};
    } uni_part_t;
*/
    stranded(boost::uint16_t __uni_xlen, boost::uint16_t __uni_ylen)
    : uni_xlen(__uni_xlen), uni_ylen(__uni_ylen) { }
    
    boost::uint8_t initialize(qg::init_details_t __init_details);

    enum lstate : boost::uint8_t {
        __is_running,
        __not_running 
    }; 

    private:
    player_info main_player;

    bool is_gloop_state(boost::uint8_t __is_type)
    {
        return (gloop_state == __is_type? true : false);
    }

    void set_gloop_state(boost::uint8_t val)
    {
        gloop_state = val;
    }

    boost::uint8_t gloop_state = lstate::__not_running;

    boost::uint16_t const uni_xlen, uni_ylen;
   
    boost::uint8_t * rwindow; 
    ub::matrix<uni_part_t> * universe;
    uni_part_t * * uni_part_ptrs;   
 
} ; }

# endif /*__qg__stranded__hpp__*/
