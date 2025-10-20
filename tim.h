#ifndef _TIM_H
#define _TIM_H

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <math.h>
#if defined(__APPLE__) || defined(linux)
#include <sys/types.h>
#endif

#define TIM_OUTPUT_CLUT4	0
#define TIM_OUTPUT_CLUT8	1
#define TIM_OUTPUT_RGB5		2
#define TIM_OUTPUT_RGB24	3

namespace tim {


	// TIM header struct
    typedef struct {

		// ID sub-struct
        struct HEADER_ID {
            u_int id:8;     // Always 0x10
            u_int ver:8;    // Always 0
            u_int pad:16;   // Useless padding
        } id;

		// Flags sub-struct
        struct HEADER_FLAGS {
            u_int pmode:3;  // Pixel mode (0: 4-bit, 1: 8-bit, 2:16-bit, 3:24-bit)
            u_int clut:1;
            u_int pad:24;
        } flags;

    } HEADER;


	// CLUT header struct
    typedef struct {
        u_int len;
        u_short cx,cy;
        u_short cw,ch;
    } CLUT_HEAD;


	// Image data block header
    typedef struct {
        u_int len;
        u_short x,y;
        u_short w,h;
    } IMG_HEAD;


    typedef struct {
        // 0: 4-bit CLUT, 1: 8-bit CLUT, 2:16-bit, 3:24-bit
        int format;
        // Image data params
        void *imgData;
        u_short imgWidth,imgHeight;
        u_short imgXoffs,imgYoffs;
        // CLUT data params
        void *clutData;
        u_short clutWidth,clutHeight;
        u_short clutXoffs,clutYoffs;
    } PARAM;


	// RGB5A1 pixel format struct
	typedef struct {
        u_short r:5;
        u_short g:5;
        u_short b:5;
        u_short i:1;
    } PIX_RGB5;

    typedef struct {
		u_char	r;
		u_char	g;
		u_char	b;
    } PIX_RGB24;


    /*! tim::ExportFile()
	 *
	 *  /param[in]  fileName - Name of TIM file.
	 *  /param[in]  *param   - tim::PARAM object of TIM export parameters.
	 *
	 *  /returns Zero if the TIM file was written successfully, otherwise an error occured.
	 *
	 */
    int ExportFile(const char* fileName, tim::PARAM *param);

	void FreeParam(tim::PARAM *param);

};


#endif // _TIM_H
