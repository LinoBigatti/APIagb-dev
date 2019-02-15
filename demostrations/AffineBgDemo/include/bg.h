
//{{BLOCK(bg)

//======================================================================
//
//	bg, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 2 tiles (t|f|p reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 512 + 128 + 1024 = 1664
//
//	Time-stamp: 2019-02-14, 21:47:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_H
#define GRIT_BG_H

#define bgTilesLen 128
extern const unsigned short bgTiles[64];

#define bgMapLen 1024
extern const unsigned short bgMap[512];

#define bgPalLen 512
extern const unsigned short bgPal[256];

#endif // GRIT_BG_H

//}}BLOCK(bg)
