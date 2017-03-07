# include "stranded.hpp"
# include <array>
#include <cstring>

boost::uint8_t qg::stranded::initialize(init_details_t __init_details)
{
    static ub::matrix<uni_part_t> __universe(this-> uni_xlen, this-> uni_ylen);

    // this just allows me to access in side the class
    this-> universe = & __universe;
    this-> main_player.xlen = __init_details.player_xlen;
    this-> main_player.ylen = __init_details.player_ylen;
    this-> main_player.coords.xpos = __init_details.plstart_xpos;
    this-> main_player.coords.ypos = __init_details.plstart_ypos;
    int unsigned uni_bcount = (sizeof(uni_part_t) * (this-> uni_xlen *this-> uni_ylen));
    int unsigned rwindow_pixcount = (__init_details.window_xlen *__init_details.window_ylen);
    int unsigned pixcount = (rwindow_pixcount * 4);
    this-> rwindow = static_cast<boost::uint8_t *>(malloc((sizeof(boost::uint8_t) * (rwindow_pixcount * 4)))); 

    std::memset((this-> rwindow), 222, (sizeof(boost::uint8_t) * (rwindow_pixcount * 4)));

    this-> set_gloop_state(lstate::__is_running);
    //std::cout << sizeof(ub::matrix<boost::uint8_t>(80,80)) << std::endl;  
    int unsigned xx = 0;    
    this-> uni_part_ptrs = new uni_part_t * [(this-> uni_xlen *this-> uni_ylen)];
    for(ub::matrix<uni_part_t>::iterator1 it1 = __universe.begin1(); it1 != __universe.end1(); ++it1) {
        for(ub::matrix<uni_part_t>::iterator2 it2 = it1.begin(); it2 !=it1.end(); ++it2) {
            this-> uni_part_ptrs[xx] = &(* it1);
            (* it1).rgba_colour = {0};
            //std::cout << "(" << it2.index1() << "," << it2.index2() << ") = "<< unsigned((* it1).rgba_colour.r) << std::endl;
            xx++;
        }
    }
//    std::cout << (* uni_part_ptrs)[0].rgba_colour.r << std::endl;

    //ub::matrix<uni_part_t>::iterator1 it1 = universe->begin1();
    //std::cout << (*(it1)).rgba_colour.r << std::endl;
    //std::cout << it1[0][0].rgba_colour.r << std::endl;
     //d::cout << &(universe-> begin1()) << std::endl;
//return 0; 
    sf::RenderWindow rwindow_instance(sf::VideoMode(__init_details.window_xlen, __init_details.window_ylen), "Stranded - Version 0.0.0");
    
    sf::Texture rwindow_texture;
    rwindow_texture.create(__init_details.window_xlen, __init_details.window_ylen);
    sf::Sprite rwindow_sprite(rwindow_texture); 
    boost::uint16_t __w_size[2] = {__init_details.window_xlen, __init_details.window_ylen};

    coord_t cam_pos = {0, 0};
    boost::uint16_t __u_size[2] = {this-> uni_xlen, this-> uni_ylen}; 
    int unsigned gloop_tick_count = 0;
    auto last_time_since_tick = std::chrono::high_resolution_clock::now();
    do
    {
        auto starting_time = std::chrono::high_resolution_clock::now();
        if (! rwindow_instance.isOpen())
            this-> set_gloop_state(lstate::__not_running);

        sf::Event rwindow_event;
        while(rwindow_instance.pollEvent(rwindow_event))
            if(rwindow_event.type == sf::Event::Closed)
                rwindow_instance.close();

        rwindow_texture.update((this-> rwindow));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this-> main_player.coords.ypos -= 1;            

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this-> main_player.coords.ypos += 1;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this-> main_player.coords.xpos -= 1;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this-> main_player.coords.xpos += 1;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            if (this-> main_player.rotation < 6)
                this-> main_player.rotation += 1;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
            if (this-> main_player.rotation != 0) this-> main_player.rotation -= 1;
          
        update_window((this-> uni_part_ptrs), rwindow, __w_size, &pixcount, cam_pos, __u_size, &main_player);
        //render_universe();
        //render_window();

        rwindow_instance.clear();
        rwindow_instance.draw(rwindow_sprite);

        rwindow_instance.display();

        //auto ending_time = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> interval_time = (ending_time - starting_time);
        std::chrono::duration<double> tick_time_count = (starting_time - last_time_since_tick);
        //std::cout << "Interval Time: " << interval_time.count() << std::endl;
        //std::cout << tick_time_count.count() << std::endl;
        if (tick_time_count.count() > 1.0)
        {
            std::cout << "FPS: " << gloop_tick_count << std::endl;
            last_time_since_tick = std::chrono::high_resolution_clock::now();
            gloop_tick_count = 0;
        }
        else gloop_tick_count ++;
    } while (this-> is_gloop_state(lstate::__is_running));


    return 0;
}

int main()
{
    qg::init_details_t init_details;

    init_details.cam_xlen = 50;
    init_details.cam_ylen = 50;
    init_details.player_xlen = 40;
    init_details.player_ylen = 40;
    init_details.plstart_xpos = 80;
    init_details.plstart_ypos = 80;
    init_details.background_colour = {0, 0, 0, 0};
    init_details.window_xlen = 600;
    init_details.window_ylen = 600;

    qg::stranded stranded(600, 600);
    stranded.initialize(init_details);
}
