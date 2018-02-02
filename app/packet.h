#ifndef PACKET_H
#define PACKET_H

#include <QString>

// Types
struct status {
	// TODO - actual types
	QString spacecraft_id;
	QString time;
	QString time_source;
	QString sequence_id;
	QString obc_temperature;
	QString battery_temperature;
	QString battery_voltage;
	QString battery_current;
	QString charge_current;
	QString antenna_deployment;
	QString data_pending;
	QString reboot_count;
	QString rails_status;
	QString rx_temperature;
	QString tx_temperature;
	QString pa_temperature;
	QString rx_noisefloor;
};

struct gps {
	// TODO: in spec, sq_id is 16bit (2 chars), so this is 3 to accomodate null
	//       terminator
	char sequence_id[3];
	unsigned int timestamp;
	float lat;
	float lon;
	float alt;
	// TODO - NOTE: according to the spec, these are 8bit reals (at least from
	//              the cubesat).
	float HDOP;
	float VDOP;
	float PDOP;
	float TDOP;
};

struct imu {
	char sequence_id[3];
	unsigned int timestamp;
	// TODO: are likely reals, not ints
	uint16_t Mag_X[5];
	uint16_t Mag_Y[5];
	uint16_t Mag_Z[5];
	uint16_t Gyro_X[5];
	uint16_t Gyro_Y[5];
	uint16_t Gyro_Z[5];
	uint16_t Accel_X[5];
	uint16_t Accel_Y[5];
	uint16_t Accel_Z[5];
};

struct img {
	char sequence_id[3];
	unsigned int timestamp;
	uint8_t image_id;
	uint16_t fragment_id;
	uint16_t num_fragments;
	// TODO: replace once size is finalized
	char image_data[6];
};

struct health {
	// TODO - actual types
	QString sequence_id;
	QString timestamp;
	QString obc_temperature;
	QString rx_temperature;
	QString tx_temperature;
	QString pa_temperature;
	QString reboot_count;
	QString data_packets_pending;
	QString antenna_switch;
	QString rx_noisefloor;
	QString detected_flash_errors;
	QString detected_ram_errors;
	QString battery_voltage;
	QString battery_current;
	QString battery_temperature;
	QString charge_current;
	QString mppt_voltage;
	QString solar_n1_current;
	QString solar_n2_current;
	QString solar_e1_current;
	QString solar_e2_current;
	QString solar_s1_current;
	QString solar_s2_current;
	QString solar_w1_current;
	QString solar_w2_current;
	QString solar_t1_current;
	QString solar_t2_current;
	QString rails_switch_status;
	QString rails_overcurrent_status;
	QString rail_1_boot_count;
	QString rail_1_overcurrent_count;
	QString rail_1_voltage;
	QString rail_1_current;
	QString rail_2_boot_count;
	QString rail_2_overcurrent_count;
	QString rail_2_voltage;
	QString rail_2_current;
	QString rail_3_boot_count;
	QString rail_3_overcurrent_count;
	QString rail_3_voltage;
	QString rail_3_current;
	QString rail_4_boot_count;
	QString rail_4_overcurrent_count;
	QString rail_4_voltage;
	QString rail_4_current;
	QString rail_5_boot_count;
	QString rail_5_overcurrent_count;
	QString rail_5_voltage;
	QString rail_5_current;
	QString rail_6_boot_count;
	QString rail_6_overcurrent_count;
	QString rail_6_voltage;
	QString rail_6_current;
	QString _3v3_voltage;
	QString _3v3_current;
	QString _5v_voltage;
	QString _5v_current;
};

struct ts_dt {
	char member[6];
};

union data {
	gps _gps;
	imu _imu;
	img _img;
//	health _health;
	ts_dt _td;
};

//class Packet {
//public:
//	// Construction / Destruction
//	Packet();
//
//	// Getters / Setters
//	status getStatus();
//	data getData();
//	void setStatus(status st);
//	void setData(data dt);
//private:
//	// Members
//	status _status;
//	data _data;
//};

#endif // PACKET_H