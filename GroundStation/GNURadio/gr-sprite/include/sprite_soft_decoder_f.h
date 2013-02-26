/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_SPRITE_SOFT_DECODER_F_H
#define INCLUDED_SPRITE_SOFT_DECODER_F_H

#include <sprite_api.h>
#include <gr_sync_block.h>

#include <vector>

class sprite_soft_decoder_f;

typedef boost::shared_ptr<sprite_soft_decoder_f> sprite_soft_decoder_f_sptr;

SPRITE_API sprite_soft_decoder_f_sptr sprite_make_soft_decoder_f();

/*!
 * \brief <+description+>
 * \ingroup block
 *
 */
class SPRITE_API sprite_soft_decoder_f : public gr_sync_block
{
 private:
	friend SPRITE_API sprite_soft_decoder_f_sptr sprite_make_soft_decoder_f();
  	sprite_soft_decoder_f();
  	
    char softdecode(const float *buffer);
    
    int m_counter;
    int m_initialized;
    float m_squares[18];
    float  m_energies[125];
    std::vector<float> m_median_buffer;

  	static float C[256][16];

 public:
  	~sprite_soft_decoder_f();

	// Where all the action really happens
	int work (int noutput_items,
	    gr_vector_const_void_star &input_items,
	    gr_vector_void_star &output_items);
};

