/*****************************************************************************
 * lpcm.h : lpcm decoder module
 *****************************************************************************
 * Copyright (C) 1999, 2000 VideoLAN
 * $Id: lpcm.h,v 1.2 2002/09/18 01:28:05 henri Exp $
 *
 * Authors: Samuel Hocevar <sam@zoy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *****************************************************************************/
#define LPCMDEC_FRAME_SIZE (2008)

/*****************************************************************************
 * lpcmdec_thread_t : lpcm decoder thread descriptor
 *****************************************************************************/
typedef struct lpcmdec_thread_s
{
    /*
     * Thread properties
     */
    vlc_thread_t        thread_id;                /* id for thread functions */

    /*
     * Input properties
     */
    decoder_fifo_t *    p_fifo;                /* stores the PES stream data */
    int                 sync_ptr;         /* sync ptr from lpcm magic header */

    /*
     * Output properties
     */
    aout_instance_t        *p_aout;
    aout_input_t           *p_aout_input;
    audio_sample_format_t   output_format;
    audio_date_t        end_date;
    
    /* The bit stream structure handles the PES stream at the bit level */
    bit_stream_t bit_stream;

} lpcmdec_thread_t;

/*****************************************************************************
 * Prototypes
 *****************************************************************************/
vlc_thread_t            lpcmdec_CreateThread( decoder_fifo_t * p_fifo );
