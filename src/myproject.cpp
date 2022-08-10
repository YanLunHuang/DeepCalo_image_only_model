//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>

//#include "myproject.h"
#include "parameters.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

#include "defines.h"



void myproject(
    hls::stream<input_t> &input_1,
    hls::stream<result_t> &layer2_out
) {


#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 576>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b2, "b2.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    //hls::stream<layer4_t> layer4_out("layer4_out");
    #pragma HLS STREAM variable=layer4_out depth=25
	/*
	input_t tmpt;
	result_t out_bigbuf;
	for(int i=0; i<72;i++){
		#pragma HLS UNROLL
		tmpt = input_1.read();
		if(tmpt == 1)out_bigbuf = 2;
		else if(tmpt == 5)out_bigbuf = 10; 
		else if(tmpt == 10)out_bigbuf = 20;
		layer2_out.write(out_bigbuf);
	}
	*/
    nnet::zeropad2d_cl_me<input_t, layer4_t, config4>(input_1, layer2_out); // zp2d_conv2d

    //nnet::conv_2d_cl_me<layer4_t, result_t, config2>(layer4_out, layer2_out, w2, b2); // conv2d

}
