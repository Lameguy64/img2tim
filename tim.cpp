#include "tim.h"


int tim::ExportFile(const char* fileName, tim::PARAM *param) {

	FILE *fp;

	if (!(fp = fopen(fileName, "wb"))) {
		return(-1);
	}


	tim::HEADER     fileHead={{0}};
	tim::CLUT_HEAD  clutHead={0};
	tim::IMG_HEAD   imgHead={0};


	// Prepare header
	fileHead.id.id  = 0x10;
	fileHead.id.ver = 0;
	fileHead.flags.pmode = param->format;


	// Prepare CLUT data block if image is 8-bit or less and that the pointer to the CLUT data is not NULL
	if ((param->format <= 1) && (param->clutData != NULL)) {
		fileHead.flags.clut = 1;
		clutHead.cw = param->clutWidth;
		clutHead.ch = param->clutHeight;
		clutHead.cx = param->clutXoffs;
		clutHead.cy = param->clutYoffs;
		clutHead.len = ((2*param->clutWidth)*param->clutHeight);
		clutHead.len += sizeof(clutHead);
	}


	// Prepare image data block
	imgHead.w = param->imgWidth;
	imgHead.h = param->imgHeight;
	imgHead.x = param->imgXoffs;
	imgHead.y = param->imgYoffs;

	// Calculate final size of image based on its color depth
	switch(param->format) {
	case 0:	// 4-bit with 16-color CLUT
		imgHead.len = param->imgWidth/2;
		imgHead.w /= 4;
		break;
	case 1:	// 8-bit with 256-color CLUT
		imgHead.len = param->imgWidth;
		imgHead.w /= 2;
		break;
	case 2:	// 16-bit RGB5I1
		imgHead.len = param->imgWidth*2;
		break;
	case 3:	// 24-bit RGB8
		imgHead.len = (param->imgWidth*3);
		imgHead.w = ceil(imgHead.w*1.5f);
		break;
	}

	// Calculate size of image data block
	imgHead.len *= param->imgHeight;
	imgHead.len += sizeof(imgHead);


	// Write the header
	fwrite(&fileHead, 1, sizeof(fileHead), fp);

	// Write the CLUT data block
	if ((param->format <= 1) && (param->clutData != NULL)) {
		fwrite(&clutHead, 1, sizeof(clutHead), fp);
		fwrite(param->clutData, 1, clutHead.len-sizeof(clutHead), fp);
	}

	// Write the image data block
	fwrite(&imgHead, 1, sizeof(imgHead), fp);
	fwrite(param->imgData, 1, imgHead.len-sizeof(imgHead), fp);

	// Close and return
	fclose(fp);
	return(0);

}


void tim::FreeParam(tim::PARAM *param) {

    if (param->imgData != NULL) {
		free(param->imgData);
		param->imgData = NULL;
    }

	if (param->clutData != NULL) {
		free(param->clutData);
		param->clutData = NULL;
	}

}
