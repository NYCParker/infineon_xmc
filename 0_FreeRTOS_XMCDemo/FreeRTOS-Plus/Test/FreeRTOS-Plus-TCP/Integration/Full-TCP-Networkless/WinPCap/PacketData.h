char pkt1[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x00, 0x30, 0x09, 0x9c, 0x40, 0x00, 0x80, 0x06,
0x6f, 0x07, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc7, 0x35, 0x00, 0x00, 0x00, 0x00, 0x70, 0x02,
0x40, 0x00, 0xdf, 0xab, 0x00, 0x00, 0x02, 0x04,
0x05, 0xb4, 0x01, 0x01, 0x04, 0x02 };

char pkt2[] = {
0x00, 0x14, 0x22, 0xcb, 0x18, 0x2d, 0x00, 0x01,
0x02, 0x45, 0x09, 0x11, 0x08, 0x00, 0x45, 0x00,
0x00, 0x2c, 0x00, 0x01, 0x00, 0x00, 0x40, 0x06,
0xf8, 0xa6, 0xc0, 0xa8, 0x00, 0x0c, 0xc0, 0xa8,
0x00, 0xc8, 0x00, 0x50, 0x0f, 0xe2, 0x00, 0x00,
0x06, 0x68, 0x09, 0xe7, 0xc7, 0x36, 0x60, 0x12,
0x05, 0x92, 0x28, 0xca, 0x00, 0x00, 0x02, 0x04,
0x05, 0x92 };

char pkt3[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x00, 0x28, 0x09, 0x9e, 0x40, 0x00, 0x80, 0x06,
0x6f, 0x0d, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc7, 0x36, 0x00, 0x00, 0x06, 0x69, 0x50, 0x10,
0x42, 0xd8, 0x82, 0x3f, 0x00, 0x00 };

