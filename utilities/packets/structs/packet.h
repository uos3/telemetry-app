struct Packet {
	char crc[3];
	char hash[17];
	PayloadType type;
	Status status;
	Payload payload;
	uint32_t downlink_time;
};
