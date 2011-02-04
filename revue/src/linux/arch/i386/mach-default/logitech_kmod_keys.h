#include <linux/rsa_verify.h>

/* PB2/PB3 */
static const char ka3_key_n[258] = {
0x08,0x00,
0x9e,0x01,0x33,0x15,0x8b,0xfa,0x77,0x4e,0x63,0x9f,0x40,0x04,0x32,0x8d,0xb8,0x43,
0x4e,0xf3,0xe1,0x71,0xa8,0x7d,0x32,0x4d,0x43,0x18,0xc2,0x23,0xa8,0xdc,0x48,0x91,
0x85,0xaa,0x4d,0x37,0x96,0xb5,0x1d,0x9a,0x13,0x94,0xae,0x8c,0x3b,0x65,0x29,0x86,
0xc6,0xbd,0xd6,0xa0,0xa6,0x8f,0x7e,0x47,0x0f,0x4d,0xab,0x4b,0xdd,0x6d,0xf5,0x0b,
0x76,0x00,0xa3,0xcf,0xc5,0xa0,0x49,0x67,0xd9,0xbb,0x99,0x3e,0x3d,0x0d,0x34,0xd1,
0xe9,0xe2,0xe9,0xae,0x32,0xdf,0x6c,0x53,0x3e,0x06,0x5b,0x6b,0x40,0xe5,0xe0,0xe6,
0xd2,0x0f,0x37,0x2a,0x8e,0x5d,0x2f,0xee,0x34,0x2d,0xa1,0xed,0x7d,0xea,0x2e,0xe1,
0x89,0x2d,0x77,0x25,0x72,0xdc,0xef,0xac,0x69,0xee,0x4a,0x18,0xc0,0xc4,0x3d,0x01,
0xfd,0x7a,0x79,0x65,0x02,0x66,0x51,0x71,0x49,0x91,0x21,0x95,0xb9,0xcb,0x0b,0x3d,
0xac,0x8d,0xd5,0x4f,0x24,0xf7,0xc1,0xea,0xab,0x45,0x2c,0xa4,0xaf,0x33,0xb1,0x6a,
0x71,0xa8,0x27,0x44,0xc7,0xa1,0xaa,0xaf,0xa7,0x02,0x7f,0x27,0xf7,0x14,0x9c,0x03,
0xa6,0xba,0xd3,0x7d,0x6a,0x70,0xd0,0x34,0xe8,0xfa,0xb5,0x92,0x75,0xea,0xac,0xe9,
0x62,0x5c,0xd7,0x2b,0x17,0x64,0x70,0x45,0xf5,0xbb,0xbd,0xde,0x32,0x7a,0x9b,0x7d,
0x25,0x77,0x6a,0x3d,0x9b,0xd0,0x36,0xff,0xfb,0x54,0x9c,0xd1,0xbb,0xe2,0xb9,0x77,
0x72,0xa7,0x29,0xb4,0xda,0xdb,0x87,0x7b,0xc1,0xbb,0xde,0x76,0x8a,0x6c,0xf5,0x80,
0x2c,0x47,0x5a,0xe9,0xc0,0x60,0x4d,0x31,0x5a,0xc9,0x8b,0x47,0xd1,0xa0,0x05,0x6d
};
static const char ka3_key_e[] = {
	0x00,0x11,0x01,0x00,0x01, 
};

static struct rsa_key ka3_rsa_key = {
	ka3_key_n,
	sizeof(ka3_key_n),
	ka3_key_e,
	sizeof(ka3_key_e),
};


/* MP */
static const char ka5_key_n[258] = {
0x08,0x00,
0xd7,0x1b,0x5e,0xdd,0x3b,0xcc,0xc0,0xc3,0x7d,0x88,0x79,0x88,0xcc,0xdf,0x3f,0x2a,
0x77,0x01,0x65,0x88,0x73,0x5f,0xfc,0xee,0x28,0x14,0x38,0x1e,0xf4,0xfc,0x6d,0x5b,
0x52,0xfd,0xd5,0x75,0xa8,0x38,0x2e,0x1d,0x3b,0x35,0x60,0x33,0x05,0x5d,0x3c,0x85,
0x27,0xa5,0xce,0xee,0x75,0x73,0x4b,0xeb,0xef,0x05,0x0f,0x68,0xac,0xe0,0x4f,0x5b,
0x8d,0xc7,0x9b,0x1b,0xf7,0xe9,0xa8,0x16,0xb7,0xd9,0x73,0x16,0xea,0x9c,0x4b,0xa7,
0x42,0x65,0x91,0x20,0x74,0x69,0xa5,0xc1,0x55,0x6e,0x29,0x88,0x4a,0x46,0x78,0x9d,
0x1e,0x5f,0xd8,0x98,0x17,0x66,0x15,0x0a,0x26,0x9c,0x53,0x0c,0x61,0xe6,0xc0,0x61,
0x15,0x1f,0x30,0x31,0x21,0x8b,0x94,0x3f,0x61,0x54,0xf6,0xb5,0x4f,0x2d,0x11,0x9c,
0x3a,0xf5,0xd3,0x70,0x0b,0x00,0x11,0x69,0xb6,0x0d,0xff,0x49,0x31,0xc0,0xda,0x43,
0x30,0x8e,0x1f,0xa9,0x57,0x68,0x37,0xf4,0x14,0xd5,0xa0,0x7a,0x01,0xd8,0xcc,0x83,
0xa2,0x6c,0x99,0x55,0xf4,0xe0,0x93,0xc3,0xa7,0x89,0xbe,0x45,0xd2,0x1e,0x30,0xe2,
0x62,0x0b,0x41,0x66,0x49,0x91,0x16,0x26,0x39,0x56,0x39,0x3e,0x93,0x2f,0x2f,0x57,
0xcf,0x2a,0x01,0xb6,0xf7,0xff,0x04,0x28,0xec,0x27,0x2f,0x40,0x95,0xe8,0x9b,0x6e,
0x3a,0xfb,0xfd,0x3f,0x29,0xc5,0xd9,0x76,0x9f,0xef,0xe9,0xe5,0xad,0xec,0xb9,0x50,
0x44,0x62,0x56,0xff,0x7e,0xd3,0x2f,0x7c,0xef,0xa0,0xf1,0xbe,0xc2,0xe4,0x88,0x39,
0xa3,0xd0,0xc8,0x43,0x70,0x3f,0xbc,0x4a,0x15,0x91,0x0f,0xde,0xe3,0x73,0xa8,0x25
};
static const char ka5_key_e[] = {
	0x00,0x11,0x01,0x00,0x01, 
};

static struct rsa_key ka5_rsa_key = {
	ka5_key_n,
	sizeof(ka5_key_n),
	ka5_key_e,
	sizeof(ka5_key_e),
};
