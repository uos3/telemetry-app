struct GPS {
	char dataset_id[3];
	uint32_t timestamp;
	uint32_t gps_time;
	float lat;
	float lon;
	float alt;
	uint8_t hdop;
	uint8_t vdop;
	uint8_t pdop;
	uint8_t tdop;
};

