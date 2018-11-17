struct Img {
	char dataset_id[3];
	uint32_t timestamp;
	uint8_t image_id;
	uint16_t fragment_id;
	uint16_t num_fragments;
	char image_data[6]; // TODO: replace once size is finalized
};