char pkt4[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x02, 0x27, 0x09, 0x9f, 0x40, 0x00, 0x80, 0x06,
0x6d, 0x0d, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc7, 0x36, 0x00, 0x00, 0x06, 0x69, 0x50, 0x18,
0x42, 0xd8, 0x84, 0x3e, 0x00, 0x00, 0x47, 0x45,
0x54, 0x20, 0x2f, 0x20, 0x48, 0x54, 0x54, 0x50,
0x2f, 0x31, 0x2e, 0x31, 0x0d, 0x0a, 0x41, 0x63,
0x63, 0x65, 0x70, 0x74, 0x3a, 0x20, 0x69, 0x6d,
0x61, 0x67, 0x65, 0x2f, 0x67, 0x69, 0x66, 0x2c,
0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x78,
0x2d, 0x78, 0x62, 0x69, 0x74, 0x6d, 0x61, 0x70,
0x2c, 0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f,
0x6a, 0x70, 0x65, 0x67, 0x2c, 0x20, 0x69, 0x6d,
0x61, 0x67, 0x65, 0x2f, 0x70, 0x6a, 0x70, 0x65,
0x67, 0x2c, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69,
0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2f, 0x76,
0x6e, 0x64, 0x2e, 0x6d, 0x73, 0x2d, 0x65, 0x78,
0x63, 0x65, 0x6c, 0x2c, 0x20, 0x61, 0x70, 0x70,
0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x2f, 0x6d, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x2c,
0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x2f, 0x76, 0x6e, 0x64,
0x2e, 0x6d, 0x73, 0x2d, 0x70, 0x6f, 0x77, 0x65,
0x72, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x2c, 0x20,
0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x2f, 0x78, 0x2d, 0x6d, 0x73,
0x2d, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x20, 0x61, 0x70,
0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
0x6e, 0x2f, 0x78, 0x2d, 0x6d, 0x73, 0x2d, 0x78,
0x62, 0x61, 0x70, 0x2c, 0x20, 0x61, 0x70, 0x70,
0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x2f, 0x76, 0x6e, 0x64, 0x2e, 0x6d, 0x73, 0x2d,
0x78, 0x70, 0x73, 0x64, 0x6f, 0x63, 0x75, 0x6d,
0x65, 0x6e, 0x74, 0x2c, 0x20, 0x61, 0x70, 0x70,
0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x2f, 0x78, 0x61, 0x6d, 0x6c, 0x2b, 0x78, 0x6d,
0x6c, 0x2c, 0x20, 0x2a, 0x2f, 0x2a, 0x0d, 0x0a,
0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d, 0x4c,
0x61, 0x6e, 0x67, 0x75, 0x61, 0x67, 0x65, 0x3a,
0x20, 0x65, 0x6e, 0x2d, 0x67, 0x62, 0x0d, 0x0a,
0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d, 0x45,
0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x3a,
0x20, 0x67, 0x7a, 0x69, 0x70, 0x2c, 0x20, 0x64,
0x65, 0x66, 0x6c, 0x61, 0x74, 0x65, 0x0d, 0x0a,
0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65,
0x6e, 0x74, 0x3a, 0x20, 0x4d, 0x6f, 0x7a, 0x69,
0x6c, 0x6c, 0x61, 0x2f, 0x34, 0x2e, 0x30, 0x20,
0x28, 0x63, 0x6f, 0x6d, 0x70, 0x61, 0x74, 0x69,
0x62, 0x6c, 0x65, 0x3b, 0x20, 0x4d, 0x53, 0x49,
0x45, 0x20, 0x36, 0x2e, 0x30, 0x3b, 0x20, 0x57,
0x69, 0x6e, 0x64, 0x6f, 0x77, 0x73, 0x20, 0x4e,
0x54, 0x20, 0x35, 0x2e, 0x31, 0x3b, 0x20, 0x53,
0x56, 0x31, 0x3b, 0x20, 0x47, 0x6f, 0x6f, 0x67,
0x6c, 0x65, 0x54, 0x35, 0x3b, 0x20, 0x2e, 0x4e,
0x45, 0x54, 0x20, 0x43, 0x4c, 0x52, 0x20, 0x32,
0x2e, 0x30, 0x2e, 0x35, 0x30, 0x37, 0x32, 0x37,
0x3b, 0x20, 0x2e, 0x4e, 0x45, 0x54, 0x20, 0x43,
0x4c, 0x52, 0x20, 0x33, 0x2e, 0x30, 0x2e, 0x30,
0x34, 0x35, 0x30, 0x36, 0x2e, 0x36, 0x34, 0x38,
0x3b, 0x20, 0x2e, 0x4e, 0x45, 0x54, 0x20, 0x43,
0x4c, 0x52, 0x20, 0x33, 0x2e, 0x35, 0x2e, 0x32,
0x31, 0x30, 0x32, 0x32, 0x29, 0x0d, 0x0a, 0x48,
0x6f, 0x73, 0x74, 0x3a, 0x20, 0x31, 0x39, 0x32,
0x2e, 0x31, 0x36, 0x38, 0x2e, 0x30, 0x2e, 0x31,
0x32, 0x0d, 0x0a, 0x43, 0x6f, 0x6e, 0x6e, 0x65,
0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, 0x4b,
0x65, 0x65, 0x70, 0x2d, 0x41, 0x6c, 0x69, 0x76,
0x65, 0x0d, 0x0a, 0x0d, 0x0a };

char pkt5[] = {
0x00, 0x14, 0x22, 0xcb, 0x18, 0x2d, 0x00, 0x01,
0x02, 0x45, 0x09, 0x11, 0x08, 0x00, 0x45, 0x00,
0x00, 0x2c, 0x00, 0x02, 0x00, 0x00, 0x40, 0x06,
0xf8, 0xa5, 0xc0, 0xa8, 0x00, 0x0c, 0xc0, 0xa8,
0x00, 0xc8, 0x00, 0x50, 0x0f, 0xe2, 0x00, 0x00,
0x06, 0x68, 0x09, 0xe7, 0xc7, 0x36, 0x60, 0x12,
0x05, 0x92, 0x28, 0xca, 0x00, 0x00, 0x02, 0x04,
0x05, 0x92 };

char pkt6[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x00, 0x28, 0x09, 0xa1, 0x40, 0x00, 0x80, 0x06,
0x6f, 0x0a, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc9, 0x35, 0x00, 0x00, 0x06, 0x69, 0x50, 0x10,
0x42, 0xd8, 0x82, 0x3f, 0x00, 0x00 };

