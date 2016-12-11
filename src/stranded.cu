# include "stranded.ch"
# include <iostream>
/*
__device__ int unsigned pos = 0;
__global__ void __update_window(boost::uint8_t * device, ub::matrix<qg::uni_part_t>::iterator1 it1, boost::uint16_t wsize[2], qg::coord_t * cam_pos)
{
	int unsigned x = pos;
	//device[x] = (* it1).rgba_colour.r;
	//device[x] = (* __uni)(cam_pos[0].xpos, cam_pos[0].ypos).rgba_colour.r;
	//device[x+1] = (* __uni)(cam_pos[0], cam_pos[0]).rgba_colour.g;
	//device[x+2] = (* __uni)(cam_pos[0], cam_pos[0]).rgba_colour.b;
	//device[x+3] = (* __uni)(cam_pos[0], cam_pos[0]).rgba_colour.a;
	//pos += 4;
}

static bool has_trig = false;
static boost::uint8_t * device;
//static int unsigned * pos;
static uni_part_t * host;
static int unsigned ssi;
*/
//void update_window(ub::matrix<ub::matrix<qg::uni_part_t> * __uni, boost::uint8_t * __win, boost::uint16_t wsize[2], int unsigned * pcount, qg::coord_t * cam_pos)
//{
/*
	if (has_trig == false)
	{
		ssi = (wsize[0] * wsize[1]);
		cudaMalloc((void **)&device, (sizeof(boost::uint8_t) * (*pcount)));
		//daMalloc((void **)*host, (sizeof (uni_part_t) * (__uni.size1 () * __uni.size2 ())));
		//cudaMalloc((void **)&pos, sizeof(int unsigned));
		has_trig = true;

	}
	
	//cudaMemcpy( host, __uni.begin1(), s, cudaMemcpyHostToDevice);
	//__update_window<<<1, ssi>>>(device, it1, wsize, cam_pos);
	//cudaMemcpy(__win, device, (* pcount), cudaMemcpyDeviceToHost );
*/
//}
__device__ static int unsigned pos = 0;
__global__ void __update_rwindow (qg::uni_part_t * __device_uni, boost::uint8_t * __device_win, boost::uint16_t * __w_size, boost::uint16_t * __u_size, qg::coord_t cam_pos)
{
	//int unsigned p = threadIdx.x + (blockIdx.x * __w_size[0];
	int unsigned pixel_location = threadIdx.x + (blockIdx.x * __w_size[0]);
	int unsigned unip_pos = threadIdx.x + (blockIdx.x * __u_size[0]);
	pixel_location = pixel_location * 4;
	__device_win[pixel_location] = __device_uni[unip_pos].rgba_colour.r;
	__device_win[pixel_location + 1] = __device_uni[unip_pos].rgba_colour.g;
	__device_win[pixel_location + 2] = __device_uni[unip_pos].rgba_colour.b;
	__device_win[pixel_location + 3] = __device_uni[unip_pos].rgba_colour.a;
/*
	if (pos > (((__w_size[0] * __w_size[1]) * 4) - 1))
		pos = 0;
	else
		pos += 4;
*/
}
//__device__ int unsigned oo = 0;
//__device__ static int unsigned dep = 0;

//__device__ int unsigned drop_down;
__global__ void __update_player (qg::uni_part_t * __device_uni, boost::uint16_t * __u_size, qg::player_info * main_player)
{
//	int unsigned *& drop_down = __drop_down;
	//int unsigned & __opl = *opl;
//	if (threadIdx.x == 0)
//	{
//		oo = 0;
//	}
        //int unsigned unip_pos = (threadIdx.x + main_player-> coords.xpos) + ((blockIdx.x + main_player-> coords.ypos) * __u_size[0]) + (oo * __u_size[0]);
	//unip_pos -= oo;
	//if (threadIdx.x == 0 && blockIdx.x == 0) __opl = 0;

	//if (threadIdx.x == 0) drop_down = 0;
		
	//drop_down = threadIdx.x;
	int unsigned uni_pos = (threadIdx.x + main_player-> coords.xpos) + ((blockIdx.x + main_player-> coords.ypos) * __u_size[0]);
	uni_pos += ((threadIdx.x * main_player->rotation) * __u_size[0]);
	uni_pos -= (blockIdx.x * main_player->rotation);
	
	__device_uni[uni_pos].rgba_colour.r = 255;
	__device_uni[uni_pos].rgba_colour.g = 255;
	__device_uni[uni_pos].rgba_colour.b = 255;
	__device_uni[uni_pos].rgba_colour.a = 255;

//	if (drop_down > 10)
//		drop_down = 0;
//rop_down ++;

//	if (threadIdx.x >= (main_player-> xlen)-3)
//		oo = 0;
//	else
//		oo ++;

}