float sprite_soft_decoder_f::C[256][16] = {
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, 1},
  {-1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1},
  {1, -1, 1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1},
  {1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1},
  {-1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1, 1, -1, 1},
  {1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1},
  {-1, 1, -1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, 1, 1},
  {-1, -1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, -1, -1, -1},
  {1, 1, 1, -1, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1},
  {-1, 1, -1, -1, 1, -1, 1, 1, -1, -1, -1, -1, 1, -1, 1, -1},
  {1, -1, -1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, -1, 1, 1},
  {1, 1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1, -1},
  {-1, -1, -1, 1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1},
  {1, -1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, -1},
  {-1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, 1, 1},
  {-1, 1, 1, -1, -1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1},
  {1, -1, 1, 1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1},
  {-1, -1, -1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, 1, -1},
  {1, 1, -1, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, 1},
  {1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 1, -1, -1},
  {-1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, 1, -1, 1},
  {1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1},
  {-1, -1, 1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1},
  {-1, 1, -1, 1, -1, 1, -1, -1, -1, -1, -1, 1, 1, -1, -1, -1},
  {1, -1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1, -1, -1, 1},
  {-1, -1, 1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, -1},
  {1, 1, 1, 1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1, 1, 1},
  {1, -1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, 1, -1, -1},
  {-1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, -1, 1},
  {1, 1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1},
  {-1, -1, -1, -1, 1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1},
  {1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, -1, -1, -1, -1},
  {-1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1},
  {1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1, -1},
  {-1, 1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1},
  {-1, -1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, -1, -1},
  {1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1},
  {-1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1, -1},
  {1, -1, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1},
  {-1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1},
  {1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1},
  {-1, 1, -1, 1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, 1},
  {-1, -1, -1, -1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, -1},
  {1, 1, -1, 1, 1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1},
  {-1, 1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, -1},
  {1, -1, 1, -1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, 1, 1},
  {1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1},
  {-1, 1, 1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1},
  {1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1, 1, -1, -1, 1, -1},
  {-1, -1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1},
  {-1, 1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1},
  {1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1},
  {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1},
  {1, 1, 1, 1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1},
  {1, -1, -1, 1, 1, -1, -1, 1, -1, -1, 1, 1, 1, -1, -1, -1},
  {-1, 1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1},
  {1, 1, 1, -1, -1, -1, -1, 1, -1, -1, 1, 1, 1, -1, 1, -1},
  {-1, -1, 1, 1, -1, 1, 1, -1, -1, -1, 1, 1, 1, -1, 1, 1},
  {-1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1},
  {1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1},
  {-1, -1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, 1, -1},
  {1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1},
  {-1, 1, -1, -1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, -1, -1},
  {1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1, 1},
  {-1, -1, 1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1},
  {1, 1, 1, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1},
  {1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1},
  {-1, 1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, 1},
  {1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1, -1},
  {-1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1, 1, 1},
  {-1, 1, 1, 1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1},
  {1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1},
  {-1, -1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, -1},
  {1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, 1},
  {1, -1, -1, -1, 1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1},
  {-1, 1, -1, 1, 1, -1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1},
  {1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, 1, -1},
  {-1, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, 1, 1, 1},
  {-1, -1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, -1},
  {1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, -1, -1, 1},
  {-1, 1, -1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1},
  {1, -1, -1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, -1, 1, 1},
  {1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, -1},
  {-1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, 1},
  {1, -1, 1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1},
  {-1, 1, 1, 1, -1, 1, -1, -1, -1, 1, -1, 1, -1, 1, 1, 1},
  {-1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, -1},
  {1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1},
  {-1, 1, 1, -1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1},
  {1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1},
  {1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, -1, -1},
  {-1, -1, 1, 1, 1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, 1},
  {1, -1, -1, 1, -1, -1, -1, -1, -1, 1, -1, 1, 1, 1, 1, -1},
  {-1, 1, -1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1},
  {1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, -1, -1, -1, -1},
  {-1, 1, -1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, 1},
  {1, 1, 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, -1, -1, 1, -1},
  {-1, -1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1},
  {-1, 1, 1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1},
  {1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1},
  {-1, -1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1},
  {1, 1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1},
  {1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1, -1},
  {-1, 1, 1, -1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, 1},
  {1, 1, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1},
  {-1, -1, -1, 1, 1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1},
  {-1, 1, -1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1, 1, -1, -1},
  {1, -1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1},
  {-1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1},
  {1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, 1, 1},
  {1, 1, 1, -1, -1, 1, -1, -1, -1, 1, 1, 1, -1, -1, -1, -1},
  {-1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1},
  {1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1, -1},
  {-1, 1, -1, -1, 1, -1, 1, 1, -1, 1, 1, 1, -1, -1, 1, 1},
  {-1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, -1},
  {1, 1, -1, -1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, -1, 1},
  {-1, 1, 1, -1, 1, 1, 1, -1, -1, 1, 1, 1, -1, 1, 1, -1},
  {1, -1, 1, 1, 1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1},
  {1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1},
  {1, -1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1, -1},
  {-1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, 1},
  {-1, -1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, -1, -1},
  {1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1, 1, 1, 1, -1, 1},
  {-1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1},
  {1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1},
  {1, -1, -1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, -1},
  {-1, 1, -1, -1, 1, -1, -1, 1, 1, -1, -1, -1, -1, -1, -1, 1},
  {1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, -1},
  {-1, -1, 1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1},
  {-1, 1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1},
  {1, -1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, 1, -1, 1},
  {-1, -1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1},
  {1, 1, -1, -1, -1, -1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1},
  {1, -1, 1, -1, 1, 1, -1, 1, 1, -1, -1, -1, 1, -1, -1, -1},
  {-1, 1, 1, 1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, 1},
  {1, 1, -1, 1, -1, 1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1},
  {-1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 1, 1},
  {-1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, 1, -1, -1},
  {1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1, -1, 1},
  {-1, -1, 1, -1, -1, 1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1},
  {1, 1, 1, 1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1},
  {-1, -1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1},
  {1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, -1, -1, 1, -1},
  {-1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, -1, 1, 1},
  {-1, -1, -1, -1, 1, -1, 1, 1, 1, -1, -1, 1, -1, 1, -1, -1},
  {1, 1, -1, 1, 1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1},
  {-1, 1, 1, 1, -1, -1, 1, 1, 1, -1, -1, 1, -1, 1, 1, -1},
  {1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, 1, 1},
  {1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1},
  {-1, -1, -1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1},
  {1, -1, 1, 1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1},
  {-1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1},
  {-1, -1, 1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1, 1, -1, -1},
  {1, 1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1, -1, 1},
  {-1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, 1, 1, 1, -1},
  {1, -1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, 1},
  {-1, 1, -1, 1, -1, -1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1},
  {1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1},
  {-1, -1, 1, -1, 1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, -1},
  {1, 1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, -1, -1, 1, 1},
  {1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, -1},
  {-1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1},
  {1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1},
  {-1, -1, -1, -1, 1, 1, 1, -1, 1, -1, 1, -1, -1, 1, 1, 1},
  {-1, 1, 1, -1, -1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1},
  {1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, -1, 1, -1, -1, 1},
  {-1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
  {1, 1, -1, -1, 1, 1, 1, 1, 1, -1, 1, -1, 1, -1, 1, 1},
  {1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, -1},
  {-1, 1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1},
  {1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, 1, -1},
  {-1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1},
  {-1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, -1, -1},
  {1, 1, 1, -1, -1, -1, 1, 1, 1, -1, 1, 1, -1, -1, -1, 1},
  {-1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1},
  {1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1},
  {1, 1, -1, -1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1},
  {-1, -1, -1, 1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1},
  {1, -1, 1, 1, 1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1},
  {-1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1},
  {-1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1},
  {1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, -1, -1, 1},
  {-1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1},
  {1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1},
  {1, 1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1},
  {-1, -1, 1, -1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, 1},
  {1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1},
  {-1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1},
  {1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, 1},
  {1, -1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, 1, -1},
  {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1},
  {-1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, -1, 1, -1, -1},
  {1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1},
  {-1, 1, -1, 1, 1, -1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1},
  {1, -1, -1, -1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1},
  {1, 1, 1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, -1},
  {-1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, 1},
  {1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1},
  {-1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1},
  {-1, -1, -1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1},
  {1, 1, -1, -1, -1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1},
  {-1, 1, 1, -1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, 1, -1},
  {1, -1, 1, 1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, 1, 1},
  {1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1},
  {-1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1},
  {1, 1, -1, -1, 1, 1, 1, 1, 1, 1, -1, 1, -1, -1, 1, -1},
  {-1, -1, -1, 1, 1, -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1},
  {-1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, -1, 1, -1, -1},
  {1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1},
  {-1, -1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1},
  {1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, 1, 1, 1},
  {1, -1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1, 1, -1, -1, -1},
  {-1, 1, -1, 1, -1, -1, 1, 1, 1, 1, -1, 1, 1, -1, -1, 1},
  {1, 1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1},
  {-1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, 1},
  {-1, 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, -1, -1},
  {1, -1, 1, -1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1},
  {-1, -1, -1, -1, 1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1},
  {1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1},
  {-1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1},
  {1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1, 1},
  {-1, 1, 1, -1, -1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1},
  {1, -1, 1, 1, -1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, 1},
  {1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1},
  {-1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1, -1, 1},
  {1, -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, -1},
  {-1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, -1, -1, 1, 1, 1},
  {-1, -1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, -1},
  {1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, -1, 1, -1, -1, 1},
  {-1, 1, -1, 1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, -1},
  {1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, -1, 1, 1},
  {1, 1, -1, 1, 1, 1, -1, -1, 1, 1, 1, -1, 1, 1, -1, -1},
  {-1, -1, -1, -1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1, -1, 1},
  {1, -1, 1, -1, -1, 1, -1, -1, 1, 1, 1, -1, 1, 1, 1, -1},
  {-1, 1, 1, 1, -1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1},
  {-1, 1, 1, 1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, -1, -1},
  {1, -1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1, -1, -1, 1},
  {-1, -1, -1, -1, -1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1},
  {1, 1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 1, 1},
  {1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, -1, 1, -1, -1},
  {-1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, -1, 1},
  {1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, 1, -1},
  {-1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1},
  {-1, 1, -1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1},
  {1, -1, -1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 1},
  {-1, -1, 1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, 1, -1},
  {1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1},
  {1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1},
  {-1, 1, 1, -1, 1, 1, -1, -1, 1, 1, 1, 1, 1, 1, -1, 1},
  {1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1},
  {-1, -1, -1, 1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1}};

#endif /* INCLUDED_SPRITE_SOFT_DECODER_F_H */
