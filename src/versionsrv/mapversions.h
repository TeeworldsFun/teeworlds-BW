/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef VERSIONSRV_MAPVERSIONS_H
#define VERSIONSRV_MAPVERSIONS_H

static CMapVersion s_aMapVersionList[] = {
	{"ctf1", {0x06, 0xb5, 0xf1, 0x17}, {0x00, 0x00, 0x12, 0x38}},
	{"ctf2", {0x27, 0xbc, 0x5e, 0xac}, {0x00, 0x00, 0x64, 0x1a}},
	{"ctf3", {0xa3, 0x73, 0x9d, 0x41}, {0x00, 0x00, 0x17, 0x0f}},
	{"ctf4", {0xbe, 0x7c, 0x4d, 0xb9}, {0x00, 0x00, 0x2e, 0xfe}},
	{"ctf5", {0xd9, 0x21, 0x29, 0xa0}, {0x00, 0x00, 0x2f, 0x4c}},
	{"ctf6", {0x28, 0xc8, 0x43, 0x51}, {0x00, 0x00, 0x69, 0x2f}},
	{"ctf7", {0x1d, 0x35, 0x98, 0x72}, {0x00, 0x00, 0x15, 0x87}},
	{"dm1", {0xf2, 0x15, 0x9e, 0x6e}, {0x00, 0x00, 0x16, 0xad}},
	{"dm2", {0x71, 0x83, 0x98, 0x78}, {0x00, 0x00, 0x21, 0xdf}},
	{"dm6", {0x47, 0x4d, 0xa2, 0x35}, {0x00, 0x00, 0x1e, 0x95}},
	{"dm7", {0x42, 0x6d, 0xa1, 0x67}, {0x00, 0x00, 0x27, 0x2a}},
	{"dm8", {0x85, 0xf1, 0x1e, 0xd6}, {0x00, 0x00, 0x9e, 0xbd}},
	{"dm9", {0x42, 0xd4, 0x77, 0x7e}, {0x00, 0x00, 0x20, 0x11}},
};
static const int s_NumMapVersionItems = sizeof(s_aMapVersionList)/sizeof(CMapVersion);
#endif