__global__ void __clean_uni(qg::uni_part_t * __device_uni, boost::uint16_t * __u_size)
{
	int unsigned unip_pos = threadIdx.x + (blockIdx.x * __u_size[0]);
	__device_uni[unip_pos].rgba_colour.r = 0;
        __device_uni[unip_pos].rgba_colour.g = 0;
        __device_uni[unip_pos].rgba_colour.b = 0;
        __device_uni[unip_pos].rgba_colour.a = 0;
}

static boost::uint8_t __has_uw_been_init = false;
static boost::uint8_t * device_win;
static qg::uni_part_t * device_uni;
static int unsigned uni_bcount = 0;
static int unsigned ssi;
static qg::player_info * m_pinfo;
static boost::uint16_t * w_sz, * u_sz;
void update_window(qg::uni_part_t ** __universe, boost::uint8_t * __rwindow, boost::uint16_t __w_size[2], int unsigned * __p_count, qg::coord_t cam_pos, boost::uint16_t __u_size[2],
qg::player_info * main_player)
{
	if (__has_uw_been_init == false) {
		ssi = (__w_size[0] * __w_size[1]);
		cudaMalloc((void **)&device_win, (sizeof(boost::uint8_t) * (*__p_count)));	
		cudaMalloc((void **)&device_uni, (sizeof(qg::uni_part_t) * (__u_size[0] * __u_size[1])));
		__has_uw_been_init = true;
		cudaMalloc((void **)&w_sz, sizeof(boost::uint16_t) * 2);
		cudaMalloc((void **)&u_sz, sizeof(boost::uint16_t) * 2);
		cudaMalloc((void **)& m_pinfo, sizeof(qg::player_info));	
		//ws[0] = __w_size[0]; ws[1] = __w_size[1];
		//us[0] = __u_size[0]; us[1] = __u_size[1];
		uni_bcount = (sizeof(qg::uni_part_t) * (__u_size[0] * __u_size[1])); 
		cudaMemcpy(w_sz, __w_size, (sizeof(boost::uint16_t) * 2), cudaMemcpyHostToDevice);
	        cudaMemcpy(u_sz, __u_size, (sizeof(boost::uint16_t) * 2), cudaMemcpyHostToDevice);
	}
//	 std::memset((* __universe), 0, uni_bcount);
	
	cudaMemcpy(m_pinfo, main_player, sizeof(qg::player_info), cudaMemcpyHostToDevice);
	cudaMemcpy(device_uni, (* __universe), uni_bcount, cudaMemcpyHostToDevice);
	__clean_uni<<<__u_size[1], __u_size[0]>>>(device_uni, u_sz);
	__update_player<<<main_player->ylen, main_player->xlen>>>(device_uni, u_sz, m_pinfo);
	__update_rwindow<<<__w_size[1], __w_size[0]>>>(device_uni, device_win, w_sz, u_sz, cam_pos);	

//	__update_player<<<main_player->ylen, main_player->xlen>>>(device_uni, u_sz, m_pinfo);
	cudaMemcpy((* __universe), device_uni, uni_bcount, cudaMemcpyDeviceToHost);
	cudaMemcpy(__rwindow, device_win, (sizeof(boost::uint8_t) * (* __p_count)), cudaMemcpyDeviceToHost);
}


void render_window()
{

}
