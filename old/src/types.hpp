# ifndef __qg__types__hpp__
# define __qg__types__hpp__
namespace qg {
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

typedef struct {
    boost::uint16_t xpos, ypos;
} coord_t;

typedef struct {
    boost::uint8_t rotation = 0;
    coord_t coords = {0, 0};
    boost::uint16_t xlen = 0, ylen = 0;
} player_info;
}
# endif /*__qg__types__hpp__*/
