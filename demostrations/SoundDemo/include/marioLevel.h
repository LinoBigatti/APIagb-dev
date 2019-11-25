
//{{BLOCK(marioLevel)

//======================================================================
//
//	marioLevel, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 67 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 2144 + 4096 = 6752
//
//	Time-stamp: 2019-02-10, 15:00:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MARIOLEVEL_H
#define GRIT_MARIOLEVEL_H

#define marioLevelTilesLen 2144
extern const unsigned short marioLevelTiles[1072];

#define marioLevelMapLen 4096
extern const unsigned short marioLevelMap[2048];

#define marioLevelPalLen 512
extern const unsigned short marioLevelPal[256];

#endif // GRIT_MARIOLEVEL_H

//}}BLOCK(marioLevel)
