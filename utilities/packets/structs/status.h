struct Status {
	char spacecraft_id[3];
	uint32_t time;
	bool time_source;
	char beacon_id[3];
	int8_t obc_temperature;
	int8_t battery_temperature;
	int8_t battery_voltage;
	uint8_t battery_current;
	uint8_t charge_current;
	bool antenna_deployment;
	uint8_t operational_mode; // TODO #refactor: enum? -- actually 2 bit -> nominal/downlinking/low power/safe
	uint16_t data_pending;
	uint8_t reboot_count;
	bool rails_status[6];
	int8_t rx_temperature;
	int8_t tx_temperature;
	int8_t pa_temperature;
	uint8_t rx_noisefloor;
};
