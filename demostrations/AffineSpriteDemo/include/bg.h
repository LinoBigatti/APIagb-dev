
//{{BLOCK(bg)

//======================================================================
//
//	bg, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 64 + 2048 = 2144
//
//	Time-stamp: 2019-02-13, 19:00:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_H
#define GRIT_BG_H

#define bgTilesLen 64
extern const unsigned short bgTiles[32];

#define bgMapLen 2048
extern const unsigned short bgMap[1024];

#define bgPalLen 32
extern const unsigned short bgPal[16];

#endif // GRIT_BG_H

//}}BLOCK(bg)