char pkt7[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x02, 0x27, 0x09, 0xa2, 0x40, 0x00, 0x80, 0x06,
0x6d, 0x0a, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc7, 0x36, 0x00, 0x00, 0x06, 0x69, 0x50, 0x18,
0x42, 0xd8, 0x84, 0x3e, 0x00, 0x00, 0x47, 0x45,
0x54, 0x20, 0x2f, 0x20, 0x48, 0x54, 0x54, 0x50,
0x2f, 0x31, 0x2e, 0x31, 0x0d, 0x0a, 0x41, 0x63,
0x63, 0x65, 0x70, 0x74, 0x3a, 0x20, 0x69, 0x6d,
0x61, 0x67, 0x65, 0x2f, 0x67, 0x69, 0x66, 0x2c,
0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x78,
0x2d, 0x78, 0x62, 0x69, 0x74, 0x6d, 0x61, 0x70,
0x2c, 0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f,
0x6a, 0x70, 0x65, 0x67, 0x2c, 0x20, 0x69, 0x6d,
0x61, 0x67, 0x65, 0x2f, 0x70, 0x6a, 0x70, 0x65,
0x67, 0x2c, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69,
0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2f, 0x76,
0x6e, 0x64, 0x2e, 0x6d, 0x73, 0x2d, 0x65, 0x78,
0x63, 0x65, 0x6c, 0x2c, 0x20, 0x61, 0x70, 0x70,
0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x2f, 0x6d, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x2c,
0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x2f, 0x76, 0x6e, 0x64,
0x2e, 0x6d, 0x73, 0x2d, 0x70, 0x6f, 0x77, 0x65,
0x72, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x2c, 0x20,
0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x2f, 0x78, 0x2d, 0x6d, 0x73,
0x2d, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x20, 0x61, 0x70,
0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
0x6e, 0x2f, 0x78, 0x2d, 0x6d, 0x73, 0x2d, 0x78,
0x62, 0x61, 0x70, 0x2c, 0x20, 0x61, 0x70, 0x70,
0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x2f, 0x76, 0x6e, 0x64, 0x2e, 0x6d, 0x73, 0x2d,
0x78, 0x70, 0x73, 0x64, 0x6f, 0x63, 0x75, 0x6d,
0x65, 0x6e, 0x74, 0x2c, 0x20, 0x61, 0x70, 0x70,
0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x2f, 0x78, 0x61, 0x6d, 0x6c, 0x2b, 0x78, 0x6d,
0x6c, 0x2c, 0x20, 0x2a, 0x2f, 0x2a, 0x0d, 0x0a,
0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d, 0x4c,
0x61, 0x6e, 0x67, 0x75, 0x61, 0x67, 0x65, 0x3a,
0x20, 0x65, 0x6e, 0x2d, 0x67, 0x62, 0x0d, 0x0a,
0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d, 0x45,
0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x3a,
0x20, 0x67, 0x7a, 0x69, 0x70, 0x2c, 0x20, 0x64,
0x65, 0x66, 0x6c, 0x61, 0x74, 0x65, 0x0d, 0x0a,
0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65,
0x6e, 0x74, 0x3a, 0x20, 0x4d, 0x6f, 0x7a, 0x69,
0x6c, 0x6c, 0x61, 0x2f, 0x34, 0x2e, 0x30, 0x20,
0x28, 0x63, 0x6f, 0x6d, 0x70, 0x61, 0x74, 0x69,
0x62, 0x6c, 0x65, 0x3b, 0x20, 0x4d, 0x53, 0x49,
0x45, 0x20, 0x36, 0x2e, 0x30, 0x3b, 0x20, 0x57,
0x69, 0x6e, 0x64, 0x6f, 0x77, 0x73, 0x20, 0x4e,
0x54, 0x20, 0x35, 0x2e, 0x31, 0x3b, 0x20, 0x53,
0x56, 0x31, 0x3b, 0x20, 0x47, 0x6f, 0x6f, 0x67,
0x6c, 0x65, 0x54, 0x35, 0x3b, 0x20, 0x2e, 0x4e,
0x45, 0x54, 0x20, 0x43, 0x4c, 0x52, 0x20, 0x32,
0x2e, 0x30, 0x2e, 0x35, 0x30, 0x37, 0x32, 0x37,
0x3b, 0x20, 0x2e, 0x4e, 0x45, 0x54, 0x20, 0x43,
0x4c, 0x52, 0x20, 0x33, 0x2e, 0x30, 0x2e, 0x30,
0x34, 0x35, 0x30, 0x36, 0x2e, 0x36, 0x34, 0x38,
0x3b, 0x20, 0x2e, 0x4e, 0x45, 0x54, 0x20, 0x43,
0x4c, 0x52, 0x20, 0x33, 0x2e, 0x35, 0x2e, 0x32,
0x31, 0x30, 0x32, 0x32, 0x29, 0x0d, 0x0a, 0x48,
0x6f, 0x73, 0x74, 0x3a, 0x20, 0x31, 0x39, 0x32,
0x2e, 0x31, 0x36, 0x38, 0x2e, 0x30, 0x2e, 0x31,
0x32, 0x0d, 0x0a, 0x43, 0x6f, 0x6e, 0x6e, 0x65,
0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, 0x4b,
0x65, 0x65, 0x70, 0x2d, 0x41, 0x6c, 0x69, 0x76,
0x65, 0x0d, 0x0a, 0x0d, 0x0a };

