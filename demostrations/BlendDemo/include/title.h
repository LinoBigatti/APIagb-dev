
//{{BLOCK(title)

//======================================================================
//
//	title, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 199 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 12736 + 2048 = 15296
//
//	Time-stamp: 2019-02-21, 22:23:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLE_H
#define GRIT_TITLE_H

#define titleTilesLen 12736
extern const unsigned short titleTiles[6368];

#define titleMapLen 2048
extern const unsigned short titleMap[1024];

#define titlePalLen 512
extern const unsigned short titlePal[256];

#endif // GRIT_TITLE_H

//}}BLOCK(title)
