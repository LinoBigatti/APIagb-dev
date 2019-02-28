
//{{BLOCK(controls)

//======================================================================
//
//	controls, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 61 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 3904 + 2048 = 6464
//
//	Time-stamp: 2019-02-25, 16:11:18
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CONTROLS_H
#define GRIT_CONTROLS_H

#define controlsTilesLen 3904
extern const unsigned short controlsTiles[1952];

#define controlsMapLen 2048
extern const unsigned short controlsMap[1024];

#define controlsPalLen 512
extern const unsigned short controlsPal[256];

#endif // GRIT_CONTROLS_H

//}}BLOCK(controls)