char pkt8[] = {
0x00, 0x14, 0x22, 0xcb, 0x18, 0x2d, 0x00, 0x01,
0x02, 0x45, 0x09, 0x11, 0x08, 0x00, 0x45, 0x00,
0x00, 0x2c, 0x00, 0x03, 0x00, 0x00, 0x40, 0x06,
0xf8, 0xa4, 0xc0, 0xa8, 0x00, 0x0c, 0xc0, 0xa8,
0x00, 0xc8, 0x00, 0x50, 0x0f, 0xe2, 0x00, 0x00,
0x06, 0x68, 0x09, 0xe7, 0xc7, 0x36, 0x60, 0x12,
0x05, 0x92, 0x28, 0xca, 0x00, 0x00, 0x02, 0x04,
0x05, 0x92 };

char pkt9[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x00, 0x28, 0x09, 0xa3, 0x40, 0x00, 0x80, 0x06,
0x6f, 0x08, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc9, 0x35, 0x00, 0x00, 0x06, 0x69, 0x50, 0x10,
0x42, 0xd8, 0x82, 0x3f, 0x00, 0x00 };

char pkt10[] = {
0x00, 0x14, 0x22, 0xcb, 0x18, 0x2d, 0x00, 0x01,
0x02, 0x45, 0x09, 0x11, 0x08, 0x00, 0x45, 0x00,
0x00, 0x2c, 0x00, 0x04, 0x00, 0x00, 0x40, 0x06,
0xf8, 0xa3, 0xc0, 0xa8, 0x00, 0x0c, 0xc0, 0xa8,
0x00, 0xc8, 0x00, 0x50, 0x0f, 0xe2, 0x00, 0x00,
0x06, 0x68, 0x09, 0xe7, 0xc7, 0x36, 0x60, 0x12,
0x05, 0x92, 0x28, 0xca, 0x00, 0x00, 0x02, 0x04,
0x05, 0x92 };

char pkt11[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x00, 0x28, 0x09, 0xa6, 0x40, 0x00, 0x80, 0x06,
0x6f, 0x05, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc9, 0x35, 0x00, 0x00, 0x06, 0x69, 0x50, 0x10,
0x42, 0xd8, 0x82, 0x3f, 0x00, 0x00 };

char pkt12[] = {
0x00, 0x01, 0x02, 0x45, 0x09, 0x11, 0x00, 0x14,
0x22, 0xcb, 0x18, 0x2d, 0x08, 0x00, 0x45, 0x00,
0x00, 0x28, 0x09, 0xa7, 0x40, 0x00, 0x80, 0x06,
0x6f, 0x04, 0xc0, 0xa8, 0x00, 0xc8, 0xc0, 0xa8,
0x00, 0x0c, 0x0f, 0xe2, 0x00, 0x50, 0x09, 0xe7,
0xc9, 0x35, 0x00, 0x00, 0x06, 0x69, 0x50, 0x14,
0x00, 0x00, 0x43, 0xf4, 0x00, 0x00 };


typedef struct
{
	char *pcData;
	int iDataLen;
} xPacketData;

xPacketData xAllPackets[] =
{
/* These comments below are there so that we may modify
 * them as and when required. Keeping them unmodified.
 * Might be removed in later incremental PRs */
	{ pkt1, sizeof( pkt1 ) },
/*	{ pkt2, sizeof( pkt2 ) },  */
	{ pkt3, sizeof( pkt3 ) },
	{ pkt4, sizeof( pkt4 ) },
/*	{ pkt5, sizeof( pkt5 ) },  */
	{ pkt6, sizeof( pkt6 ) },
	{ pkt7, sizeof( pkt7 ) },
	{ pkt8, sizeof( pkt8 ) },
	{ pkt9, sizeof( pkt9 ) },
	{ pkt10, sizeof( pkt10 ) },
/*	{ pkt11, sizeof( pkt11 ) },  */
/*	{ pkt12, sizeof( pkt12 ) },  */
/*	{ pkt13, sizeof( pkt13 ) },  */
/*	{ pkt14, sizeof( pkt14 ) },  */
/*	{ pkt15, sizeof( pkt15 ) },  */
/*	{ pkt16, sizeof( pkt16 ) },  */
};
